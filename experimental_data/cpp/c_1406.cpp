#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
int read() {
	char ch = getchar();
	int x = 0, pd = 0;
	while (ch < '0' || ch > '9')
		pd ^= ch == '-', ch = getchar();
	while ('0' <= ch && ch <= '9')
		x = x*10+(ch^48), ch = getchar();
	return pd ? -x : x;
}
const int maxn = 100005;
int n;
int e, bg[maxn], to[maxn<<1], nx[maxn<<1];
void link(int u, int v) {
	to[++e] = v, nx[e] = bg[u], bg[u] = e;
}
int size[maxn], maxw[maxn];
int rt1, rt2, t1, t2;
bool ck[maxn];
void dfs(int u, int fa) {
	size[u] = 1, maxw[u] = 0;
	for (int i = bg[u]; i; i = nx[i]) {
		int v = to[i];
		if (v == fa || ck[v]) continue;
		dfs(v, u);
		size[u] += size[v];
		maxw[u] = max(maxw[u], size[v]);
	}
	if (size[u] == 1) t1 = u, t2 = fa;
	maxw[u] = max(maxw[u], n - size[u]);
	if (maxw[u] < maxw[rt1]) rt1 = u;
	else if (maxw[u] == maxw[rt1]) rt2 = u;
}
int main() {
	int T = read();
	maxw[0] = 0x3f3f3f3f;
	while (T--) {
		n = read();
		e = 0;
		for (int i = 1; i <= n; i++)
			bg[i] = ck[i] = 0;
		for (int i = 1; i < n; i++) {
			int x = read(), y = read();
			link(x, y), link(y, x);
		}
		rt1 = rt2 = 0;
		dfs(1, -1);
		if (maxw[rt1] != maxw[rt2]) {
			printf("%d %d\n%d %d\n", 1, to[bg[1]], 1, to[bg[1]]);
		}
		else {
			ck[t1] = 1;
			printf("%d %d\n%d ", t1, t2, t1);
			rt1 = rt2 = 0;
			dfs(1, -1);
			printf("%d\n", rt1);
		}
	}
	return 0;
}