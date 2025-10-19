%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
}

%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
}

// definition of set of tokens. All tokens are of type string
%token <std::string> PLUSOP MINUSOP MULTOP DIVOP ASSIGNOP LESS GREATER NOT AND OR EQUAL LP RP LSB RSB RCB LCB SEMI DOT COMMA WHILE IF ELSE TRUE FALSE THIS NEW CLASS PUBLIC PRIVATE STATIC VOID TYPEINT BOOLEAN STRINGTYPE PRINTLN RETURN LENGTH INT IDENTIFIER MAIN
%token END 0 "end of file"

//definition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl
%left PLUSOP MINUSOP
%left MULTOP

// definition of the production rules. All production rules are of type Node
%type <Node *> root goal mainClass classDeclaration varDeclaration methodBody classDeclarationList methodParamList param type statement statementList expression expressionListOpt expressionList identifier

%%
root: goal {};

goal: mainClass classDeclarationList END{};
mainClass: PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRINGTYPE LSB RSB IDENTIFIER RP LCB statementList RCB RCB{};
classDeclaration: CLASS identifier LCB varDeclarationList methodDeclarationList RCB{}
classDeclarationList: classDeclarationList classDeclaration
| //empty

varDeclarationList: varDeclarationList varDeclaration{}
| //empty

varDeclaration: type IDENTIFIER SEMI {};

methodDeclaration: PUBLIC type IDENTIFIER LP methodParamList RP LCB methodBody RETURN expression SEMI RCB{};

methodDeclarationList: methodDeclarationList methodDeclaration {}
| //empty

//( VarDeclaration | Statement )*
methodBody: methodBody varDeclaration
| methodBody statement
|

//( Type Identifier ( "," Type Identifier )* )?

methodParamList: param {}
| methodParamList COMMA param
|

param: type IDENTIFIER


type: TYPEINT LSB RSB {}
    | BOOLEAN{}
    | TYPEINT{}
    | identifier{}


statement:
    LCB RCB { }
    | LCB statementList RCB { }
    | IF LP expression RP statement{}
    | IF LP expression RP statement ELSE statement{}
    | WHILE LP expression RP statement{}
    | PRINTLN LP expression RP SEMI{}
    | identifier ASSIGNOP expression SEMI{}
    | identifier LSB expression RSB ASSIGNOP expression SEMI{};

statementList:
    statement {}
    | statementList statement{};

expression: expression AND expression {}
            
            | expression OR expression {}
            | expression LESS expression {}
            | expression GREATER expression {}
            | expression EQUAL expression {}
            | expression PLUSOP expression {}
            | expression MINUSOP expression {}
            | expression MULTOP expression {}
            | expression DIVOP expression {}
            | expression LSB expression RSB {}
            | expression DOT LENGTH {}
            | expression DOT identifier LP expressionListOpt RP {}
            | INT {}
            | TRUE {}
            | FALSE {}
            | identifier
            | THIS {}
            | NEW TYPEINT LSB expression RSB {}
            | NEW identifier LP RP {}
            | NOT expression {}
            | LP expression RP {}

expressionListOpt: expressionList {}
              | /* empty */{};

expressionList: expression{}
               | expressionList COMMA expression {}


identifier: IDENTIFIER {}


