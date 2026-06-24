#include <cstdio>
#include <algorithm>

int main()
{
	int q;int a[200005];
	scanf("%d",&q);
	while(q--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			a[i]=0;
		for(int i=0;i<n;++i)
		{
			int x;
			scanf("%d",&x);
			a[x]++;
		}
		std::sort(a+1,a+1+n);
		int now=a[n];long long tot=0;
		for(int i=n;i>=1;--i)
		{
			if(now>=a[i])
			{
				tot+=a[i];
				now=a[i]-1;
			}
			else
			{
				tot+=now;
				now--;
			}
			if(now<=0)
				break;
		}
		printf("%I64d\n",tot);
	}
	return 0;
}