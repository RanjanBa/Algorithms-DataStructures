#include <stdio.h>

void print1stChar(int n, char *arr[]) {
    while (n--)
    {
        printf("%c\n", *arr[0]);
        arr = arr + 1;
    }
}


int main()
{
    char *arr[4] = {"Ones", "Two", "Threse", "Foursssssss"};
    
    int size1 = (int) sizeof(arr);
    printf("Full size %d\n", size1);

    int size2 = (int) sizeof(arr[0]);

    // for(int i = 0; i < 4; i++) {
    //     int size2 = (int) sizeof(arr[i]);
    //     printf("%d\n", size2);
    // }


    print1stChar(size1 / size2, arr);

    return 0;
}