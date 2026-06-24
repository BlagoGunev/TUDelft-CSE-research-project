#include <bits/stdc++.h>
#pragma GCC optimize("Ofast","-funroll-loops")

#pragma GCC target("sse4.1","sse4.2","ssse3","sse3","sse2","sse","avx2","avx","popcnt","tune=native")

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



const int N = 200005;



struct Edge {

	int to, nxt;

	Edge() {

		nxt = -1;

	}

};

Edge e[N << 1];

int n, hd[N], pnt, siz[N], son[N], dfn[N], top[N], _time, idx[N], fa[N], dep[N], tn;

long long res;



struct Segtree {

	long long sum[N << 2], tag[N << 2];

	inline void Pushdown(int p, int pl, int pr) {

		int mid = pl + pr >> 1;

		if (tag[p]) {

			tag[p << 1] += tag[p];

			sum[p << 1] += tag[p] * (mid - pl + 1);

			tag[p << 1 | 1] += tag[p];

			sum[p << 1 | 1] += tag[p] * (pr - mid);

			tag[p] = 0;

		}

	}

	inline void Modify(int p, int pl, int pr, int l, int r, long long v) {

		if (pl == l && pr == r) {

			sum[p] += (r - l + 1) * v;

			tag[p] += v;

			return;

		}

		Pushdown(p, pl, pr);

		int mid = pl + pr >> 1;

		if (mid >= r) Modify(p << 1, pl, mid, l, r, v);

		else if (mid + 1 <= l) Modify(p << 1 | 1, mid + 1, pr, l, r, v);

		else {

			Modify(p << 1, pl, mid, l, mid, v);

			Modify(p << 1 | 1, mid + 1, pr, mid + 1, r, v);

		}

		sum[p] = sum[p << 1] + sum[p << 1 | 1];

	}

	inline long long Query(int p, int pl, int pr, int l, int r) {

		if (pl == l && pr == r) return sum[p];

		Pushdown(p, pl, pr);

		int mid = pl + pr >> 1;

		if (mid >= r) return Query(p << 1, pl, mid, l, r);

		else if (mid + 1 <= l) return Query(p << 1 | 1, mid + 1, pr, l, r);

		else return Query(p << 1, pl, mid, l, mid) + Query(p << 1 | 1, mid + 1, pr, mid + 1, r);

	}

};

Segtree sgt;



inline void AddEdge(int u, int v) {

	e[++pnt].to = v;

	e[pnt].nxt = hd[u];

	hd[u] = pnt;

}



inline void Read() {

	n = qread(); tn = 2 * n - 1;

	for (int i = 1;i < n;i++) {

		int u = qread(), v = qread();

		AddEdge(u, n + i); AddEdge(n + i, u);

		AddEdge(v, n + i); AddEdge(n + i, v);

	}

}



inline void Dfs1(int u) {

	siz[u] = 1;

	for (int i = hd[u];~i;i = e[i].nxt) {

		if (e[i].to != fa[u]) {

			fa[e[i].to] = u;

			dep[e[i].to] = dep[u] + 1;

			Dfs1(e[i].to);

			siz[u] += siz[e[i].to];

			if (siz[e[i].to] > siz[son[u]]) son[u] = e[i].to;

		}

	}

}



inline void Dfs2(int u, int tp) {

	top[u] = tp;

	dfn[u] = ++_time; idx[_time] = u;

	if (son[u]) Dfs2(son[u], tp);

	for (int i = hd[u];~i;i = e[i].nxt) {

		if (e[i].to != fa[u] && e[i].to != son[u]) Dfs2(e[i].to, e[i].to);

	}

}



inline void Modify(int u, int v) {

	while (u) {

		sgt.Modify(1, 1, tn, dfn[top[u]], dfn[u], v);

		u = fa[top[u]];

	}

}



inline long long qSum(int u) {

	long long ans = 0;

	while (u) {

		ans += sgt.Query(1, 1, tn, dfn[top[u]], dfn[u]);

		u = fa[top[u]];

	}

	return ans;

}



