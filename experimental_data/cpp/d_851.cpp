#include<iostream>
#include<cstdio>
using namespace std;
int n,x,y;
bool f[1000010];
int a[500010];
int cnt[1000010];
long long ans=1e18;
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		cnt[a[i]]++;
	}
	for(int i=2;i<=1000000;i++)
	{
		if(f[i])continue;
		int s=cnt[i];
		for(int j=i+i;j<=1000000;j+=i)
		{
			f[j]=true;
			s+=cnt[j];
		}
		long long res=0;
		if(1LL*(n-s)*min(x,y)>=ans)continue;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%i==0)continue;
			int md=a[j]%i;
			res+=min(1LL*x,1LL*(i-md)*y);
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}