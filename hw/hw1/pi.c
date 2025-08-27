#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;

	printf("n = ");
	scanf("%d", &n);

	double pi = 0.;
	for (int i = 0; i <= n; ++i) {
        double temp_sum = 0;
        double t1, t2, t3, t4;
        t1 = 4. / (8.*i+1.);
        t2 = -2. / (8.*i+4.);
        t3 = -1. / (8.*i+5.);
        t4 = -1. / (8.*i+6.);
        temp_sum += (t1+t2+t3+t4);

        for (int j = 1; j <= i; ++j) {
            temp_sum /= 16.;
        }

        pi += temp_sum;
    }

	printf("PI = %.10f\n", pi);
	return 0;
}