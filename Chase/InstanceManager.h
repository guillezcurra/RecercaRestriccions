#pragma once
#include <vector>
#include <set>
#include <string>
#include <ostream>
#include <iostream>
#include "Logic.h"
#include "BufferManager.h"
#include "IdManager.h"

class InstanceManager
{
private:
	std::vector< std::vector <std::vector <int> > > instances;
	std::vector<std::set<std::vector<int>>> rules;
	BufferManager bufferManager;
	static InstanceManager* instance;
	void getTable(Predicate& p, Buffer* res, bool& some);
	void join(Predicate p, std::vector<std::pair<int, int>>& join, Buffer* input, int rowSize, Buffer* output, bool& some);
	bool exists(int pred, std::vector<int>& terms);
	bool inferred(int rule, int* ptr, int size);
public:
	InstanceManager();
	static InstanceManager* getInstance();
	void insertPred(int id);
	void insertInstance(int id, std::vector<int>& terms);
	/*
		Pre: all atom terms are constants
		Pre: all predicates id come sequentialy
	*/
	void setNumPredicates(int num);
	//rterms es el vector de terms que retorna la query
	//pred es el vector de predicats que hi ha a l'esquerra
	//joins es el vector de joins que hi ha
	void setNumRules(int size);
	bool evalRule(int ruleId, Rule& r, IdManager<std::string>& constants, int& nullCount);

	void printData(IdManager<std::string>* predicates, IdManager<std::string>* constants, std::ostream& out);
	
	
};

