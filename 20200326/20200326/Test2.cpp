/*#include <iostream>
#include <math.h>
using namespace std;
const double ANG_TO_RAD = 0.0174532925;

class angle
{
	double value;
public:
	void SetValue(double a);
	double GetSine(void);
}deg;
void angle::SetValue(double a) {
	value = a;
};
double angle::GetSine(void)
{
	double temp;
	temp = sin(ANG_TO_RAD *value);
	return temp;
};

int main()
{
	deg.SetValue(60.0);
	cout << "the sine of the angle is:";
	cout << deg.GetSine() << endl;
	getchar();
}*/