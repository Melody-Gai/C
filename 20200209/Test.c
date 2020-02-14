#include <stdio.h>

int main() 
{
	int Num;
	int flg = 0;
	int i;
	
	printf("请输入一个整数：");
	scanf("%d", &Num);
	for (i = 2; Num != 1; ) {
		if (Num % i == 0) {
			Num /= i;
			if (flg == 0) {
				printf("%d" , i);
				flg = 1;
			} else {
				printf(" * %d", i);
			}
			/*if (Num == 1) {
				printf("%d", i);
			}else {
				printf("%d * ",i);
			}*/
		}else {
			i++;
		}
	}
	
	
	
	
	
/*	int Num;
	int i;
	int k = 0;
	printf("请输入一个整数：");
	scanf("%d",&Num);
	for(i = 2;i < Num / 2;i++)
	{
		if(Num % i == 0) {
			k = 1;
		}
	}
	if(k == 1)
	{
		printf("该数不是质数");
	}else {
		printf("该数是质数");
	}
	
	
	int sum;
	int i, j;
	
	for(i = 6;i < 10000000;i++)
	{
		for(j = 1;j <= i / 2; j++) 
		{
			if(i % j == 0)
			{
				sum += j;
			}	
		}
		if(i == sum)
		{
			printf("%d\n",i);
		}
	}*/
	return 0;
}
