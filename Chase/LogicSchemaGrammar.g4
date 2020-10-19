grammar LogicSchemaGrammar;

NOT: 'NOT';
FAIL: '#FAIL';
OPERATOR: '='|'<>'|'<'|'>'|'<='|'>=';
ID: [A-Za-z_@] [A-Za-z0-9_@]*;
NUMBER: [0-9]+;
STRING: ' ([A-Za-z0-9_@]+) ';
CONSTRAINTID: '@'[0-9]+;
NEWLINE:'\r'? '\n';
WS : [ \t]+ -> skip ; // toss out whitespace
COMMENT : '%' ~[\r\n]*;
COMMA: ',';
OPENPAR: '(';
CLOSEPAR: ')';
ARROW: '->';
EXTRAINFO: '[' ~[\r\n]* ']' | '{' ~[\r\n]* '}' ;


prog: ((atom)? NEWLINE)* ((logicRule)? NEWLINE)* ;
logicRule: leftElem=body ARROW (rightElem=body | FAIL);
body: literal (COMMA literal)*;
literal: ordinaryLiteral | builtInLiteral;
builtInLiteral: leftElem=term OPERATOR rightElem=term;
ordinaryLiteral: atom;
atom: predicate OPENPAR termsList CLOSEPAR;
termsList: | term (COMMA term)*;
predicate: ID;
term: ID | STRING | NUMBER;

