#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
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

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int pivot = partition(arr, low, high);

    // printf("low : %d, high : %d\n", low, high);
    // for (int i = low; i < high; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    // printf("\n");

    quickSort(arr, low, pivot);
    quickSort(arr, pivot + 1, high);
}

int main()
{
    int n;
    // printf("Enter number of elements : ");
    // scanf("%d", &n);

    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    n = sizeof(arr) / sizeof(int);

    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }

    quickSort(arr, 0, n);

    // int p = partition(arr, 0, n);
    // printf("pivot : %d, element : %d\n", p, arr[p]);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}