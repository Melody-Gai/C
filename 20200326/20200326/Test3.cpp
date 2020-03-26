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
	return x + y;
}
int main()
{
	My_class Data;
	cout << "the result for plus(int, int)is:" << Data.plus(5, 10) << endl;
	cout << "the result for plus(double, double)is:" << Data.plus(5.0, 10.0) << endl;
	getchar();
}