#include "helpers.h"
#include "linked-list.h"
#include "queue.h"


void push(TQueue* q, TElement x) {
    if (q == NULL || q->L == NULL)
        return;
    add_last(q->L, newNode(x, NULL, NULL));
}

TElement pop(TQueue* q) {
    if (q == NULL || q->L == NULL || q->L->head == NULL) 
        return QUEUE_EMPTY;
    return remove_first(q->L);
}

TElement peek(TQueue* q) {
    if (q == NULL || q->L == NULL || q->L->head == NULL) 
        return QUEUE_EMPTY;
    return q->L->head->v;
}

int get_len(TQueue* q) {
    if (q == NULL || q->L == NULL)
        return QUEUE_EMPTY;
    return q->L->len;
}

int contains_q(TQueue* q, TElement x) {
    if (q == NULL || q->L == NULL) {
        return QUEUE_EMPTY;
    }
    return contains_LL(q->L, x);
}