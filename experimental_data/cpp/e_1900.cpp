#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,x,y) for(register int i=x;i<=y;i++)
#define rep1(i,x,y) for(register int i=x;i>=y;--i)
#define fire signed
#define il inline
il void intt(int &x) {
	x=false;
	char c=getchar();
	int f=1;
	while(c>'9'||c<'0') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=x*10+c-'0';
		c=getchar();
	}
	x*=f;
}
int T;
const int N=2e5+10;
int n,m;
ll a[N];
int dis[N];
ll f[N];
vector<int>v[N],g[N];
int c;
int h[N];
int vis[N]; 
int dfn[N],low[N],is[N],idx;
stack<int>s;
int val[N],cnt[N],tot;
ll vv[N];
il void tarjan(int x) {
	dfn[x]=low[x]=++idx;
	is[x]=1;
	s.push(x);
	for(auto to:v[x]) {
		if(!dfn[to]) tarjan(to),low[x]=min(low[x],low[to]);
		else if(is[to]) low[x]=min(low[x],dfn[to]);
	}
	if(low[x]==dfn[x]) {
		tot++;
		int p;
		do{
			p=s.top();
			s.pop();
			is[p]=false;
			val[p]=tot;
			cnt[tot]++;
			vv[tot]+=a[p];
		}while(p!=x);
	}
}
int in[N];
il void top() {
	queue<int>q;
	rep(i,1,tot) dis[i]=false,f[i]=INT_MAX;
	rep(i,1,tot) {
		if(!in[i]) {
			q.push(i);
			dis[i]=cnt[i];
			f[i]=vv[i];
		}
	}
	while(q.size()) {
		int x=q.front();
		q.pop();
		for(auto to:g[x]) {
			if(dis[to]<dis[x]+cnt[to]) {
				dis[to]=dis[x]+cnt[to];
				f[to]=f[x]+vv[to];
			}else if(dis[to]==dis[x]+cnt[to]) f[to]=min(f[x]+vv[to],f[to]);
			--in[to];
			if(!in[to]) q.push(to);
		}
	}
}
il void solve() {
	tot=idx=false;
	intt(n),intt(m);
	rep(i,1,n) cin>>a[i];
	rep(i,1,n) dfn[i]=low[i]=is[i]=cnt[i]=val[i]=vv[i]=in[i]=false,v[i].clear(),g[i].clear();
	rep(i,1,m) {
		int x,y;
		intt(x),intt(y);
		if(x!=y) v[x].push_back(y);
	}
	rep(i,1,n) if(!dfn[i]) idx=false,tarjan(i);
	rep(i,1,n) {
		for(auto to:v[i]) {
			if(val[i]!=val[to]) {
				g[val[i]].push_back(val[to]);
				in[val[to]]++;
			}
		}
	} 
	top();
	int Max=false;
	ll id=INT_MAX;
	rep(i,1,tot) {
		if(Max<dis[i]) Max=dis[i],id=f[i];
		else if(Max==dis[i]) id=min(id,f[i]);
	}
	printf("%d %lld\n",Max,id);
	return;
}
fire main() {
	intt(T);
	while(T--) solve();
	return false;
}
/*
1
5 6
2 2 4 1 3
1 2
1 3
2 4
3 4
4 5
5 2
*/