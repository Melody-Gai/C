
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main()
{
	int right = 1 + (rand() % 100);
	int number;
	printf("欢迎来到此游戏！");
	printf("请输入0~100数字：");
	scanf("%d", &number);
	while (number != right)
	{
		if (number>right)
		{
			switch ((number - right) / 10)
			{
			case 0:printf("你已经很接近答案了！\n");
				break;
			case 1:printf("你比答案大了一点！\n");
				break;
			case 2:printf("你比答案大了很多！\n");
				break;
			default:printf("数字大太多了\n");
			}
		}
		else
		{
			switch ((right - number) / 10)
			{
			case 0:printf("你已经很接近答案了！\n");
				break;
			case 1:printf("你比答案小了一点！\n");
				break;
			case 2:printf("你比答案小了很多！\n");
				break;
			default:printf("数字小太多了\n");
			}

		}
		printf("请输入0~100数字：");
		scanf("%d", &number);
	}
	printf("恭喜你答对了");
}
