#include<bits/stdc++.h>
#define re read()
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){f=ch=='-'?-1:1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int a[1005];
int main()
{
	int n,m;
	n=re;m=re;
	if (n>m)
	{
		puts("0");
		return 0;
	}
	for (int i=1;i<=n;i++)
		a[i]=re;
	long long ans=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			int t=abs(a[i]-a[j]);
			ans=ans*t;
			ans%=m;
		}
	}
	printf("%lld\n",ans);
}