#include <stdio.h>
#include <malloc.h>

typedef struct POINT {
	int row;
	int col;
	struct POINT *next;
}POINT;

void inputPoints(POINT *list);
void showOnePoint(POINT point);
void showAllPoints(POINT list);
void destoryList(POINT *list);
void insertPoint(POINT *list);
POINT *searchPrePoint(POINT list, POINT point);
void deletePoint(POINT *list);
void sortPoints(POINT *list);

void sortPoints(POINT *list) {
	POINT *p;
	POINT *q;
	POINT tmp;
	POINT *n;

	for (p = list->next; p; p = p->next) {
		for (q = p->next; q; q = q->next) {
			if(p->row > q->row) {
				tmp = *p;
				*p = *q;
				*q = tmp;

				n = p->next;
				p->next = q->next;
				q->next = n;
			}
		}
	}
}

void deletePoint(POINT *list) {
	int oldRow;
	int oldCol;
	POINT oldPoint;
	POINT *prePoint;
	POINT *p;

	printf("请输入你要删除的点的坐标：\n");
	scanf("%d%d", &oldRow, &oldCol);
	oldPoint.row = oldRow;
	oldPoint.col = oldCol;
	prePoint = searchPrePoint(*list, oldPoint);

	if(prePoint == NULL) {
		prePoint = list;
	} else {
		if (prePoint->next == NULL) {
			printf("没找到相应的点\n");
			return;
		}
	}
	p = prePoint->next;
	prePoint->next = p->next;

	free(p);
}

POINT *searchPrePoint(POINT list, POINT point) {
	POINT *p;
	POINT *pre = NULL;

	for (p = list.next; p && !(p->row == point.row && p->col == point.col); p = p->next) {
		pre = p;
	}

	return pre;
}

void insertPoint(POINT *list) {
	int oldRow;
	int oldCol;
	int newRow;
	int newCol;
	POINT *p;
	POINT oldPoint;
	POINT *prePoint;

	printf("请输入你要插入的点的横纵坐标：\n");
	scanf("%d%d",&newRow, &newCol);
	p = (POINT *)malloc(sizeof(POINT));
	p->row = newRow;
	p->col = newCol;
	p->next = NULL;

	printf("请输入你要插入的位置(前插入)：\n");
	scanf("%d%d",&oldRow, &oldCol);
	oldPoint.row = oldRow;
	oldPoint.col = oldCol;
	prePoint = searchPrePoint(*list, oldPoint);

	if (prePoint == NULL) {
		prePoint = list;
	}

	p->next = prePoint->next;
	prePoint->next = p;
}

void destoryList(POINT *list) {
	POINT *p;
	
	for (p = list->next; p; p = list->next) {
		list->next = p->next;
		free(p);
	}
}

void showAllPoints(POINT list) {
	POINT *p;

	for (p = list.next; p; p = p->next) {
		showOnePoint(*p);
		printf("\n");
	}
}

void showOnePoint(POINT point) {
	printf("row:%d col:%d\n", point.row, point.col);
}

void inputPoints(POINT *list) {
	int row;
	int col;
	POINT *p = NULL;
	POINT *tail;

	printf("请输入点坐标(横纵坐标为0时结束输入)\n");
	scanf("%d%d", &row, &col);
	while (row && col) {
		p = (POINT *) malloc(sizeof(POINT));
		p->row = row;
		p->col = col;
		p->next = NULL;

		if (list->next == NULL) {
			list->next = p;	
		} else {
			tail->next = p;
		}
		tail = p;
		printf("请输入点坐标(横纵坐标为0时结束输入)\n");
		scanf("%d%d", &row, &col);
	}
}

int main() {	
	POINT list1 = {0};

	inputPoints(&list1);
	printf("结果为\n");
	showAllPoints(list1);
	printf("下面是插入新点坐标功能\n");
	insertPoint(&list1);
	printf("插入的结果如下\n");
	showAllPoints(list1);
	printf("下面是删除新点坐标功能\n");
	deletePoint(&list1);
	printf("删除的结果如下\n");
	showAllPoints(list1);
	printf("排序的结果如下\n");
	sortPoints(&list1);
	showAllPoints(list1);

	destoryList(&list1);

	return 0;
}