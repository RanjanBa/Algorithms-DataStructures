#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int high, int mid)
{
    int i = low, j = mid + 1;
    int cnt = high - low + 1;
    int *a = (int *)malloc(cnt * sizeof(int));
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            a[k++] = arr[i++];
        }
        else
        {
            a[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        a[k++] = arr[i++];
    }

    while (j <= high)
    {
        a[k++] = arr[j++];
    }

    for (int i = 0; i < cnt; i++)
    {
        arr[low + i] = a[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, high, mid);
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(int);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nMerge Sort : \n");

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}