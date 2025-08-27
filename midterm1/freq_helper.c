#include <assert.h>
#include <stdio.h>

//TODO
unsigned firstDigit(unsigned k)
{
	//fill in code below
    unsigned j = k;
    while (j >= 10) {
        j = j / 10;
    }
    return j;

}

//TODO
void FirstDigitCount(unsigned *a, unsigned n, unsigned freq[10])
{
    for (int j = 0; j < 10; j++) {
        freq[j] = 0;
    }
	//fill in your code below
    for (int i = 0; i < n; i++) {
        int digit = firstDigit(a[i]);
        // // printf("digit=%d\n", digit);
        freq[digit] = (int) freq[digit] + 1;
        // printf("%d ", a[i]);
        // printf("%d\n", digit);
    }

}