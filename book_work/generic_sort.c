#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*compare)(const void *, const void *);

void generic_sort(void *arr, size_t n, size_t size, compare cmp) {
    
}

int main() {
    int x = 1;
    int* ptr1 = &x;
    int** ptr2 = &ptr1;

    printf("%d", **ptr2);
    return 0;
}