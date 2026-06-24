#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
int a[2000010],b[2000010],ans[1000010];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main()
{
	int x,y,vis=0;
	n=read();
	int tmp=0,flag=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		x=read();
		x+=1000000;
//		printf("%d__%d__%d\n",a[x],a[2000000-x],x);
		if(x>1000000)
		{
			if(vis==0)
			{
				ans[tmp]=cnt*2;
				tmp++;
				cnt=0;
			}
			if(b[x]!=tmp&&a[x]==a[2000000-x])
			{
				a[x]++;
				b[x]=tmp;
				vis++;
				cnt++;
//				printf("------%d------%d------\n",x,cnt);
			}
			else
			{
				flag=1;
			}
		}
		else if(x<1000000)
		{
//			printf("%d+++%d+++%d\n",a[x],a[2000000-x],tmp);
			if(b[x]!=tmp&&a[2000000-x]==a[x]+1)
			{
				a[x]++;
				b[x]=tmp;
				vis--;
//				printf("++++++%d++++++%d++++++\n",x,vis);
			}
			else
			{
				flag=1;
			}
		}
	}
//	printf("(%d)\n",vis);
	if(vis==0)
		ans[tmp]=cnt*2;
	else
		flag=1;
	if(!flag)
	{
		printf("%d\n",tmp);
		for(int i=1;i<=tmp;i++)
		{
			printf("%d ",ans[i]);
		}
	}
	else
		printf("-1\n");
	return 0;
}
/*

*/