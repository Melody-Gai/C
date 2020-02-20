#include <stdio.h>

int main()
{
	char s[20];
	char s1[22];
	
	scanf("%s",s1);
	flushall();
	gets(s);
	puts(s);
	printf("%s",s1);
	
/*		char st[80];
	char *p;

	scanf("%s", st);	// 从键盘输入字符串，存储到st所指向的数组中。
// 下面代码将逐步找到st中的所有字母'A'。
	for(p = st;p && *p; )
	{
		p = strchr(p, 'A');
		if(p != NULL)
		{
			printf("%d %c\n",p - st, *p);
			p++;
		}
}

char *p;
	char s1[10] = "abcdef";
	char s2[10] = "abcdef";	p = strchr("abcdeaabbcde", 'e');
	printf("%p %p\n", "abcdeaabbcde", p);
	m = strcmp(s1, s2);
	printf("%d\n", m);
	strcat(s1, s2);
	printf("%s\n", s1);
	strcpy(s2,s1);
	printf("%s\n", s2);*/

	return 0;
}