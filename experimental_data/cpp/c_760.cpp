#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <map>
#include <queue>
#include <set>
#define OJ
#define PROB "C"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000007;
const int maxn = 200005;

//struct edge_T {int to, next;} edge[maxn<<1];

inline int getint() {
	int r = 0; bool b = true; char c = getchar();
	while ('0' > c || c > '9') {if (c == '-') b = false; c = getchar();}
	while ('0' <= c && c <= '9') {r = r * 10 + (c - '0'); c = getchar();}
	if (b) return r;
	return -r;
}
bool vis[maxn];
int a[maxn], b[maxn];
void dfs(int now) {
	if (vis[now]) return;
	vis[now] = true;
	dfs(a[now]);
}
int n;
int calc() {
	int ret = 0;
	for (int i = 1; i <= n; ++i) if (!vis[i]) {
		dfs(i);
		++ret;
	}
	return ret;
}

int main() {
#ifndef OJ
	freopen(PROB".in", "r", stdin);
	freopen(PROB".out", "w", stdout);
#endif

	n = getint();
	for (int i = 1; i <= n; ++i)
		a[i] = getint();
	int o = 0, z = 0;
	for (int i = 1; i <= n; ++i) {
		b[i] = getint();
		if (b[i] == 1) ++o;
		if (b[i] == 0) ++z;
	}
	int ans = 0;
	if (o & 1) ans = 0;
	else ans = 1;
	int tmp = calc();
	if (tmp == 1) printf("%d\n", ans);
	else printf("%d\n", ans + tmp);

	fclose(stdin);
	fclose(stdout);

	return 0;
}