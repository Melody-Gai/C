#include<stdio.h>
#include<malloc.h>

#define TRUE  1
#define FALSE 0

typedef struct node;

typedef struct node
{
	ElenType data;
	struct node *next;
}LNode,*LinkeList;

LinkeList Creat_LinkList1();//头插法
LinkeList Creat_LinkList2();//尾插法
int Length_LinkList(LinkeList H);//求单链表表长
LinkeList Get_LinkList(LinkeList H,int k);//单链表中按序号查找
LNode *Locate_LinkList(LinkeList H,ElenType x);//单链表中按值查找
int Insert_LinkList(LinkeList H,int i,ElenType x);//单链表的插入
int Del_LinkList(LinkeList H,int i);//单链表的删除
void Reverse(LinkeList H);//单链表的倒置
void pur_LinkList(LinkeList H);//删除重复结点
void Difference(LinkeList LA,LinkeList LB);//连个集合的差集

void Difference(LinkeList LA,LinkeList LB)
{
	node *pre,*p,*r;
	pre = LA;
	p = LA->next;
	while(p != NULL)
	{
		q = LB->next;
		while(q != null && q->data != p->data)
		{
			q = q->next;
		}
		if(q !=NULL)
		{
			r = p;
			pre->next = p->next;
			p = p->next;
			free(r);
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

void pur_LinkList(LinkeList H)
{
	LNode *p,*q,*r;
	p = H->next;
	if(p != NULL)
	{
		while(q->next)
		{
			if(q->next->data == p->data)
			{
				r = q->next;
				q->next = r->next;
				free(r);
			}	
			else
			{
				q = q->next;
			}
			p = p->next;
		}
	}
}

void Reverse(LinkeList H)
{
	LNode *p,*q;
	p = H->next;
	H->next = NULL;
	while(p)
	{
		q = p;
		p = p->next;
		q->next = H->next;
		H->next = q;
	}
}

int Del_LinkList(LinkeList H,int i)
{
	LinkeListp,q;
	p = Get_LinkList(H,i - 1);
	if(p == NULL)
	{
		printf("第i - 1个结点不存在\n");
		return ERROR;
	}
	else 
	{
		q = p->next;
		p->next = q->next;
		free(q);
		return TRUE;
	}
}

int Insert_LinkList(LinkeList H,int i,ElenType x)
{
	LNode *p,*s;
	p = Get_LinkList(H,i - 1);
	if(p == NULL)
	{
		printf("插入位置i错\n");
		return ERROR;
	}
	else
	{
		s = (LinkeList)malloc(sizeof(LNode));
		s->data = x;
		s->next = p->next
		p->next = s;
		return TRUE;
	}
}

LNode *Locate_LinkList(LinkeList H,ElenType x)
{
	LNode *p = H->next;
	while(p != NULL && p->data != x)
	{
		p = p->next;
	}
	return p;
}

LinkeList Get_LinkList(LinkeList H,int k)
{
	LNode *p = H;
	int j = 0;
	while(p->next != NULL && j < k)
	{
		p= p->next;
		j++;
		if(j == k)
		{
			return p;
		}
		else
		{
			return NULL;
		}
	}
}

int Length_LinkList(LinkeList H)
{
	LNode *p = H;
	int j = 0;
	while(p->next != NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}

LinkeList Creat_LinkList2()
{
	LinkeList H = (LinkeList)malloc(sizeof(LNode));
	H->next = NULL;
	LNode *s,*r = H;
	int x;
	scanf("%d",&x);
	while(x != -1)
	{
		s = (LinkeList)malloc(sizeof(LNode));
		s->data = x;
		s->next = r->next;
		r->next = s;
		r = s;
		scanf("%d",&x);
	}
	return H;
}

LinkeList Creat_LinkList1()
{
	LinkeList H = (LinkeList)malloc(sizeof(LNode));
	H->next = NULL;
	LNode *s;
	int x;
	scanf("%d",&x);
	while(x != -1) 
	{
		s = (LinkeList)malloc(sizeof(LNode));
		s->data = x;
		s->next = H->next;
		H->next = s;
		scanf("%d",&x);
	}
	return H;
}