inline int Lca(int u, int v) {

	while (top[u] != top[v]) {

		if (dep[top[u]] < dep[top[v]]) swap(u, v);

		u = fa[top[u]];

	}

	if (dep[u] > dep[v]) swap(u, v);

	return u;

}



inline int kAnc(int u, int k) {

	for (;;) {

		if (dep[u] - dep[top[u]] < k) {

			k -= dep[u] - dep[fa[top[u]]];

			u = fa[top[u]];

		} else return idx[dfn[u] - k];

	}

}



inline int pKth(int u, int v, int l, int k) {

	int len = dep[u] + dep[v] - 2 * dep[l];

	if (dep[u] - dep[l] >= k) return kAnc(u, k);

	else return kAnc(v, len - k);

}



struct Circ {

	int o, r;

	Circ() {}

	Circ(int o, int r) : o(o), r(r) {}

	inline Circ operator + (const Circ& b) const {

		int l = Lca(o, b.o), dis = dep[o] + dep[b.o] - 2 * dep[l];

		if (b.r >= dis + r) return b;

		if (r >= dis + b.r) return *this;

		int d = b.r + r + dis;

		assert(d % 2 == 0);

		// cout << o << "," << r << "+" << b.o << "," << b.r << "=" << pKth(o, b.o, l, d / 2 - r) << "," << d / 2 << endl;

		return Circ(pKth(o, b.o, l, d / 2 - r), d / 2);

	}

	inline bool operator == (const Circ& b) const {

		return (o == b.o && r == b.r);

	}

	inline bool operator != (const Circ& b) const {

		return !(*this == b);

	}

};

Circ c[N];



inline void Work(int l, int r) {

	if (l == r) return;

	int mid = l + r >> 1;

	Work(l, mid); Work(mid + 1, r);

	for (int i = l;i <= r;i++) c[i] = Circ(i, 0);

	for (int i = mid - 1;i >= l;i--) c[i] = c[i + 1] + c[i];

	for (int i = mid + 2;i <= r;i++) c[i] = c[i - 1] + c[i];

	int l2 = mid + 1, l3 = mid + 1;

	long long rsum2 = 0, dsum = 0, rsum3 = 0;

	for (int i = mid + 1;i <= r;i++) rsum3 += c[i].r;

	//cout << l << "," << r << endl;

	//for (int i = l;i <= r;i++) cout << c[i].o << "," << c[i].r << " "; cout << endl;

	long long tmp = 0;

	for (int i = mid;i >= l;i--) {

		while (l3 <= r && c[l3] + c[i] != c[l3]) {

			Modify(c[l3].o, 1); rsum2 += c[l3].r; dsum += dep[c[l3].o]; rsum3 -= c[l3].r;

			l3++;

		}

		while (l2 < l3 && c[l2] + c[i] == c[i]) {

			Modify(c[l2].o, -1); rsum2 -= c[l2].r; dsum -= dep[c[l2].o];

			l2++;

		}

		tmp += 2ll * (l2 - mid - 1) * c[i].r;

		//cout << 2ll * (l2 - mid - 1) * c[i].r << ",";

		tmp += 1ll * (l3 - l2) * c[i].r + rsum2 + 1ll * (l3 - l2) * dep[c[i].o] + dsum - 2 * qSum(c[i].o);

		//cout << 1ll * (l3 - l2) * c[i].r + rsum2 + 1ll * (l3 - l2) * dep[c[i].o] + dsum - 2 * qSum(c[i].o) << ",";

		tmp += rsum3 * 2;

		//cout << rsum3 * 2 << " ";

	}

	//cout << endl;

	//cout << "+" << tmp << endl;

	res += tmp;

	while (l2 < l3) {

		Modify(c[l2].o, -1); rsum2 -= c[l2].r; dsum -= dep[l2];

		l2++;

	}

}



int main() {

	memset(hd, -1, sizeof(hd));

	Read();

	dep[1] = 1; Dfs1(1); Dfs2(1, 1);

	// for (int i = 1;i <= tn;i++) cout << idx[i] << " "; cout << endl;

	// cout << kAnc(4, 1) << endl;

	Work(1, n); assert(res % 2 == 0);

	cout << res / 2 << endl;

	return 0;

}