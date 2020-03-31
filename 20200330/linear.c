#include <stdio.h>

#define MAXSIZE 100

#define TRUE 1
#define FALSE 0

typedef unsigned char boolean;

typedef int ElemType;
typedef struct SeqList {
	ElemType elem[MAXSIZE];
	int length;
}SeqList;

void InitListf(SeqList *L);//线性表初始化，构造一个空的线性表
void inputElem(SeqList *L);//插入元素
int ListLength(SeqList L);//求线性表的长度，返回线性表中的数据元素的个数
void showElem(SeqList L);//打印已有元素
void GetElem (SeqList L, int i, ElemType x);//用x返回线性表中第i个元素的值
int LocationElem(SeqList L,int x);//按值查找，确定数据元素x在表中的位置
void ListInsert(SeqList *L,int i,ElemType x);//插入操作，在i位置之前插入元素x
void ListDelete(SeqList *L,int i);//删除线性表中的第i个元素
boolean ListEmpty(SeqList L);//判断顺序表是否为空，为空返回false，不为空返回true???
void ClearList(SeqList *L);//清空顺序表
void DestroryList(SeqList L);


void DestroryList(SeqList L){

}

void ClearList(SeqList *L){
	L->length = 0;
	return L;
}

boolean ListEmpty(SeqList L){
	if(L.length) {
		return TRUE;
	}
	return FALSE;
}

void ListDelete(SeqList *L,int i){
	int j;

	if(i > j) {
		return -1;
	}
	for (int j = i; j < L->length - 1; ++j)
	{
		L->elem[j] = L->elem[j + 1];
	}
	L->length --;

	return L;
}

void ListInsert(SeqList *L,int i,ElemType x) {
	int j;

	if(L->length == MAXSIZE - 1) {
		printf("顺序表已满，不能插入");
	}else{
		for (int j = L->length - 1/*???*/; j >= i; --j) {
			L->elem[j + 1] = L->elem[j];
		}
		elem[i] = x;
		L->length ++;
	}
	
	return L;
}

int LocationElem(SeqList L,int x){
	int i;
	//int flg;

	flg = 0;
	for (i = 0; i < L.length; ++i)
	{
		if(L.elem[i] == x) {
			//printf("下标为：%d\n"，i);
			//flg = 1;
			//break;
			return i;
		}
	}
	/*if(!flg) {
		printf("未找到相应的元素\n");
	}*/
	return -1;

}

void GetElem (SeqList L, int i, ElemType* x){
	x = L.elem[i];
	//GetElem(L, 3, &x);
}

void showElem(SeqList L){
	int i;

	for (i = 0; i < L.length; ++i)
	{
		printf("%d\n", L.elem[i]);
	}
	printf("\n");
}

int ListLength(SeqList L){
	//printf("线性表的长度/个数为：%d\n"，L.length);
	//返回值为 int   return L.length; 
	return L.length;
}

void inputElem(SeqList *L){
	int i = 0;
	ElemType num;

	printf("请输入顺序表的元素（最多输入100个，输入-1时结束）：\n");
	scanf("%d",&num);
	while(num != -1) {
		L->elem[i] = num;
		i++;
		scanf("%d",&num);
	}
	L->length = i;
}

void InitListf(SeqList *L){
	L->length = 0;
}

int main() {
	SeqList liner;

	InitList(&liner);  
	inputElem(&liner);

	return 0;  
}