#include <iostream>

using namespace std;

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << a << endl;
    cout << &a[0] << endl;
    cout  << &a << endl;

    cout << endl;

    cout << a + 2 << endl;
    cout << &a[2] << endl;
    cout << &2[a] << endl;

    cout << *(a + 2) << endl;
    cout << 2[a] << endl;
    cout << a[2] << endl;


    return 0;
}