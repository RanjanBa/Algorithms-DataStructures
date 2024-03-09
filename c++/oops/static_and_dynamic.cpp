#include <iostream>
using namespace std;

#include "Rectangle.cpp"
#include "student.cpp"


Rectangle t1;

void test1()
{
    cout << "TEST1 is called" << endl;
    // for (size_t i = 0; i < 1; i++)
    // {
    //     Rectangle r1;
    // }

    // {
    //     Rectangle r1;
    // }

    Rectangle r2;
    Rectangle r3(r2);
    Rectangle r4 = r2; // Rectangle r4(r2);

    cout << "TEST1 is ended" << endl;
}

void test2()
{
    cout << "TEST2 is called!" << endl;
}

void test3()
{
    char name[] = "abcd";
    Student st(name, 12, 1055); 

    st.show();
}

int main(int argc, char const *argv[])
{
    test1();

    test2();

    test3();

    return 0;
}
