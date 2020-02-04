/*#include<stdio.h>
void fun(int a,int b,long *c) {
	int m,n,j,k;
	m = a % 10;
	n = a / 10;
	j = b % 10;
	k = b / 10;
	*c = 1000 * j + 100 * m+ 10 * k + n; 
}
int main() {
	int a,b;
	long c;
	printf("Input a,b:");
	scanf("%d %d",&a,&b);
	fun(a,b,&c);
	printf("The result is:%ld\n",c);
}

#include<stdio.h>
void fun(long s,long *t) {
	long s1 = 10;
	s /= 10;
	*t = s % 10;
	while(s > 0) {
		s = s / 100;
		*t = s % 10 * s1 + *t;
		s1 = s1 * 10;
	}
}
int main() {
	long s,t;
	printf("\nPlease enter s:");
	scanf("%ld",&s);
	fun(s,&t);
	printf("The result is:%ld\n",t);
}*/




















 
