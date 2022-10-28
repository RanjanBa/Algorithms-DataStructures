#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int partition(int* arr, int low, int high)
{
    int x = arr[low];

    int j = low;

    for (int i = low + 1; i < high; i++)
    {
        if (arr[i] < x)
        {
            j++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[j], &arr[low]);
    return j;
}

void quickSort(int *arr, int low, int high)
{
    if (low >= high)
        return;

    int pivot = partition(arr, low, high);

    quickSort(arr, low, pivot);
    quickSort(arr, pivot + 1, high);
}