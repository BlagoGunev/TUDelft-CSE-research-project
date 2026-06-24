#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 3e5 + 5;

int n, a, b, tot = 0, head[N], fa[N], siz[N];

struct Edge {
	int to, nxt;
} e[N << 1];

inline void add(int from, int to) {
	e[++tot].to = to;
	e[tot].nxt = head[from];
	head[from] = tot;
} 

inline void read(int &X) {
	X = 0;
	char ch = 0;
	int op = 1;
	for(; ch > '9' || ch < '0'; ch = getchar())
		if(ch == '-') op = -1;
	for(; ch >= '0' && ch <= '9'; ch = getchar())
		X = (X << 3) + (X << 1) + ch - 48;
	X *= op;
}

void dfs(int x, int fat) {
	fa[x] = fat;
	siz[x] = 1;
	for(int i = head[x]; i; i = e[i].nxt) {
		int y = e[i].to;
		if(y == fat) continue;
		dfs(y, x);
		siz[x] += siz[y];
	}
}

int main() {
	read(n), read(a), read(b);
	for(int x, y, i = 1; i < n; i++) {
		read(x), read(y);
		add(x, y), add(y, x);
	}
	dfs(a, 0);
	ll ans = (ll)n * (n - 1);
	ll tmp = b;
	for(; fa[tmp] != a; tmp = fa[tmp]);
	ans -= (ll) siz[b] * (siz[a] - siz[tmp]);
	printf("%lld", ans);
	return 0;
}