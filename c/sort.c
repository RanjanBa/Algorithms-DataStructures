#include <stdio.h>
#include <stdlib.h>

// #include "./sorting/bubble_sort.c"
// #include "./sorting/insertion_sort.c"
// #include "./sorting/merge_sort.c"
// #include "./sorting/quick_sort.c"
// #include "./sorting/selection_sort.c"

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

    printf("Before sorting:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    // insertionSort(arr, n);
    // mergeSort(arr, 0, n - 1);
    quickSort(arr, 0, n - 1);

    printf("After sorting:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}