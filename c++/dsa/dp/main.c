#include <stdio.h>

int func(int x, int *py, int **ppz)
{
    int y, z;
    **ppz += 8;
    z = **ppz;
    *py += 7;
    y = *py;
    x += 6;

    return x + y + z;
}

int main()
{
    // int x = 0;
    // struct p p = {1, 2};
    // k k1 = p;
    // x = 2;
    // printf("%d", k1.x);

    int c = 9;
    int *b = &c;
    int **a = &b;

    printf("%d", func(c, b, a));

    // int a = 0;

    // if (a++ == 1)
    // {
    //     printf("%d", 1);
    // }
    // else if (++a == a++)
    // {
    //     printf("%d", --a);
    // }
    // else if (++a == 4)
    // {
    //     printf("%d", 3);
    // }
    // else
    // {
    //     printf("%d", 4);
    // }
    return 0;
}