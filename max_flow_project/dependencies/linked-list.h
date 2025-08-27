#ifndef __LL__H__
#define __LL__H__


typedef struct Node {
    TElement v;
    struct Node* next;
    struct Node* prev;
} TNode;

TNode* newNode(TElement v, TNode* next, TNode* prev);

void freeNode(TNode* n);

typedef struct LinkedList {
    TNode* head;
    TNode* tail;
    int len;
} TLinkedList;

void freeLL(TLinkedList* LL);

void add_last(TLinkedList* LL, TNode* n);

void add_first(TLinkedList* LL, TNode* n);

TElement remove_last(TLinkedList* LL);

TElement remove_first(TLinkedList* LL);

int contains_LL(TLinkedList* LL, TElement v);


#endif