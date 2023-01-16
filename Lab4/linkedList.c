#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

struct node* createNewNode(int idx, int type)
{
    struct node *l = (struct node*)malloc(sizeof(struct node));
    l->idx = idx;
    l->type = type;
    l->next = NULL;
    return l;
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
