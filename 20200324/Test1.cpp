/*#include <iostream>
#include <math.h>
using namespace std;
const double ANG_TO_RAD = 0.0174532925;

class My_class
{
	char *str;
	int MaxLen;
public:
	My_class(char *)
	{
		str = new char[MaxLen];
	}
	~My_class()
	{
		cout << "here delete the str" << endl;
		delete str;
	}
	void GetString(char *);
};


class angle
{
	double value;
public:
	void SetValue(double a)
	{
		value = a;
	};
	double GetSine(void)
	{
		double temp;
		temp = sin(ANG_TO_RAD *value);
		return temp;
	};
}deg;

int main()
{
	deg.SetValue(60.0);
	cout << "the sine of the angle is:";
	cout << deg.GetSine() << endl;
	getchar();
}


/*
#include <math.h>
const double ANG_TO_RAD = 0.0174532925;
class angle
{
	double value;
public:
	void SetValue(double a);
	double GetSine(void);
}deg;
inline void angle::SetValue(double a) {
	value = a;
};
inline double angle::GetSine(void)
{
	double temp;
	temp = sin(ANG_TO_RAD *value);
	return temp;
};
*/



/*
#include <math.h>
const double ANG_TO_RAD = 0.0174532925;
class angle
{
	double value;
public:
	void SetValue(double a);
	double GetSine(void);
}deg;
void angle::SetValue(double a){
		value = a;
};
	double angle::GetSine(void)
	{
		double temp;
		temp = sin(ANG_TO_RAD *value);
		return temp;
	};
	


#include <math.h>
const double ANG_TO_RAD = 0.0174532925;
class angle
{
	double value;
public:
	void SetValue(double a)
	{
		value = a;
	};
	double GetSine(void)
	{
		double temp;
		temp = sin(ANG_TO_RAD *value);
		return temp;
	};
}deg;

*/