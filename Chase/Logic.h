#pragma once
#include <vector>
#include <utility>

struct Term {
	bool constant;
	int id;
	Term(bool constant, int id) : constant(constant), id(id) {}
	Term() {}
};

struct Atom {
	int predicate;
	std::vector<Term> terms;
};

struct Equality {	
	Term left;
	Term right;
};

struct Predicate {
	int id;
	int arity;
	std::vector<std::pair<int, int>> constants;
	std::vector<int> returns;
	Predicate() {}
	Predicate(int id, int arity) : id(id), arity(arity) {}
};

struct Component {
	Predicate start;
	std::vector<std::pair<std::vector<std::pair<int, int>>, Predicate>> joins;
};

enum RetunType {
	RETURN_VALUE,
	CONST,
	NULL_VALUE
};

struct Rule {
	//id, aritat de cada predicat de l'esquerra
	std::vector<Component> comp;
	//id predicats dreta
	std::vector< Predicate > outpred;
	int rowSize;
	int numOfNulls;
	bool fail;
	//id terms de la dreta (negatius son nulls)
	std::vector<std::pair<RetunType, int>> outTerms;
	std::vector<std::pair<std::pair<RetunType, int>, std::pair<RetunType, int>>> equalities;
};