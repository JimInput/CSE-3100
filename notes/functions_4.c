#include <stdio.h>

int AddInt(int x, int y)
{
    int solution = x + y;
    return solution;
}
int main(void)
{
    printf("%d\n", AddInt(4, 5));
}