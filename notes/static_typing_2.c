#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int x = 5;
    char s[] = "hello";
    bool d = false;
}

/*
    Languages like C are statically typed
    Statically typed programming languages do type checking at compile-time.
    Languages like Python are dynamically typed.
    Dynamically types programming languages do type checking at run time.
*/

int main(void)
{
    int x[] = {1,2,3};
    // double index = 1.1;
    int index = 1;
    printf("%d\n", x[index]);
}

/*
    Since C does error checking at compile-time, this code will always give an 
    error and wont waste time like if in python.

    Are there any disadvantages to having a statically typed language?
    Efficiency gets slowed down.
*/

/*
    All C expressions have a type.
        Constants have a type
        Variables have a type
        Function return values have a type
        Every sub-expression of a larger expression has a type.
    Adding a semicolon to an expression makes a statement.

    int
        An integer
    char
        A single byte that can store a character in ASCII
        An 8-bit integer
    float
        Floating point numbers
    Quick refresher: What is a bit and what is a byte?
        A bit is a 1 or 0.
        A byte is 8 bits.
*/
// char: 'a', 'b', '\n'
// integer: 200, -34, 0x7fffFFF, 07112
// floating point numbers: 3.1415, -0.34, 1.3E20

/*
    All variables must be declared and initialized before use
    Variable declarations specify the type and name
        Compiler allocates memory based on type.
        Valid names consist of letters (case sensitive), digits, and _, but cannot start with digits.
        Multiple variables of the same type can be declared together
        Variables can be initialized when declared or using separate assignments.
*/

int main(void)
{
    char c;
    int i, j, k = 1;
    float f;
}

/*
    Operators:
        +, -, *, /, %
        &, |, ~, ^, <<, >>
        &&, ||, !

    Pre/post increment/decrement:
        i++, ++i, j--, --j
        c = i++;
        c = ++i
*/

int main(void)
{
    int i = 4;
    int c = i++;
    // c=4 i=5

    int j = 4;
    int d = ++j;
    // j=5, d=5
}

/*
    Integer Data Types:
        char
        unsigned char
        short int
        unsigned short
        int
        long int
        long long int


        8 bit signed (char): -128, 127
        8 bit unsigned(char): 0, 255
        16 bit signed (short): -32768, 32767
        16 bit unsigned (short): 0, 65535
        32 bit signed (int): -2^31, 2^31-1
        32 bit unsigned (int): 0, 2^32 -1
        64 bit signed (long): -2^63, 2^63-1
        64 bit unsigned (long)L 0, 2^64-1
        64 bit unsigned (long long):

*/

int main(void)
{
    sizeof(int); // returns 4 because ints are 32/8=4 bytes.
}