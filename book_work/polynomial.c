#include <stdio.h>
#include <math.h>

void print_discriminant(double a, double b, double c, double d) {
    d = (b*b)-(4*a*c);
    if (d < 0) {
        d = sqrt(-d);
        printf("i*%lf\n", d);
    } else {
        d = sqrt(d);
        printf("%lf\n", d);
    }
}



int main(void) {
    double a, b, c, d;
    printf("Enter a: ");
	scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b); 
    printf("Enter c: ");
    scanf("%lf", &c); 
    print_discriminant(a,b,c,d);
    return 0;
}