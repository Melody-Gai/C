#include<stdio.h>
#include<string.h>
#define __GAME_H__

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < cols; i++)
	{
	for (j = 0; j < cols; j++)
	{
	arr[i][j] = set;
	}
	}
	//memset(&arr[0][0], set, rows*cols*sizeof(arr[0][0]);
}

void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n ");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++);
		{
			printf("%c", arr[i][j]);
		}
		printf('\n');
	}
}
void menu()
{
	printf("**********************************\n");
	printf("************  1.play  ************\n");
	printf("************  0.exit  ************\n");
	printf("**********************************\n");
}
#define ROW 9
#define COL 9

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(mine,ROW,COL);
	DisplayBoard(show, ROW, COL);
}
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}