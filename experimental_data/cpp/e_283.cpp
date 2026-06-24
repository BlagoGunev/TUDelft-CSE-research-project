#include <bits/stdc++.h>

using namespace std;

// It is not guaranteed that ai and bi are equal to some cow's skill level
// 为什么是not啊……= =

#define pb push_back
using pii = pair<int,int>;
using ll = long long;

const int mxn = 100006;

int n, m;
int a[mxn];

struct Val {
	int x, y;
	Val operator+(Val b) {
		return {x + b.x, y + b.y};
	}
	Val operator-(Val b) {
		return {x - b.x, y - b.y};
	}
	Val operator~() {
		return {y, x};
	}
};

struct Segtree {
	using Ope = bool;
	Val val_[mxn * 2];
	Ope laz_[mxn * 2];
	#define oddr(l,r) (l+r|l!=r)
	#define val val_[oddr(l,r)]
	#define laz laz_[oddr(l,r)]
	#define m (l+r>>1)
	void renew(int l, int r) {
		val = get(l, m, l, r) + get(m + 1, r, l, r);
	}
	void down(int l, int r) {
		if (laz) {
			set(l, m, l, r, laz);
			set(m + 1, r, l, r, laz);
			laz = Ope();
		}
	}
	void build(int l, int r) {
		laz = Ope();
		if (l == r)
			return;
		build(l, m);
		build(m + 1, r);
		renew(l, r);
	}
	void set(int l, int r, int sl, int sr, Ope ope) {
		if (sl <= l && r <= sr) {
			if (ope) val = ~val;
			laz ^= ope;
			return;
		}
		down(l, r);
		if (sl <= m) set(l, m, sl, sr, ope);
		if (sr > m) set(m + 1, r, sl, sr, ope);
		renew(l, r);
	}
	Val get(int l, int r, int sl, int sr) {
		if (sl <= l && r <= sr)
			return val;
		down(l, r);
		if (sr <= m) return get(l, m, sl, sr);
		if (sl > m) return get(m + 1, r, sl, sr);
		return get(l, m, sl, sr) + get(m + 1, r, sl, sr);
	}
	Val &operator[](int x) { return val_[x + x]; }
	#undef oddr
	#undef val
	#undef laz
	#undef m
} Q;

inline ll comb2(ll n) { return n * (n - 1) / 2; }
inline ll comb3(ll n) { return n * (n - 1) * (n - 2) / 6; }

vector<pii> ope[mxn]; // 扫描线 + 对角正方形

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	
	for (int i = 0; i < m; ++i) {
		int L, R;
		scanf("%d%d", &L, &R);
		L = lower_bound(a, a + n, L) - a;
		R = upper_bound(a, a + n, R) - 1 - a;
		if (L <= R) {
			ope[L].pb({L, R});
			ope[R + 1].pb({L, R});
		}
	}
	
	for (int i = 0; i < n; ++i)
		Q[i] = {1, 0};
	Q.build(0, n - 1);
	
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		for (auto j : ope[i])
			Q.set(0, n - 1, j.first, j.second, true);
		auto c = Q.get(0, n - 1, 0, n - 1) - Q.get(0, n - 1, i, i);
		// cout << "> " << c.x << ' ' << c.y << endl;
		sum += comb2(c.x) + comb2(c.y);
		Q.set(0, n - 1, i, i, true);
	}
	
	cout << comb3(n) - sum / 2 << endl;
	
	return 0;
}