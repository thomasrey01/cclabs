#ifndef SEMANTICSCHECK_H

#define SEMANTICSCHECK_H

#include "symbolTable.h"

void checkType(char *s);

void checkAssign(int idx);

void addFunction(int idx);

void addConst(int idx, int isGlobal);

#endif
