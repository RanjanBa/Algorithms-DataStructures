#include <iostream>

using namespace std;

class Person
{
private:
    int age;
    string name;
    int arr[];

public:
    Person(int age, string name, int arr[])
    {
        this->age = age;
        this->name = name;
        this->arr = arr;
    }

    Person operator+(Person &other)
    {
        Person new_person(*this);

        new_person.age += other.age;
        new_person.name += other.name;

        return new_person;
    }

    void print()
    {
        cout << name << " : " << age << endl;

        cout << "size : " << sizeof(arr) << endl;

        size_t n = sizeof(*arr) / sizeof(int);

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    ~Person()
    {
    }
};

int main()
{
    int arr1[2] = {10, 15};
    int arr2[3] = {20, 25, 30};
    Person p1(28, "Ranjan", arr1);
    Person p2(25, "Chanima", arr2);

    Person p3 = p1 + p2;

    p3.print();
    p1.print();
    p2.print();

    return 0;
}
