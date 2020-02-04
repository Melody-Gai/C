#include<stdio.h>
#include<string.h>
void fun(char *s,char *t) {
	int i,s1;
	i = 0;
	s1 = strlen(s);
	for( ;i < s1;i++) {
		t[i] = s[s1 - i - 1];
	}
	for(i = 0;i < s1;i++) {
		t[s1 + i] = s[i];
	}
	t[2 * s1] = '\0';
} 
int main() {
	char s[100],t[100];
	printf("\nPlease enter string s:");
	scanf("%s",s);
	fun(s,t);
	printf("The result is:%s\n",t);
}
