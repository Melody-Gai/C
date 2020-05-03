#include<stdio.h>
#include<malloc.h>

#define MAXSIZE 50

typedef struct 
{
	datatype data[MAXSIZE];
	int top;
}SeqStack;

SeqStack *Init_SeqStack()//置空栈
{
	SeqStack *s;
	s = malloc(sizeof(SeqStack));
	s->top = -1;
	return s;
}

int Empty_SeqStack(SeqStack *s)//判空栈
{
	if(s->top == -1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

int Push_SeqStack(SeqStack *s,datatype x)//入栈
{
	if(s->top == MAXSIZE - 1)
	{
		return 0;//栈满不能入栈
	}
	else
	{
		s->top++;
		s->data[s->top] = x;
		return 1;
	}
}

int Pop_SeqStack(SeqStack *s,datatype *x)//出栈
{
	if(Empty_SeqStack(s))
	{
		return 0;//栈空不能出栈
	}
	else
	{
		*x = s->data[s->top];
		s->top--;
		return 1;
	}
}

datatype Top_SeqStack(SeqStack *s)//取栈顶元素
{
	if(Empty_SeqStack(s))
	{
		return 0;
	}
	else {
		return (s->data[s->top]);
	}
}