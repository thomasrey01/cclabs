#ifndef SYMBOLTABLE_H

#define SYMBOLTABLE_H

enum type {
    INT,
    FLOAT
};

struct symbol;

struct symbol {
    int id;
    struct symbol *next;
    int varType;
    int isConst;
    int isFunc;
    int numArguments;
};

struct symbolTable {
    int size;
    struct symbol **symbols;
};

struct Stack {
    struct identifierProp **prop;
    int size;
    int top;
};

void initTables();

struct symbolTable *createSymbolTable(int size);

void insertInSymTable(int idx, struct symbolTable *table, struct symbol *symbol);

struct symbol *findInSymTable(int idx, struct symbolTable *table);

#endif
