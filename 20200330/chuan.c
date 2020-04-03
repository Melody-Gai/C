//将串r中所有其值为ch1的字符换成ch2的字符
void chage(char *r,char ch1,char ch2)
{
	for(int i=0;i<max;i++)//max为定义r数组最大的值
	{
		if(r[i]==ch1)
		r[i]=ch2;
	}
}

//删除r中值为ch
void del(char *r,char ch)
{
	int count=max;//标记删除表后的实际长度
	for(int i=0;i<count;i++)
	{
		if(r[i]==ch)
		{
			for(int t=i;t<count;t++)
			r[i]=r[i+1];
		}
		count--;
	}
	if(count=max)
	cout<<"r中无ch!";
}

//从串r1中第index个字符起求出首次与字符r2相同的子串的起始位置
int indexW(char *r,char *r2,int index)
{
	int k,j,a;
	for( a=index-1;r[a];a++)
	for( k=0,j=a;r[j]==r2[k];k++,j++)
	if(r2[k+1]==NULL)
	return j;
	cout<<"不存在";
	return 0;
}





typedef unsigned char SString[MAXSTRLEN+1];  
/* s[0] is the string's length */

Status Replace(SString& s, SString t, SString v)
/* 用串v替换串s中所有和串t匹配的子串。  */
/* 若有与t匹配的子串被替换，则返回TRUE；*/
/* 否则返回FALSE                        */
{
    int i,j,k,b,p,pos,flag;
    i = 1;
    flag = 0;
    k = t[0] - v[0];        //串t与串v的长度差
    while(i <= s[0]-t[0]+1){
        j = 1;
        pos = i;         //记录当前模式串的位置
        while(j <= t[0]){
            if(s[pos] == t[j]){//模式串匹配
                ++j;
                ++pos;
            }
            else
                break;
        }
        if(j > t[0]){    //模式串匹配成功，进行替换操作 
            if(k == 0){   //串t与串v的长度相等
                for(j = 1,p = i;j <= v[0];++p,++j){
                    s[p] = v[j];                  
                }
            }
            if(k > 0){//串t的长度大于串v的长度
                for(j = 1,p = i;j <= v[0];++p,++j){
                    s[p] = v[j];                  
                }
                for(p = pos;p <= s[0];++p){//被替换子串后的元素往前移
                    s[p-k]=s[p];
                }
                s[0] = s[0] - k;//当前主串长度改变
            }
            if(k < 0){//串t的长度小于串v的长度
                for(p = s[0]; p >= i;--p){ //被替换子串后的元素往后移
                    s[p-k] =s[p];
                }
                for(j = 1,p = i;j <= v[0];++p,++j){
                    s[p] = v[j];                   
                }
                s[0] = s[0] - k;//当前主串长度改变
            }            
            flag = 1;      //匹配成功，标记为1               
        }
        else 
            ++i;          //模式串匹配不成功，模式串向后移
    }
    if(flag)
        return TRUE;
    else
        return FALSE;    
}