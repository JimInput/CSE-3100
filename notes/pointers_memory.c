// Notes 2/10/2025
#include <stdio.h>

int* AddThreeToArray(int* x) {
    // stack grows from top to bottom, heap grows bottom to top.
    // Code at bottom of heap
    // Globals and statics are stored in data segment (bottom of heap)
    // Locals are stored in stack frames.
    // Stack frame destroyed when function done.

    // not using static will cause this to be destroyed when the function is removed from the frame
    // segmentation fault (loose pointer)
    static int z[3];
    for(int i = 0; i < 3; ++i) {
        z[i] = x[i] + 3;
    }
    // return pointer to z
    return z;
}

void AddThreeToArray2(int* x, int* sol) {
    for (int i = 0; i < 3; ++i) {
        sol[i] = x[i] + 3;
    }
}

int main(void) {
    // declare variables
    int x = 10;
    int y = 5;

    // & - Reference: "get" the address of something.
    // * - Dereference: "use" the address

    // declare a pointer to some place in memory
    int* px;
    // get the address where x is stored
    px = &x;
    // at the address where x is stored, put 20 instead
    *px = 20;
    printf("The value of x %d\n", x);
    printf("The address of x is %d. The address of y is %d.\n", px, &y);

    printf("The difference of pointers &x and &y is: %d\n", px-&y);

    // to return arrays in C we instead return a pointer to the start of the array 
    // since a function in C can only return 1 variable.

    int m[3] = {1,2,3};
    int *z = AddThreeToArray(m);
    for (int i = 0; i < 3; ++i) {
        printf("z[%d]=%d\n", i, z[i]);
    }

    // better to do in-place to save storage space
    int solution[3];
    AddThreeToArray2(m, solution);
    for (int i = 0; i < 3; ++i) {
        printf("s[%d]=%d\n", i, solution[i]);
    }




}

// The reference to the address in computer memory is called a pointer.
// Memory is just an array of bytes.
// Every byte has an address in memory.
// *  An address is just an unsigned integer.


