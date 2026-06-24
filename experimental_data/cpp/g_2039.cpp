//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(...) fprintf (stderr, __VA_ARGS__)

#define lep(i, l, r) for (int i = (l), i##_end = (r); i <= i##_end; ++ i)
#define rep(i, r, l) for (int i = (r), i##_end = (l); i >= i##_end; -- i)

char _c; bool _f; template <class T> inline void IN (T & x) {
	_f = 0, x = 0; while (_c = getchar (), ! isdigit (_c)) if (_c == '-') _f = 1;
	while (isdigit (_c)) x = x * 10 + _c - '0', _c = getchar (); if (_f) x = - x;
}

const int mod = 998244353;
inline int mul (int x, int y) { return 1ll * x * y % mod; }
inline int qpow (int x, int y, int r = 1) { for ( ; y; y >>= 1, x = mul (x, x)) if (y & 1) r = mul (r, x); return r; }
inline void pls (int &x, int y) { x += y; if (x >= mod) x -= mod; }
inline int add (int x, int y) { x += y; if (x >= mod) x -= mod; return x; }

const int N = 1e6 + 50;

int n, m;
vector <int> to[N];

int dia[N], len[N];

void dfs1 (int u, int pre) {
	len[u] = 1;
	for (auto & v : to[u]) if (v != pre) {
		dfs1 (v, u), len[u] = max ( len[u], len[v] + 1 );
	}
}
void dfs2 (int u, int pre) {
	int q = -1, s = 0;
	for (auto & v : to[u]) if (v != pre) {
		if (! ~ q || len[v] > len[q]) {
			if ( ~ q) s = len[q];
			q = v;
		} else {
			s = max (s, len[v]);
		}
	}
	for (auto & v : to[u]) if (v != pre) {
		dia[v] = dia[u] + 1;
		dia[v] = max (dia[v], (q == v ? s : len[q]) + 2);
		dfs2 (v, u);
	}
	int fst = dia[u], snd = 1;
	for (auto & v : to[u]) if (v != pre) {
		if (len[v] + 1 >= fst) {
			snd = fst, fst = len[v] + 1;
		} else {
			snd = max ( snd, len[v] + 1 );
		}
	}
	dia[u] = fst + snd - 1;
}

int cnt, pri[N / 5], mui[N];
bitset <N> vis;

inline void sieve (const int L = N - 3) {
	mui[1] = 1;
	lep (i, 2, L) {
		if (! vis.test ( i )) {
			pri[ ++ cnt] = i;
			mui[i] = mod - 1;
		}
		for (int j = 1; j <= cnt && i * pri[j] <= L; ++ j) {
			vis.set ( i * pri[j] );
			if (! (i % pri[j])) {
				mui[i * pri[j]] = 0;
				break ;
			}
			mui[i * pri[j]] = mod - mui[i];
		}
	}
}

int sqrtm, tot, val[N], id1[N], id2[N];
inline int id (ll x) { return x <= sqrtm ? id1[x] : id2[m / x]; }

inline void prework () {
	sqrtm = sqrt (m);
	for (int l = 1, r, num; l <= m; l = r + 1) {
		r = m / (m / l), val[ ++ tot] = num = m / l;
		num <= sqrtm ? id1[num] = tot : id2[m / num] = tot;
	}
}

int prod[N], dp[N];

inline void q_prod () {
	vector <int> pre (N);
	lep (i, 1, tot) dp[i] = val[i] - 1;
	lep (i, 1, n) pre[dia[i]] ++ ;
	lep (i, 1, N - 1) pre[i] += pre[i - 1];
	lep (i, 1, tot) prod[i] = 1;
	lep (j, 1, cnt) {
		int cur = pre[pri[j] - 1] - (j > 1 ? pre[pri[j - 1] - 1] : 0);
		if (cur) {
			for (int i = 1; i <= tot && val[i] >= pri[j]; ++ i) {
				prod[i] = mul ( prod[i], qpow ( 1 + max (0, dp[i] - j + 1), cur ) );
			}
		}
		ll lim = 1ll * pri[j] * pri[j];
		for (int i = 1; i <= tot && val[i] >= lim; ++ i) {
			int nxt = id (val[i] / pri[j]);
			pls (dp[i], mod - add (dp[nxt], mod - (j - 1)));
		}
	}
}

int S (int n, int j) {
    if (j > cnt || n < pri[j] || n <= 1) return 0;
	int cur = id (n);;
	ll ret = mod - dp[cur] + j - 1;
    for(int i = j; i <= cnt && 1ll * pri[i] * pri[i] <= n; ++ i) ret -= S (n / pri[i], i + 1);
    return ret %= mod, ret += mod, ret %= mod;
}

signed main () {
	IN (n), IN (m);
	for (int u, v, i = 1; i < n; ++ i) {
		IN (u), IN (v);
		to[u].emplace_back ( v );
		to[v].emplace_back ( u );
	}
	dfs1 (1, 0), dia[1] = 1, dfs2 (1, 0);
	int eq = 0, lim = 1;
	lep (i, 1, n) eq = max (eq, dia[i]);
	sieve (), prework (), q_prod ();
	while (lim <= cnt && pri[lim] <= eq) ++ lim;

	int ret = 0, lst = 0;
	for (int l = 1, r; l <= m; l = r + 1) {
		r = m / (m / l);
		int nxt = S (r, lim);
		pls (ret, mul (prod[id (m / l)], nxt - lst + (l == 1) + mod)), lst = nxt;
	}
	printf ("%d\n", ret);
	return 0;
}