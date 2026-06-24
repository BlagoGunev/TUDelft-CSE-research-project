/* Heroes Never Die. */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <class T> inline void read(T &_a) {
	bool _f = 0; int _c = 0; _a = 0;
	while (_c < '0' || _c > '9') _f |= _c == '-', _c = getchar();
	while (_c >= '0' && _c <= '9') _a = _a * 10 + _c - '0', _c = getchar();
	if (_f) _a = -_a;
}

#define MAXN 200005

#define INF 0x3f3f3f3f

struct Edge {
	int nxt, v;
} e[MAXN];

int head[MAXN], ecnt = 1;

void add(int u, int v) {
	e[++ecnt] = (Edge) {head[u], v}; head[u] = ecnt;
	e[++ecnt] = (Edge) {head[v], u}; head[v] = ecnt;
}

int n;
int dp[MAXN][2];

void dfs(int x, int fa) {
	dp[x][1] = 0;
	for (int o = head[x]; o; o = e[o].nxt) {
		if (e[o].v != fa) {
			int v = e[o].v;
			dfs(v, x);
			int d0 = dp[x][0], d1 = dp[x][1];
			dp[x][0] = max(d0 + dp[v][0] + 1, d1 + dp[v][1]);
			dp[x][1] = max(d1 + dp[v][0] + 1, d0 + dp[v][1]);
		}
	}
}


int main() {
	read(n);
	if (n & 1) {
		puts("-1"); return 0;
	}
	for (int i = 1; i < n; i++) {
		int u, v; read(u); read(v); add(u, v);
	}
	
	for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = -INF;

	dfs(1, 0);

	printf("%d\n", dp[1][0]);
}