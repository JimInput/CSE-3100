#include <stdio.h>

int sumOddIntegers(int n) {
    if (n == 0) {
        return 0;
    }
    return (2 * n - 1) + sumOddIntegers(n - 1);
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Sum of first %d odd integers is: %d\n", n, sumOddIntegers(n));
    return 0;
}