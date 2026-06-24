#include "stdio.h"
#include <string.h>
char str[1000001];
int p[1000001];
int main()
{
    int i,k,ans,m,t;
    scanf("%d%d%s",&m,&t,str);
    {
		p[0]=-1;
		for(i=1;i<m;i++)
		{
			k=i-1;
			while(k!=-1&&str[i]!=str[p[k]+1])
			k=p[k];
			if(k==-1)p[i]=-1;
			else p[i]=p[k]+1;
		}
		for(i=0;i<m;i++)
		{
			int d=i-p[i];
			int x=(i+1)/d;
			if(x<t)putchar('0');
			else
			{
				int y=x/t,z=x%t;
				if(y*d>=z*d+(i+1)%d)putchar('1');
				else putchar('0');
			}
			//printf("i:%d d:%d x:%d \n",i,d,x);
		}
    }
}