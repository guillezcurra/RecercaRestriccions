#include "ChaseAlg.h"

ChaseAlg::ChaseAlg() {

}
ChaseAlg::~ChaseAlg() {

}


int ChaseAlg::chase(int maxIterations) {
	int iterations = 0;
	bool newValues = true;
	instanceManager.setNumRules(rules.size());
	while (newValues && iterations < maxIterations) {
		newValues = false;
		for (int i = 0; i < rules.size(); i++) {
			bool b = instanceManager.evalRule(i, rules[i], constants, nullCount);
			if (rules[i].fail && !b) return -1;
			else if (!rules[i].fail && b) newValues = true;
		}
		iterations++;
	}
	return iterations;
}


int ChaseAlg::chase() {
	return chase(147483648);
}

void ChaseAlg::print() {
	instanceManager.printData(&predicates, &constants, std::cout);
}

////////////////////////////
// Parser Functions       //
////////////////////////////

using namespace antlr4;
using namespace std;

static void change(int a, int b, vector<uint8_t>& vec) {
	int size = vec.size();
	for (int i = 0; i < size; i++) {
		if (vec[i] == a) vec[i] == b;
	}
}

void ChaseAlg::evalLogicRule(LogicSchemaGrammarParser::LogicRuleContext* logicRule) {
	vector<Atom> leftAtoms;
	vector<Equality> leftEqualities;
	vector<Atom> rightAtoms;
	vector<Equality> rightEqualities;

	IdManager<std::string> localMap;

	Rule r;
	evalBody(logicRule->leftElem, leftAtoms, leftEqualities, localMap);
	if (logicRule->rightElem != nullptr) {
		evalBody(logicRule->rightElem, rightAtoms, rightEqualities, localMap);
		r.fail = false;
	}
	else r.fail = true;
	
	//r.outpred.resize(rightAtoms.size());

	//create the right rule preducates
	vector<bool> needed(localMap.getNum(), false);
	vector<int> pos(localMap.getNum(), -1);
	int size = rightAtoms.size();
	for (int i = 0; i < size; i++) {
		std::vector<Term>& t = rightAtoms[i].terms;
		for (int j = 0; j < t.size(); j++) {
			if (!t[j].constant) {
				needed[t[j].id] = true;
			}
		}
	}

	size = rightEqualities.size();
	for (int i = 0; i < size; i++) {
		if (!rightEqualities[i].left.constant) {
			needed[rightEqualities[i].left.id] = true;
		}

		if (!rightEqualities[i].right.constant) {
			needed[rightEqualities[i].right.id] = true;
		}
	}

	//group all the joins
	vector<uint8_t> joins(localMap.getNum(), 0);
	int nextTeam = 1;
	int numGroups = 0;
	vector<uint8_t> teamVal(localMap.getNum(), 0);
	vector<uint8_t> teams(leftAtoms.size(), 0);
	size = leftAtoms.size();
	for (int i = 0; i < size; i++) {
		//search joins
		std::vector<Term>& t = leftAtoms[i].terms;
		int team = 0;
		for (int j = 0; j < t.size(); j++) {
			if (!t[j].constant) {
				if (joins[t[j].id] > 0) {
					needed[t[j].id] = true;
				}
				joins[t[j].id]++;

				if (teamVal[t[j].id] != 0) {
					if (team == 0) {
						team = teamVal[t[j].id];
					}
					else {
						//join two groups
						change(teamVal[t[j].id], team, teams);
						change(teamVal[t[j].id], team, teamVal);
						numGroups--;
					}
				}
			}
		}

		if (team == 0) {
			team = nextTeam++;
			numGroups++;
		}
		teams[i] = team;
		for (int j = 0; j < t.size(); j++) {
			if (!t[j].constant) {
				teamVal[t[j].id] = team;
			}
		}
	}

	//inverse the vector teams
	vector<int> inverseTeams(nextTeam, -1);
	int next = 0;
	vector<vector<int>> groups(numGroups, vector<int>());

	size = teams.size();
	for (int i = 0; i < size; i++) {
		if (inverseTeams[teams[i]] == -1) {
			inverseTeams[teams[i]] = next++;
		}
		groups[inverseTeams[teams[i]]].push_back(i);
	}


	// compile the left side rule
	int nextParam = 0;
	vector<int> used(localMap.getNum(), -1);
	int ruleId = rules.size();
	rules.push_back(r);
	rules[ruleId].rowSize = 0;
	for (int g = 0; g < numGroups; g++) {
		rules[ruleId].comp.push_back(Component());
		Component& c = rules[ruleId].comp[rules[ruleId].comp.size() - 1];

		c.start.id = leftAtoms[groups[g][0]].predicate;
		c.start.arity = leftAtoms[groups[g][0]].terms.size();

		int size = leftAtoms[groups[g][0]].terms.size();

		for (int j = 0; j < size; j++) {
			if (!leftAtoms[groups[g][0]].terms[j].constant) {
				if (needed[leftAtoms[groups[g][0]].terms[j].id] && used[leftAtoms[groups[g][0]].terms[j].id] == -1) {
					c.start.returns.push_back(j);
					rules[ruleId].rowSize++;
					used[leftAtoms[groups[g][0]].terms[j].id] = nextParam++;
				}
			}
			else {
				//add to the constant list
				c.start.constants.push_back(make_pair(j, leftAtoms[groups[g][0]].terms[j].id));
			}
		}

		for (int i = 1; i < groups[g].size(); i++) {
			c.joins.push_back(std::make_pair(std::vector<pair<int, int>>(), Predicate()));
			Predicate& p = c.joins[c.joins.size() - 1].second;
			auto& joins = c.joins[c.joins.size() - 1].first;

			p.id = leftAtoms[groups[g][i]].predicate;
			p.arity = leftAtoms[groups[g][i]].terms.size();

			int size = leftAtoms[groups[g][i]].terms.size();

			for (int j = 0; j < size; j++) {
				if (!leftAtoms[groups[g][i]].terms[j].constant) {
					if (needed[leftAtoms[groups[g][i]].terms[j].id] && used[leftAtoms[groups[g][i]].terms[j].id] == -1) {
						p.returns.push_back(j);
						rules[ruleId].rowSize++;
						used[leftAtoms[groups[g][i]].terms[j].id] = nextParam++;
					}
					else if (used[leftAtoms[groups[g][i]].terms[j].id] != -1) {
						//add as a join
						joins.push_back(make_pair(used[leftAtoms[groups[g][i]].terms[j].id], j));
					}

				}
				else {
					//add to the constant list
					p.constants.push_back(make_pair(j, leftAtoms[groups[g][i]].terms[j].id));
				}
			}
		}
	}

	//compile the right side rule atoms
	std::vector<int> nulls(localMap.getNum(), -1);
	size = rightAtoms.size();
	int nextNull = 0;
	for (int i = 0; i < size; i++) {
		rules[ruleId].outpred.push_back(Predicate(rightAtoms[i].predicate, rightAtoms[i].terms.size()));

		int size = rightAtoms[i].terms.size();

		for (int j = 0; j < size; j++) {
			if (!rightAtoms[i].terms[j].constant) {
				if (used[rightAtoms[i].terms[j].id] == -1) {
					//is a null value
					if (nulls[rightAtoms[i].terms[j].id] == -1) {
						rules[ruleId].outTerms.push_back(make_pair(NULL_VALUE, nextNull));
						nulls[rightAtoms[i].terms[j].id] = nextNull++;
					}
					else {
						rules[ruleId].outTerms.push_back(make_pair(NULL_VALUE, nulls[rightAtoms[i].terms[j].id]));
					}
				}
				else {
					//is a parameters
					rules[ruleId].outTerms.push_back(make_pair(RETURN_VALUE, used[rightAtoms[i].terms[j].id]));
				}
			}
			else {
				//add to the constant list
				rules[ruleId].outTerms.push_back(make_pair(CONST, rightAtoms[i].terms[j].id));
			}
		}
	}

	//compile the right side rule equalities
	size = rightEqualities.size();
	for (int i = 0; i < size; i++) {
		rules[ruleId].equalities.push_back(make_pair(make_pair(CONST, -1), make_pair(CONST, -1)));
		int eqIndex = rules[ruleId].equalities.size() - 1;

		if (!rightEqualities[i].left.constant) {
			if (used[rightEqualities[i].left.id] == -1) {
				//is a null value
				if (nulls[rightEqualities[i].left.id] == -1) {
					rules[ruleId].equalities[eqIndex].first = make_pair(NULL_VALUE, nextNull);
					nulls[rightEqualities[i].left.id] = nextNull++;
				}
				else {
					rules[ruleId].equalities[eqIndex].first = make_pair(NULL_VALUE, nulls[rightEqualities[i].left.id]);
				}
			}
			else {
				//is a parameters
				rules[ruleId].equalities[eqIndex].first = make_pair(RETURN_VALUE, used[rightEqualities[i].left.id]);
			}
		}
		else {
			//add to the constant list
			rules[ruleId].equalities[eqIndex].first = make_pair(CONST, rightEqualities[i].left.id);
		}

		if (!rightEqualities[i].right.constant) {
			if (used[rightEqualities[i].right.id] == -1) {
				//is a null value
				if (nulls[rightEqualities[i].right.id] == -1) {
					rules[ruleId].equalities[eqIndex].second = make_pair(NULL_VALUE, nextNull);
					nulls[rightEqualities[i].right.id] = nextNull++;
				}
				else {
					rules[ruleId].equalities[eqIndex].second = make_pair(NULL_VALUE, nulls[rightEqualities[i].right.id]);
				}
			}
			else {
				//is a parameters
				rules[ruleId].equalities[eqIndex].second = make_pair(RETURN_VALUE, used[rightEqualities[i].right.id]);
			}
		}
		else {
			//add to the constant list
			rules[ruleId].equalities[eqIndex].second = make_pair(CONST, rightEqualities[i].right.id);
		}
	}
	rules[ruleId].numOfNulls = nextNull;
}

