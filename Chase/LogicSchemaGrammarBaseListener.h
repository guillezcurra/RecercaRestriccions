
// Generated from ./LogicSchemaGrammar.g4 by ANTLR 4.7.2

#pragma once


#include "H:\Documents\TFG\vcpkg\packages\antlr4_x86-windows\include\antlr4-runtime.h"
#include "LogicSchemaGrammarListener.h"


/**
 * This class provides an empty implementation of LogicSchemaGrammarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  LogicSchemaGrammarBaseListener : public LogicSchemaGrammarListener {
public:

  virtual void enterProg(LogicSchemaGrammarParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(LogicSchemaGrammarParser::ProgContext * /*ctx*/) override { }

  virtual void enterLogicRule(LogicSchemaGrammarParser::LogicRuleContext * /*ctx*/) override { }
  virtual void exitLogicRule(LogicSchemaGrammarParser::LogicRuleContext * /*ctx*/) override { }

  virtual void enterBody(LogicSchemaGrammarParser::BodyContext * /*ctx*/) override { }
  virtual void exitBody(LogicSchemaGrammarParser::BodyContext * /*ctx*/) override { }

  virtual void enterLiteral(LogicSchemaGrammarParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(LogicSchemaGrammarParser::LiteralContext * /*ctx*/) override { }

  virtual void enterBuiltInLiteral(LogicSchemaGrammarParser::BuiltInLiteralContext * /*ctx*/) override { }
  virtual void exitBuiltInLiteral(LogicSchemaGrammarParser::BuiltInLiteralContext * /*ctx*/) override { }

  virtual void enterOrdinaryLiteral(LogicSchemaGrammarParser::OrdinaryLiteralContext * /*ctx*/) override { }
  virtual void exitOrdinaryLiteral(LogicSchemaGrammarParser::OrdinaryLiteralContext * /*ctx*/) override { }

  virtual void enterAtom(LogicSchemaGrammarParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(LogicSchemaGrammarParser::AtomContext * /*ctx*/) override { }

  virtual void enterTermsList(LogicSchemaGrammarParser::TermsListContext * /*ctx*/) override { }
  virtual void exitTermsList(LogicSchemaGrammarParser::TermsListContext * /*ctx*/) override { }

  virtual void enterPredicate(LogicSchemaGrammarParser::PredicateContext * /*ctx*/) override { }
  virtual void exitPredicate(LogicSchemaGrammarParser::PredicateContext * /*ctx*/) override { }

  virtual void enterTerm(LogicSchemaGrammarParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(LogicSchemaGrammarParser::TermContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

