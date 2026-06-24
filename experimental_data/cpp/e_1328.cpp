#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;

ll mod = 998244353;
const int maxn = 2e5 + 777;
int head[maxn];
struct Node {
	int to;
	int next;
}G[2 * maxn];
int n, m;
int z = 0;
void add(int be, int en) {
	G[++z].to = en;
	G[z].next = head[be];

	head[be] = z;
}
int dep[maxn];
int fa[maxn];
int top[maxn], son[maxn], siz[maxn];


int dfs(int x, int f, int d) {
	dep[x] = dep[f] + 1;
	fa[x] = f;
	siz[x] = 1;
	int s = 0;
	for (int i = head[x]; i; i = G[i].next) {
		int p = G[i].to;
		if (p == f) continue;
		dfs(p, x, d + 1);
		siz[x] += siz[p];
		if (s < siz[p]) {
			s = siz[p];
			son[x] = p;
		}
	}
	return 0;
}

int dfs2(int x, int t) {
	top[x] = t;
	if (son[x]) dfs2(son[x], t);
	for (int i = head[x]; i; i = G[i].next) {
		int p = G[i].to;
		if (p == fa[x] || p == son[x]) continue;
		dfs2(p, p);
	}
	return 0;
}

int LCA(int x, int y) {
	for (; top[x] != top[y];) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);//利用二进制的 swap() 
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	return x;
}
int list[maxn];
int get(int x, int y) {
	int root = LCA(x, y);
	int d = dep[x] + dep[y] - 2 * dep[root];
	return d;
}
int main() {
	
	scanf("%d %d", &n, &m);
	int be, en;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &be, &en);
		add(be, en);
		add(en, be);
	}
	dfs(1, -1, 0);
	dfs2(1, 1);
	int k;
	while (m--) {
		en = 0;//最大深度
		int u = 0;//
		scanf("%d", &k);
		for (int i = 1; i <= k; i++) {
			scanf("%d", &list[i]);
			if (en < dep[list[i]]) {
				en = dep[list[i]];
				u = list[i];
			}
		}
		int flag = 0;
		for (int i = 1; i <= k; i++) {
			int cn = get(u, list[i]);
			if (dep[list[i]] + cn == dep[u] || dep[list[i]] + cn == dep[u] + 2) {
			}
			else {
				flag = 1;
			}
		}
		if (flag) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}