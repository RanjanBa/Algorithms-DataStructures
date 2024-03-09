class Rectangle
{
private:
    int width;
    int height;
public:
    Rectangle();            // Default constructor
    Rectangle(int, int);    // Parameterized constructor
    Rectangle(Rectangle &); // Copy constructor
    ~Rectangle();
    void print();
};

Rectangle::Rectangle()
{
    cout << "Constructor1 is called!" << endl;
}

Rectangle::Rectangle(Rectangle &rec)
{
    cout << "Copy constructor is called!" << endl;
}

Rectangle::Rectangle(int width, int h)
{
    this->width = width;
    height = h;
}

Rectangle::~Rectangle()
{
    cout << "Destructor is called!" << endl;
}

void Rectangle::print()
{
    cout << "Width : " << width << ", Height : " << height << endl;
}
