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

	printf("������˳����Ԫ��(�������100��,����-1ʱ����)��\n");
	scanf("%d", &num);
	while (num != -1) {
		L->elem[i] = num;
		i++;
		printf("������˳����Ԫ��(�������100��,����-1ʱ����)��\n");
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
	printf("����������ɾ��Ԫ�صĲ�������������Ҫɾ������ֹ�±�\n");
	scanf("%d%d", &i, &j);
	t = DeleteList(&liner, i, j);
	if (t == -1) {
		printf("ɾ��ʧ�ܣ��±겻��ȷ\n");
	} else {
		printf("ɾ���ɹ���������£�\n");
		showElem(liner);
	}

}