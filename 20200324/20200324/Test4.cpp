#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

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
	return (x + y) * 1.0;
}
int main()
{
	My_class Data;
	cout << "the result for plus(int, int)is:" << Data.plus(5, 10) << endl;
	cout << "the result for plus(double, double)is:" << Data.plus(5.2, 10.3) << endl;
	getchar();
}/*

#include <iostream>
using namespace std;

class Base
{
public:
	virtual void virtualFunc(void)
	{
		cout << "here is Base\n";
	}
};
class Derived :public Base
{
public:
	void virtualFunc(void)
	{
		cout << "here is Derived\n";
	}
};
void main()
{
	Base *BasePtr, BaseObject;
	Derived DerivedObject;
	BasePtr = &BaseObject;
	BasePtr->virtualFunc();
	BasePtr = &DerivedObject;
	BasePtr->virtualFunc();
	cout << endl;
}*/