#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = -1;
        int minVal = arr[i];

        for (int j = i + 1; j < n; j++)
        {
            if (minVal > arr[j])
            {
                minIdx = j;
                minVal = arr[j];
            }
        }

        if (minIdx != -1)
        {
            swap(&arr[i], &arr[minIdx]);
        }

        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}