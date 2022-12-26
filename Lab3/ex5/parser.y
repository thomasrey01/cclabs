%{
    #include <stdio.h>
    #include <stdlib.h>


    extern int yylex(void);
    extern int line;
    int yyerror(char *s);

    extern char *yytext;
%}

%define parse.trace

%token VAR SKIP PROGRAM REAL INTEGER RELOP BEG END IF ELSE THEN DIV MOD ID ARRAY 
%token FUNCTION WHILE DO OF NUM PROCEDURE SEMICOLON PERIOD LSPAREN RSPAREN LPAREN 
%token RPAREN COLON COMMA DOUBLEPERIOD COLEQUAL PLUS TIMES DIVIDE MINUS 

%left PLUS MINUS
%left DIV TIMES DIVIDE
%left MOD

%start ProgramStart

%%

ProgramStart    : PROGRAM ID SEMICOLON ProgramVars
                ;

ProgramVars     : VarDecl ProgramVars
                | ProgramFuncs
                ;

ProgramFuncs    : FuncProcDecl ProgramFuncs
                | CompoundStatement PERIOD
                ;

VarDecl         : VAR IdentifierList COLON TypeSpec SEMICOLON
                ;

IdentifierList  : ID
                | IdentifierList COMMA ID
                ;

TypeSpec        : BasicType
                | ARRAY LSPAREN NUM DOUBLEPERIOD NUM RSPAREN OF BasicType
                ;

BasicType       : INTEGER
                | REAL
                ;

FuncProcDecl    : FUNCTION ID Parameters COLON BasicType SEMICOLON FuncVars
                | PROCEDURE ID SEMICOLON FuncVars
                | PROCEDURE ID Parameters SEMICOLON FuncVars
                ;

FuncVars        : VarDecl FuncVars
                | CompoundStatement SEMICOLON
                ;

Parameters      : LPAREN ParametersList RPAREN
                ;

ParametersList  : VAR IdentifierList COLON TypeSpec
                | VAR IdentifierList COLON TypeSpec SEMICOLON ParametersList
                | IdentifierList COLON TypeSpec
                | IdentifierList COLON TypeSpec SEMICOLON ParametersList
                ;

CompoundStatement   : BEG END
                    | BEG StatementList END
                    ;

StatementList   : Statement
                | Statement SEMICOLON StatementList
                ;

Statement       : Lhs COLEQUAL ArithExpr
                | ProcedureCall
                | CompoundStatement
                | SKIP
                | IF Guard THEN Statement ELSE Statement
                | WHILE Guard DO Statement
                ;

Guard           : ArithExpr RELOP ArithExpr
                ;

Lhs             : ID
                | ID LSPAREN ArithExpr RSPAREN
                ;

ProcedureCall   : ID
                | ID LPAREN ArithExprList RPAREN
                ;

ArithExprList   : ArithExpr
                | ArithExpr COMMA ArithExprList
                ;

ArithExpr       : ID
                | ID LSPAREN ArithExpr RSPAREN
                | NUM
                | ID LPAREN ArithExprList RPAREN
                | ArithExpr PLUS ArithExpr
                | ArithExpr MINUS ArithExpr
                | ArithExpr TIMES ArithExpr
                | ArithExpr DIVIDE ArithExpr
                | ArithExpr DIV ArithExpr
                | ArithExpr MOD ArithExpr
                | MINUS ArithExpr
                | LPAREN ArithExpr RPAREN
                ;

%%

int yyerror(char *s) {
  /* printf("%c", *yytext); */
  printf("PARSE ERROR (%d)\n", line);
  exit(EXIT_SUCCESS);
}

int main() {
  /* yydebug=1; */
  yyparse();
  printf("ACCEPTED\n");
  return 0;
}

