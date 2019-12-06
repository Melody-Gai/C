/*#include<stdio.h> 

	int main() {
		int N1,N2;
		int sum = 0;
		int cha = 0;
		scanf("%d %d",&N1,&N2);
		sum = N1 + N2;
		if(N1 > N2) {
			cha = N1 - N2;
		}else {
			cha = N2 - N1;
		}
		printf("%d %d",sum,cha);
		return 0;
	}

#include<stdio.h> 
int main () {
	int N1,N2,N3;
	int max = 0;
	int min = 0;
	scanf("%d %d %d",&N1,&N2,&N3);
	max = (((N1 < N2)?N1:N2)>N3)?((N1 > N2)?N1:N2):N3;
	min = (((N1 < N2)?N1:N2)<N3)?((N1 < N2)?N1:N2):N3;
	printf("%d %d",max,min);
	return 0;
}
#include <stdio.h>
#include <string.h>
      
int main() {
	int i, j; 
    char a[200], b[200];
    int c = 0;
    printf("请输入主串：");
    gets(a);
    printf("请输入子串：");
    gets(b); 
    int str1len = strlen(a);
	int str2len = strlen(b); 
    int count = 0; 
    for(i = 0; i < str1len - str2len + 1; i++) { 
       for(j = 0; j < str2len; j++) { 
         if(b[j] != a[i + j]) 
           break;    
       } 
       if(j == str2len)
       	    printf("出现的位置：%d\n", i);  
    }

    return 0;
}
#include<stdio.h>
#include<string.h>
int main() {
	int i,j;
	char a[200],b[200];
	printf("请输入主串：");
	gets(a);
	printf("请输入子串：");
	gets(b);
	int len1 = strlen(a);
	int len2 = strlen(b);
	for(i = 0; i < len1 - len2 + 1;i++) {
		for(j = 0;j < len2;j++) {
			if(b[j] != a[i+j]) {
				break;
			}
		}
		if(j == len2) {
			printf("出现的位置：%d\n", i);  
		}
	}
	return 0;
}
#include<stdio.h> 
int main() {
	int a[200];
	int b[200];
	int c[200];
	int i,j;
	for(i = 0;i < 200;i++) {
		scanf("%d",&a[i]);
	}
	for(i = 0;i < 200;i++) {
		if(a[i] % 2 ==1) {
			for(j = 0;j < 200;j++) {
				scanf("%d",&b[j]);
			}
		}else {
			for(j = 0;j < 200;j++) {
				scanf("%d",&c[j]);
			}
		}
	}
	for(i = 0;i < 200;i++) {
		for(j = i + 1;j < 200;j++) {
			if(b[i] > b[j]) {
				int tmp;
				tmp = b[i];
				b[i] = b[j];
				b[j] = tmp;
			}
			if(c[i] > c[j]) {
				int tmp;
				tmp = c[i];
				c[i] = c[j];
				c[j] = tmp;
			}
		}
	}
	for(i = 0;i < 200;i++) {
		printf("%d ",b[i]);
	}
	for(i = 0;i < 200;i++) {
		printf("%d ",c[i]);
	}
	return 0;
}
#include<stdio.h>
int main() {
	int a,b,c;
	int sum=0;
	scanf("%d %d %d",&a,&b,&c);
	sum = a + b + c;
	if(a >= 65 && b >= 60 && c >= 70 && sum >= 210) {
		printf("Pass");
	}else {
		printf("Fail");
	}
	return 0;
}
#include<stdio.h>
int main() {
	int N,K;
	int i,j;
	int tmp,flag;
	int scor[1000];
	scanf("%d %d",&N,&K);
	for(i = 0;i < N;i++) {
		scanf("%d",&scor[i]);
	}
	flag = scor[K - 1];
	for(i = 0;i < N;i++) {
		for(j = i + 1;j < N;j++) {
			if(scor[i] < scor[j]) {
				tmp = scor[i];
				scor[i] = scor[j];
				scor[j] = tmp;
			}
		}
	}
	for(i = 0;i < N;i++) {
		if(scor[i] == flag) {
			printf("%d",i+1);
			break;
		}
	}
}
#include<stdio.h>
int main() {
	int N,K;
	int i,j;
	int tmp,flag;
	int scor[1000];
	scanf("%d %d",&N,&K);
	for(i = 0;i < N;i++) {
		scanf("%d",&scor[i]);
	}
	for(i = 0;i < N;i++) {
		for(j = i + 1;j < N;j++) {
			if(scor[i] < scor[j]) {
				tmp = scor[i];
				scor[i] = scor[j];
				scor[j] = tmp;
			}
		}
	}
	for(i = 0;i < N;i++) {
		printf("%d",scor[i]);
	}
	
}
#include<stdio.h>
int main() {
	int N,K;
	int i,j;
	int tmp,flag;
	int scor[1000];
	scanf("%d %d",&N,&K);
	for(i = 0;i < N;i++) {
		scanf("%d",&scor[i]);
	}
	flag = scor[K - 1];
	for(i = 0;i < N;i++) {
		for(j = i + 1;j < N;j++) {
			if(scor[i] < scor[j]) {
				tmp = scor[i];
				scor[i] = scor[j];
				scor[j] = tmp;
			}
		}
	}
	for(i = 0;i < N;i++) {
		if(scor[i] == flag) {
			printf("%d",i+1);
			break;
		}
	}
	return 0;
}
#include <stdio.h>

int main() {
	int n, m;
	int i;
	int count = 0;
	
	scanf("%d%d",&n, &m);
	for(i = n; i <= m; i++) {
		if((i % 7 != 0) && (i % 2 == 0) || (i % 3 == 0)) {
			count++;
		}
	}
	printf("%d", count);
	 
	return 0;
}*/
#include<stdio.h>
#include<math.h>
int main() {
	int i,j;
	int N,R;
	int count = 0;
	int S[1000][1];
	int G[1000];
	int m = 0;
	int n = 0;
	scanf("%d %d",&N,&R);
	for(i = 0;i < N;i++) {
		scanf("%d %d",&S[i][0],&S[i][1]);
	}
	for(i = 0;i < N;i++) {
		m = S[i][0] * S[i][0] + S[i][1] * S[i][1];
		n = sqrt(m);
		G[i] = n;
		m = 0;
		n = 0;
	}
	for(i = 0;i < N;i++) {
		if(G[i] <= R) {
			count++;
		}
	}
	printf("%d",count);
	return 0 ;
}
















