#include <stdio.h>
#include <stdlib.h>
#include "codegen.h"
#include "semanticsCheck.h"
#include "strtab.h"
#include "symbolTable.h"

extern char *stringTable;

int lblCnt = 0;
int varCnt = 0;

struct symbol *getSymbol(int idx)
{
    struct symbol *sym = findInSymTable(idx, localvars);
    if (sym == NULL) {
        sym = findInSymTable(idx, globalvars);
        if (sym == NULL) raiseError("Unintialised value!");
    }
    return sym;
}

void printWriteArguments(struct node *args) 
{
    struct node *l = args;
    while (l != NULL) {
        if (l->type != 2 || l->type != 3) {
            printf(",%s", &stringTable[l->idx]);
        }
        if (l->type == 4 || l->type == 5) {
            putchar('(');
            printWriteArguments(l->arguments);
            putchar(')');
        }
        l = l->next;
    }
    printf("\n");
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

void printToken(struct node *l, int isEnd)
{
    if (l->type == 0 || l->type == 4) {
            putchar('%');
            printf("d");
    } else if (l->type == 1 || l->type == 5) {
            putchar('%');
            printf("f");
    } else if (l->type == 2) {
            printf("%d", l->ival); // a bit more complicated than anticipated...
    } else if (l->type == 3) {
            printf("%f", l->rval);
    }
    if (!isEnd) {
        printf(" ");
    }
}

void printStmt(struct node *args)
{
    int len = getLength(args);
    if (len == 0) return;
    printf("printf(\"");
    struct node *l = args;
    while (--len != 0) {
        printToken(l, 0);    
        l = l->next;
    }
    printToken(l, 1);
    printf("\")");
    printWriteArguments(args);
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
            printf("d\"");
        } else if (l->type == 1) {
            printf("f\"");
        }
    }
    printWriteArguments(args);
    printf(")\n");
}

void includeHeaders()
{
    printf("#include <stdio.h>\n");
    printf("#include <stdlib.h>\n");
    
}

void printMain()
{
    printf("int main()\n{");
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
    printf("int _t%d = _t%d ", ++varCnt, val1);
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
    struct symbol *sym = getSymbol(idx);
    int type = sym->varType;
    if (type == 0) {
        printf("int _t%d = %s", ++varCnt, &stringTable[idx]);
    } else if (type == 1) {
        printf("double _t%d = %s", ++varCnt, &stringTable[idx]);
    }
    return varCnt;
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
        printf("_t%d,", l->val);
        l = l->next;
    }
    printf(");\n");
}
