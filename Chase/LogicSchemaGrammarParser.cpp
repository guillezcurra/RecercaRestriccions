
// Generated from ./LogicSchemaGrammar.g4 by ANTLR 4.7.2


#include "LogicSchemaGrammarListener.h"

#include "LogicSchemaGrammarParser.h"


using namespace antlrcpp;
using namespace antlr4;

LogicSchemaGrammarParser::LogicSchemaGrammarParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

LogicSchemaGrammarParser::~LogicSchemaGrammarParser() {
  delete _interpreter;
}

std::string LogicSchemaGrammarParser::getGrammarFileName() const {
  return "LogicSchemaGrammar.g4";
}

const std::vector<std::string>& LogicSchemaGrammarParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& LogicSchemaGrammarParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

LogicSchemaGrammarParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> LogicSchemaGrammarParser::ProgContext::NEWLINE() {
  return getTokens(LogicSchemaGrammarParser::NEWLINE);
}

tree::TerminalNode* LogicSchemaGrammarParser::ProgContext::NEWLINE(size_t i) {
  return getToken(LogicSchemaGrammarParser::NEWLINE, i);
}

std::vector<LogicSchemaGrammarParser::AtomContext *> LogicSchemaGrammarParser::ProgContext::atom() {
  return getRuleContexts<LogicSchemaGrammarParser::AtomContext>();
}

LogicSchemaGrammarParser::AtomContext* LogicSchemaGrammarParser::ProgContext::atom(size_t i) {
  return getRuleContext<LogicSchemaGrammarParser::AtomContext>(i);
}

std::vector<LogicSchemaGrammarParser::LogicRuleContext *> LogicSchemaGrammarParser::ProgContext::logicRule() {
  return getRuleContexts<LogicSchemaGrammarParser::LogicRuleContext>();
}

LogicSchemaGrammarParser::LogicRuleContext* LogicSchemaGrammarParser::ProgContext::logicRule(size_t i) {
  return getRuleContext<LogicSchemaGrammarParser::LogicRuleContext>(i);
}


size_t LogicSchemaGrammarParser::ProgContext::getRuleIndex() const {
  return LogicSchemaGrammarParser::RuleProg;
}

void LogicSchemaGrammarParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void LogicSchemaGrammarParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}

LogicSchemaGrammarParser::ProgContext* LogicSchemaGrammarParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, LogicSchemaGrammarParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(26);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(21);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == LogicSchemaGrammarParser::ID) {
          setState(20);
          atom();
        }
        setState(23);
        match(LogicSchemaGrammarParser::NEWLINE); 
      }
      setState(28);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(35);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LogicSchemaGrammarParser::ID)
      | (1ULL << LogicSchemaGrammarParser::NUMBER)
      | (1ULL << LogicSchemaGrammarParser::STRING)
      | (1ULL << LogicSchemaGrammarParser::NEWLINE))) != 0)) {
      setState(30);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << LogicSchemaGrammarParser::ID)
        | (1ULL << LogicSchemaGrammarParser::NUMBER)
        | (1ULL << LogicSchemaGrammarParser::STRING))) != 0)) {
        setState(29);
        logicRule();
      }
      setState(32);
      match(LogicSchemaGrammarParser::NEWLINE);
      setState(37);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicRuleContext ------------------------------------------------------------------

LogicSchemaGrammarParser::LogicRuleContext::LogicRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LogicSchemaGrammarParser::LogicRuleContext::ARROW() {
  return getToken(LogicSchemaGrammarParser::ARROW, 0);
}

std::vector<LogicSchemaGrammarParser::BodyContext *> LogicSchemaGrammarParser::LogicRuleContext::body() {
  return getRuleContexts<LogicSchemaGrammarParser::BodyContext>();
}

LogicSchemaGrammarParser::BodyContext* LogicSchemaGrammarParser::LogicRuleContext::body(size_t i) {
  return getRuleContext<LogicSchemaGrammarParser::BodyContext>(i);
}

tree::TerminalNode* LogicSchemaGrammarParser::LogicRuleContext::FAIL() {
  return getToken(LogicSchemaGrammarParser::FAIL, 0);
}


size_t LogicSchemaGrammarParser::LogicRuleContext::getRuleIndex() const {
  return LogicSchemaGrammarParser::RuleLogicRule;
}

