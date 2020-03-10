#include <stdio.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct SeqList { 
	ElemType elem[MAXSIZE];
	int length;
} SeqList;

int DeleteList( SeqList *L, int i, int j );
void showElem (SeqList L);
void inputElem(SeqList *L);

void showLiner(SeqList L) {
	int i;

	for (i = 0; i < L.length; i++) {
		printf("%d ", L.elem[i]);
	}
	printf("\n");
}

void inputElem(SeqList *L) {
	int i = 0;
	ElemType num;

	printf("请输入顺序表的元素(最多输入100个,输入-1时结束)：\n");
	scanf("%d", &num);
	while (num != -1) {
		L->elem[i] = num;
		i++;
		printf("请输入顺序表的元素(最多输入100个,输入-1时结束)：\n");
		scanf("%d", &num);
	}
	L->length = i;
}

void showElem (SeqList L) {
	int i;

	for (i = 0; i < L.length; ++i)
	{
		printf("%d ", L.elem[i]);
	}
	printf("\n");
}

int DeleteList( SeqList *L, int i, int j ){
	int k;

	if(i > j) {
		return -1;
	}
	for(k = 0; k < L->length - j - 1; k++) {
		L->elem[i++] = L->elem[++j];
	}
	L->length -= j - i + 1;

	return 1;
}


int main() {
	SeqList liner;
	int i;
	int j;
	int t;
	
	inputElem(&liner);
	showElem(liner);
	printf("下面是批量删除元素的操作，请输入你要删除的起止下标\n");
	scanf("%d%d", &i, &j);
	t = DeleteList(&liner, i, j);
	if (t == -1) {
		printf("删除失败，下标不正确\n");
	} else {
		printf("删除成功，结果如下：\n");
		showElem(liner);
	}

}