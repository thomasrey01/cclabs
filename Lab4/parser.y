%{
#include <stdio.h>
#include <stdlib.h>
#include "strtab.h"
#include "symbolTable.h"
#include "semanticsCheck.h"

  int numArguments = 0;
  void yyerror(char *msg);    /* forward declaration */
  /* exported by the lexer (made with flex) */
  extern int yylex(void);
  extern char *yytext;
  extern void showErrorLine();
  extern void initLexer(FILE *f);
  extern void finalizeLexer();
  extern struct symbolTable *symtab;
  extern int readToken;
%}

%token PROGRAM CONST IDENTIFIER VAR ARRAY RANGE INTNUMBER REALNUMBER OF 
       FUNCTION PROCEDURE BEGINTOK ENDTOK ASSIGN IF THEN ELSE WHILE DO
       RELOPLT RELOPLEQ RELOPEQ RELOPNEQ RELOPGEQ RELOPGT INTEGER REAL
       AND OR NOT DIV MOD

%left '+' '-'
%left '*' '/' DIV MOD
%left OR
%left AND
%left NOT

%union {
  int ival;     /* used for passing int values from lexer to parser */
  double dval;  /* used for passing double values from lexer to parser */
  /* add here anything you may need */
  /*....*/  
}

%type <ival> IDENTIFIER
%type <ival> BasicType

%%

program            : PROGRAM IDENTIFIER ';'
                     ConstDecl
                     VarDecl
	                 FuncProcDecl
	                 CompoundStatement
	                 '.'
                   ;

ConstDecl          : ConstDecl CONST IDENTIFIER RELOPEQ NumericValue ';' { addConst(readToken, 1); /* Problem in this function */ }
	               | /* epsilon */
                   ;

NumericValue       : INTNUMBER  /* dont care about this bullshit for now */
                   | REALNUMBER
                   ;

VarDecl            : VarDecl VAR IdentifierList ':' TypeSpec ';' {}
	               | /* epsilon */
                   ;

IdentifierList     : IDENTIFIER { /*checkTable(readToken);*/ }
                   | IdentifierList ',' IDENTIFIER { /*checkTable(readToken);*/ }
                   ;

TypeSpec           : BasicType
                   | ARRAY '[' INTNUMBER RANGE INTNUMBER ']' OF BasicType
                   ;

BasicType          : INTEGER { $$ = 0; }
                   | REAL { $$ = 1; }
                   ;

FuncProcDecl       : FuncProcDecl SubProgDecl ';'
                   | /* epsilon */
                   ;

SubProgDecl        : SubProgHeading VarDecl CompoundStatement
                   ;

SubProgHeading     : FUNCTION IDENTIFIER Parameters ':' BasicType ';'
                   | PROCEDURE IDENTIFIER PossibleParameters ';'
                   ;

PossibleParameters : Parameters
                   | /* epsilon */
                   ;

Parameters         : '(' ParameterList ')'
                   ;

ParameterList      : ParamList
                   | ParameterList ';' ParamList
                   ;

ParamList          : VAR IdentifierList ':' TypeSpec
                   | IdentifierList ':' TypeSpec
                   ;                   

CompoundStatement  : BEGINTOK OptionalStatements ENDTOK
                   ;

OptionalStatements : StatementList
                   | /* epsilon */
                   ;

StatementList      : Statement
                   | StatementList ';' Statement
                   ;

Statement          : Lhs ASSIGN ArithExpr
                   | ProcedureCall
                   | CompoundStatement
                   | IF Guard THEN Statement ELSE Statement
                   | WHILE Guard DO Statement
                   ;

Lhs                : IDENTIFIER { checkAssign(readToken); }
                   | IDENTIFIER '[' ArithExpr ']'
                   ;

ProcedureCall      : IDENTIFIER
                   | IDENTIFIER '(' ArithExprList ')'
                   ;

Guard              : BoolAtom
                   | NOT Guard
                   | Guard OR Guard
                   | Guard AND Guard
                   | '(' Guard ')'
                   ;

BoolAtom           : ArithExpr Relop ArithExpr
                   ;

Relop              : RELOPLT
                   | RELOPLEQ
                   | RELOPEQ
                   | RELOPNEQ
                   | RELOPGEQ
                   | RELOPGT
                   ;

ArithExprList      : ArithExpr { numArguments++; }
                   | ArithExprList ',' ArithExpr { numArguments++; }
                   ;

ArithExpr          : IDENTIFIER
                   | IDENTIFIER '[' ArithExpr ']'
                   | IDENTIFIER '(' ArithExprList ')' { checkFunction(readToken, numArguments); }
                   | INTNUMBER
                   | REALNUMBER
                   | ArithExpr '+' ArithExpr
                   | ArithExpr '-' ArithExpr
                   | ArithExpr '*' ArithExpr
                   | ArithExpr '/' ArithExpr
                   | ArithExpr DIV ArithExpr
                   | ArithExpr MOD ArithExpr
                   | '-' ArithExpr
                   | '(' ArithExpr ')'
                   ;

%%

void printToken(int token) {
  /* single character tokens */
  if (token < 256) {
    if (token < 33) {
      /* non-printable character */
      printf("chr(%d)", token);
    } else {
      printf("'%c'", token);
    }
    return;
  }
  /* standard tokens (>255) */
  switch (token) {
  case PROGRAM   : printf("PROGRAM");
    break;
  case CONST     : printf("CONST");
    break;
  case IDENTIFIER: printf("identifier<%s>", yytext);
    break;
  case VAR       : printf("VAR");
    break;
  case ARRAY     : printf("ARRAY");
    break;
  case RANGE     : printf("..");
    break;
  case INTNUMBER : printf("Integer<%d>", yylval.ival);
    break;
  case REALNUMBER: printf("Real<%lf>", yylval.dval);
    break;
  case OF        : printf("OF");
    break;
  case INTEGER   : printf("INTEGER");
    break;
  case REAL      : printf("REAL");
    break;
  case FUNCTION  : printf("FUNCTION");
    break;
  case PROCEDURE : printf("PROCEDURE");
    break;
  case BEGINTOK  : printf("BEGIN");
    break;
  case ENDTOK    : printf("END");
    break;
  case ASSIGN    : printf(":=");
    break;
  case IF        : printf("IF");
    break;
  case THEN      : printf("THEN");
    break;
  case ELSE      : printf("ELSE");
    break;
  case WHILE     : printf("WHILE");
    break;
  case DO        : printf("DO");
    break;
  }
}

void yyerror (char *msg) {
  showErrorLine();
  fprintf (stderr, "%s (detected at token=", msg);
  printToken(yychar);
  printf(").\n");
  exit(EXIT_SUCCESS);  /* EXIT_SUCCESS because we use Themis */
}

int main(int argc, char *argv[]) {
  if (argc > 2) {
    fprintf(stderr, "Usage: %s [pasfile]\n", argv[0]);
    return EXIT_FAILURE;
  }
  initTables();

  
  FILE *f = stdin;
  if (argc == 2) {
    f = fopen(argv[1], "r");
    if (f == NULL) {
      fprintf(stderr, "Error: failed to open file\n");
      exit(EXIT_FAILURE);
    }
  }

  initLexer(f);
  yyparse();
  finalizeLexer();

#if 0
  showStringTable();
#endif
  printf("ACCEPTED\n");
  return EXIT_SUCCESS;
}