void ChaseAlg::evalAtom(LogicSchemaGrammarParser::AtomContext* atom) {
	int pred = predicates.addObj(atom->predicate()->ID()->getText());

	std::vector<int> termsList;
	std::vector<LogicSchemaGrammarParser::TermContext*> terms = atom->termsList()->term();
	for (int i = 0; i < terms.size(); i++) {
		if (terms[i]->ID() != nullptr) {
			throw "No term ids in the initial database state";
		}
		else {
			if (terms[i]->NUMBER()) {
				termsList.push_back(constants.addObj(terms[i]->NUMBER()->getText()));
			}
			else {
				termsList.push_back(constants.addObj(terms[i]->STRING()->getText()));
			}
		}
	}

	//insert the atom
	instanceManager.insertInstance(pred, termsList);

}

void ChaseAlg::evalBody(LogicSchemaGrammarParser::BodyContext* body, std::vector<Atom>& listAtoms, std::vector<Equality>& listEqual, IdManager<std::string>& localMap) {
	vector<LogicSchemaGrammarParser::LiteralContext*> terms = body->literal();
	for (int i = 0; i < terms.size(); i++) {
		if (terms[i]->ordinaryLiteral() != nullptr) {
			LogicSchemaGrammarParser::OrdinaryLiteralContext* ol = terms[i]->ordinaryLiteral();
			listAtoms.push_back(Atom());
			evalAtom(ol->atom(), listAtoms[listAtoms.size() - 1], localMap);
		}
		else if (terms[i]->builtInLiteral() != nullptr) {
			LogicSchemaGrammarParser::BuiltInLiteralContext* bl = terms[i]->builtInLiteral();
			listEqual.push_back(Equality());
			evalEquality(bl, listEqual[listEqual.size()-1], localMap);
		}
	}
}

