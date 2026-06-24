#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<iostream>
#define int long long

using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;if(ch>='a'&&ch<='z')return ch-'a';if(ch>='A'&&ch<='Z')return ch-'A';ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f; 
}

const int add=2e5+5;

int t,n,a[400005],sum[400005];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		int ans=0;
		for(int i=1;i<=2*n;i++)
			sum[i]=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			a[i]-=i;
		}
		for(int i=1;i<=n;i++)
		{
			ans+=sum[a[i]+n];
			sum[a[i]+n]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}