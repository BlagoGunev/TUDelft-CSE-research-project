#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n, a[N], b[N], c[N];
int tot = 0, lnk[N], son[N<<1], nxt[N<<1];

inline int read() {
	int red = 0, f_f = 1; char ch = getchar();
	while(ch>'9'||ch<'0') {if(ch == '-') f_f = -1; ch = getchar();}
	while(ch>='0'&&ch<='9') red = red * 10+ch-'0', ch = getchar();
	return red * f_f;
}

void add(int x, int y) { son[++tot] = y, nxt[tot] = lnk[x], lnk[x] = tot; }

void dfs1(int u, int fa) {
	a[u] = c[u];
	for(int i = lnk[u]; i; i = nxt[i]) {
		int v = son[i];
		if(v == fa) continue;
		dfs1(v, u);
		if(a[v] > 0) a[u] += a[v];
	}
}

void dfs(int u, int fa, int s) {
	s = b[u] = max(a[u], s);
	for(int i = lnk[u]; i; i = nxt[i]) {
		int v = son[i];
		if(v == fa) continue;
		if(a[v] >= 0) dfs(v, u, s);
		else dfs(v, u, s-1);
	}
}

int main()
{
	n = read();
	for(int i = 1; i <= n; i++) {
		c[i] = read();
		if(!c[i]) c[i]--;
	}
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		add(x, y); add(y, x);
	}
	dfs1(1, 0);
	dfs(1, 0, a[1]);
	for(int i = 1; i <= n; i++) printf("%d ", b[i]);
	printf("\n");
	return 0;
}