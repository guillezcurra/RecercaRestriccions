#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
#include "InstanceManager.h"
#include "IdManager.h"
#include <H:\Documents\TFG\vcpkg\packages\antlr4_x86-windows\include\antlr4-runtime.h>
#include "LogicSchemaGrammarParser.h"
#include "LogicSchemaGrammarLexer.h"

using namespace std;

class ChaseAlg
{
public:
	ChaseAlg();
	~ChaseAlg();

	//read function
	virtual void readFile(const std::string& fileName);
	virtual void readText(const std::string& text);

	//infereix un maxim de "iterations" cops
	//retorna el nombre d'iteracions que ha realitzat
	int chase(int iterations);
	//itera fins que no es pot inferir res mes
	//retorna el nombre d'iteracions que ha realitzat
	int chase();

	void print();

private:
	int nullCount = 0;

	InstanceManager instanceManager;
	std::vector<Rule> rules;

	int maxRetunSize;
	std::vector <std::vector<int>> returnBuffer;

	//parser
	IdManager<std::string> predicates;
	IdManager<std::string> constants;


	virtual void read(antlr4::ANTLRInputStream& input);

	//PARSE FUNCTIONS (TEXT TO LOGICS)
	void evalLogicRule(LogicSchemaGrammarParser::LogicRuleContext* logicRule);
	void evalAtom(LogicSchemaGrammarParser::AtomContext* atom);
	void evalBody(LogicSchemaGrammarParser::BodyContext* body, std::vector<Atom>& listAtoms, std::vector<Equality>& listEqual, IdManager<std::string>& localMap);
	void evalAtom(LogicSchemaGrammarParser::AtomContext* at, Atom& atom, IdManager<std::string>& localMap);
	void evalEquality(LogicSchemaGrammarParser::BuiltInLiteralContext* eq, Equality& equal, IdManager<std::string>&localMap);

};

