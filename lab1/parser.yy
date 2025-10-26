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
%type <Node *> root goal mainClass classDeclaration varDeclaration type statement expression identifier methodDeclaration classDeclarations statements varDeclarations methodDeclarations moreParams methodItem methodContent moreArgs paramsOpt elseOpt argsOpt
%%
root: goal;

//grammar rules
goal: mainClass classDeclarations END {
  $$ = new Node("Goal", "", yylineno);
  $$->children.push_back($1);
  $$->children.push_back($2);
  root = $$;
}
mainClass: PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRINGTYPE LSB RSB identifier RP LCB statement statements RCB RCB {
  $$ = new Node("mainClass","", yylineno);
  $$->children.push_back($3);
  $$->children.push_back($13);
  $$->children.push_back($16);
  $$->children.push_back($17);
}

classDeclaration: CLASS identifier LCB varDeclarations methodDeclarations RCB {
  $$ = new Node("class declaration", "", yylineno);
  $$->children.push_back($2);
  if ($4) $$->children.push_back($4);
  if ($5) $$->children.push_back($5);
}

varDeclaration: type identifier SEMI {
  $$ = new Node("varDeclaration", "", yylineno);
  $$->children.push_back($1);
  $$->children.push_back($2);
}

methodDeclaration: PUBLIC type identifier LP paramsOpt RP LCB methodContent RETURN expression SEMI RCB {
  $$ = new Node("methodDeclaration", "", yylineno);
  $$->children.push_back($2);
  $$->children.push_back($3);
  if ($5) $$->children.push_back($5);
  $$->children.push_back($8);
  $$->children.push_back($10);
}

type: TYPEINT LSB RSB {$$=new Node("type Array","", yylineno);}
  | BOOLEAN {$$=new Node("type Boolean","", yylineno);}
  | TYPEINT {$$=new Node("type Int","", yylineno);}
  | identifier {$$=$1;}

statement: LCB statements RCB {$$ = new Node("statement block", "", yylineno); $$->children.push_back($2);}
  | IF LP expression RP statement elseOpt {
    $$ = new Node("if statement","", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($5);
    if ($6) $$->children.push_back($6);
    }
  | WHILE LP expression RP statement {$$ = new Node("while", "", yylineno); $$->children.push_back($3); $$->children.push_back($5);}
  | PRINTLN LP expression RP SEMI { 
    $$=new Node("statement print", "", yylineno); 
    $$->children.push_back($3);
    }
  | identifier ASSIGNOP expression SEMI {
    $$ = new Node("assign statement", "", yylineno); 
    $$->children.push_back($1);
    $$->children.push_back($3);
    }
  | identifier LSB expression RSB ASSIGNOP expression SEMI {
    $$ = new Node("array assign", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    $$->children.push_back($6);
    }

expression: expression AND expression {$$ = new Node("And","", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
  | expression OR expression {$$ = new Node("Or","", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
  | expression LESS expression {$$ = new Node("Less","", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
  | expression GREATER expression {$$ = new Node("Greater","", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
  | expression EQUAL expression {$$ = new Node("Equal","", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
  | expression PLUSOP expression {$$ = new Node("Plus","", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
  | expression MINUSOP expression {$$ = new Node("Minus","", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
  | expression MULTOP expression {$$ = new Node("Mult","", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
  | expression LSB expression RSB {$$ = new Node("Array access", "", yylineno); $$->children.push_back($1); $$->children.push_back($3);}
  | expression DOT LENGTH {$$ = new Node(".length","", yylineno); $$->children.push_back($1);}
  | expression DOT identifier LP argsOpt RP {
    $$ = new Node("methodCall", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    if ($5) $$->children.push_back($5);
  }
  | INT {$$ = new Node("Int", $1, yylineno);}
  | TRUE {$$ = new Node("True", "", yylineno);}
  | FALSE {$$ = new Node("False", "", yylineno);}
  | identifier {$$ = $1;}
  | THIS {$$ = new Node("this","",yylineno);}
  | NEW TYPEINT LSB expression RSB {$$ = new Node("array create", "", yylineno); $$->children.push_back($4);}
  | NEW identifier LP RP {
    $$ = new Node("expression NewObject","",yylineno);
    $$->children.push_back($2);
  }
  | NOT expression {$$ = new Node("Not", "", yylineno); $$->children.push_back($2);}
  | LP expression RP {$$ = new Node("grouped expression", "", yylineno); $$->children.push_back($2);}

identifier: IDENTIFIER {$$ = new Node("identifier", $1, yylineno);};

// * rules (zero or more)

//(ClassDeclaration)*
classDeclarations: %empty {$$ = new Node("ClassDeclarations", "", yylineno);}
| classDeclarations classDeclaration {$$ = $1; $$->children.push_back($2);}

//(Statement)*
statements: %empty {$$ = new Node("statements", "", yylineno);}
| statements statement {$$ = $1; $$->children.push_back($2);}

//(VarDeclaration)*
varDeclarations: %empty {$$ = new Node("varDeclarations", "", yylineno);}
| varDeclarations varDeclaration {$$ = $1; $$->children.push_back($2);}

//(MethodDeclaration*)
methodDeclarations: %empty {$$ = new Node("methodDeclarations", "", yylineno);}
| methodDeclarations methodDeclaration {$$ = $1; $$->children.push_back($2);}

//("," Type Identifier)*
moreParams: %empty {$$ = new Node("moreParams", "", yylineno);}
| moreParams COMMA type identifier {$$=$1; $$->children.push_back($3); $$->children.push_back($4);}

// (VarDeclaration | Statement)
methodItem: varDeclaration {$$ = new Node("methodItem", "", yylineno); $$->children.push_back($1);}
| statement {$$ = new Node("methodItem", "", yylineno); $$->children.push_back($1);}

//(VarDeclaration | Statement )*
methodContent: %empty {$$ = new Node("methodContent", "", yylineno);}
| methodContent methodItem {$$ = $1; $$->children.push_back($2);}

//("," Expression )*
moreArgs: %empty {$$ = new Node("moreArgs", "", yylineno);}
| moreArgs COMMA expression {$$=$1; $$->children.push_back($3);}

// ? rules (zero or one)

//(Type Identifier("," Type Identifier )*)?
paramsOpt: %empty {$$ = nullptr;}
| type identifier moreParams {
  $$ = new Node("paramsOpt", "", yylineno);
  $$->children.push_back($1);
  $$->children.push_back($2);
  $$->children.push_back($3);
  }

//("else" Statement)?
elseOpt: %empty {$$ = nullptr;}
| ELSE statement {$$ = new Node("else statement", "", yylineno); $$->children.push_back($2);}

//( Expression( "," Expression )*)?
argsOpt: %empty {$$ = nullptr;}
| expression moreArgs {
  $$ = new Node("args opt", "", yylineno);
  $$->children.push_back($1);
  if ($2) $$->children.push_back($2);
};