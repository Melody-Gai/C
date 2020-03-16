#include <stdio.h>
#include <malloc.h>

typedef struct POINT {
	int data;
	struct POINT *next;
}POINT;

void inputPoints(POINT *head);
void showOnePoint(POINT point);
void showPointList(POINT head);
void destoryPointList(POINT *head);
void movePoint(POINT *head);

void movePoint(POINT *head) {
	POINT *p = NULL;
	int standard = head->next->data;
	POINT *standardPoint = head->next;
	POINT *tail = head->next;
	POINT *q = NULL;

	q = head->next->next;
	while (q) {
		p = q;
		if (p->data <= standard) {
			q = q->next;
			standardPoint->next = p->next;
			head->next = p;
			p->next = tail;
			tail = p;
			continue;
		}
		standardPoint = q;
		q = q->next;
	}	
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
		printf(" ");
	}
}

void showOnePoint(POINT point) {
	printf("%d ", point.data);
}

void inputPoints(POINT *head) {
	int data;
	POINT *p = NULL;
	POINT *tail = NULL;

	printf("请输入一个数据：(数据为0时停止输入)");
	scanf_s("%d", &data);
	while (data) {
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
		scanf_s("%d", &data);
	}
}

int main(int argc, char const *argv[]) {
	POINT liner = {0};

	inputPoints(&liner);
	showPointList(liner);
	movePoint(&liner);
	showPointList(liner);

	destoryPointList(&liner); 
	return 0;
}