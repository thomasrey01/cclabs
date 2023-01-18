#ifndef SEMANTICSCHECK_H

#define SEMANTICSCHECK_H

#include "linkedList.h"
#include "symbolTable.h"

void checkProcedure(int idx, struct node *args);

void noReal(int val1, int val2);

int getFuncType(int idx);

int getType(int idx);

void checkSyms(struct symbol *sym);

void checkType(char *s);

void checkAssign(int idx);

void addConsts(struct node *l, int tab);

void addVars(struct node *l, int tab);

void addToLocal(int idx, int type);

void checkFunction(int idx, struct node *args);

void addFunction(int idx, struct node *args, int funcType);

void purgeLocalTable();

void addGlobal(int idx, int type);

void checkTable(int idx);

#endif
