#include <stdio.h> 

int Jc(int n);

int Jc(int n)
{
	int sum;

	if(n > 0)
		sum = n * Jc(n-1);
	else
		sum = 1;

	return sum;
}
int main()
{
	return 0;
}
/*void fun(double **q);

void fun(double **q)
{
	*q = *q + 1;
}

int main()
{

	double a[10] = {1,2,3,4,5,6,7,7,8,9};
	double *p;
	for(p = a; p < a + 10; fun(&p))
	{
		printf("%lf\n",*p);
	}

	return 0;
}
*/