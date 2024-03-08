class Student
{
	char *name;
	int age;
	const int roll_number;

public:
	Student(char *, int, int);
	void show();
};

Student::Student(char *name, int age, int roll_number) : roll_number(roll_number) // Initialization List of constant variables
{
	(*this).name = name;
	age = age;
}

void Student::show()
{
	cout << "Name : " << name << ", age : " << age << ", roll no. : " << roll_number << endl;
}
