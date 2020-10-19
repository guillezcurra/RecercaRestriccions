#include "InstanceManager.h"

InstanceManager* InstanceManager::instance = nullptr;

InstanceManager::InstanceManager() {

}

InstanceManager* InstanceManager::getInstance() {
	if (instance == nullptr) instance = new InstanceManager();
	return instance;
}

void InstanceManager::insertPred(int id) {
	if (instances.size() <= id) instances.resize(id + 1);
}

void InstanceManager::insertInstance(int pId, std::vector<int>& terms) {
	if (pId >= instances.size()) {
		//inssert the new predicate
		instances.push_back(std::vector<std::vector <int>>());
	}

	instances[pId].push_back(terms);
}

void InstanceManager::setNumPredicates(int num) {
	instances.resize(num);
}

bool InstanceManager::exists(int pred, std::vector<int>& terms) {
	std::vector <std::vector <int> >& ins = instances[pred];
	int rows = ins.size();
	int numTerms = terms.size();
	for (int r = 0; r < rows; r++) {
		bool same = true;
		for (int i = 0; i < numTerms; i++) {
			same &= (terms[i] == ins[r][i]);
		}
		if (same) return true;
	}
	return false;
}

bool InstanceManager::inferred(int rule, int* ptr, int size) {
	auto res = rules[rule].insert(std::vector<int>(ptr, ptr + size));
	return !res.second;
}

void InstanceManager::getTable(Predicate& p, Buffer* res, bool& some) {
	std::vector <std::vector <int> >& table = instances[p.id];
	int rows = table.size();
	for (int i = 0; i < rows; i++) {
		//check the constant constraints of the query
		bool merge = true;
		for (int c = 0; c < p.constants.size(); c++) {
			if (table[i][p.constants[c].first] != p.constants[c].second) {
				merge = false;
				break;
			}
		}
		if (merge) {
			//get the values
			for (int r = 0; r < p.returns.size(); r++) {
				res->put(table[i][p.returns[r]]);
			}
			some = true;
		}
	}
}

void InstanceManager::join(Predicate p, std::vector<std::pair<int, int>>& join, Buffer* input, int rowSize, Buffer* output, bool &some) {
	Buffer* reciver = bufferManager.get();
	int joinConstants = p.constants.size();
	for (int i = 0; i < join.size(); i++) {
		p.constants.push_back(std::make_pair(join[i].second, -1));
	}
	int constantsSize = p.constants.size();
	int tableReturnSize = p.returns.size();
	for (int i = 0; i < input->getSize(); i += rowSize) {
		//set the join constants
		for (int c = joinConstants; c < constantsSize; c++) {
			p.constants[c].second = input->ptr[i + join[c-joinConstants].first];
		}
		some = false;
		getTable(p, reciver, some);
		
		if (some) {
			if (tableReturnSize > 0) {
				// make the cartesion product
				for (int j = 0; j < reciver->getSize(); j += tableReturnSize) {
					//copy values
					for (int k = 0; k < rowSize; k++) {
						output->put(input->ptr[i + k]);
					}
					for (int k = 0; k < tableReturnSize; k++) {
						output->put(reciver->ptr[j + k]);
					}
				}
			}
			else {
				for (int k = 0; k < rowSize; k++) {
					output->put(input->ptr[i + k]);
				}
			}	
		}
		
		reciver->reset();
	}
	bufferManager.free(reciver);
}

void InstanceManager::setNumRules(int size) {
	rules.resize(size);
}

