%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor


%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY 0 //change this macro to true if you want to isolate the lexer from the parser.
}

%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
}

// definition of set of tokens. All tokens are of type string
%token <std::string>  PLUSOP MINUSOP MULTOP ASSIGNOP LESS GREATER NOT AND OR EQUAL LP RP LSB RSB RCB LCB SEMI DOT COMMA WHILE IF ELSE TRUE FALSE THIS NEW CLASS PUBLIC PRIVATE STATIC VOID TYPEINT BOOLEAN STRINGTYPE PRINTLN RETURN LENGTH INT IDENTIFIER MAIN
%token END 0 "end of file"

//definition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl

// https://www.cs.bilkent.edu.tr/~guvenir/courses/CS101/op_precedence.html
%left ASSIGNOP
%left OR
%left AND
%left EQUAL
%left LESS GREATER
%left PLUSOP MINUSOP
%left MULTOP
%left NOT
%left LP RP

// definition of the production rules. All production rules are of type Node
%type <Node *> root goal mainClass classDeclaration varDeclaration type statement expression identifier methodDeclaration classDeclarations statements varDeclarations methodDeclarations moreParams methodItem methodContent moreArgs paramsOpt elseOpt

%%
root: goal;

//Base grammar
goal: mainClass classDeclarations END
mainClass: PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRINGTYPE LSB RSB identifier RP LCB statement statements RCB RCB
classDeclaration: CLASS identifier LCB varDeclarations methodDeclarations RCB
varDeclaration: type identifier SEMI
methodDeclaration: PUBLIC type identifier LP paramsOpt RP LCB methodContent RETURN expression SEMI RCB

type: TYPEINT LSB RSB
  | BOOLEAN
  | TYPEINT
  | identifier

statement: LCB statements RCB
  | IF LP expression RP statement elseOpt
  | WHILE LP expression RP statement
  | PRINTLN LP expression RP SEMI 
  | identifier ASSIGNOP expression SEMI
  | identifier LSB expression RSB ASSIGNOP expression SEMI

expression: expression AND expression
  | expression OR expression
  | expression LESS expression
  | expression GREATER expression
  | expression EQUAL expression
  | expression PLUSOP expression 
  | expression MINUSOP expression
  | expression MULTOP expression
  | expression LSB expression RSB
  | expression DOT LENGTH
  | expression DOT identifier LP argsOpt RP {}
  | INT {$$ = new Node("Int", $1, yylineno);}
  | TRUE {$$ = new Node("True", "", yylineno);}
  | FALSE {$$ = new Node("False", "", yylineno);}
  | identifier
  | THIS
  | NEW TYPEINT LSB expression RSB
  | NEW identifier LP RP
  | NOT expression
  | LP expression RP

identifier: IDENTIFIER {$$ = new Node("identifier", $1, yylineno);};

// * rules (zero or more)

//(ClassDeclaration)*
classDeclarations: %empty
| classDeclarations classDeclaration

//(Statement)*
statements: %empty
| statements statement

//(VarDeclaration)*
varDeclarations: %empty
| varDeclarations varDeclaration

//(MethodDeclaration*)
methodDeclarations: %empty
| methodDeclarations methodDeclaration

//("," Type Identifier)*
moreParams: %empty
| moreParams COMMA type identifier

// (VarDeclaration | Statement)
methodItem: varDeclaration
| statement

//(VarDeclaration | Statement )*
methodContent: %empty
| methodContent methodItem

//("," Expression )*
moreArgs: %empty
| moreArgs COMMA expression

// ? rules (zero or one)

//(Type Identifier("," Type Identifier )*)?
paramsOpt: %empty
| type identifier moreParams

//("else" Statement)?
elseOpt: %empty
| ELSE statement

//( Expression( "," Expression )*)?
argsOpt: %empty
| expression moreArgs