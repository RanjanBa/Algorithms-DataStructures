#include <stdio.h>
#include <stdlib.h>

// #include "./sorting/bubble_sort.h"
// #include "./sorting/insertion_sort.h"
#include "./sorting/selection_sort.h"
// #include "./sorting/merge_sort.h"
// #include "./sorting/quick_sort.h"

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

int main()
{
    int n;
    // scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    int a[] = {64, 25, 12, 22, 11};

    n = sizeof(a) / sizeof(int);

    for (int i = 0; i < n; i++)
    {
        // scanf("%d", arr + i);
        arr[i] = a[i];
    }

    selectionSort(arr, n);
}