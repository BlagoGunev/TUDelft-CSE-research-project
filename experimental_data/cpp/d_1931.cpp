#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m;
inline void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		int n,x,y;
		cin>>n>>x>>y;
		vector<int> a(n+1);
		map<int,map<int,int> > p;
		for(int i=1; i<=n; i++)
			cin>>a[i];
		for(int i=1; i<=n; i++)
			p[a[i]%x][a[i]%y]++;
		int cnt=0;
		for(int i=1; i<=n; i++)
		{
			if (a[i]%x==0)
				cnt+=p[a[i]%x][a[i]%y]-1;
			else
			{
				if (x-a[i]%x==a[i]%x)
					cnt+=p[x-a[i]%x][a[i]%y]-1;
				else
					cnt+=p[x-a[i]%x][a[i]%y];
			}
			p[a[i]%x][a[i]%y]--;
		}
		cout<<cnt<<endl;
	}
}
signed main()
{
	init();
	return 0;
}