#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

struct node* createNewNode(int idx)
{
    struct node *l = (struct node*)malloc(sizeof(struct node));
    l->idx = idx;
    l->next = NULL;
    return l;
}

void addType(struct node *l, int type)
{
    if (l == NULL) return;
    l->type = type;
    addType(l->next, type);
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
    return ((l1->idx == l2->idx) && (l1->type == l2->type) && isSameList(l1->next, l2->next));
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
