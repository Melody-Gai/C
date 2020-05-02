#include<stdio.h>

#define MAXSIZE 1000
#define OK 1
#define ERROR 0

/*线性表的静态链表存储结构*/
typedef struct
{
	ElemType data;
	int cur;
}Component,StaticLinkList[MAXSIZE];

/*将一维数组space中各分量链成一备用链表*/
Status InitList (StaticLinkList space)
{
	int i;
	for (int i = 0; i < MAXSIZE - 1; ++i)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
	return OK;
}

/*若备用空间链表非空，则返回分配的节点下标，否则返回0*/
int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;
	if(space[0].cur)
	{
		space[0].cur = space[i].cur;
	}
	return i;
}

/*在L中第i个元素之前插入新的数据元素e*/
Status ListInsert(StaticLinkList L,int i,ElemType e)
{
	int j,k,l;
	k = MAXSIZE - 1;
	if(i < 1 || i > ListLength(L) + 1)
	{
		return ERROR;
	}
	j = Malloc_SLL(L);
	if (j)
	{
		L[j].data = e;
		for (int l = 0; l < i - 1; ++l)
		{
			k = L[k].cur;
		}
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}

/*删除在L中第i个数据元素e*/
Status ListDelete(StaticLinkList L,int i)
{
	int j,k;
	if (i < 1 || i > ListLength(L))
	{
		return ERROR;
	}
	k = MAXSIZE - 1;
	for (int j = 0; j <= i - 1; ++j)
	{
		k = L[k].cur;
	}
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL(L,j);
	return OK;
}

/*将下标为k的空闲节点回收到备用链表*/
void Free_SSL(StaticLinkList space,int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

/*初始条件：静态链表L已存在。操作结果：返回L中数据元素个数*/
int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while(i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}