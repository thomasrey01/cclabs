%{
#include <stdio.h>
#include <stdlib.h>
#include "codegen.h"
#include "strtab.h"
#include "linkedList.h"
#include "stack.h"

  struct stack *s;
  struct stack *labels;
  int max(int val1, int val2);
  void yyerror(char *msg);    /* forward declaration */
  /* exported by the lexer (made with flex) */
  extern int yylex(void);
  extern char *yytext;
  extern void showErrorLine();
  extern void initLexer(FILE *f);
  extern void finalizeLexer();
  extern int readToken;
  int funcSave;
  struct symbol *createNewSymbol(int idx);
  void assignType(int type, struct symbol *sym);
  void printList(struct symbol *symbol);
  int countList(struct symbol *sym);
%}

%token PROGRAM CONST IDENTIFIER VAR ARRAY RANGE INTNUMBER REALNUMBER OF 
       FUNCTION PROCEDURE BEGINTOK ENDTOK ASSIGN IF THEN ELSE WHILE DO
       RELOPLT RELOPLEQ RELOPEQ RELOPNEQ RELOPGEQ RELOPGT INTEGER REAL
       AND OR NOT DIV MOD SKIP READLN WRITELN

%left '+' '-'
%left '*' '/' DIV MOD
%left OR
%left AND
%left NOT

%union {
  int ival;     /* used for passing int values from lexer to parser */
  double rval;  /* used for passing double values from lexer to parser */
  double dval;
  /* add here anything you may need */
  /*....*/  
  struct node* iden;
  struct arithNode *list;
}

%type <ival> IDENTIFIER
%type <ival> BasicType
%type <ival> TypeSpec
%type <ival> Relop
%type <ival> ArithExpr
%type <ival> BoolAtom
%type <list> ArithExprList
%type <ival> Guard
%type <iden> NumericValue
%type <iden> SubProgHeading
%type <iden> VarDecl
%type <iden> IdentifierList
%type <iden> ConstDecl
%type <iden> PossibleParameters 
%type <iden> Parameters 
%type <iden> ParameterList
%type <iden> ParamList
%% //Change these later

program            : PROGRAM IDENTIFIER ';' { includeHeaders(); }
                     ConstDecl { printVars($5, 1); }
                     VarDecl { printVars($7, 0); }
	                 FuncProcDecl { printMain(); }
	                 CompoundStatement
	                 '.' { printf("}\n"); }
                   ;

ConstDecl          : ConstDecl CONST IDENTIFIER RELOPEQ NumericValue ';' { 
                    $$ = createNewNode(yylval.ival);
                    $$->next = $1;
                    assignValue($$, $5);
                    free($5);
}
	               | /* epsilon */ { $$ = NULL; }
                   ;

NumericValue       : INTNUMBER { $$ = createNewNode(-1);
                                $$->type = 0;
                                $$->ival = yylval.ival;
}
                   | REALNUMBER { $$ = createNewNode(-1);
                                $$->type = 1;
                                $$->rval = yylval.rval;
}
                   ;

