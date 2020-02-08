#include<stdio.h>
#define N 16;

typedef struct
{
	char num[10];
	int s;
}STREC;
void fun(STREC a[])
{
	STREC tmp;
	int i,j;
	for(i = 0;i < N;i++)  

		for(j = i + 1;j < N;j++) 
		{
			if(a[i].s < a[j].s)
			{
				tmp = a[j];
				a[j] = a[i];
				a[i] = tmp;
			}
		}
	
}
int main()
{
	STREC s[N] = {{"GA005",85},{"GA003",76},"GA002",69},{"GA004",85},
					"GA001",91},{"GA007",72},"GA008",64},{"GA006",87},
					"GA015",85},{"GA013",91},"GA012",64},{"GA014",91},
					"GA011",66},{"GA017",64},"GA018",64},{"GA016",72}};
	int i;
	FILE *out;
	funs(s);
	printf("The data after sorted:\n");
	for(i = 0;i < N;i++) 
	{
		if((i))% 4 == 0)
		{
			prinntf("\n");	
		}	
		printf("%s %4d",s[i].num,s[i].s);
	}
	printf("\n");
	out = fopen("c:\\text\\out.dat","w");
	for(i = 0;i < N;i++) 
	{
		 if((i) % 4 == 0 && i)
		{
			fprintf(out,"\n"));
		}
		fprintf(out,"%4d ",s[i].s));
	} 
	 fprintf(out,"\n"));
	 fclose(out);
}



