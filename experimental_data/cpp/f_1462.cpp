# include <stdio.h>
# include <iostream>
# include <string.h>
# include <string>
# include <algorithm>
# include <math.h>
# include <queue>
# include <deque>
# include <climits>
# include <stack>
using namespace std;
struct seg
{
	int l,r;
	bool operator <(const seg x)const
	{
		return l<x.l;
	}
}a[200001];
int n;
int l[200001];
int c[200001];
int ans1[200001],ans2[200001];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y)
{
	for(int i=x;i<=n;i+=lowbit(i))
		c[i]+=y;
}
int sum(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		ans+=c[i];
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
			c[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&a[i].l,&a[i].r);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			l[i]=a[i].l;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int p=upper_bound(l+i,l+n+1,a[i].r)-l;
			ans1[i]=p-i;
			ans2[i]=sum(n)-sum(i-1);
			add(ans1[i]+i-1,1);
		}
		for(int i=1;i<=n;i++)
			ans=max(ans,ans1[i]+ans2[i]);
		printf("%d\n",n-ans);
	}
	return 0;
}