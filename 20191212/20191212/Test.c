#include<stdio.h>


#if 0
int main()
{
	int a = '\7';//0 1 2 3 4 5 6 7 
	int b = 1;
	printf("a = %d b = %d\n", a, b);
}


int main()
{
	//char str[] = "Hello";
	//char str[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
	char str[] = { 'h', '0', 'l',0, 'l', 'o', '\0' };
	//char str[10] = {'h','e','l','l','o','\0'};
	printf("size = %d\n", sizeof(str));
	printf("str = %s\n", str);
	return 0;
}
#endif