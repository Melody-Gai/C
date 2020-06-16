#include <stdio.h>

#define MAXNUM 100

typedef struct
{
	Elemtype stack[MAXNUM];
	int lefttop;
	int righttop;
}dupsqstack;

int initDupStack(dupsqstack *s);//初始化操作
int pushDupStack(dupsqstack *s, char status,Elemtype x);//入栈操作
Elemtype popDupStack(dupsqstack *s,char status);//出栈操作

Elemtype popDupStack(dupsqstack *s,char status)
{
	if(status == 'L')
	{
		if(s->lefttop < 0) return NULL;
		else return (s->stack[s->lefttop--]);
	}
	else if(status == 'R')
	{
		if(s->righttop > MAXNUM - 1) return NULL;
		else return (s->stack[s->righttop++]);
	}
	else return NULL;
}

int pushDupStack(dupsqstack *s, char status,Elemtype x)
{
	if(s->lefttop + 1 == s->righttop) return FALSE;
	if(status == 'L') s->stack[++s->lefttop] = x;
	else if(status == 'R') s->stack[--s->lefttop] = x;
	else return FALSE;
	return TRUE;
}

int initDupStack(dupsqstack *s)
{
	if((s = (dupsqstack*)malloc(sizeof(dupsqstack))) == NULL)
	{
		return FALSE;
	}
	s->lefttop = -1;
	s->righttop = MAXNUM;
	return TRUE;
}

int main()
{
	char status;
	status = 'L';
	status = 'R';
}