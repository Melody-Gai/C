#include <stdio.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct SeqList {
	ElemType elem[MAXSIZE];
	int length;
}SeqList;

void InitListf(SeqList *L);
void inputElem(SeqList *L);

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
	int i;
	int j;
	int t;

	//InitList(&liner);  //线性表初始化，构造一个空的线性表
	inputElem(&liner);  //插入元素
}