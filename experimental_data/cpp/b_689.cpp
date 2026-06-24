#include <bits/stdc++.h>
using namespace std;

const int Maxn = 222222;
struct edge {
	int v;
	edge *nxt;
} pool[Maxn*3], *g[Maxn], *tail = pool;

int n, q[Maxn], l, r, dist[Maxn];
bool visited[Maxn];

inline int getint() {
	int c = getchar(), ret = 0;
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret = ret*10+c-48;
		c = getchar();
	}
	return ret;
}
inline void addedge(int u, int v) {
	tail->v = v;
	tail->nxt = g[u]; g[u] = tail++;
}

int main() {
	n = getint();
	for (int i = 1; i <= n; ++i) {
		addedge(i, getint());
		if (i != n) {
			addedge(i, i+1);
		}
		if (i != 1) {
			addedge(i, i-1);
		}
	}
	l = r = 1; q[1] = 1; visited[1] = true;
	for (int i = 2; i <= n; ++i) {
		dist[i] = INT_MAX;
	}
	while (l <= r) {
		for (edge *p = g[q[l]]; p; p = p->nxt) {
			if (!visited[p->v]) {
				dist[p->v] = dist[q[l]]+1;
				visited[p->v] = true;
				q[++r] = p->v;
			}
		}
		++l;
	}
	for (int i = 1; i < n; ++i) {
		printf("%d ", dist[i]);
	}
	printf("%d\n", dist[n]);
	return 0;
}