void LogicSchemaGrammarParser::LogicRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicRule(this);
}

void LogicSchemaGrammarParser::LogicRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicRule(this);
}

LogicSchemaGrammarParser::LogicRuleContext* LogicSchemaGrammarParser::logicRule() {
  LogicRuleContext *_localctx = _tracker.createInstance<LogicRuleContext>(_ctx, getState());
  enterRule(_localctx, 2, LogicSchemaGrammarParser::RuleLogicRule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    dynamic_cast<LogicRuleContext *>(_localctx)->leftElem = body();
    setState(39);
    match(LogicSchemaGrammarParser::ARROW);
    setState(42);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LogicSchemaGrammarParser::ID:
      case LogicSchemaGrammarParser::NUMBER:
      case LogicSchemaGrammarParser::STRING: {
        setState(40);
        dynamic_cast<LogicRuleContext *>(_localctx)->rightElem = body();
        break;
      }

      case LogicSchemaGrammarParser::FAIL: {
        setState(41);
        match(LogicSchemaGrammarParser::FAIL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BodyContext ------------------------------------------------------------------

LogicSchemaGrammarParser::BodyContext::BodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LogicSchemaGrammarParser::LiteralContext *> LogicSchemaGrammarParser::BodyContext::literal() {
  return getRuleContexts<LogicSchemaGrammarParser::LiteralContext>();
}

LogicSchemaGrammarParser::LiteralContext* LogicSchemaGrammarParser::BodyContext::literal(size_t i) {
  return getRuleContext<LogicSchemaGrammarParser::LiteralContext>(i);
}

std::vector<tree::TerminalNode *> LogicSchemaGrammarParser::BodyContext::COMMA() {
  return getTokens(LogicSchemaGrammarParser::COMMA);
}

tree::TerminalNode* LogicSchemaGrammarParser::BodyContext::COMMA(size_t i) {
  return getToken(LogicSchemaGrammarParser::COMMA, i);
}


size_t LogicSchemaGrammarParser::BodyContext::getRuleIndex() const {
  return LogicSchemaGrammarParser::RuleBody;
}

void LogicSchemaGrammarParser::BodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBody(this);
}

void LogicSchemaGrammarParser::BodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBody(this);
}

LogicSchemaGrammarParser::BodyContext* LogicSchemaGrammarParser::body() {
  BodyContext *_localctx = _tracker.createInstance<BodyContext>(_ctx, getState());
  enterRule(_localctx, 4, LogicSchemaGrammarParser::RuleBody);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(44);
    literal();
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == LogicSchemaGrammarParser::COMMA) {
      setState(45);
      match(LogicSchemaGrammarParser::COMMA);
      setState(46);
      literal();
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

LogicSchemaGrammarParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LogicSchemaGrammarParser::OrdinaryLiteralContext* LogicSchemaGrammarParser::LiteralContext::ordinaryLiteral() {
  return getRuleContext<LogicSchemaGrammarParser::OrdinaryLiteralContext>(0);
}

LogicSchemaGrammarParser::BuiltInLiteralContext* LogicSchemaGrammarParser::LiteralContext::builtInLiteral() {
  return getRuleContext<LogicSchemaGrammarParser::BuiltInLiteralContext>(0);
}


size_t LogicSchemaGrammarParser::LiteralContext::getRuleIndex() const {
  return LogicSchemaGrammarParser::RuleLiteral;
}

void LogicSchemaGrammarParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void LogicSchemaGrammarParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}

LogicSchemaGrammarParser::LiteralContext* LogicSchemaGrammarParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 6, LogicSchemaGrammarParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(54);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(52);
      ordinaryLiteral();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(53);
      builtInLiteral();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BuiltInLiteralContext ------------------------------------------------------------------

LogicSchemaGrammarParser::BuiltInLiteralContext::BuiltInLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LogicSchemaGrammarParser::BuiltInLiteralContext::OPERATOR() {
  return getToken(LogicSchemaGrammarParser::OPERATOR, 0);
}

std::vector<LogicSchemaGrammarParser::TermContext *> LogicSchemaGrammarParser::BuiltInLiteralContext::term() {
  return getRuleContexts<LogicSchemaGrammarParser::TermContext>();
}

LogicSchemaGrammarParser::TermContext* LogicSchemaGrammarParser::BuiltInLiteralContext::term(size_t i) {
  return getRuleContext<LogicSchemaGrammarParser::TermContext>(i);
}


size_t LogicSchemaGrammarParser::BuiltInLiteralContext::getRuleIndex() const {
  return LogicSchemaGrammarParser::RuleBuiltInLiteral;
}

void LogicSchemaGrammarParser::BuiltInLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBuiltInLiteral(this);
}

void LogicSchemaGrammarParser::BuiltInLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBuiltInLiteral(this);
}

