#include<stdio.h>
struct work
{
	char name[100];
	float base;
	float fdgz;
	float expend;
	float sum;
 } ;
 int main()
 {
	struct work s[10];
 		int n,i,j;
 		scanf("%d",&n);
		 for(i=0;i<n;i++)
		 {
		 	scanf("%s",&s[i].name);
		 	scanf("%f",&s[i].base);
		 	scanf("%f",&s[i].fdgz);
		 	scanf("%f",&s[i].expend);
		 	s[i].sum=(s[i].base+s[i].fdgz-s[i].expend); 
		  } 
		  for(i=0;j<n;j++)
		  {
		  	printf("%s %.2f\n",s[j].name,s[j].sum); 
		   } 
		   return 0;
 }
