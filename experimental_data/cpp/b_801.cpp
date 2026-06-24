/*#include<stdio.h>
#include<string.h>
int main()
{
	char string[101],temp[101];
	while(~scanf("%s",string))
	{
		int i,len=strlen(string),res=0,num=0;
		for(i=0;i<len;i+=2)
			if(i!=len-1)
				if(string[i]=='V'&&string[i+1]=='K')
					res++;
				else
				{
					temp[num++]=string[i];
					temp[num++]=string[i+1];
				}
			else
				temp[num++]=string[i];
		int v=0,k=0;
		for(i=0;i<num;i++)
		{
			if(temp[i]=='V')
				v++,k=0;
			else
				k++,v=0;
			if(v==2)
			{
				res++;
				break;
			}
			if(k==3)
			{
				res++;
				break;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
#define min(x,y) ((x)<(y)?(x):(y))
int main()
{
	char x[102],z[102],y[102];
	while(~scanf("%s%s",x,z))
	{
		int i,len=strlen(x),flag=0;
		for(i=0;i<len;i++)
			if(x[i]!=z[i]&&min(x[i],z[i])==x[i])
			{
				flag=1;
				break;
			}
			else if(x[i]==z[i])
				y[i]='z';
			else
				y[i]=z[i];
			y[i]=0;
		if(flag)
			printf("-1\n");
		else
			printf("%s\n",y);
	}
	return 0;
}