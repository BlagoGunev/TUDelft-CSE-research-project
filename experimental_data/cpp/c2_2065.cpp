#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+10,inf=1e15;
set<int> s;
int n,m,a[N];

void solve()
{
	s.clear();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1,tmp;i<=m;i++)
	{
		cin>>tmp;
		s.insert(tmp);
	}
	a[0]=-inf;
	for(int i=1;i<=n;i++)
	{
		int minn=inf;
		if(a[i]>=a[i-1])
		{
			minn=a[i];
		}
		auto pos=s.lower_bound(a[i]+a[i-1]);
		if(pos==s.end())
		{
			;
		}
		else
		{
			minn=min(minn,(*pos)-a[i]);
		}
		a[i]=minn;
	}
	// for(int i=1;i<=n;i++)
	// {
		// cout<<a[i]<<" ";
	// }
	// cout<<endl;
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i+1])
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	if(a[n]==inf)
	{
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
}

signed main()
{
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
  int t;
  cin>>t;
  // build();
  while(t--)
  {
    solve();
  }
  return 0;
}