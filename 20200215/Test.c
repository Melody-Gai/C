#include <stdio.h>

int main()
{
	int i, j, *p, *q = &j;
	char c, *cp = &c, **cpp = &cp;
	double d, *dp = &d, **dpp = &dp;

	
	p = &i;
	printf("i���׵�ַ��%p\tj���׵�ַ��%p\np��ֵ��%p\tq��ֵ��%p\n", &i, &j, p, q);
	printf("p���׵�ַ��%p\tq���׵�ַ��%p\n", &p, &q);
	printf("%p %p\t%p %p\n", &i, &i+1, p, p+1);
	printf("%p %p, %p %p\n", cp, cp+1, dp, dp+1);
	printf("%p %p, %p %p\n", cpp, cpp+1, dpp, dpp+1);
	printf("%d\n", sizeof(cpp));
	return 0;
 } 
