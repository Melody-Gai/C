#include<stdio.h>
int main()
{
	int i = 0, j = 0;
	int a = 3;
	char c = 1;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5 - 2 * i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 5 + 4 * i; j++)
		{
			printf("%c", c);
		}
		for (j = 0; j < 9 - 4 * i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 5 + 4 * i; j++)
		{
			printf("%c", c);
		}
		printf("\n");
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 29; j++)
			printf("%c", c);
		printf("\n");
	}
	for (i = 0; i < 6 + 1; i++)
	{
		for (j = 0; j < 2 * i + 1; j++)
			printf(" ");
		for (j = 0; j < 27 - 4 * i; j++)
			printf("%c", c);
		printf("\n");
	}
	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < 14; j++)
			printf(" ");
		for (j = 0; j < 1; j++)
			printf("%c", c);
		printf("\n");
	}
	return 0;
}

