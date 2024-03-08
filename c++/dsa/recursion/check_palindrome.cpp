#include <iostream>

using namespace std;

bool check(int i, int j, char str[])
{
    if (i == j)
    {
        return true;
    }

    if (str[i] != str[j])
    {
        return false;
    }
    return check(i + 1, j - 1, str);
}

int main()
{
    char str[] = "abcbae";
    int n = sizeof(str) / sizeof(str[0]);
    cout << str << endl;
    cout << "Is Palindrome : " << check(0, n - 1, str) << endl;

    return 0;
}