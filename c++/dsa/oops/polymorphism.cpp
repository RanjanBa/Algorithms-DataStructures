#include <iostream>

using namespace std;

class Parent
{
private:
    // const int x; // how to initialize constant value
public:
    int value;
    Parent() // : x(0)
    {
        cout << "Parent's default constructor is called\n";
    }

    ~Parent()
    {
        cout << "Parent's destructor is called\n";
    }

    void print()
    {
        cout << "Parent's print is called\n";
    }

    void show()
    {
        cout << "Parent's show function is called\n";
    }

    virtual void virtualFunction()
    {
        cout << "Parent's virtual function is called\n";
    }
};

class Child : public Parent
{
private:
public:
    int value;
    Child()
    {
        cout << "Child's default constructor is called\n";
    }
    Child(int x)
    {
        cout << "Child's parameterized constructor is called\n";
    }

    ~Child()
    {
        cout << "Child's destructor is called\n";
    }

    void print()
    {
        cout << "Child's print is called\n";
    }

    void show()
    {
        cout << "Child's show function is called\n";
    }

    virtual void virtualFunction()
    {
        cout << "child's virtual function is called\n";
    }
};

class GrandChild : public Child
{
private:
    /* data */
public:
    GrandChild()
    {
        cout << "Grandchild's default constructor is called\n";
    }

    GrandChild(int x, int y, int z)
    {
        cout << "Grandchild's paremeterized constructor is called\n";
    }

    void print()
    {
        cout << "Grandchild's print is called\n";
    }

    virtual void virtualFunction()
    {
        cout << "Grandchild's virtual function is called\n";
    }

    ~GrandChild()
    {
        cout << "Grandchild's destructor is called\n";
    }
};

int main()
{
    // {
    //     {
    //         Parent pa;
    //         Child ch1;
    //         Child ch(0);
    //         GrandChild gc(0, 0, 0);
    //     }

    //     Parent *ch = new Child();
    //     delete (ch);
    // }
    // {
    //     Parent *gc = new GrandChild();
    //     gc->print(); // parent's print function is called

    //     Child *ch = new GrandChild();
    //     ch->print(); // child's print function is called

    //     {
    //         GrandChild *ch = new GrandChild();
    //         ch->print(); // grandchild's print function is called
    //         delete ch;
    //     }

    //     delete gc;
    //     delete (ch);
    // }

    // {
    //     GrandChild gc;
    //     gc.show(); // child's show function is called
    // }
    {
        Parent *p;
        GrandChild ch;
        p = &ch;

        p->show();
        p->print();
        p->virtualFunction();
    }
    return 0;
}