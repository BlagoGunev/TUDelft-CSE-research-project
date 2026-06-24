#include <bits/stdc++.h>
#define fi first
#define se second
#define pb emplace_back
using namespace std;
typedef long long ll;
typedef long double db;
//mt19937_64 rnd64(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 7;
int i, j, k, l, r, m, n;
ll K;
int f[N], g[N], u[N], v[N], c[N];
vector <int> d[N], p[N];
int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
void tarjan(int a)
{
	for (int b:d[a])
	{
		if (!v[b])
		{
			v[b] = v[a] + 1;
			tarjan(b);
		}
		int fa = find(a), fb = find(b);
		if (v[fb] > 0)
		{
			if (v[fb] > v[fa]) swap(fa, fb);
			f[fa] = fb;
		}
	}
	v[a] = -1;
}
void dfs(int a, int rt)
{
	for (int b:d[a])
	{
		if (find(b) != find(rt)) continue;
		if (u[b])
		{
			int c = abs(u[a] + 1 - u[b]);
			g[rt] = g[rt] ? __gcd(g[rt], c) : c;
		}
		else
		{
			u[b] = u[a] + 1;
			dfs(b, rt);
		}
	}
}
signed main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	scanf("%d %d %lld", &n, &m, &K);
	for (i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		d[a].pb(b);
	}
	iota(f+1, f+n+1, 1);
	for (i=1; i<=n; i++) if (!v[i]) v[i] = 1, tarjan(i);
	for (i=1; i<=n; i++) if (find(i) == i) u[i] = 1, dfs(i, i);
	for (i=1; i<=n; i++) p[find(i)].pb(i);
	ll ans = 0;
	for (i=1; i<=n; i++)
	{
		if (!g[i] || 2*K%g[i]) continue;
		for (j=0; j<g[i]; j++) c[j] = 0;
		for (int j:p[i]) c[u[j]%g[i]]++;
//		printf("_%d\n", g[i]);
		for (j=0; j<g[i]; j++)
		{
			int k = (j+K) % g[i];
			if (k == j) ans += 1ll * c[j] * (c[j] + 1);
			else ans += 1ll * c[j] * c[k];
		}
	}
	printf("%lld", ans/2);
	return 0;
}