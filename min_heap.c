#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

void heapifyUp(int *arr, int n, int child_index)
{
    while (child_index > 0)
    {
        int parent_index = (child_index - 1) / 2;

        if (arr[child_index] < arr[parent_index])
        {
            swap(&arr[child_index], &arr[parent_index]);
            child_index = parent_index;
        }
        else
        {
            break;
        }
    }
}

void heapifyDown(int *arr, int n, int parent_index)
{
    while (2 * parent_index + 1 < n)
    {
        int left_child = 2 * parent_index + 1;
        int right_child = 2 * parent_index + 2;

        int swap_index = -1;

        if (right_child < n)
        {
            if (arr[left_child] <= arr[right_child])
            {
                if (arr[parent_index] > arr[left_child])
                {
                    swap_index = left_child;
                }
            }
            else
            {
                if (arr[parent_index] > arr[right_child])
                {
                    swap_index = right_child;
                }
            }
        }
        else if (left_child < n)
        {
            if (arr[parent_index] > arr[left_child])
            {
                swap_index = left_child;
            }
        }

        if (swap_index != -1)
        {
            swap(&arr[parent_index], &arr[swap_index]);
            parent_index = swap_index;
        }
        else
        {
            break;
        }
    }
}

void insert(int *arr, int n, int value)
{
    int *new_arr = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        new_arr[i] = arr[i];
    }

    new_arr[n] = value;

    arr = new_arr;

    printf("New value : %d\n", arr[n]);

    heapifyUp(arr, n + 1, n);

    printf("Array after insertion : ");
    for (int i = 0; i < n + 1; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void delete ()
{
}

void buildHeap(int *arr, int n)
{
    // if n is size of the array, there should be n / 2 non-leaf.
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyDown(arr, n, i);
    }

    printf("MaxHeap : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{
    int n;
    // scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    int a[] = {2, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

    n = sizeof(a) / sizeof(int);

    for (int i = 0; i < n; i++)
    {
        // scanf("%d", arr + i);
        arr[i] = a[i];
    }

    buildHeap(arr, n);

    int val;
    printf("Enter value to insert into array : ");
    scanf("%d", &val);

    insert(arr, n, val);

    return 0;
}
