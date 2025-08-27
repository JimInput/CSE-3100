#include <stdio.h>
#include <stdlib.h>

// return a random number in the range [0,1)
float uniform_random() {
    float num = rand() % 10000;
    num /= 10000;
    return num;
}

int count_n() {
    int count = 0;
    float sum = 0;
    while (sum <= 1) {
        sum += uniform_random();
        ++count;
    }

    return count;
}

int next_index(int a[], int k, int n) {
    int next = (k + a[k]) % n;
    a[k]--;
    return next;
}

int main(void) {
    srand(12345);
    for (int i = 0; i < 50; ++i) {
        printf("%d\n", count_n());
    }
    return 0;
}