#include <iostream>

using namespace std;

void printArr(const int arr[], int const &size)
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

int count(int idx, int arr[], const int &size, const int &ele)
{
    if (idx >= size)
    {
        return 0;
    }

    int ans = 0;

    if (arr[idx] == ele)
    {
        ans++;
    }

    ans += count(idx + 1, arr, size, ele);

    return ans;
}

int main()
{
    int n = 10;
    int arr[n] = {1, 0, 2, 0, 3, 0, 0, 10, 0, 11};

    printArr(arr, n);

    cout << "Count : " << count(0, arr, n, 0) << endl;
}