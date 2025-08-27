#include <stdio.h>
#include <stdlib.h>

float (*operation) (float, float) = NULL;

float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { 
    if (b == 0) {
        perror("Division by 0 error.\n");
        exit(1);
    }
    return a / b; 
}


int main() {
    float num1, num2;
    char choice;

    printf("Enter first number: ");
    scanf(" %f", &num1);
    printf("Enter operation: ");
    scanf(" %c", &choice);
    printf("Enter second number: \n");
    scanf(" %f", &num2);

    switch (choice) {
        case '+':
        operation = add;
        break;
        case '-':
        operation = subtract;
        break;
        case '*':
        operation = multiply;
        break;
        case '/':
        operation = divide;
        break;
        default:
        operation = NULL;
    }

    if (operation != NULL) {
        printf(" %.3f %c %.3f = %.3f\n", num1, choice, num2, operation(num1, num2));
    }


    return 0;
}