LogicSchemaGrammarParser::BuiltInLiteralContext* LogicSchemaGrammarParser::builtInLiteral() {
  BuiltInLiteralContext *_localctx = _tracker.createInstance<BuiltInLiteralContext>(_ctx, getState());
  enterRule(_localctx, 8, LogicSchemaGrammarParser::RuleBuiltInLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    dynamic_cast<BuiltInLiteralContext *>(_localctx)->leftElem = term();
    setState(57);
    match(LogicSchemaGrammarParser::OPERATOR);
    setState(58);
    dynamic_cast<BuiltInLiteralContext *>(_localctx)->rightElem = term();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrdinaryLiteralContext ------------------------------------------------------------------

LogicSchemaGrammarParser::OrdinaryLiteralContext::OrdinaryLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LogicSchemaGrammarParser::AtomContext* LogicSchemaGrammarParser::OrdinaryLiteralContext::atom() {
  return getRuleContext<LogicSchemaGrammarParser::AtomContext>(0);
}


size_t LogicSchemaGrammarParser::OrdinaryLiteralContext::getRuleIndex() const {
  return LogicSchemaGrammarParser::RuleOrdinaryLiteral;
}

void LogicSchemaGrammarParser::OrdinaryLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrdinaryLiteral(this);
}

void LogicSchemaGrammarParser::OrdinaryLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrdinaryLiteral(this);
}

