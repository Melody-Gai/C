#include<stdio.h>

int main() 
{	
	int score[20];
	int scoreCount = 0;
	int temp;
	int i,j;
	int newScore;
	int oldScore;
	
	printf("������ɼ�(-1��������):");
	scanf("%d", &temp);
	while (temp != -1) {
		score[scoreCount++] = temp;
		printf("������ɼ�(-1��������):");
		scanf("%d", &temp);
	}
	for(i = 0; i < scoreCount; i++)
	{
		printf("%d ",score[i]);
	}
	printf("���빦�ܣ�ǰ�壬�������ĩβ��\n");
	printf("�������������ĳɼ���");
	scanf("%d", &newScore); 
	printf("��������������λ�ã�");
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
	printf("ɾ������\n");
	printf("��������Ҫɾ���ĳɼ���");
	scanf("%d",&oldScore);
	for(i = 0; i < scoreCount && score[i] != oldScore; i++)
	{
		;
	}
	if(i >= scoreCount)
	{
		printf("ɾ��ʧ��\n");
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
	printf("����");
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
