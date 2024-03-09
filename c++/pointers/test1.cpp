#include <iostream>

using namespace std;

int main()
{
    int i = 10;
    char ch = 'a';
    float f = 1;
    double d = 0;
    string str = "abcd";
    bool b = false;

    cout << "size of int : " << sizeof(i) << endl;
    cout << "size of char : " << sizeof(ch) << endl;
    cout << "size of float : " << sizeof(f) << endl;
    cout << "size of double : " << sizeof(d) << endl;
    cout << "size of str : " << sizeof(str) << endl;
    cout << "size of bool : " << sizeof(b) << endl;

    return 0;
}
//          Output:
// 
// size of int : 4
// size of char : 1
// size of float : 4
// size of double : 8
// size of str : 32
// size of bool : 1