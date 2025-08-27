#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // stack is a fixed size, so if we want big arrays in it we should use malloc
    // heap is not a fixed size, we should allocate memory to it using malloc

    // However we should always use malloc since accessing stack memory is faster than the heap.

    // the value of a pointer is a byte address

    printf("%lld\n", sizeof(int));
    return 0;
}