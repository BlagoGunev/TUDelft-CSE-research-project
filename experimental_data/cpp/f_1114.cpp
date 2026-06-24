#include <bits/stdc++.h>

#define rep(i, x, y) for (int i = (x), _ = (y); i < _; ++i)
#define down(i, x, y) for (int i = (x) - 1, _ = (y); i >= _; --i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define bin(x) (1 << (x))
#define SZ(x) int((x).size())
//#define LX_JUDGE

using namespace std;
typedef pair<int, int> pii;
typedef vector<int> Vi;
typedef long long ll;
typedef unsigned long long ull;

template<typename T> inline bool upmax(T &x, T y) { return x < y ? (x = y, 1) : 0; }
template<typename T> inline bool upmin(T &x, T y) { return x > y ? (x = y, 1) : 0; }

namespace MATH_CAL {
	const int mod = 1e9 + 7;
	inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
	inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
	inline int mul(int a, int b) { return (ll) a * b % mod; }
	inline void Add(int &a, int b) { (a += b) >= mod ? a -= mod : 0; }
	inline void Sub(int &a, int b) { (a -= b) < 0 ? a += mod : 0; }
	inline int qpow(int x, int n) { int r = 1; for ( ; n; n /= 2, x = mul(x, x)) if (n & 1) r = mul(r, x); return r; }
	inline int mod_inv(int x) { return qpow(x, mod - 2); }
} using namespace MATH_CAL;

const int MAX_N = 4e5 + 10;

int vis[305];
int prime[305], pcnt;
int number[305];

void prepare(int n) {
	vis[1] = 1;
	rep (i, 2, n) {
		if (!vis[i]) {
			vis[i] = i;
			number[i] = pcnt;
			prime[pcnt++] = i;
		}
		rep (j, 0, pcnt) {
			int to = prime[j] * i;
			if (to >= n) break ;
			vis[to] = prime[j];
			if (i % prime[j] == 0) break ;
		}
	}
}

ull get_mask(int v) {
	ull res = 0;
	while (vis[v] != 1) {
		int p = vis[v];
		while (vis[v] == p) v /= p;
		p = number[p];
		res |= (1ll << (p));
	}
	return res;
}

int calc(ull v) {
	int sum = 1, res = 1;
	rep (_i, 0, pcnt) {
		int j = _i;
		if (v & (1ll << j)) {
			sum = mul(sum, prime[j]);
			res = mul(res, prime[j] - 1);
		}
	}
	return mul(mod_inv(sum), res);
}

#define ls (o << 1)
#define rs (o << 1 | 1)

int val[MAX_N * 4], tag[MAX_N * 4];
ull tp[MAX_N * 4], sum[MAX_N * 4];

inline void _mul(int o, int v, int len) {
	tag[o] = mul(tag[o], v);
	val[o] = mul(val[o], qpow(v, len));
}
inline void _cov(int o, ull v) {
	tp[o] = tp[o] | v;
	sum[o] = sum[o] | v;
}

void push_down(int o, int l, int r) {
	int m = (l + r) / 2;
	if (tag[o] != 1) {
		_mul(ls, tag[o], m - l + 1);
		_mul(rs, tag[o], r - m);
		tag[o] = 1;
	}
	if (tp[o] != 0) {
		_cov(ls, tp[o]);
		_cov(rs, tp[o]);
		tp[o] = 0;
	}
}

int _l, _r;

void Mul(int o, int l, int r, int v) {
	if (_l <= l and r <= _r) {
		_mul(o, v, r - l + 1);
		return ;
	}
	push_down(o, l, r);
	int m = (l + r) / 2;
	if (m >= _r) Mul(ls, l, m, v);
	else if (m < _l) Mul(rs, m + 1, r, v);
	else { Mul(ls, l, m, v); Mul(rs, m + 1, r, v); }
	val[o] = mul(val[ls], val[rs]);
}

void Cov(int o, int l, int r, ull v) {
	if (_l <= l and r <= _r) {
		_cov(o, v);
		return ;
	}
	push_down(o, l, r);
	int m = (l + r) / 2;
	if (m >= _r) Cov(ls, l, m, v);
	else if (m < _l) Cov(rs, m + 1, r, v);
	else { Cov(ls, l, m, v); Cov(rs, m + 1, r, v); }
	sum[o] = sum[ls] | sum[rs];
}

int qry(int o, int l, int r) {
	if (_l <= l and r <= _r) return val[o];
	push_down(o, l, r);
	int m = (l + r) / 2;
	if (m >= _r) return qry(ls, l, m);
	if (m < _l) return qry(rs, m + 1, r);
	return (ll) qry(ls, l, m) * qry(rs, m + 1, r) % mod;
}

ull rec(int o, int l, int r) {
	if (_l <= l and r <= _r) return sum[o];
	push_down(o, l, r);
	int m = (l + r) / 2;
	if (m >= _r) return rec(ls, l, m);
	if (m < _l) return rec(rs, m + 1, r);
	return rec(ls, l, m) | rec(rs, m + 1, r);
}

void build(int o, int l, int r, int *a) {
	tag[o] = 1;
	tp[o] = 0;
	if (l == r) {
		val[o] = a[l];
		sum[o] = get_mask(a[l]);
		return ;
	}
	int m = (l + r) / 2;
	build(ls, l, m, a);
	build(rs, m + 1, r, a);
	val[o] = mul(val[ls], val[rs]);
	sum[o] = sum[ls] | sum[rs];
}

int main() {
#ifdef LX_JUDGE
	freopen(".in", "r", stdin);
#endif

	prepare(301);
	int N, Q;
	scanf("%d%d", &N, &Q);

	static int A[MAX_N];

	rep (i, 1, N + 1) {
		scanf("%d", &A[i]);
	}

	build(1, 1, N, A);

	rep (i, 1, Q + 1) {
		static char str[105];
		int v;
		scanf("%s", str);
		if (str[0] == 'M') {
			scanf("%d%d%d", &_l, &_r, &v);
			Mul(1, 1, N, v);
			Cov(1, 1, N, get_mask(v));
		} else {
			scanf("%d%d", &_l, &_r);
			int ans = qry(1, 1, N);
			ull mo = rec(1, 1, N);
			printf("%d\n", mul(ans, calc(mo)));
		}
	}

	return 0;
}