#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define ff first
#define ss second
#define pb push_back
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
// debug template
#ifdef POTATO
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif
// convenient functions
inline void yes() { cout << "YES\n"; return; }
inline void no() { cout << "NO\n"; return; }
template <class T>
inline void out(T temp) { cout << temp << '\n'; return; }
// globals
#define int long long
const int MOD = 998244353;
void chadd(int& x, int y) { x = (x + y) % MOD; }
void chsub(int& x, int y) { x = (x - (y % MOD) + MOD) % MOD; }
void chmul(int& x, int y) { x = (x * (y % MOD)) % MOD; }
int bigmod(int b, int p) {
	b %= MOD;
	int res = 1;
	while (p) {
		if (p & 1) res = (res * b) % MOD;
		p >>= 1; b = (b * b) % MOD;
	}
	return res;
}
int modinv(int x) {
	return bigmod(x, MOD - 2);
}
const int mxN = 5e5 + 10;
int fact[mxN], finv[mxN];
void init() {
	// initialize
	fact[0] = fact[1] = 1;
	finv[0] = finv[1] = 1;
	for (int i = 2; i < mxN; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	finv[mxN - 1] = modinv(fact[mxN - 1]);
	for (int i = mxN - 2; i >= 2; i--) {
		finv[i] = (finv[i + 1] * (i + 1)) % MOD;
	}
}
int nCr(int n, int r) {
	if (r < 0 || r > n) return 0;
	int res = fact[n];
	chmul(res, finv[r]);
	chmul(res, finv[n - r]);
	return res;
}
pii output_frac(int x) {
	for (int den = 1; den <= 500; den++) {
		for (int num = 0; num <= 500; num++) {
			if (num * modinv(den) % MOD == x) {
				return {num, den};
			}
		}
	}
	return {-1, -1};
}
void solve() {
	// solve
	int n, m, k;
	cin >> n >> m >> k;
	vector<pii> pts(k + 2);
	pts[0] = {0, 0}; pts[k + 1] = {n, m};
	for (int i = 1; i <= k; i++) {
		cin >> pts[i].ff >> pts[i].ss;
		pts[i].ff = n - pts[i].ff;
		pts[i].ss = m - pts[i].ss;
	}
	sort(pts.begin(), pts.end(), [&](const pii& lhs, const pii& rhs) {
		return (lhs.ff + lhs.ss) < (rhs.ff + rhs.ss);
	});
	vector<int> ans(k + 2);
	ans[0] = 0;
	vector<int> calc(k + 2);
	for (int i = 0; i <= k; i++) {
		calc[i] = 1;
		int sx = pts[i].ff, sy = pts[i].ss;
		for (int j = i + 1; j <= k + 1; j++) {
			int ex = pts[j].ff, ey = pts[j].ss;
			calc[j] = nCr((ex - sx) + (ey - sy), (ex - sx));
			for (int l = i + 1; l < j; l++) {
				int mx = pts[l].ff, my = pts[l].ss;
				int cur = nCr((ex - mx) + (ey - my), (ex - mx));
				chmul(cur, calc[l]);
				chsub(calc[j], cur);
			}
			int contrib = ans[i];
			chadd(contrib, ((ex - sx) * 2 + (ey - sy)) * nCr(sx + sy, sx));
			chmul(contrib, calc[j]);
			if (j <= k) chmul(contrib, 2);
			chadd(ans[j], contrib);
		}
	}
	chmul(ans[k + 1], modinv(nCr(n + m, n)));
	out(ans[k + 1]);
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef POTATO
		auto start = chrono::high_resolution_clock::now();
	#endif

	init();
	int t = 1;
	cin >> t;
	while (t--) solve();

	#ifdef POTATO
		auto end = chrono::high_resolution_clock::now();
		cerr << "Execution time: "
			<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
			<< " ms" << endl;
	#endif
}
/*

*/