#include <iostream>

using namespace std;

void printArr(const int arr[], const int &size)
{
    for (int i = 0; i < size; i++)
    {
        // cout << arr[i] << " ";
        // cout << i[arr] << " ";
        // cout << *(arr + i) << " ";
        cout << *(i + arr) << " ";
    }
    cout << endl;
}

int findIndex(int idx, int arr[], int size, int ele)
{
    if (idx >= size)
    {
        return -1;
    }

    if (arr[idx] == ele)
    {
        return idx;
    }

    return findIndex(idx + 1, arr, size, ele);
}

int main()
{
    int arr[10] = {5, 4, 6, 7, 9, 8, 10, 11, 3, 2};

    printArr(arr, 10);

    cout << "Index : " << findIndex(0, arr, 10, 7) << endl;

    return 0;
}