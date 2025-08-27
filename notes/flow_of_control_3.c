#include <stdio.h>

int main()
{
    //some block of code
    // Purpose: To use local variables which cannot be accessed
    //          outside the block
    {
        int c;
        c = 5 * 3;
        printf("The value of c is %d\n", c);
    } //notice the code block end doesnt need a semicolon
    // printf("The value of c is %d\n", c); c is undefined here
    /*
        Blocks can be empty
        Blocks can be nested
        Useful for branching/loop statements
        Can define variables at the beginning of blocks
            Can mix declarations and code in c99
    */

    /* 
    Comparison Operators:
        ==, !=, >, <, >=, <=
    Logical Operators:
        &&, ||, !
    The result is either 0 or 1 (of int type)
        0 = false, 1 = true
    */

    int i, j, min;
    i = 3;
    j = 4;

    if (i < j) {
        min = i;
        printf("i is selected.\n");
    } else {
        min = j;
        printf("j is selected.\n");
    }

    int max = i > j ? i : j;
    printf("max=%d\n", max);

    int m = 0, sum = 0;
    while (m < 100) {
        sum += m;
        ++m;
    }

    printf("sum=%d\n", sum);

    int zum = 0;
    for(int q = 0; q < 100; ++q) {
        zum += q;
    }

    printf("zum=%d\n", zum);

    int bum;
    int b;
    // comma operator
    for (bum = 0, b = 0; b < 100; bum += b, ++b);
    printf("bum=%d\n", bum);


    int val = 2;

    switch (val) {
        case 1:
            printf("1\n");
            break;
        case 2:
        case 3:
        {
            int a = 4;
            printf("%d\n", a);
            break;
        }
        default:
            val += 1;
            break;
    }    

    printf("val=%d", val);


    return 0;
}