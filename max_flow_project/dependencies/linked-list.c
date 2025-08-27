#include "helpers.h"
#include "linked-list.h"

TNode* newNode(TElement v, TNode* next, TNode* prev) {
    TNode* newN = (TNode*) malloc(sizeof(TNode));
    newN->v = v;
    newN->next = next;
    newN->prev = prev;

    return newN;
}

void freeNode(TNode* n) {
    if (n == NULL)
        return;
    free(n);
}

void freeLL(TLinkedList* LL) {
    if (LL == NULL || LL->head == NULL)
        return;

    TNode* curr = LL->head;
    while (curr->next != NULL) {
        TNode* next = curr->next;
        freeNode(curr);
        curr = curr->next;
    }

    LL->head = NULL;
    LL->tail = NULL;
    LL->len = 0;
}

void add_last(TLinkedList *LL, TNode *n) {
    n->next = NULL;
    if (LL->len == 0) {
        n->prev = NULL;
        LL->head = n;
        LL->tail = n;
    } else {
        LL->tail->next = n;
        n->prev = LL->tail;
    }
    LL->len++;

}

void add_first(TLinkedList *LL, TNode *n) {
    n->prev = NULL;
    if (LL->len == 0) {
        n->next = NULL;
        LL->head = n;
        LL->tail = n;
    } else {
        n->next = LL->head;
        LL->head->prev = n;
        LL->head = n;
    }
    LL->len++;
}

TElement remove_last(TLinkedList *LL) {
    if (LL->len == 0) { 
        return LL_EMPTY;
    } 

    TNode* old_tail = LL->tail;
    int v = LL->tail->v;

    if (LL->len == 1) {
        LL->head = NULL;
        LL->tail = NULL;
    } else {
        LL->tail = old_tail->prev;
        LL->tail->next = NULL;
        old_tail->prev = NULL;
    }

    LL->len--;
    freeNode(old_tail);
    return v;

}

TElement remove_first(TLinkedList *LL) {
    if (LL->len == 0) { 
        return LL_EMPTY;
    } 

    TNode* old_head = LL->head;
    int v = LL->head->v;

    if (LL->len == 1) {
        LL->head = NULL;
        LL->tail = NULL;
    } else {
        LL->head = old_head->next;
        LL->head->prev = NULL;
    }

    LL->len--;
    freeNode(old_head);
    return v;
}

int contains_LL(TLinkedList *LL, TElement v) {
    if (LL == NULL || LL->head == NULL)
        return LL_EMPTY;

    TNode* curr = LL->head;
    while (curr != NULL) {
        if (curr->v == v)
            return TRUE;
        curr = curr->next;
    }

    return FALSE;
}
