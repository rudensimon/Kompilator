// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 14 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;

#line 54 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 127 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_classDeclarations: // classDeclarations
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_varDeclarations: // varDeclarations
      case symbol_kind::S_methodDeclarations: // methodDeclarations
      case symbol_kind::S_moreParams: // moreParams
      case symbol_kind::S_methodItem: // methodItem
      case symbol_kind::S_methodContent: // methodContent
      case symbol_kind::S_moreArgs: // moreArgs
      case symbol_kind::S_paramsOpt: // paramsOpt
      case symbol_kind::S_elseOpt: // elseOpt
      case symbol_kind::S_argsOpt: // argsOpt
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_ASSIGNOP: // ASSIGNOP
      case symbol_kind::S_LESS: // LESS
      case symbol_kind::S_GREATER: // GREATER
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LSB: // LSB
      case symbol_kind::S_RSB: // RSB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_SEMI: // SEMI
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_PRIVATE: // PRIVATE
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_TYPEINT: // TYPEINT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRINGTYPE: // STRINGTYPE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_MAIN: // MAIN
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_classDeclarations: // classDeclarations
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_varDeclarations: // varDeclarations
      case symbol_kind::S_methodDeclarations: // methodDeclarations
      case symbol_kind::S_moreParams: // moreParams
      case symbol_kind::S_methodItem: // methodItem
      case symbol_kind::S_methodContent: // methodContent
      case symbol_kind::S_moreArgs: // moreArgs
      case symbol_kind::S_paramsOpt: // paramsOpt
      case symbol_kind::S_elseOpt: // elseOpt
      case symbol_kind::S_argsOpt: // argsOpt
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_ASSIGNOP: // ASSIGNOP
      case symbol_kind::S_LESS: // LESS
      case symbol_kind::S_GREATER: // GREATER
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LSB: // LSB
      case symbol_kind::S_RSB: // RSB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_SEMI: // SEMI
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_PRIVATE: // PRIVATE
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_TYPEINT: // TYPEINT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRINGTYPE: // STRINGTYPE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_MAIN: // MAIN
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_classDeclarations: // classDeclarations
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_varDeclarations: // varDeclarations
      case symbol_kind::S_methodDeclarations: // methodDeclarations
      case symbol_kind::S_moreParams: // moreParams
      case symbol_kind::S_methodItem: // methodItem
      case symbol_kind::S_methodContent: // methodContent
      case symbol_kind::S_moreArgs: // moreArgs
      case symbol_kind::S_paramsOpt: // paramsOpt
      case symbol_kind::S_elseOpt: // elseOpt
      case symbol_kind::S_argsOpt: // argsOpt
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_ASSIGNOP: // ASSIGNOP
      case symbol_kind::S_LESS: // LESS
      case symbol_kind::S_GREATER: // GREATER
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LSB: // LSB
      case symbol_kind::S_RSB: // RSB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_SEMI: // SEMI
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_PRIVATE: // PRIVATE
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_TYPEINT: // TYPEINT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRINGTYPE: // STRINGTYPE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_MAIN: // MAIN
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_classDeclarations: // classDeclarations
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_varDeclarations: // varDeclarations
      case symbol_kind::S_methodDeclarations: // methodDeclarations
      case symbol_kind::S_moreParams: // moreParams
      case symbol_kind::S_methodItem: // methodItem
      case symbol_kind::S_methodContent: // methodContent
      case symbol_kind::S_moreArgs: // moreArgs
      case symbol_kind::S_paramsOpt: // paramsOpt
      case symbol_kind::S_elseOpt: // elseOpt
      case symbol_kind::S_argsOpt: // argsOpt
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_ASSIGNOP: // ASSIGNOP
      case symbol_kind::S_LESS: // LESS
      case symbol_kind::S_GREATER: // GREATER
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LSB: // LSB
      case symbol_kind::S_RSB: // RSB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_SEMI: // SEMI
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_PRIVATE: // PRIVATE
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_TYPEINT: // TYPEINT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRINGTYPE: // STRINGTYPE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_MAIN: // MAIN
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_classDeclarations: // classDeclarations
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_varDeclarations: // varDeclarations
      case symbol_kind::S_methodDeclarations: // methodDeclarations
      case symbol_kind::S_moreParams: // moreParams
      case symbol_kind::S_methodItem: // methodItem
      case symbol_kind::S_methodContent: // methodContent
      case symbol_kind::S_moreArgs: // moreArgs
      case symbol_kind::S_paramsOpt: // paramsOpt
      case symbol_kind::S_elseOpt: // elseOpt
      case symbol_kind::S_argsOpt: // argsOpt
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_ASSIGNOP: // ASSIGNOP
      case symbol_kind::S_LESS: // LESS
      case symbol_kind::S_GREATER: // GREATER
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LSB: // LSB
      case symbol_kind::S_RSB: // RSB
      case symbol_kind::S_RCB: // RCB
      case symbol_kind::S_LCB: // LCB
      case symbol_kind::S_SEMI: // SEMI
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_PRIVATE: // PRIVATE
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_TYPEINT: // TYPEINT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRINGTYPE: // STRINGTYPE
      case symbol_kind::S_PRINTLN: // PRINTLN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_MAIN: // MAIN
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: goal
#line 42 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 843 "parser.tab.cc"
    break;

  case 3: // goal: mainClass classDeclarations "end of file"
