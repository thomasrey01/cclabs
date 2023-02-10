#include <stdio.h>
#include <stdlib.h>
#include "codegen.h"
#include "strtab.h"

extern char *stringTable;

int tabSize = 100;
int lblCnt = 0;
int varCnt = 0;
int *vartable;

void initTable()
{
    vartable = (int *)malloc(tabSize * sizeof(int));
}

void addToTable(int var, int type)
{
    if (var >= tabSize) {
        tabSize *= 2;
        vartable = (int *)realloc(vartable, tabSize * sizeof(int));
    }
    vartable[var] = type;
}

int createVar(int type)
{
    int label = varCnt;
    addToTable(label, type);
    varCnt++;
    if (type == 0) {
        printf("int _t%d", label);
    } else {
        printf("double _t%d", label);
    }
    return label;
}

void printWriteArguments(struct arithNode *args) 
{
    struct arithNode *l = args;
    while (l != NULL) {
        printf(",_t%d", l->idx); 
        l = l->next;
    }
}

void printFuncArguments(struct node *args)
{
    struct node *l = args;
    int len = getLength(l);
    if (len == 0) return;
    while (--len != 0) { // Doesn't deal with array parsing...
        printf("%s,", &stringTable[l->idx]);
        l = l->next;
    }
    printf("%s", &stringTable[l->idx]);
}

void printNode(struct arithNode *l, int isEnd)
{
    int type = vartable[l->idx]; 
    if (type == 0) {
            putchar('%');
            printf("d");
    } else if (type == 1) {
            putchar('%');
            printf("lf");
    }
    if (!isEnd) {
        printf(" ");
    }
}

void printStmt(struct arithNode *args)
{
    int len = getArithLength(args);
    if (len == 0) return;
    printf("printf(\"");
    struct arithNode *l = args;
    while (--len != 0) {
        printNode(l, 0);    
        l = l->next;
    }
    printNode(l, 1);
    printf("\"");
    printWriteArguments(args);
    printf(")\n");
}

void printReadArguments(struct node *args)
{
    struct node *l = args;
    while (l != NULL) {
        printf(",&%s", &stringTable[l->idx]);
        l = l->next;
    }
}

void readInput(struct node *args)
{
    struct node *l = args;
    struct symbol *sym;
    int len = getLength(args);
    if (len <= 0) {
        return;
    }
    printf("scanf(\"");
    while (--len > 0) {
        if (l->type == 0) {
            putchar('%');
            printf("d ");
        } else if (l->type == 1) {
            putchar('%');
            printf("f ");
        } else {
            printf("Wrong argument passed in readln()\n");
            exit(EXIT_SUCCESS);
        }
        l = l->next;
    }
    if (l != NULL) {
        putchar('%');
        if (l->type == 0) {
            printf("d\")");
        } else if (l->type == 1) {
            printf("f\")");
        }
    }
    printReadArguments(args);
    printf(")\n");
}

void includeHeaders()
{
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n");
    
}

void printMain()
{
    printf("int main()\n{\n");
}

void printVars(struct node *args, int isConst)
{
    struct node *l = args;
    while (l != NULL) {
        if (isConst) {
            printf("const ");
        }
        if (l->type == 0) {
            printf("int %s;\n", &stringTable[l->idx]);
        } else if (l->type == 1) {
            printf("double %s;\n", &stringTable[l->idx]);
        } 
        l = l->next;
    }
}

void printFunctionHeader(int idx, struct node *params, int type)
{
    switch (type) {
        case 2:
            printf("void ");
            break;
        case 0:
            printf("int ");
            break;
        case 1:
            printf("double ");
            break;
        default:
            break;
    }
    printf("%s", &stringTable[idx]);
    printf("(");
    printFuncArguments(params);
    printf(")\n");
}

int printNextLabel()
{
    printf("lbl%d : ;\n", ++lblCnt);
    return lblCnt;
}

void incrementLabel()
{
    lblCnt++;
}

void printWhileCondition(int label, int gvariable) 
{
    printf("if !(_t%d) goto lb%d\n", gvariable, label);
}

void printIfStmt(int gvariable, int label)
{
    printf("if(_t%d) goto lb%d else goto lb%d;\n", gvariable, label + 1, label + 2); 
}

int printBool(int val1, int val2, int op) // 0 lt, 1 leq, 2 eq, 3 neg, 4 geq, 5 gt
{
    createVar(0);
    printf("=_t%d", val1);
    switch (op) {
        case 0:
            printf("<");
            break;
        case 1:
            printf("<=");
            break;
        case 2:
            printf("==");
            break;
        case 3:
            printf("!=");
            break;
        case 4:
            printf(">=");
            break;
        case 5:
            printf(">");
            break;
        default:
            break;
    }
    printf(" _t%d;\n", val2);
    return varCnt;
}

int printGuard(int val1, int val2, int op) // 0 not, 1 or, 2 and
{
    if (val1 == -1) {
       printf("int _t%d = !_t%d;\n", ++varCnt, val2);
       return varCnt;
    }
    printf("_t%d = _t%d ", ++varCnt, val1);
    switch (op) {
        case 1:
            printf("||");
            break;
        case 2:
            printf("&&");
            break;
        default:
            break;
    }
    printf(" _t%d;\n", val2);
    return varCnt;
}

void printIdentifier(int idx)
{
    printf("%s", &stringTable[idx]);
}

int printIdenExpr(int idx)
{
    int type = 0; // To fix
    int res = createVar(type);
    printf("=%s;", &stringTable[idx]);
    return res;
}

void callFunc(int idx, struct arithNode *expr)
{
    struct arithNode *l;
    int len = getArithLength(expr);
    printf("%s(", &stringTable[idx]);
    if (len == 0) {
        printf(")");
        return;
    }
    while (--len) {
        printf("_t%d,", l->idx);
        l = l->next;
    }
    printf(");\n");
}

int makeArith(int var1, int var2, int op) // 0 +, 1 -, 2 *, 3 /, 4 DIV, 5 MOD, 6 neg
{
    int label;
    if (op == 3) {
        label = createVar(1);
        printf("=(double)_t%d/(double)_t%d;\n", var1, var2);
        return label;
    }
    if (op == 6) {
        label = createVar(vartable[var1]);
        printf("=-_t%d;\n", var1);
        return label;
    }
    if (vartable[var1] == 1 || vartable[var2] == 1) {
        label = createVar(1);
    } else {
        label = createVar(0);
    }
    printf("=_t%d", var1);
    switch (op) {
        case 0:
            putchar('+');
            break;
        case 1:
            putchar('-');
            break;
        case 2:
            putchar('*');
            break;
        case 3:
            break;
        case 4:
            putchar('/');
            break;
        case 5:
            putchar('%');
            break;
        default:
            break;
    }
    printf("_t%d;\n", var2);
    return label;
}
