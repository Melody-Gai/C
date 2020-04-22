#include <stdio.h>

int main() 
{
	int i = 3;
	int j;
	j = (i++) + (i++) + (i++);
	printf("%d %d\n", i, j);
	printf("i=%d\n", i);

	i = 3;
	printf("%d %d\n", i, j = (++i) + (++i) + (++i));

	i = 3;
	printf("%d %d\n", j = (++i) + (++i) + (++i), i);
	printf("i=%d\n", i);
	system("pause");
	return 0;
} 
