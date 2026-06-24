#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int maxk=3e5+10;
const int maxN=1e6+10;
int t;
int n,m,k;
int x[maxn],y[maxn];
struct node
{
	int x, y;
}a[maxk];
bool cmp1(node a,node b) {return a.x<b.x || a.x==b.x && a.y<b.y;}
bool cmp2(node a,node b) {return a.y<b.y || a.y==b.y && a.x<b.x;}
int xian[maxN];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>n>>m>>k;
		for (int i=1;i<=n;i++) cin>>x[i];
		for (int i=1;i<=m;i++) cin>>y[i];
		for (int i=1;i<=k;i++) cin>>a[i].x>>a[i].y;
		sort(a+1,a+k+1,cmp1);
		int now=0;
		ll ans=0;
		for (int I=1;I<n;I++)
		{
			while (a[now].x==x[I] && now<=k) now++;
			int flag=now,num=0;
			while (a[now].x<x[I+1] && now<=k)
			{
				xian[a[now].y]++;
				now++;num++;
			}
			for (int i=flag;i<now;i++)
				ans=ans+num-1-(xian[a[i].y]-1);
			for (int i=flag;i<now;i++) xian[a[i].y]=0;
		}

		sort(a+1,a+k+1,cmp2);now=0;
		for (int I=1;I<m;I++)
		{
			while (a[now].y==y[I] && now<=k) now++;
			int flag=now,num=0;
			while (a[now].y<y[I+1] && now<=k)
			{
				xian[a[now].x]++;
				now++;num++;
			}
			for (int i=flag;i<now;i++)
				ans=ans+num-1-(xian[a[i].x]-1);
			for (int i=flag;i<now;i++) xian[a[i].x]=0;
		}

		cout<<ans/2<<endl;
		for (int i=1;i<=n;i++) x[i]=0;
		for (int i=1;i<=m;i++) y[i]=0;
		for (int i=1;i<=k;i++) a[i].x=a[i].y=0;

	}
	return 0;
}