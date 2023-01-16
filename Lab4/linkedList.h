#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node;

struct node {
    int idx;
    int type;
    struct node* next;
};

struct node *createNewNode(int idx, int type);
void freeList(struct node *l);
int isSameList(struct node *l1, struct node *l2);

#endif
