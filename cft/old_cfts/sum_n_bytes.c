//In this assignment, we write code to sum up the values of the first n bytes in a memory block
//that is allocated for n unsigned integers.
//The memory allocation occurs in the main function
//We need to implement the function sum_n_bytes
//This function returns the sum of the values of the first n bytes that is pointed by 
//the pointer p

 
#include <stdio.h>
#include <stdlib.h>

//Implement the following function
//The function sum_n_bytes returns the sum of the values of the first n bytes in the memory block
//pointed by the pointer p
unsigned sum_n_bytes(unsigned *p, int n)
{
    unsigned sum = 0; 
    unsigned char *byte_ptr = (unsigned char *)p;

    for (int i = 0; i < n; ++i) {
        // printf("%u\n", byte_ptr[i]);
        sum += byte_ptr[i]; 
    }

    return sum;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s n\n", argv[0]);
        exit(-1);
    }

    int n = atoi(argv[1]);
    // Allocate memory for n unsigned integers
    unsigned *p = calloc(n, sizeof(unsigned));
    
    if (!p) {
        printf("Memory allocation failed\n");
        return -1;
    }

    // Assign values to these unsigned integers in a certain pattern
    for(int i = 0; i < n; i++)
    {
        p[i] = 1 << (i % 32);
    }

    // Print out the sum of the first n bytes
    printf("%u\n", sum_n_bytes(p, n));

    // Do not forget to free p
    free(p);

    return 0;
}