#line 45 "parser.yy"
                                      {
  yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  root = yylhs.value.as < Node * > ();
}
#line 854 "parser.tab.cc"
    break;

  case 4: // mainClass: PUBLIC CLASS identifier LCB PUBLIC STATIC VOID MAIN LP STRINGTYPE LSB RSB identifier RP LCB statement statements RCB RCB
#line 51 "parser.yy"
                                                                                                                                    {
  yylhs.value.as < Node * > () = new Node("mainClass","", yylineno);
  yylhs.value.as < Node * > ()->children.push_back(yystack_[16].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
}
#line 866 "parser.tab.cc"
    break;

  case 5: // classDeclaration: CLASS identifier LCB varDeclarations methodDeclarations RCB
#line 59 "parser.yy"
                                                                              {
  yylhs.value.as < Node * > () = new Node("class declaration", "", yylineno);
  yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
  if (yystack_[2].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  if (yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 877 "parser.tab.cc"
    break;

  case 6: // varDeclaration: type identifier SEMI
#line 66 "parser.yy"
                                     {
  yylhs.value.as < Node * > () = new Node("varDeclaration", "", yylineno);
  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
}
#line 887 "parser.tab.cc"
    break;

  case 7: // methodDeclaration: PUBLIC type identifier LP paramsOpt RP LCB methodContent RETURN expression SEMI RCB
#line 72 "parser.yy"
                                                                                                       {
  yylhs.value.as < Node * > () = new Node("methodDeclaration", "", yylineno);
  yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
  if (yystack_[7].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
}
#line 900 "parser.tab.cc"
    break;

  case 8: // type: TYPEINT LSB RSB
#line 81 "parser.yy"
                      {yylhs.value.as < Node * > ()=new Node("type Array","", yylineno);}
#line 906 "parser.tab.cc"
    break;

  case 9: // type: BOOLEAN
#line 82 "parser.yy"
            {yylhs.value.as < Node * > ()=new Node("type Boolean","", yylineno);}
#line 912 "parser.tab.cc"
    break;

  case 10: // type: TYPEINT
#line 83 "parser.yy"
            {yylhs.value.as < Node * > ()=new Node("type Int","", yylineno);}
#line 918 "parser.tab.cc"
    break;

  case 11: // type: identifier
#line 84 "parser.yy"
               {yylhs.value.as < Node * > ()=yystack_[0].value.as < Node * > ();}
#line 924 "parser.tab.cc"
    break;

  case 12: // statement: LCB statements RCB
#line 86 "parser.yy"
                              {yylhs.value.as < Node * > () = new Node("statement block", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 930 "parser.tab.cc"
    break;

  case 13: // statement: IF LP expression RP statement elseOpt
#line 87 "parser.yy"
                                          {
    yylhs.value.as < Node * > () = new Node("if statement","", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    if (yystack_[0].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 941 "parser.tab.cc"
    break;

  case 14: // statement: WHILE LP expression RP statement
#line 93 "parser.yy"
                                     {yylhs.value.as < Node * > () = new Node("while", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 947 "parser.tab.cc"
    break;

  case 15: // statement: PRINTLN LP expression RP SEMI
#line 94 "parser.yy"
                                  { 
    yylhs.value.as < Node * > ()=new Node("statement print", "", yylineno); 
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    }
#line 956 "parser.tab.cc"
    break;

  case 16: // statement: identifier ASSIGNOP expression SEMI
#line 98 "parser.yy"
                                        {
    yylhs.value.as < Node * > () = new Node("assign statement", "", yylineno); 
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    }
#line 966 "parser.tab.cc"
    break;

  case 17: // statement: identifier LSB expression RSB ASSIGNOP expression SEMI
#line 103 "parser.yy"
                                                           {
    yylhs.value.as < Node * > () = new Node("array assign", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    }
#line 977 "parser.tab.cc"
    break;

  case 18: // expression: expression AND expression
#line 110 "parser.yy"
                                      {yylhs.value.as < Node * > () = new Node("And","", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 983 "parser.tab.cc"
    break;

  case 19: // expression: expression OR expression
#line 111 "parser.yy"
                             {yylhs.value.as < Node * > () = new Node("Or","", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 989 "parser.tab.cc"
    break;

  case 20: // expression: expression LESS expression
#line 112 "parser.yy"
                               {yylhs.value.as < Node * > () = new Node("Less","", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 995 "parser.tab.cc"
    break;

  case 21: // expression: expression GREATER expression
#line 113 "parser.yy"
                                  {yylhs.value.as < Node * > () = new Node("Greater","", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1001 "parser.tab.cc"
    break;

  case 22: // expression: expression EQUAL expression
#line 114 "parser.yy"
                                {yylhs.value.as < Node * > () = new Node("Equal","", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1007 "parser.tab.cc"
    break;

  case 23: // expression: expression PLUSOP expression
#line 115 "parser.yy"
                                 {yylhs.value.as < Node * > () = new Node("Plus","", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1013 "parser.tab.cc"
    break;

  case 24: // expression: expression MINUSOP expression
#line 116 "parser.yy"
                                  {yylhs.value.as < Node * > () = new Node("Minus","", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1019 "parser.tab.cc"
    break;

  case 25: // expression: expression MULTOP expression
#line 117 "parser.yy"
                                 {yylhs.value.as < Node * > () = new Node("Mult","", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1025 "parser.tab.cc"
    break;

  case 26: // expression: expression LSB expression RSB
#line 118 "parser.yy"
                                  {yylhs.value.as < Node * > () = new Node("Array access", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 1031 "parser.tab.cc"
    break;

  case 27: // expression: expression DOT LENGTH
#line 119 "parser.yy"
                          {yylhs.value.as < Node * > () = new Node(".length","", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());}
#line 1037 "parser.tab.cc"
    break;

  case 28: // expression: expression DOT identifier LP argsOpt RP
#line 120 "parser.yy"
                                            {
    yylhs.value.as < Node * > () = new Node("methodCall", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
    yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
    if (yystack_[1].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 1048 "parser.tab.cc"
    break;

  case 29: // expression: INT
#line 126 "parser.yy"
        {yylhs.value.as < Node * > () = new Node("Int", yystack_[0].value.as < std::string > (), yylineno);}
#line 1054 "parser.tab.cc"
    break;

  case 30: // expression: TRUE
#line 127 "parser.yy"
         {yylhs.value.as < Node * > () = new Node("True", "", yylineno);}
#line 1060 "parser.tab.cc"
    break;

  case 31: // expression: FALSE
#line 128 "parser.yy"
          {yylhs.value.as < Node * > () = new Node("False", "", yylineno);}
#line 1066 "parser.tab.cc"
    break;

  case 32: // expression: identifier
#line 129 "parser.yy"
               {yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();}
#line 1072 "parser.tab.cc"
    break;

  case 33: // expression: THIS
#line 130 "parser.yy"
         {yylhs.value.as < Node * > () = new Node("this","",yylineno);}
#line 1078 "parser.tab.cc"
    break;

  case 34: // expression: NEW TYPEINT LSB expression RSB
#line 131 "parser.yy"
                                   {yylhs.value.as < Node * > () = new Node("array create", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 1084 "parser.tab.cc"
    break;

  case 35: // expression: NEW identifier LP RP
#line 132 "parser.yy"
                         {
    yylhs.value.as < Node * > () = new Node("expression NewObject","",yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  }
#line 1093 "parser.tab.cc"
    break;

  case 36: // expression: NOT expression
#line 136 "parser.yy"
                   {yylhs.value.as < Node * > () = new Node("Not", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1099 "parser.tab.cc"
    break;

  case 37: // expression: LP expression RP
#line 137 "parser.yy"
                     {yylhs.value.as < Node * > () = new Node("grouped expression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 1105 "parser.tab.cc"
    break;

  case 38: // identifier: IDENTIFIER
#line 139 "parser.yy"
                       {yylhs.value.as < Node * > () = new Node("identifier", yystack_[0].value.as < std::string > (), yylineno);}
#line 1111 "parser.tab.cc"
    break;

  case 39: // classDeclarations: %empty
#line 144 "parser.yy"
                          {yylhs.value.as < Node * > () = new Node("ClassDeclarations", "", yylineno);}
#line 1117 "parser.tab.cc"
    break;

  case 40: // classDeclarations: classDeclarations classDeclaration
#line 145 "parser.yy"
                                     {yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1123 "parser.tab.cc"
    break;

  case 41: // statements: %empty
#line 148 "parser.yy"
                   {yylhs.value.as < Node * > () = new Node("statements", "", yylineno);}
#line 1129 "parser.tab.cc"
    break;

  case 42: // statements: statements statement
#line 149 "parser.yy"
                       {yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1135 "parser.tab.cc"
    break;

  case 43: // varDeclarations: %empty
#line 152 "parser.yy"
                        {yylhs.value.as < Node * > () = new Node("varDeclarations", "", yylineno);}
#line 1141 "parser.tab.cc"
    break;

  case 44: // varDeclarations: varDeclarations varDeclaration
#line 153 "parser.yy"
                                 {yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1147 "parser.tab.cc"
    break;

  case 45: // methodDeclarations: %empty
#line 156 "parser.yy"
                           {yylhs.value.as < Node * > () = new Node("methodDeclarations", "", yylineno);}
#line 1153 "parser.tab.cc"
    break;

  case 46: // methodDeclarations: methodDeclarations methodDeclaration
#line 157 "parser.yy"
                                       {yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1159 "parser.tab.cc"
    break;

  case 47: // moreParams: %empty
#line 160 "parser.yy"
                   {yylhs.value.as < Node * > () = new Node("moreParams", "", yylineno);}
#line 1165 "parser.tab.cc"
    break;

  case 48: // moreParams: moreParams COMMA type identifier
#line 161 "parser.yy"
                                   {yylhs.value.as < Node * > ()=yystack_[3].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1171 "parser.tab.cc"
    break;

  case 49: // methodItem: varDeclaration
#line 164 "parser.yy"
                           {yylhs.value.as < Node * > () = new Node("methodItem", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1177 "parser.tab.cc"
    break;

  case 50: // methodItem: statement
#line 165 "parser.yy"
            {yylhs.value.as < Node * > () = new Node("methodItem", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1183 "parser.tab.cc"
    break;

  case 51: // methodContent: %empty
#line 168 "parser.yy"
                      {yylhs.value.as < Node * > () = new Node("methodContent", "", yylineno);}
#line 1189 "parser.tab.cc"
    break;

  case 52: // methodContent: methodContent methodItem
#line 169 "parser.yy"
                           {yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1195 "parser.tab.cc"
    break;

  case 53: // moreArgs: %empty
#line 172 "parser.yy"
                 {yylhs.value.as < Node * > () = new Node("moreArgs", "", yylineno);}
#line 1201 "parser.tab.cc"
    break;

  case 54: // moreArgs: moreArgs COMMA expression
#line 173 "parser.yy"
                            {yylhs.value.as < Node * > ()=yystack_[2].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1207 "parser.tab.cc"
    break;

  case 55: // paramsOpt: %empty
#line 178 "parser.yy"
                  {yylhs.value.as < Node * > () = nullptr;}
#line 1213 "parser.tab.cc"
    break;

  case 56: // paramsOpt: type identifier moreParams
#line 179 "parser.yy"
                             {
  yylhs.value.as < Node * > () = new Node("paramsOpt", "", yylineno);
  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  }
#line 1224 "parser.tab.cc"
    break;

  case 57: // elseOpt: %empty
#line 187 "parser.yy"
                {yylhs.value.as < Node * > () = nullptr;}
#line 1230 "parser.tab.cc"
    break;

  case 58: // elseOpt: ELSE statement
#line 188 "parser.yy"
                 {yylhs.value.as < Node * > () = new Node("else statement", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());}
#line 1236 "parser.tab.cc"
    break;

  case 59: // argsOpt: %empty
#line 191 "parser.yy"
                {yylhs.value.as < Node * > () = nullptr;}
#line 1242 "parser.tab.cc"
    break;

  case 60: // argsOpt: expression moreArgs
#line 192 "parser.yy"
                      {
  yylhs.value.as < Node * > () = new Node("args opt", "", yylineno);
  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  if (yystack_[0].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
}
#line 1252 "parser.tab.cc"
    break;


#line 1256 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -49;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      -9,     9,    22,   -49,   -49,    19,   -49,     2,   -49,    32,
     -49,    19,   -49,    43,    56,    54,   -49,    58,    27,    45,
      87,   -49,   -49,    19,   -49,   -13,    90,    88,    89,   -49,
      27,   -49,    71,   -49,   -49,    19,    97,   103,   106,    27,
      19,    19,   105,   109,   -49,   108,   114,   118,   -49,    74,
      27,    83,   -49,   122,   127,   129,   -49,    52,    19,     1,
     -49,   -49,    52,   -49,    47,     1,     1,     1,    72,     1,
       1,   -49,     1,     1,   -49,   -49,   -49,    -1,   -49,   126,
     -49,   -49,   -49,   144,   158,   172,   110,   186,   204,    51,
     218,   128,   131,     1,     1,     1,     1,     1,     1,     1,
       1,     1,   133,    -2,    74,    74,   134,   -49,   -49,   151,
     -49,     1,   146,     0,     0,    51,   312,   312,     4,   292,
     306,   232,   -49,   -49,   154,   -49,   147,   -49,     1,   246,
     -49,   -49,     1,    74,   -49,   260,   -49,   278,   160,   -49,
     -49,   164,   -49,     1,   278
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,    39,     0,     1,     0,    38,     0,
       3,     0,    40,     0,     0,     0,    43,     0,    45,     0,
      10,     9,    44,     0,    11,     0,     0,     0,     0,     5,
       0,    46,     0,     8,     6,     0,     0,     0,     0,    55,
       0,     0,     0,     0,    47,     0,     0,    56,    51,     0,
       0,     0,    41,     0,     0,     0,    41,     0,     0,     0,
      49,    50,    11,    52,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,    30,    31,    33,     0,    29,     0,
      32,    12,    42,     0,     0,     0,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,    16,     0,
      37,     0,     0,    23,    24,    25,    20,    21,    18,    19,
      22,     0,     7,    27,     0,    14,    57,    15,     0,     0,
      35,    26,    59,     0,    13,     0,    34,    53,     0,    58,
      17,    60,    28,     0,    54
  };

  const short
  parser::yypgoto_[] =
  {
     -49,   -49,   -49,   -49,   -49,   130,   -49,    -7,   -48,   -18,
      -5,   -49,   132,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,    12,    22,    31,    23,    82,    79,
      80,     7,    64,    18,    25,    47,    63,    51,   141,    42,
     134,   138
  };

  const unsigned char
  parser::yytable_[] =
  {
       9,    56,    10,    61,    29,    95,    14,    93,    94,    95,
      72,    96,    97,    24,    73,   101,   100,    30,    28,   101,
     103,     1,     6,    35,   103,    24,    74,    75,    76,    77,
      37,    11,    41,    91,    24,    43,    44,   123,     5,     8,
       8,    78,     8,    58,    57,    24,    62,    83,    84,    85,
      13,    87,    88,    71,    89,    90,   125,   126,    69,    57,
       8,    20,    21,    57,    81,    52,   101,    70,     8,    53,
      54,   103,    92,    15,    16,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    55,   139,    17,    26,     8,    86,
      52,    19,    52,   129,    53,    54,    53,    54,   124,    57,
      57,    52,    27,    32,    33,    53,    54,    36,    34,    55,
     135,    55,    38,     8,   137,     8,    39,    20,    21,    45,
      55,    59,    40,    46,     8,   144,    48,   107,    57,    93,
      94,    95,    49,    96,    97,    65,    98,    99,   100,    50,
      66,   101,    67,   111,   112,   102,   103,    93,    94,    95,
     122,    96,    97,   127,    98,    99,   100,   128,   104,   101,
     130,    93,    94,    95,   103,    96,    97,   132,    98,    99,
     100,   133,   105,   101,   142,    93,    94,    95,   103,    96,
      97,    60,    98,    99,   100,   143,   106,   101,    68,    93,
      94,    95,   103,    96,    97,     0,    98,    99,   100,     0,
       0,   101,     0,     0,     0,   108,   103,    93,    94,    95,
       0,    96,    97,     0,    98,    99,   100,     0,     0,   101,
     109,    93,    94,    95,   103,    96,    97,     0,    98,    99,
     100,     0,   110,   101,     0,    93,    94,    95,   103,    96,
      97,     0,    98,    99,   100,     0,     0,   101,   131,    93,
      94,    95,   103,    96,    97,     0,    98,    99,   100,     0,
       0,   101,   136,    93,    94,    95,   103,    96,    97,     0,
      98,    99,   100,     0,     0,   101,     0,     0,     0,   140,
     103,    93,    94,    95,     0,    96,    97,     0,    98,    99,
     100,     0,     0,   101,     0,    93,    94,    95,   103,    96,
      97,     0,    98,     0,   100,     0,     0,   101,     0,    93,
      94,    95,   103,    96,    97,    93,    94,    95,     0,     0,
       0,   101,     0,     0,     0,     0,   103,   101,     0,     0,
       0,     0,   103
  };

  const short
  parser::yycheck_[] =
  {
       5,    49,     0,    51,    17,     5,    11,     3,     4,     5,
       9,     7,     8,    18,    13,    15,    12,    30,    23,    15,
      20,    30,     0,    30,    20,    30,    25,    26,    27,    28,
      35,    29,    39,    34,    39,    40,    41,    39,    29,    41,
      41,    40,    41,    50,    49,    50,    51,    65,    66,    67,
      18,    69,    70,    58,    72,    73,   104,   105,     6,    64,
      41,    34,    35,    68,    17,    18,    15,    15,    41,    22,
      23,    20,    77,    30,    18,    93,    94,    95,    96,    97,
      98,    99,   100,   101,    37,   133,    32,    42,    41,    17,
      18,    33,    18,   111,    22,    23,    22,    23,   103,   104,
     105,    18,    15,    13,    16,    22,    23,    36,    19,    37,
     128,    37,    15,    41,   132,    41,    13,    34,    35,    14,
      37,    38,    16,    14,    41,   143,    18,    17,   133,     3,
       4,     5,    18,     7,     8,    13,    10,    11,    12,    21,
      13,    15,    13,    15,    13,    19,    20,     3,     4,     5,
      17,     7,     8,    19,    10,    11,    12,     6,    14,    15,
      14,     3,     4,     5,    20,     7,     8,    13,    10,    11,
      12,    24,    14,    15,    14,     3,     4,     5,    20,     7,
       8,    51,    10,    11,    12,    21,    14,    15,    56,     3,
       4,     5,    20,     7,     8,    -1,    10,    11,    12,    -1,
      -1,    15,    -1,    -1,    -1,    19,    20,     3,     4,     5,
      -1,     7,     8,    -1,    10,    11,    12,    -1,    -1,    15,
      16,     3,     4,     5,    20,     7,     8,    -1,    10,    11,
      12,    -1,    14,    15,    -1,     3,     4,     5,    20,     7,
       8,    -1,    10,    11,    12,    -1,    -1,    15,    16,     3,
       4,     5,    20,     7,     8,    -1,    10,    11,    12,    -1,
      -1,    15,    16,     3,     4,     5,    20,     7,     8,    -1,
      10,    11,    12,    -1,    -1,    15,    -1,    -1,    -1,    19,
      20,     3,     4,     5,    -1,     7,     8,    -1,    10,    11,
      12,    -1,    -1,    15,    -1,     3,     4,     5,    20,     7,
       8,    -1,    10,    -1,    12,    -1,    -1,    15,    -1,     3,
       4,     5,    20,     7,     8,     3,     4,     5,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20,    15,    -1,    -1,
      -1,    -1,    20
  };

  const signed char
  parser::yystos_[] =
  {
       0,    30,    44,    45,    46,    29,     0,    54,    41,    53,
       0,    29,    47,    18,    53,    30,    18,    32,    56,    33,
      34,    35,    48,    50,    53,    57,    42,    15,    53,    17,
      30,    49,    13,    16,    19,    50,    36,    53,    15,    13,
      16,    50,    62,    53,    53,    14,    14,    58,    18,    18,
      21,    60,    18,    22,    23,    37,    51,    53,    50,    38,
      48,    51,    53,    59,    55,    13,    13,    13,    55,     6,
      15,    53,     9,    13,    25,    26,    27,    28,    40,    52,
      53,    17,    51,    52,    52,    52,    17,    52,    52,    52,
      52,    34,    53,     3,     4,     5,     7,     8,    10,    11,
      12,    15,    19,    20,    14,    14,    14,    17,    19,    16,
      14,    15,    13,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    17,    39,    53,    51,    51,    19,     6,    52,
      14,    16,    13,    24,    63,    52,    16,    52,    64,    51,
      19,    61,    14,    21,    52
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    43,    44,    45,    46,    47,    48,    49,    50,    50,
      50,    50,    51,    51,    51,    51,    51,    51,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    63,    64,
      64
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,    19,     6,     3,    12,     3,     1,
       1,     1,     3,     6,     5,     5,     4,     7,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     6,     1,
       1,     1,     1,     1,     5,     4,     2,     3,     1,     0,
       2,     0,     2,     0,     2,     0,     2,     0,     4,     1,
       1,     0,     2,     0,     3,     0,     3,     0,     2,     0,
       2
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PLUSOP", "MINUSOP",
  "MULTOP", "ASSIGNOP", "LESS", "GREATER", "NOT", "AND", "OR", "EQUAL",
  "LP", "RP", "LSB", "RSB", "RCB", "LCB", "SEMI", "DOT", "COMMA", "WHILE",
  "IF", "ELSE", "TRUE", "FALSE", "THIS", "NEW", "CLASS", "PUBLIC",
  "PRIVATE", "STATIC", "VOID", "TYPEINT", "BOOLEAN", "STRINGTYPE",
  "PRINTLN", "RETURN", "LENGTH", "INT", "IDENTIFIER", "MAIN", "$accept",
  "root", "goal", "mainClass", "classDeclaration", "varDeclaration",
  "methodDeclaration", "type", "statement", "expression", "identifier",
  "classDeclarations", "statements", "varDeclarations",
  "methodDeclarations", "moreParams", "methodItem", "methodContent",
  "moreArgs", "paramsOpt", "elseOpt", "argsOpt", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    42,    42,    45,    51,    59,    66,    72,    81,    82,
      83,    84,    86,    87,    93,    94,    98,   103,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   126,
     127,   128,   129,   130,   131,   132,   136,   137,   139,   144,
     145,   148,   149,   152,   153,   156,   157,   160,   161,   164,
     165,   168,   169,   172,   173,   178,   179,   187,   188,   191,
     192
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1850 "parser.tab.cc"

