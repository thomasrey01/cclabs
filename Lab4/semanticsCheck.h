#ifndef SEMANTICSCHECK_H

#define SEMANTICSCHECK_H

#include "symbolTable.h"

void checkSyms(struct symbol *sym);

void checkType(char *s);

void checkAssign(int idx);

void addFunction(int idx, int numArgs);

void addConst(int idx, int isGlobal);

void addToLocal(int idx, int type);

void checkFunction(int idx, int args);

void addFunction(int idx, int numArgs);

void purgeLocalTable();

void addGlobal(int idx, int type);

void checkTable(int idx);

void freeListRec(struct symbol *sym);

void addFromList(struct symbol *sym, int table);

#endif
