#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define fi first 
#define se second 
typedef long long ll;
#define maxn 201000
int n, m, a[maxn];
struct edge{
	int to, nxt;
};
edge e[maxn*2];
pair<int, int> edges[maxn];
int nxt[maxn];
int l;
void add_edge(int x, int y){
	e[++l] = (edge){y, nxt[x]}; nxt[x] = l;
	e[++l] = (edge){x, nxt[y]}; nxt[y] = l;
}
ll f[maxn];
int fa[maxn];
bool b[maxn];
void dfs(int u, int father = 0){
	fa[u] = father;
	b[u] = 1;
	for (int i=nxt[u]; i; i=e[i].nxt){ 
		int v = e[i].to;
		if (v == father) continue;
		if (!b[v]) dfs(v, u);
		f[u] = max(f[u], f[v]);
	}
	f[u] += a[u];
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i=1;i<=n;i++) scanf("%d", a+i);
	for (int i=1;i<=m;i++) {
		int u,v;
		scanf("%d%d", &u, &v); 
		add_edge(u, v);
		edges[i] = make_pair(u, v);
	}
	int s;
	scanf("%d", &s);
	dfs(s);
	memset(b, 0, sizeof(b));
	ll ans = 0;
	ans += a[s]; 
	b[s] = 1;
	for (int i=1;i<=m;i++) {
		int u =edges[i].fi, v = edges[i].se;
		if (fa[u] == v || fa[v] == u) continue;
		while (!b[u]) {b[u] = 1; ans += a[u]; u = fa[u];}
		while (!b[v]) {b[v] = 1; ans += a[v]; v = fa[v];}
	}
	ll mx = 0;
	for (int i=1;i<=n;i++) { 
		if (!b[i]) mx = max(f[i], mx);
	}
	printf("%I64d\n", ans+mx);
	return 0;
}