void ChaseAlg::evalEquality(LogicSchemaGrammarParser::BuiltInLiteralContext* eq, Equality& equal, IdManager<std::string>& localMap) {
	if (eq->OPERATOR()) {
		if (eq->leftElem->ID() != nullptr) {
			equal.left = Term(false, localMap.addObj(eq->leftElem->ID()->getText()));
		}
		else {
			if (eq->leftElem->NUMBER()) {
				equal.left = Term(true, constants.addObj(eq->leftElem->NUMBER()->getText()));
			}
			else {
				equal.left = Term(true, constants.addObj(eq->leftElem->STRING()->getText()));
			}
		}

		if (eq->rightElem->ID() != nullptr) {
			equal.right = Term(false, localMap.addObj(eq->rightElem->ID()->getText()));
		}
		else {
			if (eq->rightElem->NUMBER()) {
				equal.right = Term(true, constants.addObj(eq->rightElem->NUMBER()->getText()));
			}
			else {
				equal.right = Term(true, constants.addObj(eq->rightElem->STRING()->getText()));
			}
		}
	}
	else {
		std::cout << "only build in literals with equalities" << std::endl;
	}
}

void ChaseAlg::evalAtom(LogicSchemaGrammarParser::AtomContext* at, Atom& atom, IdManager<std::string>& localMap) {

	atom.predicate = predicates.addObj(at->predicate()->ID()->getText());

	std::vector<LogicSchemaGrammarParser::TermContext*> terms = at->termsList()->term();
	for (int i = 0; i < terms.size(); i++) {
		if (terms[i]->ID() != nullptr) {
			atom.terms.push_back(Term(false, localMap.addObj(terms[i]->ID()->getText())));
		}
		else {
			if (terms[i]->NUMBER()) {
				atom.terms.push_back(Term(true, constants.addObj(terms[i]->NUMBER()->getText())));
			}
			else {
				atom.terms.push_back(Term(true, constants.addObj(terms[i]->STRING()->getText())));
			}
		}
	}
}

void ChaseAlg::read(ANTLRInputStream& input) {
	string aux = input.toString();
	transform(aux.begin(), aux.end(), aux.begin(), ::toupper);
	ANTLRInputStream inputU(aux);
	LogicSchemaGrammarLexer lexer(&inputU);
	CommonTokenStream tokens(&lexer);
	LogicSchemaGrammarParser parser(&tokens);
	LogicSchemaGrammarParser::ProgContext* prog = parser.prog();

	vector<LogicSchemaGrammarParser::AtomContext*> atoms = prog->atom();
	for (int i = 0; i < atoms.size(); i++) {
		evalAtom(atoms[i]);
	}

	vector<LogicSchemaGrammarParser::LogicRuleContext*> rules = prog->logicRule();
	for (int i = 0; i < rules.size(); i++) {
		evalLogicRule(rules[i]);
	}

	instanceManager.setNumPredicates(predicates.getNum());
}

void ChaseAlg::readFile(const string& fileName) {
	ifstream stream;
	stream.open(fileName);
	ANTLRInputStream input(stream);
	read(input);
}

void ChaseAlg::readText(const string& text) {
	ANTLRInputStream input(text);
	read(input);
}