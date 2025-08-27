#ifndef __QUEUE__H__
#define __QUEUE__H__

typedef struct Queue {
    TLinkedList* L;
} TQueue;

void push(TQueue* q, TElement x);

TElement pop(TQueue* q);

int get_len(TQueue* q);

#endif