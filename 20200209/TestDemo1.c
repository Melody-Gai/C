#include<stdio.h>

int main() 
{	
	int score[20];
	int scoreCount = 0;
	int temp;
	int i,j;
	int newScore;
	int oldScore;
	
	printf("请输入成绩(-1结束输入):");
	scanf("%d", &temp);
	while (temp != -1) {
		score[scoreCount++] = temp;
		printf("请输入成绩(-1结束输入):");
		scanf("%d", &temp);
	}
	for(i = 0; i < scoreCount; i++)
	{
		printf("%d ",score[i]);
	}
	printf("插入功能（前插，否则放在末尾）\n");
	printf("请输入你想插入的成绩：");
	scanf("%d", &newScore); 
	printf("请输入你想插入的位置：");
	scanf("%d", &oldScore);
	for(i = 0;i < scoreCount && score[i] != oldScore; i++)
	{
		;
	}
	for(j = scoreCount; j > i; j--)
	{
		score[j] = score[j - 1];
	}
	
	score[i] = newScore;
	scoreCount++;
	
	for(i = 0; i < scoreCount; i++)
	{
		printf("%d ",score[i]);
	}
	printf("删除功能\n");
	printf("请输入你要删除的成绩：");
	scanf("%d",&oldScore);
	for(i = 0; i < scoreCount && score[i] != oldScore; i++)
	{
		;
	}
	if(i >= scoreCount)
	{
		printf("删除失败\n");
	} else {
		for(j = i; j < scoreCount - 1; j++)
		{
			score[j] = score[j + 1]; 
		}
	}
	scoreCount--;
	for(i = 0; i < scoreCount; i++)
	{
		printf("%d ",score[i]);
	}
	printf("排序");
	for(i = 0; i < scoreCount; i++)
	{
		for(j = 0; j < i; j++) 
		{
			if(score[i] > score[j])
			{
				temp = score[i];
				score[i] = score[j];
				score[j] = temp;
			}
		}
	}	
	for(i = 0; i < scoreCount; i++)
	{
		printf("%d ",score[i]);
	}
	
	return 0;
} 