bool InstanceManager::evalRule(int ruleId, Rule& r, IdManager<std::string>& constants, int& nullCount) {

	Buffer* res = bufferManager.get();
	int resultSize = 0;
	bool some = false;
	for (int i = 0; i < r.comp.size(); i++) {
		Component& c = r.comp[i];
		Buffer* aux;
		if (i == 0) aux = res;
		else aux = bufferManager.get();

		bool s = false;
		getTable(c.start, aux, s);
		int componentSize = c.start.returns.size();
		for (int j = 0; j < c.joins.size(); j++) {
			Buffer* tmp = bufferManager.get();
			join(c.joins[j].second, c.joins[j].first, aux, componentSize, tmp, s);
			componentSize += c.joins[j].second.returns.size();
			bufferManager.free(aux);
			aux = tmp;
		}

		if (i != 0) {
			Buffer* tmp = bufferManager.get();
			for (int k1 = 0; k1 < res->getSize(); k1 += resultSize) {
				for (int k2 = 0; k2 < aux->getSize(); k2 += componentSize) {
					for (int t = 0; t < resultSize; t++) {
						tmp->put(res->ptr[k1 + t]);
					}
					for (int t = 0; t < componentSize; t++) {
						tmp->put(aux->ptr[k2 + t]);
					}
				}
			}
			bufferManager.free(aux);
			bufferManager.free(res);
			res = tmp;
		}
		else res = aux;

		resultSize += componentSize;
	}
	/*
	for (int i = 0; i < r.equalities.size(); ++i) {
		std::pair<RetunType, int>& left = r.equalities[i].first;
		std::pair<RetunType, int>& right = r.equalities[i].second;
		switch (left.first)
		{
		case RETURN_VALUE:
			if (right.first == RETURN_VALUE) {
				for (int j = 0; j < res->getSize(); j += resultSize) res->ptr[j + left.second] = res->ptr[j + right.second];
			}
			else if (right.first == CONST) {
				for (int j = 0; j < res->getSize(); j += resultSize) res->ptr[j + left.second] = right.second;
			}
			else if (right.first == NULL_VALUE) {
				for (int j = 0; j < res->getSize(); j += resultSize) res->ptr[j + left.second] = right.second;
			}
			break;
		case CONST:
			if (right.first == RETURN_VALUE) {
				for (int j = 0; j < res->getSize(); j += resultSize) res->ptr[j + right.second] = left.second;
			}
			else if (right.first == CONST) {if (right.second != left.second) return false;}
			else if (right.first == NULL_VALUE) return false;
			break;
		case NULL_VALUE:
			if (right.first == RETURN_VALUE) { 
				for (int j = 0; j < res->getSize(); j += resultSize) res->ptr[j + right.second] = left.second;
			}
			else if (right.first == CONST) return false;
			else if (right.first == NULL_VALUE) { if (right.second != left.second) return false; }
			break;
		}
	}
	*/

	bool result = false;
	if (r.fail) {
		result = !some;
	}
	else {
		if (res->getSize() == 0) result = false;
		else {
			//create the new instances
			for (int i = 0; i < res->getSize(); i += resultSize) {
				if (inferred(ruleId, res->ptr + i, resultSize)) {
					continue;
				}
				
				
				bool b = false;
				for (int j = 0; j < r.equalities.size() && !b; ++j) {
					std::pair<RetunType, int>& left = r.equalities[j].first;
					std::pair<RetunType, int>& right = r.equalities[j].second;
					
					if (left.first == RETURN_VALUE && right.first == RETURN_VALUE) {
						if (constants.toObj(res->ptr[i + left.second])[0] == '#') res->ptr[i + left.second] = res->ptr[i + right.second];
						else if (constants.toObj(res->ptr[i + right.second])[0] == '#') res->ptr[i + right.second] = res->ptr[i + left.second];
						else if (res->ptr[i + left.second] != res->ptr[i + right.second]) b = true;
					}
					else if (left.first == RETURN_VALUE && constants.toObj(res->ptr[i + left.second]) != constants.toObj(right.second)) b = true;
					else if (right.first == RETURN_VALUE && constants.toObj(res->ptr[i + right.second]) != constants.toObj(left.second)) b = true;
					
				}
				if (b) { r.fail = true; return false; };
				

				std::vector<int> nullValues(r.numOfNulls, -1);
				int incr = 0;
				for (int p = 0; p < r.outpred.size(); p++) {
					int pred = r.outpred[p].id;
					int arity = r.outpred[p].arity;

					int nInstance = instances[pred].size();
					std::vector<int> newInstance(arity);

					for (int a = 0; a < arity; a++) {
						switch (r.outTerms[a + incr].first)
						{
						case RETURN_VALUE:
							newInstance[a] = res->ptr[i + r.outTerms[a + incr].second];
							break;
						case CONST:
							newInstance[a] = r.outTerms[a + incr].second;
							break;
						case NULL_VALUE:
							if (nullValues[r.outTerms[a + incr].second] == -1) {
								nullValues[r.outTerms[a + incr].second] = constants.addObj("#" + std::to_string(nullCount++));
							}
							newInstance[a] = nullValues[r.outTerms[a + incr].second];
							break;
						}
					}
					incr += arity;

					//TODO check if curreny exists
					if (!exists(pred, newInstance)) {
						instances[pred].push_back(newInstance);
						result = true;
					}
				}
			}
		}
	}

	bufferManager.free(res);
	return result;
}

void InstanceManager::printData(IdManager<std::string>* predicates, IdManager<std::string>* constants, std::ostream& out) {
	int numPred = instances.size();
	for (int p = 0; p < numPred; p++) {
		int rows = instances[p].size();
		std::string pred = predicates->toObj(p);
		for (int r = 0; r < rows; r++) {
			int columns = instances[p][r].size();
			out << pred << "(";
			for (int c = 0; c < columns; c++) {
				if (c != 0) out << ", ";
				out << constants->toObj(instances[p][r][c]);
			}
			out << ")" << "\n";
		}
	}
}