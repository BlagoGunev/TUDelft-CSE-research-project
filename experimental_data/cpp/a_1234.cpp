#include<cstdio>
using namespace std;
int n,T,now,sum,ans;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		sum=0;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&now);
			sum+=now;
		}
		ans=sum/n;
		if (ans*n<sum)
			++ans;
		printf("%d\n",ans);
	}
	return 0;
}