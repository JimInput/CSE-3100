#include <stdio.h>

int main(void) {
    double x, total, average;
    int count;

    while (scanf("%lf", &x) == 1) { // pay attention to %lf
        total += x;
        ++count;
        average = total / count;

        printf("Total=%f Average=%f\n", total, average);
    }   

    return 0;
}

