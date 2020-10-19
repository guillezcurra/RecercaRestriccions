
// Generated from ./LogicSchemaGrammar.g4 by ANTLR 4.7.2

#pragma once


#include "H:\Documents\TFG\vcpkg\packages\antlr4_x86-windows\include\antlr4-runtime.h"
#include "LogicSchemaGrammarParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by LogicSchemaGrammarParser.
 */
class  LogicSchemaGrammarListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(LogicSchemaGrammarParser::ProgContext *ctx) = 0;
  virtual void exitProg(LogicSchemaGrammarParser::ProgContext *ctx) = 0;

  virtual void enterLogicRule(LogicSchemaGrammarParser::LogicRuleContext *ctx) = 0;
  virtual void exitLogicRule(LogicSchemaGrammarParser::LogicRuleContext *ctx) = 0;

  virtual void enterBody(LogicSchemaGrammarParser::BodyContext *ctx) = 0;
  virtual void exitBody(LogicSchemaGrammarParser::BodyContext *ctx) = 0;

  virtual void enterLiteral(LogicSchemaGrammarParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(LogicSchemaGrammarParser::LiteralContext *ctx) = 0;

  virtual void enterBuiltInLiteral(LogicSchemaGrammarParser::BuiltInLiteralContext *ctx) = 0;
  virtual void exitBuiltInLiteral(LogicSchemaGrammarParser::BuiltInLiteralContext *ctx) = 0;

  virtual void enterOrdinaryLiteral(LogicSchemaGrammarParser::OrdinaryLiteralContext *ctx) = 0;
  virtual void exitOrdinaryLiteral(LogicSchemaGrammarParser::OrdinaryLiteralContext *ctx) = 0;

  virtual void enterAtom(LogicSchemaGrammarParser::AtomContext *ctx) = 0;
  virtual void exitAtom(LogicSchemaGrammarParser::AtomContext *ctx) = 0;

  virtual void enterTermsList(LogicSchemaGrammarParser::TermsListContext *ctx) = 0;
  virtual void exitTermsList(LogicSchemaGrammarParser::TermsListContext *ctx) = 0;

  virtual void enterPredicate(LogicSchemaGrammarParser::PredicateContext *ctx) = 0;
  virtual void exitPredicate(LogicSchemaGrammarParser::PredicateContext *ctx) = 0;

  virtual void enterTerm(LogicSchemaGrammarParser::TermContext *ctx) = 0;
  virtual void exitTerm(LogicSchemaGrammarParser::TermContext *ctx) = 0;


};

