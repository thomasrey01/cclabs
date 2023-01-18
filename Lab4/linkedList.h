#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node;

struct node {
    int idx;
    int type;
    int isRef;
    struct node* next;
};

struct node *createNewNode(int idx);
void freeList(struct node *l);
int isSameList(struct node *l1, struct node *l2);
void addType(struct node *l, int type);
void makeReference(struct node *l, int ref);
void appendToList(struct node *front, struct node *end);

#endif
