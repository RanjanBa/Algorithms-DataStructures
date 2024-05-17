#include <stdio.h>

int main()
{
    int a = 10;

    int *p = &a;

    int** p2 = &p;

    printf("%d %d %d", *p2, p, &a);

    return 0;
}