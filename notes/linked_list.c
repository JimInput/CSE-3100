#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define N 20
#define R 100

typedef struct node_tag {
    int v;
    node* next;
} node;

node* new_node(int v) {
    node* p = malloc(sizeof(node));
    assert(p != NULL);

    p->v = v;
    p->next = NULL;
    return p;
}

node* prepend(node* head, node* new_node) {
    new_node->next = head;
    return new_node;
}

node* find_last(node* head) {
    if (head != NULL) {
        while (head->next != NULL) {
            head = head->next;
        }
    }
    return head;
}

node* append(node* head, node* new_node) {
    node* last = find_last(head);
    if (last == NULL) 
        return new_node;
    last->next = new_node;
    return head;
}

void printLinkedList(node* head) {
    if (head == NULL)
        printf("No elements in LL.\n");

    printf("%d ", head->v);

    while (head->next != NULL) {
        head = head->next;
        printf("%d ", head->v);
    }

    printf("\n");
}

int compareInt(const void* a, const void* b) {
    return (*(const int*) a) - (*(const int*) b); 
}

typedef enum {
    RED=4, ORANGE, YELLOW, BLUE, GREEN, PURPLE
} Color;

int my_max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    printf("LL Testing\n");

    node* head = new_node(5);

    // Same declaration
    // node head_node = {5, NULL};
    // node* head = &head_node;

    printf("%d\n", head->v);

    if (head->next == NULL) {
        printf("no child\n");
    }

    head = prepend(head, new_node(4));

    printf("%d\n", head->v);
    printf("%d\n", head->next->v);

    for (int i = 0; i < 10; i++) {
        head = append(head, new_node(i));
    }

    printf("%d\n", find_last(head)->v);

    printLinkedList(head);
    printf("Enum Testing\n");

    Color c1 = RED;
    Color c2 = ORANGE;
    printf("red=%d\n", c1);
    printf("orange=%d\n", c2);
    printf("c1+c2=%d\n",c1+c2);

    printf("Function Pointer Test\n");

    int a = 2;
    int b = 3;

    int (*pf)(int a, int b) = my_max;

    printf("the max of %d, and %d is %d\n", a, b, pf(a, b));

    int x[N];
    for (int i = 0; i < N; ++i) {
        x[i] = rand() % R;
        printf("%d ", x[i]);
    }
    printf("\n");

    int (*compare)(const void* a, const void* b) = compareInt;

    qsort(x, N, sizeof(int), compare);

    for (int i = 0; i < N; ++i) {
        printf("%d ", x[i]);
    }
    printf("\n");

    

    return 0;
}