#include <stdio.h>

int main()
{
	int i, j, *p, *q = &j;
	char c, *cp = &c, **cpp = &cp;
	double d, *dp = &d, **dpp = &dp;

	
	p = &i;
	printf("i的首地址：%p\tj的首地址：%p\np的值：%p\tq的值：%p\n", &i, &j, p, q);
	printf("p的首地址：%p\tq的首地址：%p\n", &p, &q);
	printf("%p %p\t%p %p\n", &i, &i+1, p, p+1);
	printf("%p %p, %p %p\n", cp, cp+1, dp, dp+1);
	printf("%p %p, %p %p\n", cpp, cpp+1, dpp, dpp+1);
	printf("%d\n", sizeof(cpp));
	return 0;
 } 
