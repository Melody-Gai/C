#include <stdio.h>

int main()
{
	char st[80] = "abcdefghijklmn"; // char st[80] = {'a', 'b', …, 'n', 0};
	char *p = st + 4;
	int *q;

	q = (int *)p;
	q++;
	p = (char *)q;

	printf("%c %s\n", p[0], p);

	
/*
		char s[80] = "Xiaoming is a good boy!";
		char *p = s+14;

		p = "bad";
		printf("%s\n", s);

	char s[80] = "Xiaoming is a good boy!";
	char *p = s+14;
	p[0] = 'b';
	p[1] = 'a';
	p[2] = 'd';
	p[3] = ' ';
	printf("%s\n", s);*/


/*	int num = 32;
	for(; num; num /= 16)
	printf("%c", "0123456789ABCDEF"[num % 16]);

	printf("%c %c\n", "abcdef"[3], *("abcdef" + 3));
	printf("%d\n", "abcdef" - "xyz");
	printf("%d\n", "abcdef" < "xyz");



	char *s = "abcdef";
	char st[] = "abcdef";
	char str[80] = "abcdef";

	

	int i;
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	printf("%d %d\n",0[a],*a);
	printf("%d %d\n",5[a],*(a + 5));
	for(i = 0;i < 10 ; i++)
	{
		printf("%d\n",*(a + i));
	}

	int i, j, *p, *q = &j;
	char c, *cp = &c, **cpp = &cp;
	double d, *dp = &d, **dpp = &dp;

	
	p = &i;
	printf("i的首地址：%p\tj的首地址：%p\np的值：%p\tq的值：%p\n", &i, &j, p, q);
	printf("p的首地址：%p\tq的首地址：%p\n", &p, &q);
	printf("%p %p\t%p %p\n", &i, &i+1, p, p+1);
	printf("%p %p, %p %p\n", cp, cp+1, dp, dp+1);
	printf("%p %p, %p %p\n", cpp, cpp+1, dpp, dpp+1);
	printf("%d\n", sizeof(cpp));*/
	return 0;
 }