LogicSchemaGrammarParser::OrdinaryLiteralContext* LogicSchemaGrammarParser::ordinaryLiteral() {
  OrdinaryLiteralContext *_localctx = _tracker.createInstance<OrdinaryLiteralContext>(_ctx, getState());
  enterRule(_localctx, 10, LogicSchemaGrammarParser::RuleOrdinaryLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    atom();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

LogicSchemaGrammarParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

LogicSchemaGrammarParser::PredicateContext* LogicSchemaGrammarParser::AtomContext::predicate() {
  return getRuleContext<LogicSchemaGrammarParser::PredicateContext>(0);
}

tree::TerminalNode* LogicSchemaGrammarParser::AtomContext::OPENPAR() {
  return getToken(LogicSchemaGrammarParser::OPENPAR, 0);
}

LogicSchemaGrammarParser::TermsListContext* LogicSchemaGrammarParser::AtomContext::termsList() {
  return getRuleContext<LogicSchemaGrammarParser::TermsListContext>(0);
}

tree::TerminalNode* LogicSchemaGrammarParser::AtomContext::CLOSEPAR() {
  return getToken(LogicSchemaGrammarParser::CLOSEPAR, 0);
}


size_t LogicSchemaGrammarParser::AtomContext::getRuleIndex() const {
  return LogicSchemaGrammarParser::RuleAtom;
}

void LogicSchemaGrammarParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void LogicSchemaGrammarParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

LogicSchemaGrammarParser::AtomContext* LogicSchemaGrammarParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 12, LogicSchemaGrammarParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(62);
    predicate();
    setState(63);
    match(LogicSchemaGrammarParser::OPENPAR);
    setState(64);
    termsList();
    setState(65);
    match(LogicSchemaGrammarParser::CLOSEPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermsListContext ------------------------------------------------------------------

LogicSchemaGrammarParser::TermsListContext::TermsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<LogicSchemaGrammarParser::TermContext *> LogicSchemaGrammarParser::TermsListContext::term() {
  return getRuleContexts<LogicSchemaGrammarParser::TermContext>();
}

LogicSchemaGrammarParser::TermContext* LogicSchemaGrammarParser::TermsListContext::term(size_t i) {
  return getRuleContext<LogicSchemaGrammarParser::TermContext>(i);
}

std::vector<tree::TerminalNode *> LogicSchemaGrammarParser::TermsListContext::COMMA() {
  return getTokens(LogicSchemaGrammarParser::COMMA);
}

tree::TerminalNode* LogicSchemaGrammarParser::TermsListContext::COMMA(size_t i) {
  return getToken(LogicSchemaGrammarParser::COMMA, i);
}


size_t LogicSchemaGrammarParser::TermsListContext::getRuleIndex() const {
  return LogicSchemaGrammarParser::RuleTermsList;
}

void LogicSchemaGrammarParser::TermsListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTermsList(this);
}

void LogicSchemaGrammarParser::TermsListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTermsList(this);
}

LogicSchemaGrammarParser::TermsListContext* LogicSchemaGrammarParser::termsList() {
  TermsListContext *_localctx = _tracker.createInstance<TermsListContext>(_ctx, getState());
  enterRule(_localctx, 14, LogicSchemaGrammarParser::RuleTermsList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case LogicSchemaGrammarParser::CLOSEPAR: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case LogicSchemaGrammarParser::ID:
      case LogicSchemaGrammarParser::NUMBER:
      case LogicSchemaGrammarParser::STRING: {
        enterOuterAlt(_localctx, 2);
        setState(68);
        term();
        setState(73);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == LogicSchemaGrammarParser::COMMA) {
          setState(69);
          match(LogicSchemaGrammarParser::COMMA);
          setState(70);
          term();
          setState(75);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PredicateContext ------------------------------------------------------------------

LogicSchemaGrammarParser::PredicateContext::PredicateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LogicSchemaGrammarParser::PredicateContext::ID() {
  return getToken(LogicSchemaGrammarParser::ID, 0);
}


size_t LogicSchemaGrammarParser::PredicateContext::getRuleIndex() const {
  return LogicSchemaGrammarParser::RulePredicate;
}

void LogicSchemaGrammarParser::PredicateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPredicate(this);
}

void LogicSchemaGrammarParser::PredicateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPredicate(this);
}

LogicSchemaGrammarParser::PredicateContext* LogicSchemaGrammarParser::predicate() {
  PredicateContext *_localctx = _tracker.createInstance<PredicateContext>(_ctx, getState());
  enterRule(_localctx, 16, LogicSchemaGrammarParser::RulePredicate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    match(LogicSchemaGrammarParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

LogicSchemaGrammarParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* LogicSchemaGrammarParser::TermContext::ID() {
  return getToken(LogicSchemaGrammarParser::ID, 0);
}

tree::TerminalNode* LogicSchemaGrammarParser::TermContext::STRING() {
  return getToken(LogicSchemaGrammarParser::STRING, 0);
}

tree::TerminalNode* LogicSchemaGrammarParser::TermContext::NUMBER() {
  return getToken(LogicSchemaGrammarParser::NUMBER, 0);
}


size_t LogicSchemaGrammarParser::TermContext::getRuleIndex() const {
  return LogicSchemaGrammarParser::RuleTerm;
}

void LogicSchemaGrammarParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void LogicSchemaGrammarParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<LogicSchemaGrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}

LogicSchemaGrammarParser::TermContext* LogicSchemaGrammarParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 18, LogicSchemaGrammarParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << LogicSchemaGrammarParser::ID)
      | (1ULL << LogicSchemaGrammarParser::NUMBER)
      | (1ULL << LogicSchemaGrammarParser::STRING))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> LogicSchemaGrammarParser::_decisionToDFA;
atn::PredictionContextCache LogicSchemaGrammarParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN LogicSchemaGrammarParser::_atn;
std::vector<uint16_t> LogicSchemaGrammarParser::_serializedATN;

std::vector<std::string> LogicSchemaGrammarParser::_ruleNames = {
  "prog", "logicRule", "body", "literal", "builtInLiteral", "ordinaryLiteral", 
  "atom", "termsList", "predicate", "term"
};

std::vector<std::string> LogicSchemaGrammarParser::_literalNames = {
  "", "'NOT'", "'#FAIL'", "", "", "", "' ([A-Za-z0-9_@]+) '", "", "", "", 
  "", "','", "'('", "')'", "'->'"
};

std::vector<std::string> LogicSchemaGrammarParser::_symbolicNames = {
  "", "NOT", "FAIL", "OPERATOR", "ID", "NUMBER", "STRING", "CONSTRAINTID", 
  "NEWLINE", "WS", "COMMENT", "COMMA", "OPENPAR", "CLOSEPAR", "ARROW", "EXTRAINFO"
};

dfa::Vocabulary LogicSchemaGrammarParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> LogicSchemaGrammarParser::_tokenNames;

LogicSchemaGrammarParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x11, 0x55, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x3, 0x2, 0x5, 0x2, 0x18, 0xa, 0x2, 0x3, 0x2, 0x7, 0x2, 0x1b, 0xa, 
    0x2, 0xc, 0x2, 0xe, 0x2, 0x1e, 0xb, 0x2, 0x3, 0x2, 0x5, 0x2, 0x21, 0xa, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x24, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x27, 0xb, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2d, 0xa, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x32, 0xa, 0x4, 0xc, 0x4, 0xe, 
    0x4, 0x35, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x39, 0xa, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x7, 0x9, 0x4a, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x4d, 0xb, 0x9, 0x5, 
    0x9, 0x4f, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x2, 0x2, 0xc, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x2, 0x3, 0x3, 0x2, 0x6, 0x8, 0x2, 0x53, 0x2, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x28, 0x3, 0x2, 0x2, 0x2, 0x6, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x38, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x3a, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3e, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x40, 0x3, 0x2, 0x2, 0x2, 0x10, 0x4e, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x50, 0x3, 0x2, 0x2, 0x2, 0x14, 0x52, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x18, 0x5, 0xe, 0x8, 0x2, 0x17, 0x16, 0x3, 0x2, 0x2, 0x2, 0x17, 
    0x18, 0x3, 0x2, 0x2, 0x2, 0x18, 0x19, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1b, 
    0x7, 0xa, 0x2, 0x2, 0x1a, 0x17, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1e, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x1d, 0x25, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1c, 0x3, 0x2, 0x2, 
    0x2, 0x1f, 0x21, 0x5, 0x4, 0x3, 0x2, 0x20, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x24, 0x7, 0xa, 0x2, 0x2, 0x23, 0x20, 0x3, 0x2, 0x2, 0x2, 0x24, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0x25, 0x23, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x3, 
    0x2, 0x2, 0x2, 0x26, 0x3, 0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x29, 0x5, 0x6, 0x4, 0x2, 0x29, 0x2c, 0x7, 0x10, 0x2, 
    0x2, 0x2a, 0x2d, 0x5, 0x6, 0x4, 0x2, 0x2b, 0x2d, 0x7, 0x4, 0x2, 0x2, 
    0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x33, 0x5, 0x8, 0x5, 0x2, 0x2f, 0x30, 
    0x7, 0xd, 0x2, 0x2, 0x30, 0x32, 0x5, 0x8, 0x5, 0x2, 0x31, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x35, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 0x7, 0x3, 0x2, 0x2, 
    0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x36, 0x39, 0x5, 0xc, 0x7, 0x2, 
    0x37, 0x39, 0x5, 0xa, 0x6, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 
    0x5, 0x14, 0xb, 0x2, 0x3b, 0x3c, 0x7, 0x5, 0x2, 0x2, 0x3c, 0x3d, 0x5, 
    0x14, 0xb, 0x2, 0x3d, 0xb, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x5, 0xe, 
    0x8, 0x2, 0x3f, 0xd, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x5, 0x12, 0xa, 
    0x2, 0x41, 0x42, 0x7, 0xe, 0x2, 0x2, 0x42, 0x43, 0x5, 0x10, 0x9, 0x2, 
    0x43, 0x44, 0x7, 0xf, 0x2, 0x2, 0x44, 0xf, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x46, 0x4b, 0x5, 0x14, 0xb, 0x2, 0x47, 0x48, 
    0x7, 0xd, 0x2, 0x2, 0x48, 0x4a, 0x5, 0x14, 0xb, 0x2, 0x49, 0x47, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 
    0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x46, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x11, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x51, 0x7, 0x6, 0x2, 0x2, 0x51, 0x13, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 
    0x9, 0x2, 0x2, 0x2, 0x53, 0x15, 0x3, 0x2, 0x2, 0x2, 0xb, 0x17, 0x1c, 
    0x20, 0x25, 0x2c, 0x33, 0x38, 0x4b, 0x4e, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

LogicSchemaGrammarParser::Initializer LogicSchemaGrammarParser::_init;
