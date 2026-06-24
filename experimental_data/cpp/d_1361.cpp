#include <bits/stdc++.h>

using namespace std;



#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)

char buf[1 << 21], *p1 = buf, *p2 = buf;



inline int qread() {

	register char c = getchar();

	register int x = 0, f = 1;

	while (c < '0' || c > '9') {

		if (c == '-') f = -1;

		c = getchar();

	}

	while (c >= '0' && c <= '9') {

		x = (x << 3) + (x << 1) + c - 48;

		c = getchar();

	}

	return x * f;

}



const int N = 500005;



struct Edge {

	int to, nxt;

	Edge() {

		nxt = -1;

	}

};

int n, k, x[N], y[N], idx[N], hd[N], dgr[N], pnt, cnt[N], siz[N], d1[N], vid[N], fa[N];

bool vis[N];

map <pair <int, int>, int> mp;

Edge e[N << 1];

long double ans, dep[N];

bool type;



struct Node {

	int x;

	Node() {}

	Node(int x) : x(x) {}

	inline bool operator < (const Node &y) const {

		if (type) return cnt[x] > cnt[y.x];

	}

};



priority_queue <Node> que;



inline void AddEdge(int u, int v) {

	// cerr << "ae " << u << " " << v << endl;

	dgr[u]++;

	e[++pnt].to = v;

	e[pnt].nxt = hd[u];

	hd[u] = pnt;

}



inline void Read() {

	n = qread(); k = qread();

	for (int i = 1;i <= n;i++) {

		x[i] = qread(); y[i] = qread(); idx[i] = i;

	}

}



inline int gcd(int m, int n) {

	if (!m) return n; if (!n) return m;

	int r = m % n;

	while (r) {

		m = n;

		n = r;

		r = m % n;

	}

	return n;

}



inline void Prefix() {

	sort(idx + 1, idx + n + 1, [&](const int &a, const int &b) {

		return 1ll * x[a] * x[a] + 1ll * y[a] * y[a] < 1ll * x[b] * x[b] + 1ll * y[b] * y[b];

	});

	for (int i = 2;i <= n;i++) {

		int g = gcd(abs(x[idx[i]]), abs(y[idx[i]]));

		int f = mp[make_pair(x[idx[i]] / g, y[idx[i]] / g)];

		if (!f) {

			AddEdge(idx[1], idx[i]);

			AddEdge(idx[i], idx[1]);

			f = idx[1];

		} else {

			AddEdge(f, idx[i]);

			AddEdge(idx[i], f);

		}

		fa[idx[i]] = f;

		dep[idx[i]] = dep[f] + sqrt(1ll * (x[idx[i]] - x[f]) * (x[idx[i]] - x[f]) + 1ll * (y[idx[i]] - y[f]) * (y[idx[i]] - y[f]));

		mp[make_pair(x[idx[i]] / g, y[idx[i]] / g)] = idx[i];

		d1[idx[i]] = d1[f] + 1;

	}

}



inline void Dfs(int u, int fa) {

	siz[u] = vis[u];

	for (int i = hd[u];~i;i = e[i].nxt) {

		if (e[i].to != fa) {

			Dfs(e[i].to, u);

			siz[u] += siz[e[i].to];

		}

	}

	if (~fa) {

		long double dis = sqrt(1ll * (x[u] - x[fa]) * (x[u] - x[fa]) + 1ll * (y[u] - y[fa]) * (y[u] - y[fa]));

		ans += dis * siz[u] * (k - siz[u]);

	}

}



inline long double Solve1() {

	for (int i = 1;i <= n;i++) vis[i] = 1;

	Dfs(idx[1], -1);

	ans = 0;

	for (int i = 1;i <= n;i++) vid[i] = i;

	sort(vid + 1, vid + n + 1, [&](const int &x, const int &y) {

		return (k + 1 - 2 * siz[x]) * dep[x] > (k + 1 - 2 * siz[y]) * dep[y];

	});

	for (int i = 1;i <= n;i++) vis[i] = 0;

	for (int i = 1;i <= k;i++) vis[vid[i]] = 1;

	Dfs(idx[1], -1);

	return ans;

}



inline long double Solve2() {

	int u = 1;

	for (int i = 1;i <= n;i++) {

		if (d1[i] > d1[u]) u = i;

	}

	for (int i = 1;i <= n;i++) vis[i] = 1;

	// cout << u << " " << d1[u] << endl;

	if (d1[u] < k / 2) return -1;

	for (int i = 1;i <= k / 2;i++) u = fa[u];

	for (int i = 1;i <= n - k;i++) {

		if (u == idx[1]) return -1;

		vis[u] = 0;

		u = fa[u];

	}

	// for (int i = 1;i <= n;i++) cout << vis[i]; cout << endl;

	ans = 0;

	Dfs(idx[1], -1);

	return ans;

}



int main() {

	memset(hd, -1, sizeof(hd));

	Read();

	Prefix();

	long double ans = Solve1();

	// cout << ans << endl;

	cout << fixed << setprecision(12) << max(ans, Solve2()) << endl;

	return 0;

}

/*

14 10

0 19

0 17

0 15

0 13

0 -17

0 -15

0 -13

-19 0

-17 0

-13 0

-6 0

19 0

6 0

0 0

*/