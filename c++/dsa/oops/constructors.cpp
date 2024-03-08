#include <iostream>
#include <string.h>

using namespace std;

class Test
{
private:
    char *name;
    int x, y, z;

public:
    Test() // default constructor
    {
    }

    Test(int x = 0) // default constructor
    {
    }

    Test(char &name, int x, int y, int z) // parameterized constructor
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->name = new char[strlen(&name)]; // deep copy
        strcpy(this->name, &name);
        this->name[0] = 'w';
        cout << "new : " << this->name << endl;
    }

    void print()
    {
        cout << this->name << ", x : " << x << ", y : " << y << ", z : " << z << endl;
    }

    ~Test() {}
};

class Person
{
private:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}
    Person(Person &p)
    {
    }
    ~Person()
    {
    }

    void show()
    {
        cout << name << " : " << age << endl;
    }
};

int main()
{
    // char name[] = "abcde";
    // cout << "Original : " << name << endl;
    // Test t1 = Test(*name, 10, 20, 30); // Test t(*name, 10, 20, 30);
    // cout << "After : " << name << endl;

    // t1.print();

    // Test t2 = Test(t1); // Test t2(t);
    // t2.print();

    // char n[] = "mnpq";
    // Test t3 = Test(*n, 5, 6, 7);
    // t2 = t3;

    // t2.print();

    Person *p1 = new Person("test", 10);

    p1->show();

    Person p2(*p1);
    p2.show();

    return 0;
}
