#include <stdio.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct POINT {
	char data;
	struct POINT *next;
}POINT;

void inputPoints(POINT *head);
void showOnePoint(POINT point);
void showPointList(POINT head);
void destoryPointList(POINT *head);
void DeleteListNode(POINT *head);

void DeleteListNode(POINT *head) {
	char ch;
	POINT *p = NULL;
	POINT *q = NULL;

	if (NULL == head) {
		return;
	} 
	printf("你现在会知道一个点的指针，请输入你想选择的点：\n");
	scanf("%c", &ch);
	getchar();
	for (p = head->next->next; p->data != ch; p = p->next) {
		;
	}
	printf("你想知道的指针是：%x\n", p);
	printf("现在我就根据这一个指针，把这个指针指向的节点给删除了\n");
	p->data = p->next->data;
	q = p->next;
	p->next = p->next->next;
	showPointList(*head);
	printf("好了，我做到了\n");

	free(q);
}



void destoryPointList(POINT *head) {
	POINT *p;

	for (p = head->next; p; p = head->next) {
		head->next = p->next;
		free(p);
	}
}

void showPointList(POINT head) {
	POINT *p;

	for (p = head.next; p; p = p->next) {
		showOnePoint(*p);
	}
	printf("\n");
}

void showOnePoint(POINT point) {
	printf("%c ", point.data);
}

void inputPoints(POINT *head) {
	char data;
	POINT *p = NULL;
	POINT *tail = NULL;

	printf("请输入一个数据：(数据为0时停止输入)");
	scanf("%c", &data);
	getchar();
	while (data != '0') {
		p = (POINT *)calloc(sizeof(POINT), 1);
		p->data = data;
		p->next = NULL;

		if (head->next == NULL) {
			head->next = p;
		}
		else {
			tail->next = p;
		}
		tail = p;
		printf("请输入一个数据：(数据为0时停止输入)");
		scanf("%c", &data);
		getchar();
	}
}

int main(int argc, char const *argv[]) {
	POINT liner = {0};

	inputPoints(&liner);
	showPointList(liner);
	DeleteListNode(&liner);

	destoryPointList(&liner); 
	return 0;
}