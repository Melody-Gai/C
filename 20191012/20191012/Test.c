
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main()
{
	int right = 1 + (rand() % 100);
	int number;
	printf("��ӭ��������Ϸ��");
	printf("������0~100���֣�");
	scanf("%d", &number);
	while (number != right)
	{
		if (number>right)
		{
			switch ((number - right) / 10)
			{
			case 0:printf("���Ѿ��ܽӽ����ˣ�\n");
				break;
			case 1:printf("��ȴ𰸴���һ�㣡\n");
				break;
			case 2:printf("��ȴ𰸴��˺ܶ࣡\n");
				break;
			default:printf("���ִ�̫����\n");
			}
		}
		else
		{
			switch ((right - number) / 10)
			{
			case 0:printf("���Ѿ��ܽӽ����ˣ�\n");
				break;
			case 1:printf("��ȴ�С��һ�㣡\n");
				break;
			case 2:printf("��ȴ�С�˺ܶ࣡\n");
				break;
			default:printf("����С̫����\n");
			}

		}
		printf("������0~100���֣�");
		scanf("%d", &number);
	}
	printf("��ϲ������");
}
