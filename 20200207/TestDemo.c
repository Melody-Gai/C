#include<stdio.h>

int main()
{
	int n;
	int t = 0;
	int m;
	printf("������һ������");
	scanf("%d",&n);
	m = n;
	
	for(; m; m /= 10) {
		t = t * 10 + m % 10;
	}
	
	
	
	
/*	int height;
	int i,j,k;
	
	printf("���������ĸ߶ȣ�");
	scanf("%d",&height);
	
	for(i = 0;i <= height / 2 + 1;i++) {
		for(j = 0;j < height / 2 + 1 - i;j++) {
			printf(" ");
		}
		for(k = 0;k < 2 * i - 1;k++) {
			printf("*");
		}
		printf("\n");
		
	}
	for(i = 0;i < height / 2;i++) {
		for(j = 0;j < i + 1;j++) {
			printf(" ");
		}
		for(k = 0;k < height - 2 * i - 2;k++) {
			printf("*");
		}
		printf("\n");
	} 
*/	
	return 0;
 } 
