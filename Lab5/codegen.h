#ifndef CODEGEN_H
#define CODEGEN_H

#include "linkedList.h"
#include "symbolTable.h"
#include "semanticsCheck.h"

extern struct symbolTable *localvars;
extern struct symbolTable *globalvars;
extern struct symbolTable *functions;

void printTokens(struct node *args);
void printWriteArguments(struct node *args);
void printFuncArguments(struct node *args);
void printToken(struct node *l, int isEnd);
void printStmt(struct node *args);
void readInput(struct node *args);
void includeHeaders();
void printMain();
void printVars(struct node *args, int isConst);
void printFunctionHeader(int idx, struct node *params, int type);
int printNextLabel();
void incrementLabel();
void printWhileCondition(int label, int gvariable);
void printIfStmt(int gvariable, int label);
int printBool(int val1, int val2, int op);
int printGuard(int val1, int val2, int op);
void printIdentifier(int idx);
void callFunc(int idx, struct arithNode *expr);

#endif
