#include<bits/stdc++.h>//0xnnb
using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9') {
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
const int N = 200005, M = 32000005;
int n, q, p[N], ee, vex[N], fa[N], siz[N], son[N], pos[N], tim, top[N];
int tot, rt[N], nums[N], ch[M][2], tag[M], now[M], nowtim;
ll lastans, dis[N], sump[N], sumt[N], t[M], fw[N];
struct Node {
	int u, v, next;
	ll w;
}e[N * 2];
void add(int u, int v, ll w) {
	e[++ee].u = u, e[ee].v = v, e[ee].w = w;
	e[ee].next = vex[u], vex[u] = ee;
}
void dfs1(int u, int f) {
	fa[u] = f;
	siz[u] = 1;
	for (int i = vex[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == f)continue;
		ll w = e[i].w;
		fw[v] = w;
		dis[v] = dis[u] + w;
		dfs1(v, u);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]])son[u] = v;
	}
}
void dfs2(int u, int tp) {
	top[u] = tp;
	pos[u] = ++tim;
	nums[tim] = u;
	if (!son[u])return;
	dfs2(son[u], tp);
	for (int i = vex[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == fa[u] || v == son[u])continue;
		dfs2(v, v);
	}
}
void up(int p, int l, int r) {
	t[p] = t[ch[p][0]] + t[ch[p][1]] + tag[p] * (sumt[r] - sumt[l - 1]);
}
void clone(int& p) {
	if (now[p] == nowtim)return;
	tag[++tot] = tag[p];
	t[tot] = t[p];
	ch[tot][0] = ch[p][0];
	ch[tot][1] = ch[p][1];
	now[tot] = nowtim;
	p = tot;
}
void upd(int& p, int l, int r, int xl, int xr) {
	clone(p);
	if (xl <= l && r <= xr) {
		tag[p]++;
		up(p, l, r);
		return;
	}
	int mid = (l + r) >> 1;
	if (xl <= mid)upd(ch[p][0], l, mid, xl, xr);
	if (xr > mid)upd(ch[p][1], mid + 1, r, xl, xr);
	up(p, l, r);
}
ll ask(int p, int l, int r, int xl, int xr, ll sum) {
	if (xl <= l && r <= xr) {
		return t[p] + sum * (sumt[r] - sumt[l - 1]);
	}
	int mid = (l + r) >> 1;
	if (xr <= mid)return ask(ch[p][0], l, mid, xl, xr, sum + tag[p]);
	if (xl > mid)return ask(ch[p][1], mid + 1, r, xl, xr, sum + tag[p]);
	return ask(ch[p][0], l, mid, xl, xr, sum + tag[p]) + ask(ch[p][1], mid + 1, r, xl, xr, sum + tag[p]);
}
void upd2(int& rt, int u) {
	nowtim++;
	while (u) {
		upd(rt, 1, n, pos[top[u]], pos[u]);
		u = fa[top[u]];
	}
}
ll ask2(int rt, int u) {
	ll sum = 0;
	while (u) {
		sum += ask(rt, 1, n, pos[top[u]], pos[u], 0);
		u = fa[top[u]];
	}
	return sum;
}
ll solve1(int l, int r, int u) {
	ll ans = dis[u] * (r - l + 1);
	ans += sump[r] - sump[l - 1];
	ans -= (ask2(rt[r], u) - ask2(rt[l - 1], u)) * 2;
	return ans;
}
void solve2(int x) {
	swap(p[x], p[x + 1]);
	sump[x] = sump[x - 1] + dis[p[x]];
	if (tot >= 30000000) {
		tot = 0;
		for (int i = 1; i <= n; i++) {
			rt[i] = rt[i - 1];
			upd2(rt[i], p[i]);
		}
		return;
	}
	rt[x] = rt[x - 1];
	upd2(rt[x], p[x]);
}
int main() {
	n = read(), q = read();
	for (int i = 1; i <= n; i++)p[i] = read();
	for (int i = 1; i < n; i++) {
		int u = read(), v = read(), w = read();
		add(u, v, w), add(v, u, w);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	for (int i = 1; i <= n; i++) {
		sump[i] = sump[i - 1] + dis[p[i]];
		sumt[i] = sumt[i - 1] + fw[nums[i]];
	}
	for (int i = 1; i <= n; i++) {
		rt[i] = rt[i - 1];
		upd2(rt[i], p[i]);
	}
	for (int qq = 1; qq <= q; qq++) {
		int op = read();
		int tmp = (lastans & ((1 << 30) - 1));
		if (op == 1) {
			int l = read() ^ tmp, r = read() ^ tmp, u = read() ^ tmp;
			lastans = solve1(l, r, u);
			printf("%lld\n", lastans);
		}
		else {
			int x = read() ^ tmp;
			solve2(x);
		}
	}
	return 0;
}