VarDecl            : VarDecl VAR IdentifierList ':' TypeSpec ';' { 
                        addType($3, $5); 
                        appendToList($3, $1); 
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

SubProgDecl        : SubProgHeading VarDecl { printVars($2, 0); } CompoundStatement { }
                   ;

SubProgHeading     : FUNCTION IDENTIFIER { pushStack(yylval.ival, s); } Parameters ':' BasicType ';' { 
                   funcSave = popStack(s);
                   printFunctionHeader(funcSave, $4, $6);
}
                   | PROCEDURE IDENTIFIER { pushStack(yylval.ival, s); } PossibleParameters ';' { 
                    funcSave = popStack(s);
                    printFunctionHeader(funcSave, $4, 2);
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

Statement          : Lhs ASSIGN ArithExpr { printf("=_t%d;", $3); }
                   | ProcedureCall
                   | CompoundStatement
                   | IF Guard {
                    int label = printNextLabel();
                    printIfStmt($2, label);
                    pushStack(label, labels);
                    incrementLabel();
                    incrementLabel();
} 
                   THEN  Statement {
                    int label = peekStack(labels);
                    label += 2;
                    printf("goto lb%d;\n", label);
                   }  ELSE { printf("lb%d : ;", popStack(labels)); } Statement { 
}
                   | WHILE {  
                    pushStack(printNextLabel(), labels); 
                   } Guard DO Statement {
                    printWhileCondition(popStack(labels), $3);
}
                   | READLN Parameters { 
                    readInput($2); 
}
                   | WRITELN '(' ArithExprList ')' { 
                    printStmt($3); 
}
                   | SKIP
                   ;


Lhs                : IDENTIFIER { printIdentifier(yylval.ival); }
                   | IDENTIFIER { pushStack(yylval.ival, s); } '[' ArithExpr ']' {
                    int idx = popStack(s);
                    printIdentifier(idx);
                    printf("[_t%d]", $4);
}
                   ;

ProcedureCall      : IDENTIFIER { callFunc(yylval.ival, NULL); }
                   | IDENTIFIER { pushStack(yylval.ival, s); } '(' ArithExprList ')' { callFunc(popStack(s), $4); }
                   ;

Guard              : BoolAtom { $$ = $1; }
                   | NOT Guard { $$ = printGuard(-1, $2, 0); }
                   | Guard OR Guard { $$ = printGuard($1, $3, 1); }
                   | Guard AND Guard { $$ = printGuard($1, $3, 2); }
                   | '(' Guard ')' { $$ = $2; }
                   ;

BoolAtom           : ArithExpr Relop ArithExpr { $$ = printBool($1, $3, $2); } 
                   ;

Relop              : RELOPLT { $$ = 0; }
                   | RELOPLEQ { $$ = 1; }
                   | RELOPEQ { $$ = 2; }
                   | RELOPNEQ { $$ = 3; }
                   | RELOPGEQ { $$ = 4; }
                   | RELOPGT { $$ = 5; }
                   ;

ArithExprList      : ArithExpr { $$ = createArithNode($1); $$->next = NULL;  } 
                   | ArithExprList ',' ArithExpr {
                    $$ = createArithNode($3);
                    $$->next = $1;
}
                   ;

ArithExpr          : IDENTIFIER { // arithNodes for arithmetic expressions. 
                   $$ = printIdenExpr(yylval.ival);
}
                   | IDENTIFIER { pushStack(yylval.ival, s); }'[' ArithExpr ']' { // Identifiers need array type...
                    int idx = popStack(s);
                    printIdentifier(idx);
                    printf("[_t%d]", $4);
        
}
                   | IDENTIFIER { pushStack(yylval.ival, s); } '(' ArithExprList ')' { // Functions need types 
                    funcSave = popStack(s);
                    
} // This needs doing, add every function to a special tree
                   | INTNUMBER { printf("%d\n", yylval.ival); }
                   | REALNUMBER { printf("%lf\n", yylval.rval); }
                   | ArithExpr '+' ArithExpr { $$ = makeArith($1, $3, 0); } // These rules are wrong
                   | ArithExpr '-' ArithExpr { $$ = makeArith($1, $3, 1); }
                   | ArithExpr '*' ArithExpr { $$ = makeArith($1, $3, 2); }
                   | ArithExpr '/' ArithExpr { $$ = makeArith($1, $3, 3); }
                   | ArithExpr DIV ArithExpr { $$ = makeArith($1, $3, 4); }
                   | ArithExpr MOD ArithExpr { $$ = makeArith($1, $3, 5); }
                   | '-' ArithExpr { makeArith($2, 0, 6); }
                   | '(' ArithExpr ')' { }
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
  // initTables();
  initTable();
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
