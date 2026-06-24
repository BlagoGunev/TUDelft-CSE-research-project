#include<bits/stdc++.h>

using ll = long long;
using ld = long double;

namespace GTI
{
	char gc(void)
   	{
		const int S = 1 << 16;
		static char buf[S], *s = buf, *t = buf;
		if (s == t) t = buf + fread(s = buf, 1, S, stdin);
		if (s == t) return EOF;
		return *s++;
	}
	ll gti(void)
   	{
		ll a = 0, b = 1, c = gc();
		for (; !isdigit(c); c = gc()) b ^= (c == '-');
		for (; isdigit(c); c = gc()) a = a * 10 + c - '0';
		return b ? a : -a;
	}
	int gts(char *s)
   	{
		int len = 0, c = gc();
		for (; isspace(c); c = gc());
		for (; c != EOF && !isspace(c); c = gc()) s[len++] = c;
		s[len] = 0;
		return len;
	}
	int gtl(char *s)
   	{
		int len = 0, c = gc();
		for (; isspace(c); c = gc());
		for (; c != EOF && c != '\n'; c = gc()) s[len++] = c;
		s[len] = 0;
		return len;
	}
}
using GTI::gti;
using GTI::gts;
using GTI::gtl;

int calc(int w)
{
	int ret = 0;
	while (w) ret ^= (w & 1), w >>= 1;
	return ret;
}

const int N = 1e6 + 500;
struct E
{
	struct edge{edge *nxt; int to, w;}epool[N << 1], *ep = epool, *pt[N];
	void addedge(int u, int v, int w)
	{
		++ep, *ep = (edge){pt[u], v, w}, pt[u] = ep;
		++ep, *ep = (edge){pt[v], u, w}, pt[v] = ep;
	}
	void init(int n)
	{
		memset(pt, 0, sizeof(pt[0]) * (n + 1));
		ep = epool;
	}
}e1, e2;
using edge = E::edge;

void dfs(int v, int fa = 0)
{
	for (edge *e = e1.pt[v]; e; e = e->nxt)
		if (e->to != fa)
		{
			dfs(e->to, v);
			if (e->w >= 0)
				e2.addedge(v, e->to, calc(e->w));
		}
}

int col[N];
bool vis[N];
bool ansTag;
void search(int v)
{
	vis[v] = true;
	for (edge *e = e2.pt[v]; e; e = e->nxt)
	{
		if (vis[e->to])
		{
			if ((col[e->to] ^ col[v]) != e->w)
				ansTag = false;
		}
		else
		{
			col[e->to] = (col[v] ^ e->w);
			search(e->to);
		}
	}
}
void opt(int v = 1, int fa = 0)
{
	for (edge *e = e1.pt[v]; e; e = e->nxt)
		if (e->to != fa)
		{
			if (e->w == -1)
				e->w = (col[e->to] ^ col[v]);
			printf("%d %d %d\n", v, e->to, e->w);
			opt(e->to, v);
		}
}
void solve(int n)
{
	memset(col, 0, sizeof(col[0]) * (n + 1));
	memset(vis, 0, sizeof(vis[0]) * (n + 1));
	ansTag = true;
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			search(i);
	if (ansTag) puts("YES"), opt();
	else puts("NO");
}

int main(void)
{
	for (int T = gti(); T; T--)
	{
		int n = gti(), m = gti();
		e1.init(n), e2.init(n);
		for (int i = 1; i < n; i++)
		{
			int u = gti(), v = gti(), w = gti();
			e1.addedge(u, v, w);
		}
		dfs(1);
		for (int i = 1; i <= m; i++)
		{
			int a = gti(), b = gti(), p = gti();
			e2.addedge(a, b, p);
		}
		solve(n);
	}
	return 0;
}