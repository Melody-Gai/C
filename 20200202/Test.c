#include<stdio.h>

int func(int x) {
	int n,s1,s2,s3,t;
	n = 0;
	t = 100;
	while(t <= x) {
		s1 = t % 10;
		s2 = (t / 10) % 10;
		s3 = t / 100;
		if(s1 + s2 + s3 == 15) {
			printf ("%d\n",t);
			n++;
		}
		t++;
	}
	return n;
}
int main() {
	int x = -1;
	while(x > 999 || x < 0) {
		printf ("Please input(0 < x <= 999):");
		scanf("%d",&x);
		printf("\nThe result is:%d  ",func(x)); 
	}
}


/*#include<stdio.h>
int fun(int x) {
	int n,s1,s2,s3,t;
	n = 0;
	t = 100;
	while(t <= 999) {
		s1 = t % 10;
		s2 = (t / 10) % 10;
		s3 = t / 100;
		if(s1 + s2 + s3 == x) {
			printf("%d\n",t);
			n++;
		}
		t++;
	}
	return n;
} 
int main() {
	int x = -1;
	while(x < 0) {
		printf("Please input(x > 0):");
		scanf("%d",&x);
	}
	printf("\nThe result is:%d  ",fun(x));
}*/
