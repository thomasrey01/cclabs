%{
#include <stdio.h>
#include <stdlib.h>
#include "strtab.h"
#include "symbolTable.h"
#include "semanticsCheck.h"
#include "linkedList.h"
#include "stack.h"

  struct stack *s;
  int max(int val1, int val2);
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
       AND OR NOT DIV MOD SKIP

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
  struct node* iden;
}

%type <ival> ArithExpr
%type <ival> NumericValue
%type <ival> IDENTIFIER
%type <ival> BasicType
%type <ival> TypeSpec

%type <iden> VarDecl
%type <iden> IdentifierList
%type <iden> ArithExprList
%type <iden> ConstDecl
%type <iden> PossibleParameters 
%type <iden> Parameters 
%type <iden> ParameterList
%type <iden> ParamList
%% //Change these later

program            : PROGRAM IDENTIFIER ';'
                     ConstDecl { addConsts($4, 0); } //to implement
                     VarDecl { addVars($6, 0); } //to implement
	                 FuncProcDecl
	                 CompoundStatement
	                 '.'
                   ;

ConstDecl          : ConstDecl CONST IDENTIFIER RELOPEQ NumericValue ';' { 
                    $$ = createNewNode(yylval.ival);
                    $$->type = $5;
                    $$->next = $1;
}
	               | /* epsilon */ { $$ = NULL; }
                   ;

NumericValue       : INTNUMBER { $$ = 0; }
                   | REALNUMBER { $$ = 1; }
                   ;

VarDecl            : VarDecl VAR IdentifierList ':' TypeSpec ';' { 
                        addType($3, $5); 
                        appendToList($3, $1); // this function may not work? Fix later
                        $$ = $3;
                    }
	               | /* epsilon */ { $$ = NULL; }
                   ;

IdentifierList     : IDENTIFIER { $$ = createNewNode(yylval.ival); $$->next = NULL; }
                   | IdentifierList ',' IDENTIFIER { 
                        $$ = createNewNode(yylval.ival);
                        $$->next = $1;
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

SubProgDecl        : SubProgHeading VarDecl { addVars($2, 1); } CompoundStatement { purgeLocalTable(); }
                   ;

SubProgHeading     : FUNCTION IDENTIFIER { pushStack(yylval.ival, s); } Parameters ':' BasicType ';' { 
                   funcSave = popStack(s);
                   addFunction(funcSave, $4, 1);
                   addToLocal(funcSave, $6);
                   addVars($4, 1);
}
                   | PROCEDURE IDENTIFIER { pushStack(yylval.ival, s); } PossibleParameters ';' { 
                    funcSave = popStack(s);
                    addFunction(funcSave, $4, 2);
                    addVars($4, 1);
}
                   ;

PossibleParameters : Parameters {$$ = $1;}
                   | /* epsilon */ {$$ = NULL;}
                   ;

Parameters         : '(' ParameterList ')' {$$ = $2;}
                   ;

ParameterList      : ParamList { $$ = $1; }
                   | ParameterList ';' ParamList { appendToList($3, $1); $$ = $3; }
                   ;

ParamList          : VAR IdentifierList ':' TypeSpec { makeReference($2, 1); addType($2, $4); $$ = $2; } 
                   | IdentifierList ':' TypeSpec { makeReference($1, 0); addType($1, $3); $$ = $1; }
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
                   | SKIP
                   ;


Lhs                : IDENTIFIER { checkAssign(yylval.ival); }
                   | IDENTIFIER '[' ArithExpr ']' { checkAssign(yylval.ival); }
                   ;

ProcedureCall      : IDENTIFIER { checkProcedure(yylval.ival, NULL); }
                   | IDENTIFIER { pushStack(yylval.ival, s); } '(' ArithExprList ')' { checkProcedure(popStack(s), $4);}
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

ArithExprList      : ArithExpr { $$ = createNewNode(-1); $$->type = $1; $$->next = NULL;  } 
                   | ArithExprList ',' ArithExpr {
                    $$ = createNewNode(-1);
                    $$->type = $3;
                    $$->next = $1;
}
                   ;

ArithExpr          : IDENTIFIER { $$ = getType(yylval.ival); }
                   | IDENTIFIER { pushStack(yylval.ival, s); }'[' ArithExpr ']' {
                    $$ = getType(popStack(s));
        
}
                   | IDENTIFIER { pushStack(yylval.ival, s); } '(' ArithExprList ')' { 
                    funcSave = popStack(s);
                    $$ = getFuncType(funcSave);
                    checkFunction(funcSave, $4); 
                    
}
                   | INTNUMBER { $$ = 0; }
                   | REALNUMBER { $$ = 1; }
                   | ArithExpr '+' ArithExpr { $$ = max($1, $3); }
                   | ArithExpr '-' ArithExpr { $$ = max($1, $3); }
                   | ArithExpr '*' ArithExpr { $$ = max($1, $3); }
                   | ArithExpr '/' ArithExpr { $$ = 1; }
                   | ArithExpr DIV ArithExpr { $$ = 0, noReal($1, $3);}
                   | ArithExpr MOD ArithExpr { $$ = 0; noReal($1, $3);}
                   | '-' ArithExpr { $$ = $2; }
                   | '(' ArithExpr ')' { $$ = $2; }
                   ;

%%

int max(int val1, int val2)
{
    return (val1 > val2 ? val1 : val2);
}

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
  s = newStack();
  
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
