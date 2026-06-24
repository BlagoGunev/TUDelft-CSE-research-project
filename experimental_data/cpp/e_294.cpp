#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <bitset>
#include <queue>
#include <set>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

#define LL long long
#define ULL unsigned long long
#define eps 1e-9
#define N (100000 + 10)
#define M (200000 + 10)
#define pii pair<int,int>
#define MP make_pair
#define inf 0x3f3f3f3f
#define md (ll+rr>>1)
#define lson ll, md, ls
#define rson md + 1, rr, rs
#define ls i<<1
#define rs i<<1|1
#define mod 1000000007
#define Pi acos(-1.0)


int fst[N], vv[M], nxt[M], cost[M],e;
void init() {
	memset(fst, -1, sizeof fst);
	e = 0;
}

void add(int u, int v, int w) {
	vv[e] = v, nxt[e] = fst[u], cost[e] = w, fst[u] = e++;
}

LL s[N], tot[N];
int sz[N];
int tn;

void dfs(int u, int p) {
	sz[u] = 1;
	s[u] = tot[u] = 0;
	for(int i = fst[u]; ~i; i = nxt[i]) {
		int v = vv[i];
		if(v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
		s[u] += s[v] + (LL) cost[i] * sz[v];
	}
	for(int i = fst[u]; ~i; i = nxt[i]) {
		int v = vv[i];
		if(v == p) continue;
		tot[u] += tot[v] + (LL)(sz[u]-sz[v]) * sz[v] * cost[i] + s[v] * (sz[u] - sz[v]);
	}
}

LL cal(int u, int p, LL sum) {
	LL ret = sum + s[u];
	for(int i = fst[u]; ~i; i = nxt[i]) {
		int v = vv[i];
		if(v == p) continue;
		ret = min(ret, cal(v, u, sum + s[u] - s[v] - (LL)sz[v] * cost[i] + (LL)(tn-sz[v]) * cost[i]));
	}
	return ret;
}

int a[N], b[N], c[N];
int main() {
	int n;
	scanf("%d", &n);

	init();
	for(int i = 1; i < n; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		a[i] = u, b[i] = v, c[i] = w;
		add(u, v, w);
		add(v, u, w);
	}
	LL ans = 1LL<<60;
	for(int i = 1; i < n; ++i) {
		dfs(a[i], b[i]);
		dfs(b[i], a[i]);
		tn = sz[a[i]];
		LL t1 = cal(a[i], b[i], 0);
		tn = sz[b[i]];
		LL t2 = cal(b[i], a[i], 0);
		ans = min(ans, tot[a[i]] + tot[b[i]] + (LL) c[i] * sz[a[i]] * sz[b[i]] + t1 * sz[b[i]] + t2 * sz[a[i]]);
	}
	printf("%I64d\n", ans);
}