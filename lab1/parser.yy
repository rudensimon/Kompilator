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
%token <std::string>  PLUSOP MINUSOP MULTOP DIVOP ASSIGNOP LESS GREATER NOT AND OR EQUAL LP RP LSB RSB RCB LCB SEMI DOT COMMA WHILE IF ELSE TRUE FALSE THIS NEW CLASS PUBLIC PRIVATE STATIC VOID TYPEINT BOOLEAN STRINGTYPE PRINTLN RETURN LENGTH INT IDENTIFIER MAIN
%token END 0 "end of file"

//definition of operator precedence. See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl
%left ASSIGNOP
%left OR
%left AND
%left EQUAL
%left LESS GREATER
%left PLUSOP MINUSOP
%left MULTOP DIVOP
%left NOT
%left LP RP
// definition of the production rules. All production rules are of type Node
%type <Node *> root goal mainClass classDeclaration varDeclaration methodBody varDeclarationList classDeclarationList methodParamList param type statement statementList expression expressionList identifier methodDeclaration methodDeclarationList

%%
root: goal;

goal: mainClass END {
  root = $$;
  $$ = $1;
  
}
|mainClass classDeclarationList END {
  $$ = $1;
  $$->children.push_back($2);
  root = $$;
}

mainClass: PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRINGTYPE LSB RSB identifier RP LCB statementList RCB RCB {
  $$ = new Node("Mainclass", $3->value, yylineno);
  $$->children.push_back($13);
  $$->children.push_back($16);
}

classDeclarationList: classDeclarationList classDeclaration {
  $$ = new Node("classes", "", yylineno);
  $$->children.push_back($2);
}
  | %empty     {
      $$ = new Node("classes", "", yylineno);
    }


classDeclaration: CLASS identifier LCB varDeclarationList methodDeclarationList RCB {
  $$ = new Node(" Class: ", $2->value , yylineno);
  if ($4) $$->children.push_back($4);
  if ($5) $$->children.push_back($5);
}



varDeclarationList: varDeclarationList varDeclaration {
  $$ = new Node("Test var dec", "", yylineno);
  }
  | %empty { 
  }

varDeclaration: type identifier SEMI {
  $$ = new Node("var declaration", "", yylineno);
  $$->children.push_back($1);
  $$->children.push_back($2);
  }

methodDeclaration: PUBLIC type identifier LP methodParamList RP LCB methodBody RETURN expression SEMI RCB
{
  $$ = new Node("method ", $3->value , yylineno);
  $$->children.push_back($2);
  if ($5) $$->children.push_back($5);
  $$->children.push_back($8);
  $$->children.push_back($10);
}

methodDeclarationList: %empty {$$ = new Node("method Declaration", "", yylineno);}
  | methodDeclarationList methodDeclaration {
  $$ = $1;
  $$->children.push_back($2);
  }


methodBody: %empty {$$ = new Node("method body","", yylineno);}
  | methodBody varDeclaration {
  $$ = $1;
  $$->children.push_back($2); 
  }
  | methodBody statement{
  $$ = $1;
  $$->children.push_back($2);
    
  }


  methodParamList: param {
    $$ = new Node("params", "", yylineno);
    $$->children.push_back($1);
    }
  | methodParamList COMMA param {
    $$ = $1;
    $$->children.push_back($3);
  }
  | %empty

param: type identifier {
  $$ = new Node("Param", "", yylineno);
  $$->children.push_back($1);
  $$->children.push_back($2);
}

type: TYPEINT LSB RSB {$$ = new Node("type", "array", yylineno);}
  | BOOLEAN { $$ = new Node("type", "boolean", yylineno);}
  | TYPEINT { $$ = new Node("type", "int", yylineno);}
  | identifier {$$ = new Node("type", $1->value , yylineno);}

statement: LCB RCB {$$ = new Node("empty", "", yylineno);}
  | LCB statementList RCB {$$=$2;}
  | IF LP expression RP statement {
    $$ = new Node("if statement", "", yylineno);
  }
  | IF LP expression RP statement ELSE statement {
    $$ = new Node("if/else statement", "", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($5);
    $$->children.push_back($7);
    }
  | WHILE LP expression RP statement {
    $$ = new Node("While loop", "", yylineno);
    $$->children.push_back($3);
    $$->children.push_back($5); 
  }
  | PRINTLN LP expression RP SEMI {
    $$ = new Node("print", "", yylineno);
    $$->children.push_back($3);
  } 
  | identifier ASSIGNOP expression SEMI {
    $$ = new Node("ASSIGN", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | identifier LSB expression RSB ASSIGNOP expression SEMI {
    $$ = new Node("array assign", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    $$->children.push_back($6);
  }

statementList: statement{
      $$ = new Node("statement","", yylineno);  
      $$->children.push_back($1);
    }
  | statementList statement{
      $$ = $1;
      $$->children.push_back($2);
    }


expression: expression AND expression {
    $$ = new Node("AND expression", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | expression OR expression {
    $$ = new Node("OR expression", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  
  | expression LESS expression {
    $$ = new Node("LESS expression", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | expression GREATER expression {
    $$ = new Node("GREATER expression", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | expression EQUAL expression {
    $$ = new Node("EQUAL expression", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | expression PLUSOP expression {
    $$ = new Node("PLUS expression", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    }
  | expression MINUSOP expression{
    $$ = new Node("MINUS expression", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | expression MULTOP expression {
    $$ = new Node("MUL expression", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | expression DIVOP expression {
    $$ = new Node("DIV expression", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | expression LSB expression RSB {
    $$ = new Node("index expression", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
  }
  | expression DOT LENGTH {
    $$ = new Node("length expression", "", yylineno);
    $$->children.push_back($1);
  }
  | expression DOT identifier LP expressionList RP {
    $$ = new Node("MethodInvocation", "", yylineno);
    $$->children.push_back($1);
    $$->children.push_back($3);
    $$->children.push_back($5);
    }
  | INT {$$ = new Node("Int", $1, yylineno);}
  | TRUE {$$ = new Node("True", "", yylineno);}
  | FALSE {$$ = new Node("False", "", yylineno);}
  | identifier {$$ = $1;}
  | THIS {$$ = new Node("this","", yylineno);}
  | NEW TYPEINT LSB expression RSB {
    $$ = new Node("new array expression", "", yylineno);
    $$->children.push_back($4);
  }
  | NEW identifier LP RP {
    $$ = new Node("ClassInstanceCreation", $2->value, yylineno);}
  | NOT expression {
    $$ = new Node("not expression", "", yylineno);
    $$->children.push_back($2);
  }
  | LP expression RP {
    $$ = $2;
    }


expressionList: expression {
    $$ = new Node("Expressions", "", yylineno);
    $$->children.push_back($1);
  }
  | expressionList COMMA expression {
    $$ = $1;
    $$->children.push_back($3);
  }
  | %empty {
    $$ = new Node("Expressions", "", yylineno);
  }
;

identifier: IDENTIFIER {$$ = new Node("identifier", $1, yylineno);};


