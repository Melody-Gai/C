#include <stdio.h>

void Exchange(int *m, int *n);


void Exchange(int *m, int *n)
{
	int tmp;

	tmp = *m;
	*m = *n;
	*n = tmp;
}

int main()
{
    int a, b;

	printf("����������������");
	scanf("%d%d", &a, &b);
	Exchange(&a, &b);
	printf("%d %d", a, b);

	return 0;
}