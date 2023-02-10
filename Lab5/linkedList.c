#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int getLength(struct node *args)
{
    struct node *l = args;
    int cnt = 0;
    while (l != NULL) {
        cnt++;
        l = l->next;
    }
    return cnt;
}

struct node* createNewNode(int idx)
{
    struct node *l = (struct node*)malloc(sizeof(struct node));
    l->idx = idx;
    l->isRef = 0;
    l->type = 0;
    l->next = NULL;
    return l;
}

void addType(struct node *l, int type)
{
    if (l == NULL) return;
    l->type = type;
    addType(l->next, type);
}

void makeReference(struct node *l, int ref)
{
    if (l == NULL) return;
    l->isRef = ref;
    makeReference(l->next, ref);
}

void freeList(struct node *l)
{
    if (l == NULL) return;
    freeList(l->next);
    free(l);
}

int isSameList(struct node *l1, struct node *l2)
{
    if (l1 == NULL && l2 == NULL) return 1;
    if (l1 == NULL) return 0;
    if (l2 == NULL) return 0;
    return ((l1->type <= l2->type) && isSameList(l1->next, l2->next));
}

void appendToList(struct node *front, struct node *end)
{
    struct node *ptr = front;
    if (ptr == NULL) {
        front = end;
        return;    
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = end;
}

void assignValue(struct node *var, struct node *value)
{
    var->type = value->type;
    if (value->type == 0) {
        var->ival = value->ival;
    } else if (value->type == 1) {
        var->rval = value->rval;
    }
}

struct arithNode *createArithNode(int val)
{
    struct arithNode *node = (struct arithNode*)malloc(sizeof(struct arithNode));
    node->idx = val;
    return node;
}

int getArithLength(struct arithNode *expr)
{
    int len = 0;
    struct arithNode *l;
    while (l != NULL) {
        len++;
        l = l->next;
    }
    return len;
}
