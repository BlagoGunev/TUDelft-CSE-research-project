#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long ans;
int s1,s0,s2;
int main()
{
	scanf("%d",&n);
	int x;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		if (!x)
		{
			s0++;
			continue;
		}
		if (x>0)
		{
			ans+=x-1;
			s1++;
		}
		else
		{
			ans+=-1-x;
			s2++;
		}
	}
	if (s2%2&&s0==0)
		ans+=2;
	else
		ans+=s0;
	printf("%lld",ans);
	return 0;
}