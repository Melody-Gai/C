#include <stdio.h>
#include <malloc.h>

typedef struct POINT {
	int row;
	int col;
	struct POINT *next;
}POINT;

void inputPoints(POINT *list);

void inputPoints(POINT *list) {
	int row;
	int col;
	POINT *p = NULL;
	POINT *tail;

	printf("����������꣨��������Ϊ0ʱ�������룩\n");
	scanf("%d%d", &row, &col);
	while (row && col) {
		p = (POINT *)malloc(sizeof(POINT));
		p->row = row;
		p->col = col;
		p->next = NULL;

		if (list->next == NULL) {
			list->next = p;
		}
	}
}

int main() {
	POINT list1 = { 0 };


}