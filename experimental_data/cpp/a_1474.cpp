#include<stdio.h>
#include<string.h>
int main()
{
	int t,n,w,m;
	char a[100010],b[100010];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",a);
		memset(b,0,sizeof(b));
		w=a[0]-'0';
		b[0]='1';
		w+=1;
		for(int i=1;i<n;i++)
		{
			m=a[i]-'0';
			m+=1;
			if(m!=w)
			{
				b[i]='1';
				w=m;
			}
			else
			{
			b[i]='0';
			w=m-1;
		}
		 } 
		 printf("%s\n",b);
	}
 }