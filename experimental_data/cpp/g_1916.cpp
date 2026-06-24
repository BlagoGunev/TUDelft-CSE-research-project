// LUOGU_RID: 149531982
#include <bits/stdc++.h>
#define PB push_back
#define EB emplace_back
#define gcd(x, y) __gcd(x, y)
using namespace std;
const int maxn = 100000;
struct edge { int v; long long w; };
vector<edge> G[maxn + 5];
bool vis[maxn + 5];
int ts, mn, rt;
int siz[maxn + 5];
void findRt(int u, int fa)
{
	siz[u] = 1;
	int mx = 0;
	for (edge it : G[u])
	{
		int v = it.v;
		if (v != fa && !vis[v])
		{
			findRt(v, u);
			siz[u] += siz[v];
			mx = max(mx, siz[v]);
		}
	}
	mx = max(mx, ts - siz[u]);
	if (mx < mn) mn = mx, rt = u;
}
long long mx;
map<long long, int> mxl, smx, id, id2;
void dfs(int u, int fa, int len, long long g, int t)
{
	mx = max(mx, 1LL * len * g);
	if (len > mxl[g])
	{
		if (t != id[g]) smx[g] = mxl[g], id2[g] = id[g];
		mxl[g] = len, id[g] = t;
	}
	else if (len > smx[g] && t != id[g])
	{
		smx[g] = len;
		id2[g] = t;
	}
	for (const auto &[v, w] : G[u])
	{
		if (v != fa && !vis[v])
		{
			dfs(v, u, len + 1, gcd(g, w), t);
		}
	}
}
long long ans;
void divide(int u, int tot)
{
	ts = tot, mn = 1E9, findRt(u, 0);
	vis[u = rt] = 1;
	mx = 0;
	mxl.clear(), smx.clear(), id.clear();
	for (const auto &[v, w] : G[u])
		if (!vis[v]) dfs(v, u, 1, w, v);
	ans = max(ans, mx);
	for (const auto &[v, l1] : mxl)
	{
		int l2 = smx[v], t = id[v], t2 = id2[v];
		if (2 * v * l1 < mx) continue;
		for (int i = 1; i <= l1; i++)
			if (mxl.count(v * i))
			{
				int l3 = id[v * i] == t ? smx[v * i] : mxl[v * i];
				ans = max(ans, 1LL * (l1 + l3) * v);
				if (i <= l2)
				{
					int l4 = id[v * i] == t2 ? smx[v * i] : mxl[v * i];
					ans = max(ans, 1LL * (l2 + l4) * v);
				}
			}
	}
	for (const auto &[v, _] : G[u])
	{
		if (!vis[v])
		{
			divide(v, siz[v] < siz[u] ? siz[v] : tot - siz[u]);
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i < n; i++)
		{
			int u, v;
			long long w;
			scanf("%d%d%lld", &u, &v, &w);
			G[u].PB({v, w}), G[v].PB({u, w});
		}
		ans = 0, divide(1, n);
		printf("%lld\n", ans);
		memset(vis + 1, 0, n * sizeof(bool));
		fill(G + 1, G + n + 1, vector<edge>());
	}
}