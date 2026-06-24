#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<long long,long long>
#define mp make_pair
#define pb push_back
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18;
struct Convex
{
	vector <pii > stk;
	vector <double > pnt;
	double get(pii x,pii y)
	{
		if(x.fi==y.fi) return (x.se>y.se?-1e18:1e18);
		return 1.0*(y.se-x.se)/(x.fi-y.fi);
	}
	void ins(pii li)
	{
		if(!stk.size()) stk.pb(li),pnt.pb(-1e18);
		else
		{
			while(stk.size()>1&&get(li,stk.back())<pnt.back()) stk.pop_back(),pnt.pop_back();
			pnt.pb(get(li,stk.back())),stk.pb(li);
		}
	}
	int query(int y)
	{
		if(!stk.size()) return -INF;
		int pos=upper_bound(pnt.begin(),pnt.end(),(double)(y))-pnt.begin()-1;
		int res=y*stk[pos].fi+stk[pos].se;
		return res;
	}
}conv1[100005][31],conv2[100005][31];
vector <pii > g[100005];
vector <pii > lne[100005];
int n,in[100005],out[100005],all=0;
void dfs1(int u,int fa)
{
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].fi,w=g[u][i].se;
		if(v==fa) continue;
		dfs1(v,u),in[u]=max(in[u],in[v]+w);
	}
	all=max(all,in[u]);
}
void dfs2(int u,int fa,int d,int tof)
{
	out[u]=d;
	all=max(all,in[u]+out[u]);
	pii mx1=mp(-1,-1),mx2=mp(-1,-1);
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].fi,w=g[u][i].se+in[v];
		if(v==fa) continue;
		pii t=mp(w,v);
		if(t>mx1) mx2=mx1,mx1=t;
		else if(t>mx2) mx2=t;
	}
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].fi,w=g[u][i].se;
		if(v==fa) continue;
		lne[u].pb(mp(w,in[v]+w));
		int d2=d;
		if(mx1.se==v) d2=max(d2,mx2.fi);
		else d2=max(d2,mx1.fi);
		dfs2(v,u,d2+w,w);
	}
	if(out[u]) lne[u].pb(mp(tof,out[u]));
}
mt19937 rnd(114514);
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb(mp(v,w)),g[v].pb(mp(u,w));
	}
	dfs1(1,-1),dfs2(1,-1,0,0);
	for(int i=1;i<=n;i++) if(lne[i].size()>=2)
	{
		sort(lne[i].begin(),lne[i].end()); 
		for(int ti=1;ti<=30;ti++) for(int j=0;j<lne[i].size();j++)
		{
			if(rnd()%2) conv1[i][ti].ins(lne[i][j]);
			else conv2[i][ti].ins(lne[i][j]);
		}
	}
	int Q;
	cin>>Q;
	while(Q--)
	{
		int u,K;
		cin>>u>>K;
		K--;
		if(lne[u].size()==1) 
		{
			cout<<max(all,lne[u][0].fi*K+lne[u][0].se)<<"\n";
			continue;
		}
		int maxx=0;
		for(int j=1;j<=30;j++) maxx=max(maxx,conv1[u][j].query(K)+conv2[u][j].query(K));
		maxx=max(maxx,all);
		cout<<maxx<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}