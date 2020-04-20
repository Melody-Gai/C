#include<stdio.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct 
{
	ElemType elem[MAXSIZE];
	int length;
}seqList;

void init_SeqList(SeqList *L);//顺序表的初始化
int Insert_SeqList(SeqList *L, int i,ElemType x);//顺序表的插入
int Delete_SeqList(SeqList *L,int i);//顺序表的删除
int Location_SeqList(SeqList *L,ElemType x);//顺序表中按值查找
void merge(SeqList *A,SeqList *B,SeqList *C);//两个顺序表合并

void merge(SeqList *A,SeqList *B,SeqList *C)
{
	int i,j,k;
	i = 1;
	j = 1;
	k = 1;
	while(i < A->length && j <= B->length)
	{
		if(A->elem[i] <= B->length)
		{
			C->elem[k++] = A->elem[i++];
		}else {
			C->elem[k++] = B->elem[j++];
		}
		while(i <= A->length)
		{
			C->elem[k++] = A->elem[i++];
		}
		while(j <= B->length)
		{
			C->elem[k++] = B->elem[j++];
			C->length = A->length + B->length;
		}
	}
}

int Location_SeqList(SeqList *L,ElemType x)
{
	int i = 1;
	while(i <= L->length && L->elem[i] != x)
	{
		i++;
	}
	if(i < L->length)
	{
		return FALSE;
	}else {
		return L;
	}
}

int Delete_SeqList(SeqList *L,int i)
{
	int j;
	if(i < 1 || i > L->length)
	{
		printf("不存在第i个元素");
		return ERROR;
	}
	for(j = i; j < L->length - 1;j++)
	{
		L->elem[j] = L->elem[j + 1];	
	}
	L->length--;
	return TRUE;
}

int Insert_SeqList(SeqList *L, int i,ElemType x)
{
	int j;
	if(L->length == MAXSIZE - 1)
	{
		printf("表满");
		return OVERFLOW;
	}
	if(i < 1 || i > L->length + 1) 
	{
		printf("位置错");
		return ERROR;
	}
	for (j = L->length; j >= i; j--)
	{
		L->elem[j + 1] = L->elem[j];
		L->elem[i] = x;
		L->length++;
		return true;
	}
}

void init_SeqList(SeqList *L)
{
	L->length = 0;
}