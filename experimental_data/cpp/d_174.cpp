//#define FILEIO

#define INPUT "in"
#define OUTPUT "out"

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cassert>

#define mp make_pair
#define pb push_back
#define foreach(i,T) for(__typeof(T.begin()) i = T.begin(); i != T.end(); ++i)

using namespace std;

namespace Solve {
	const int MAXN = 100010;

	struct Edge {
		int y; Edge *next, *opt; bool flag;
		Edge(int y, Edge *next, bool f = false):y(y), next(next), flag(f){}
	}*a[MAXN];

	inline int ScanInt(void) {
		int r = 0, c, d;
		while (!isdigit(c = getchar()) && c != '-');
		if (c != '-') r = c - '0'; d = c;
		while ( isdigit(c = getchar())) r = r * 10 + c - '0';
		return d=='-'?-r:r;
	}

	int n, m, c[MAXN], d[MAXN];
	bool vis1[MAXN], vis2[MAXN];

	inline void Bfs(int u, bool vis[], bool f) {
		int head = 1, tail = 1; d[1] = u;
		vis[u] = true;
		while (head <= tail) {
			int now = d[head++]; if (f == false && c[now] == 1) continue;
			for (Edge *p = a[now]; p; p = p->next) if (p->flag == f)
				if (!vis[p->y])
					vis[d[++tail] = p->y] = true;
		}
	}

	inline void solve(void) {
		n = ScanInt(), m = ScanInt();
		for (int i = 1; i <= n; i++) scanf("%d", c + i);
		while (m--) {
			int x = ScanInt(), y = ScanInt();
			a[x] = new Edge(y, a[x], true);
			a[y] = new Edge(x, a[y]);
			a[x]->opt = a[y];
			a[y]->opt = a[x];
		}
		for (int i = 1; i <= n; i++) if (c[i] == 1 && !vis1[i])
			Bfs(i, vis1, true);
		for (int i = 1; i <= n; i++) if (c[i] == 2 && !vis2[i])
			Bfs(i, vis2, false);
		for (int i = 1; i <= n; i++) {
			if (vis1[i] && vis2[i])
				puts("1");
			else
				puts("0");
		}
	}
}

int main(void) {
	#ifdef FILEIO
		freopen(INPUT, "r", stdin);
//c		freopen(OUTPUT, "w", stdout);
	#endif
	Solve::solve();
	return 0;
}