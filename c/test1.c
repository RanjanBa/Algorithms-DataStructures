#include <stdio.h>

int main()
{
    int i = 5;

    while (i++ <= 5)
    {
        i++;
        printf("%d\n", i);
    }

    i = 4;

    while (i-- > 4)
    {
        printf("%d\n", i);
    }

    while (i++ <= 5)
    {
        printf("%d\n", i);
    }

    return 0;
}