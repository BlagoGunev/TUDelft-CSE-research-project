#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,c,t;
struct node
{
	int tim;
	int cost;
	int re;
	bool operator < (const node & b)const
	{
		return tim<b.tim;
	}
}m[1005];
int main()
{
	while(~scanf("%d%d%d%d%d",&n,&a,&b,&c,&t))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m[i].tim);
			m[i].cost=a;
			m[i].re=0;
		}
		sort(m+1,m+1+n);
		int ans=0;
		if(c>=b)
		{
			for(int i=1;i<=n;i++)
				ans+=a+(c-b)*(t-m[i].tim);
		}
		else
		{
			ans=n*a;
		}
		printf("%d\n",ans);
	}
	return 0;
}