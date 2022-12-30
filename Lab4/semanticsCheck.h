#ifndef SEMANTICSCHECK_H

#define SEMANTICSCHECK_H

#include "symbolTable.h"

void checkType(char *s);

void checkAssign(int idx);

void addFunction(int idx, int numArgs);

void addConst(int idx, int isGlobal);

void checkFunction(int idx, int args);

void addFunction(int idx, int numArgs);

#endif
