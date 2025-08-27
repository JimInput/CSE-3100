#include <stdio.h>
#include <stdlib.h>

void reverse(int a[], int n) {
    int i;
    for (i=0; i<n; ++i) {
        int temp;
        temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }
}

int main(void) {
    // double sum = 0;
    // for (int i = 1; i <= 1000000; ++i) 
    //     sum += 1/i/i;
    // printf("sum=%lf", sum);

    // int a = 1;
    // if (a = 2) {
    //     printf("a=%d", a);
    // }

    int a[] = {0,1,2,3,4};
    for (int i = 0; i < 5; ++i) {
        printf("%d ", a[i]);
    }

    printf("\n");
    for (int i=0; i<5; ++i) {
        int temp;
        temp = a[i];
        a[i] = a[5-1-i];
        a[5-1-i] = temp;
    }

    // for (int i = 0; i < 5; ++i) {
    //     printf("%d ", a[i]);
    // }

    // a[0] = 5;

    for (int i = 0; i < 5; ++i) {
        printf("%d ", a[i]);
    }

    // int *p = malloc(sizeof(int));
    // if (p == NULL) {
    //     perror("Meomory allocation error\n");
    //     return -1;
    // }

    // if ((unsigned long)&p > (unsigned long)p) {
    //     printf("Hello World!\n");
    // }

    // free(p);

    // int *p;

    // printf("%p\n", p);
    // printf("%d\n", *p);

    // int a[] = {1};

    // int *p = a;

    // int r = (unsigned long) p == (unsigned long) &p;

    // // *p++;
    // printf("%d\n", r);

    // int a[] = {1,2,3};
    // char *p = (char *) a;

    // printf("%d\n", p[0] + p[1] + p[2]);

    // int t[10];

    // char *p = (char *) t + 8;
    // char *q = (char *) (t+8);

    // printf("%ld\n", q-p);

    // int a[10], *p = a, i;

    // for (i=0; i<10; ++i) *++p = i;

    // for (i=0; i<10; i++)
    //     printf("%d ", a[i]);
    // printf("\n");
    
    return 0;
}