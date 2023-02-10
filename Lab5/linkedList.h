#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node;

struct arithNode;

struct node {
    int idx;
    int type; // 0 int var, 1 real var, 2 int num, 3 real num, 4 int func, 5 real func, 6 int array, 7 real array;
    int isRef;
    int ival;
    float rval;
    int startIndex;
    int endIndex;
    struct node *arguments;
    struct node* next;
};

struct arithNode {
    int idx;
    struct arithNode *next;
};

struct arithNode* createArithNode(int val);
struct node *createNewNode(int idx);
int getLength(struct node *args);
int getArithLength(struct arithNode *expr);
void freeList(struct node *l);
int isSameList(struct node *l1, struct node *l2);
void addType(struct node *l, int type);
void makeReference(struct node *l, int ref);
void appendToList(struct node *front, struct node *end);
void assignValue(struct node *var, struct node *value);

#endif
