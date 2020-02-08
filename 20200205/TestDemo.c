#include<stdio.h>
	
void main()
{
	int n;
	int i;

	
	for(i = 0; i < 7; i++)
	{
		n = (n + 1) * 2;
	}
	
	printf("%d", n);
	
/*	int Num;
	int i,j;
	
	printf("请输入一个整数：");
	scanf("%d", &Num);
	
	for(i = 0; i <= Num / 2; i++)
	{
		j = (Num - 2 * i);
		if(j % 4 == 0)
		{
			printf("%d %d\n", i, j / 4);
		}
	}
	
	int a;
	int i;
	
	printf("请输入一个整数：");
	scanf("%d", &a);
	
	for(i = 1; i <= a; i++)
	{
		if(a % i == 0)
		{
			printf("%d\n", i);
		}
	}
	
	
	int a;
	int i;
	int max;
	scanf("%d", &max);
	for(i = 1; i < 10; i++)
	{
		scanf("%d", &a);
		max = max > a ? max : a;	
	}
	printf("%d", max);


	for(i = 0; i < 100; i++) {
		printf("");
	}
	
	i = 0;
	while(i < 100)
	{
		printf();
		i++;
	}
	
	
	int a;
	int b;
	int tmp;
	
	printf("请输入两个整数：");
	scanf("%d%d", &a, &b); 
	
	tmp = a;
	a = b;
	b = tmp;
	
	printf("%d %d", a, b);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	printf("\t%-16s %-8s %-4s %-9s\n", "姓名", "职称", "年龄", "月薪");
	printf("\t%-16s %-8s %04d %-9.2lf\n", "臭脚丫子", "洗碗工", 3, 1.23);
	printf("\t%-16s %-8s %04d %-9.2lf\n", "李四", "配菜师", 23, 1111.23);
	printf("%04d %04d %04d %04d %04d\n", 1, 12, 123, 1234, 12345);
	printf("%9.2lf %.2lf (%4.0lf)\n", 1234567890.127, 123.456789, 123.5678);

	
	printf("%d + %d = %d\n", 4, 5, 4-5);
	printf("%d %d %d %d\n", 3);
	printf("%d %d\n", 3, 4, 5, 6);

	
	int i;
	int j = 2;
	int k;

	i = 1;
	k = i-- || ++j;
	printf("%d %d %d\n", i, j, k);

	i = 0;
	k = i++ && ++i && ++j;
	//k = 0 && ++i && ++j;	i自增为1
	//k = (0 && A) && ++j;
	//A被短路，即，++i被短路；
	//k = 0 && ++j;
	//k = 0 && A;
	//A被短路，即，++j被短路；
	//k = 0; i依然自增过了
	//若语句改为：
	//k = i++ && (++i && ++j);
	//由于i的初值为0，满足了短路运算的条件，因此(++i && ++j)被短路！
	printf("%d %d %d\n", i, j, k);
*/
	return 0;
}
