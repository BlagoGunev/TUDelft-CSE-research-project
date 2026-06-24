#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define fo(i, n) for(int i = 1; i <= n; ++i)

typedef long long ll;
typedef pair <int, int> pii;

const int N = 200200;
const int mod = 1e9 + 7;

ll all,n,k;
vector<ll>g[N];
ll sum[N], cnt[N];
ll rs;
vector<ll>s[N];
pair<ll,ll>res[N];

ll u,v;
ll root=-1;
ll x;

inline void dfs(int v, int p=-1)
{
	sum[v]=cnt[v]==1;
	ll w=0;
	ll z=0;
	for(int to:g[v])
	{
		if(to==p) continue;
		dfs(to,v);
		sum[v]+=sum[to];
		w+=sum[to];
		z=max(z,sum[to]);
	}
	z=max(z,all-w);
	if(z<=k)
		root=v;
}

inline void calc(int v, int p, int col=-1)
{
	int z=0;
	if(v!=root&&cnt[v]==1)
		s[col].pb(v);
	for(int to:g[v])
	{
		if(to==p) continue;
		z++;
		if(v==root)
			calc(to,v,z);
		else
			calc(to,v,col);
	}
	if(v==root)
	{
		multiset<pair<ll, ll>> q;
		for(int i=1;i<=z;++i)
			if(s[i].size()>0) q.insert(mp(-s[i].size(), i));
		while(q.size()>=2)
		{
			int a=q.begin()->S;
			auto it=q.begin(); it++;
			int b=it->S;
			q.erase(q.begin());
			q.erase(q.begin());
			int cnt=1;
			for(int i=0;i<cnt;++i)
			{
				int x=s[b].back();
				int y=s[a].back();
				res[++rs] = mp(x,y);
				s[b].pop_back();
				s[a].pop_back();
			}
			if(s[a].size()) q.insert(mp(-s[a].size(), a));
			if(s[b].size()) q.insert(mp(-s[b].size(), b));
		}
		if(q.size()==1)
		{
			int a=q.begin()->S;
			int x=s[a].back();
			res[++rs]=mp(x,v);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>k;
	fo(i,n-1)
	{
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	all=k+k;
	fo(i,k+k)
	{
		cin>>x;
		cnt[x]++;
	}
	dfs(1);
	assert(root!=-1);
	calc(root,-1);
	assert(rs==k);
	cout << "1\n";
	cout << root << "\n";
	for(int i = 1; i <= k; ++i)
		cout << res[i].F<<' '<<res[i].S<<" "<<root << "\n";
	return 0;	
}