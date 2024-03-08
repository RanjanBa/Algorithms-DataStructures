#include <iostream>

using namespace std;

class Student
{
private:
    int x;

public:
    Student()
    {
        x = 10;
    }
    ~Student()
    {
    }

    friend void print(Student &);
    friend void print(Student &, int);
};

void print(Student &st)
{
    cout << st.x << endl;
}

void print(Student &st, int x)
{
    cout << st.x << endl;
}

int main()
{
    Student st;

    print(st);

    print(st, 10);

    return 0;
}
