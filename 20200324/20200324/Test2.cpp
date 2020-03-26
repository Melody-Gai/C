/*#include <iostream>

using namespace std;

class Student;
class Teacher
{
public:
	void assignGrades(Student &s);
	void adjustHours(Student &s);
protected:
	int NoOfStudent;
	Student * pList[100];
};
class Student
{
public:
	friend class Teacher;
protected:
	int semesterHours;
	float gpa;
};

class OperClass
{
	int x;
public:
	OperClass();
	OperClass &operator++();
	OperClass operator+(OperClass&);
	OperClass operator++(int);
	void display();
};
OperClass::OperClass()
{
	x = 0;
}
void OperClass::display()
{
	cout << "x = " << x << endl;
}

class My_class
{
public:
	int plus(int, int);
	double plus(double, double);
};
int My_class::plus(int x, int y)
{
	return x + y;
}
double My_class::plus(double x, double y)
{
	return x + y;
}
int main()
{
	My_class Data;
cout << "the result for plus(int, int)is:" << Data.plus(5, 10) << endl;
cout << "the result for plus(double, double)is:" << Data.plus(5.0, 10.0) << endl;
getchar();
}*/