
// Generated from ./LogicSchemaGrammar.g4 by ANTLR 4.7.2

#pragma once


#include "H:\Documents\TFG\vcpkg\packages\antlr4_x86-windows\include\antlr4-runtime.h"




class  LogicSchemaGrammarLexer : public antlr4::Lexer {
public:
  enum {
    NOT = 1, FAIL = 2, OPERATOR = 3, ID = 4, NUMBER = 5, STRING = 6, CONSTRAINTID = 7, 
    NEWLINE = 8, WS = 9, COMMENT = 10, COMMA = 11, OPENPAR = 12, CLOSEPAR = 13, 
    ARROW = 14, EXTRAINFO = 15
  };

  LogicSchemaGrammarLexer(antlr4::CharStream *input);
  ~LogicSchemaGrammarLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

