%{
#include <stdio.h>
#include <stdlib.h>
#include "strtab.h"
#include "symbolTable.h"
#include "semanticsCheck.h"
#include "linkedList.h"

  int numArguments = 0;
  void yyerror(char *msg);    /* forward declaration */
  /* exported by the lexer (made with flex) */
  extern int yylex(void);
  extern char *yytext;
  extern void showErrorLine();
  extern void initLexer(FILE *f);
  extern void finalizeLexer();
  extern int readToken;
  struct symbol *sym = NULL;
  int funcSave;
  struct symbol *createNewSymbol(int idx);
  void assignType(int type, struct symbol *sym);
  void printList(struct symbol *symbol);
  int countList(struct symbol *sym);
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
  struct symbol *sym;
}

%type <ival> ArithExpr
%type <ival> IDENTIFIER
%type <ival> BasicType
%type <ival> TypeSpec
%type <sym> IdentifierList
%type <sym> ArithExprList

%type <sym> PossibleParameters 
%type <sym> Parameters 
%type <sym> ParameterList
%type <sym> ParamList
%%

program            : PROGRAM IDENTIFIER ';' { }
                     ConstDecl
                     VarDecl
	                 FuncProcDecl
	                 CompoundStatement
	                 '.'
                   ;

ConstDecl          : ConstDecl CONST IDENTIFIER RELOPEQ NumericValue ';' { addConst(yylval.ival, 1); }
	               | /* epsilon */
                   ;

NumericValue       : INTNUMBER  /* dont care about this bullshit for now */
                   | REALNUMBER
                   ;

VarDecl            : VarDecl VAR IdentifierList ':' TypeSpec ';' { 
                        assignType($5, $3); 
                        addFromList($3, 1); 
                        freeListRec($3);
                    }
	               | /* epsilon */
                   ;

IdentifierList     : IDENTIFIER { $$ = createNewSymbol(yylval.ival); }
                   | IdentifierList ',' IDENTIFIER { 
                        struct symbol *res = createNewSymbol(yylval.ival);
                        res->next = $1;
                        $$ = res;
                        }
                   ;

TypeSpec           : BasicType { $$ = $1; }
                   | ARRAY '[' INTNUMBER RANGE INTNUMBER ']' OF BasicType { $$ = $8; }
                   ;

BasicType          : INTEGER { $$ = 0; }
                   | REAL { $$ = 1; }
                   ;

FuncProcDecl       : FuncProcDecl SubProgDecl ';'
                   | /* epsilon */
                   ;

SubProgDecl        : SubProgHeading VarDecl CompoundStatement
                   ;

SubProgHeading     : FUNCTION IDENTIFIER { funcSave = yylval.ival; } Parameters ':' BasicType ';' { 
                   addFunction(funcSave, countList($4), 1);
                   addToLocal(funcSave, $6);
}
                   | PROCEDURE IDENTIFIER { funcSave = yylval.ival; } PossibleParameters ';' { 
                    addFunction(funcSave, countList($4), 2);
}
                   ;

PossibleParameters : Parameters {$$ = $1;}
                   | /* epsilon */ {$$ = NULL;}
                   ;

Parameters         : '(' ParameterList ')' {$$ = $2;}
                   ;

ParameterList      : ParamList { $$ = $1; }
                   | ParameterList ';' ParamList { $1->next = $3; }
                   ;

ParamList          : VAR IdentifierList ':' TypeSpec { addFromList($2, 1); } 
                   | IdentifierList ':' TypeSpec { checkSyms($1); }
                   ;                   

CompoundStatement  : BEGINTOK OptionalStatements ENDTOK { purgeLocalTable(); }
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

Lhs                : IDENTIFIER { checkAssign(yylval.ival); }
                   | IDENTIFIER '[' ArithExpr ']' { checkAssign(yylval.ival); }
                   ;

ProcedureCall      : IDENTIFIER
                   | IDENTIFIER '(' ArithExprList ')' {checkFunction(yylval.ival, countList($3));}
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

ArithExprList      : ArithExpr { $$ = createNewSymbol(0); }
                   | ArithExprList ',' ArithExpr { 
                    struct symbol *res = createNewSymbol(0);
                    res->next = $1;
                    $$ = res;
}
                   ;

ArithExpr          : IDENTIFIER
                   | IDENTIFIER '[' ArithExpr ']'
                   | IDENTIFIER '(' ArithExprList ')' { checkFunction(yylval.ival, countList($3)); }
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

int countList(struct symbol *sym)
{
    int cnt = 0;
    struct symbol *temp = sym;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
}

void printList(struct symbol *symbol)
{
    struct symbol *temp = symbol;
    while (temp != NULL) {
        printf("id: %d\n", temp->id);
        temp = temp->next;
    }
}

struct symbol *createNewSymbol(int idx)
{
    struct symbol *res;
    res = (struct symbol*)malloc(sizeof(struct symbol));
    res->id = idx;
    res->next = NULL;
    return res;
}

void assignType(int type, struct symbol *sym)
{
    struct symbol *temp = sym;
    while (temp != NULL) {
        temp->varType = type;
        temp = temp->next;
    }
}

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
