#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXSIZE 52

typedef int ElemType;
typedef struct SeqList
{ 
	ElemType elem[ MAXSIZE ];
	int length;
} SeqList;

void CreateRandomBigInt(SeqList *num);
void DisplayBigInt(SeqList num);
void AddBigInt(SeqList num1, SeqList num2, SeqList *result);
void ListRevers(SeqList *num);

void ListRevers(SeqList *num) {
	int i;
	ElemType t;

	for (i = 0; i < num->length / 2; i++) {
		t = num->elem[i];
		num->elem[i] = num->elem[num->length - i - 1];
		num->elem[num->length - i - 1] = t;
	}
}

void AddBigInt(SeqList num1, SeqList num2, SeqList *result) {
	int i;
	ElemType t;
	int carry = 0;
	ElemType count;
	ElemType a;
	ElemType b;
	int len = num1.length > num2.length ? num1.length : num2.length;
	int num1len = num1.length - 1;
	int num2len = num2.length - 1;

	for (i = 0; i < len; i++) {
		if (num1len >= 0) {
			a = num1.elem[num1len];
			num1len--;
		} else {
			a = 0;
		}
		if (num2len >= 0) {
			b = num2.elem[num2len];
			num2len--;
		} else {
			b = 0;
		}
		count = a + b + carry;
		t = count % 10;
		carry = count / 10;
		result->elem[i] = t;
	}
	if (carry) {
		result->elem[i] = 1; 
		result->length = i + 1;
	} else {
		result->length = i;
	}
}

void DisplayBigInt(SeqList num) {
	int i;

	printf("这是一个%d位数：\n", num.length);
	for (i = 0; i < num.length; i++) {
		printf("%d", num.elem[i]);
	}
	printf("\n");
}

void CreateRandomBigInt(SeqList *num) {
	int i;
	static int first = 0;

	if (first == 0) {
		srand(time(0));
		first = 1;
	}

	num->length = rand() % 50 + 1;
	num->elem[0] = rand() % 9 + 1;
	for (i = 1; i < num->length; i++) {
		num->elem[i] = rand() % 10;
	}
}
int main() {
	SeqList num1;
	SeqList num2;
	SeqList result;

	CreateRandomBigInt(&num1);
	CreateRandomBigInt(&num2);
	printf("第一个随机大数：\n");
	DisplayBigInt(num1);
	printf("第二个随机大数：\n");
	DisplayBigInt(num2);
	AddBigInt(num1, num2, &result);
	ListRevers(&result);
	printf("两个大数相加的和：\n");
	DisplayBigInt(result);

	return 0;
}