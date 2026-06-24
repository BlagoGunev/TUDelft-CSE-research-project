#include<stdio.h>
#include<string.h>
char a[100005];
int n,k,i,dis,dir;
int main()
{
	while(~scanf("%d%d%s",&n,&k,a))
	{
		a[n]='\0';
		for(i=0;i<n;i++)
		{
			dir= 'z'-a[i]>=13?1:-1;
			dis= 'z'-a[i]>=13?'z'-a[i]:a[i]-'a';
			if(k>dis)
			{
				k-=dis;
				a[i]=a[i]+dis*dir;
			}
			else
			{
				a[i]=a[i]+k*dir;
				k=0;
				break;
			}
		}
		if(k>0)
			printf("-1\n");
		else
			puts(a);
	}
}