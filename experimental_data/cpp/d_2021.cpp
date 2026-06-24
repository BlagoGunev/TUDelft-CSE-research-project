#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a[200005];
int dp[200005];
int pre[200005];
const int inf=0x3f3f3f3f3f3f3f3f;
struct node
{
	int l,r,v;
	node operator + (const node a) const
	{
		return {max(l,a.l),max(r,a.r),max({v,a.v,l+a.r})};
	}
};
void test()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i].clear();
		a[i].push_back(0);
		for(int j=1;j<=m;j++)
		{
			int x;
			cin>>x;
			a[i].push_back(x);
		}
		for(int j=1;j<=m;j++)
			a[i][j]+=a[i][j-1];
	}
	int minpre=inf;
	for(int i=0;i<=m;i++)
	{
		dp[i]=a[1][i]-minpre;
		minpre=min(minpre,a[1][i]);
	}
	int maxsuf=-inf;
	for(int i=m;i>=0;i--)
	{
		dp[i]=max(dp[i],maxsuf-a[1][i]);
		maxsuf=max(maxsuf,a[1][i]);
	}
//	for(int j=0;j<=m;j++)
//		cout<<"1 "<<j<<" "<<dp[j]<<"\n";
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
			pre[j]=dp[j];
		for(int j=0;j<=m;j++)
			dp[j]=-inf;
		node cur={-inf,-inf,-inf};
		for(int j=0;j<=m;j++)
		{
			dp[j]=max(dp[j],cur.v+a[i][j]);
			cur=cur+(node){-a[i][j],pre[j],-inf};
//			cout<<"pre to "<<j<<":"<<cur.l<<" "<<cur.r<<" "<<cur.v<<"\n";
		}
		cur={-inf,-inf,-inf};
		for(int j=m;j>=0;j--)
		{
			dp[j]=max(dp[j],cur.v-a[i][j]);
			cur=(node){pre[j],a[i][j],-inf}+cur;
//			cout<<"suf to "<<j<<":"<<cur.l<<" "<<cur.r<<" "<<cur.v<<"\n";
		}
//		for(int j=0;j<=m;j++)
//			cout<<i<<" "<<j<<" "<<dp[j]<<"\n";
	}
	int maxn=-inf;
	for(int i=0;i<=m;i++)
		maxn=max(maxn,dp[i]);
	cout<<maxn<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
		test();
}