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
%token <std::string> PLUSOP MINUSOP MULTOP DIVOP ASSIGNOP LESS GREATER NOT AND OR EQUAL LP RP LSB RSB LCB RCB COLON DOT COMMA WHILE IF ELSE TRUE FALSE THIS NEW CLASS PUBLIC PRIVATE STATIC VOID TYPEINT BOOLEAN STRINGTYPE PRINTLN RETURN LENGTH INT IDENTIFIER MAIN
%token END 0 "end of file"

//definition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl
%left PLUSOP MINUSOP
%left MULTOP

// definition of the production rules. All production rules are of type Node
%type <Node *> root expression goal mainclass classDeclaration statement type methodDeclaration varDeclaration identifier arguments parameters

%%
/*NOTES
  *: 0 or more occurences
  ?: 0 or 1 occurences   
*/

goal: mainclass (classDeclaration)* END {}
mainclass: PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRINGTYPE LSB RSB identifier RP LCB statement (statement)* RCB RCB {}
classDeclaration: CLASS identifier {}
varDeclaration: type identifier COLON {}
methodDeclaration: PUBLIC type identifier LP parameters RP LCB (varDeclaration | statement)* RETURN expression COLON RCB {}

parameters: type identifier
|type identifier COMMA parameters
|// empty no more parameters

type: TYPEINT LSB RSB {}
| BOOLEAN {}
| TYPEINT {}
| identifier {}

statement: LCB (statement)* RCB {}
| IF LP expression RP statement (ELSE statement)? {}
| WHILE LP expression RP statement {}
| PRINTLN LP expression RP COLON {}
| identifier ASSIGNOP expression COLON {}
| identifier LSB expression RSB ASSIGNOP expression COLON {}

expression: expression PLUSOP expression {      /*
                                                  Create a subtree that corresponds to the AddExpression
                                                  The root of the subtree is AddExpression
                                                  The childdren of the AddExpression subtree are the left hand side (expression accessed through $1) and right hand side of the expression (expression accessed through $3)
                                                */
                            $$ = new Node("AddExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression MINUSOP expression {
                            $$ = new Node("SubExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression MULTOP expression {
                            $$ = new Node("MultExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression DIVOP expression {
                            $$ = new Node("DivExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression AND expression {
                            $$ = new Node("AndExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression OR expression {
                            $$ = new Node("OrExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression LESS expression {
                            $$ = new Node("LessExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
            | expression GREATER expression {
                            $$ = new Node("GreaterExpression", "", yylineno);
                            $$->children.push_back($1);
                            $$->children.push_back($3);
                          }
| expression LSB expression RSB {}
| expression DOT LENGTH {}
| expression DOT identifier LP arguments RP {}
| INT {}
| TRUE {}
| FALSE {}
| identifier {}
| THIS {}
| NEW TYPEINT LSB expression RSB {}
| NEW identifier LP RP {}
| NOT expression{}
| LP expression RP{}

arguments: expression //If multiple arguments add recursivly
| expression COMMA arguments
| // empty

identifier: IDENTIFIER {}