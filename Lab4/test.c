#include <stdio.h>
#include <stdlib.h>
#include "symbolTable.h"

int main()
{
    struct symbolTable *table = createSymbolTable(10);
    char s[] = "test1";
    struct symbol *sym = (struct symbol*)malloc(sizeof(struct symbol));
    sym->id = s;
    sym->next = NULL;
    sym->type = 1;
    sym->value1 = 100;
    struct symbol *sym2 = (struct symbol*)malloc(sizeof(struct symbol));
    sym2->id = "F";
    sym2->next = NULL;
    sym->type = 1;
    sym->value1 = 200;
    printf("inserting\n");
    insert(table, sym);
    insert(table, sym2);
    printf("inserted\n");
    printf("%d\n", find(s, table));
    printf("%d\n", find("G", table));
    printf("%d\n", find("F", table));
    free(sym);
    free(table);
}
