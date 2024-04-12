#include <iostream>
#include <string>

using namespace std;

struct Node
{
    long long n1;
    int n;
    char x1;
};

int getValue()
{
    return 50;
}

void print()
{
    static int i = 100;
    // i = getValue();

    i++;
    cout << i << endl;
}

int main(int argc, char const *argv[])
{
    // cout << sizeof(char) << endl;
    // string str;
    // cout << "Enter the sentences with spaces : " << endl;

    // getline(cin, str);

    // cout << sizeof(struct Node) << endl;
    print();
    print();
    print();
    return 0;
}
