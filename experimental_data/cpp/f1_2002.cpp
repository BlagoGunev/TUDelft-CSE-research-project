#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <array>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_set>
#include <unordered_map>
#define all(a) (a).begin(), (a).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define req(i, a, b) for (ll i = (a); i < (b); i++)
#define pb push_back
#define debug(x) cerr << __LINE__ << ' ' << #x << ':' << (x) << '\n'
#define debug2(x, y) cerr << __LINE__ << ' ' << #x << ':' << (x) << ',' << #y << ':' << (y) << '\n'
#define debug3(x, y, z) cerr << __LINE__ << ' ' << #x << ':' << (x) << ',' << #y << ':' << (y) << ',' << #z << ':' << (z) << '\n'
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
template<class T> using P = pair<T, T>;
template<class T> using pri_s = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pri_b = priority_queue<T>;
constexpr int inf = 1000000010;
constexpr int inf2 = 2000000010;
constexpr ll INF = 1000000000000000010;
constexpr ll INF4 = 4000000000000000010;
constexpr int mod1e9 = 1000000007;
constexpr int mod998 = 998244353;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
constexpr ll ten(int n) { return n ? 10 * ten(n - 1) : 1; };
int dx[] = { 1,0,-1,0,1,1,-1,-1,0 }; int dy[] = { 0,1,0,-1,1,-1,1,-1,0 };
ll mul(ll a, ll b) { return (b != 0 && a > INF / b ? INF : a * b); }
void fail() { cout << "-1\n"; exit(0); } void no() { cout << "No\n"; exit(0); }
template<class T> void er(T a) { cout << a << '\n'; exit(0); }
template<class T, class U> inline bool chmax(T& a, const U& b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T& a, const U& b) { if (a > b) { a = b; return true; } return false; }
template<class T> istream& operator >>(istream& s, vector<T>& v) { for (auto& e : v) s >> e; return s; }
template<class T> ostream& operator <<(ostream& s, const vector<T>& v) { for (auto& e : v) s << e << ' '; return s; }
template<class T, class U> ostream& operator << (ostream& s, const pair<T, U>& p) { s << p.first << ' ' << p.second; return s; }

struct fastio {
	fastio() {
		cin.tie(0); cout.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(20);
		cerr << fixed << setprecision(20);
	}
}fastio_;

namespace rdv {
	random_device seed_gen;
	mt19937_64 engine(seed_gen());
	ll rnum(ll r) { return engine() % r; } // [0, r)
	ll rnum(ll l, ll r) { return rnum(r - l) + l; } // [l, r)
	// ll rng(ll r) { return rnum(r) + 1; } // [1, r]
	ll rng(ll l, ll r) { return rnum(l, r + 1); } // [l, r]
	double rng01() { return engine() * pow(2, -64); }
	template<class T> void shuf(vector<T>& v) { shuffle(all(v), engine); }
	void shuf(string& s) { shuffle(all(s), engine); }
}

using namespace rdv;

constexpr ll mod = mod998;
template <int mod> class modint {
public:
	int n;
	modint() : n(0) {};
	modint(ll n_) {
		n = n_ % mod;
		if (n < 0) n += mod;
	}
	modint operator -() const { return n > 0 ? mod - n : -n; }
	bool operator == (const modint& m) const { return n == m.n; }
	bool operator != (const modint& m) const { return n != m.n; }
	modint& operator += (const modint& m) { n += m.n; if (n >= mod) n -= mod; return *this; }
	modint& operator -= (const modint& m) { n -= m.n; if (n < 0) n += mod; return *this; }
	modint& operator *= (const modint& m) { n = ll(n) * m.n % mod; return *this; }
	modint& operator /= (const modint& m) { n = ll(n) * modinv(m).n % mod; return *this; }
	modint operator +(modint m) const { return modint(*this) += m; }
	modint operator -(modint m) const { return modint(*this) -= m; }
	modint operator *(modint m) const { return modint(*this) *= m; }
	modint operator /(modint m) const { return modint(*this) /= m; }
	modint& operator ++ () { *this += 1; return *this; }
	modint operator ++ (int) { *this += 1; return *this - 1; }
	modint& operator -- () { *this -= 1; return *this; }
	modint operator -- (int) { *this -= 1; return *this + 1; }
	modint pow(ll b) const {
		modint res = 1, a = modint(*this);
		while (b) {
			if (b & 1) res *= a;
			a *= a;
			b >>= 1;
		}
		return res;
	}
	friend istream& operator >> (istream& s, modint<mod>& a) { s >> a.n; return s; }
	friend ostream& operator << (ostream& s, modint<mod>& a) { s << a.n; return s; }
};

using mint = modint<mod>;

mint modinv(mint x) {
	ll a = x.n;
	if (a == 0) abort();
	ll b = mod, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	mint res = u;
	return res;
}

template<class T> vector<int> compress(vector<T> v) {
	int n = v.size();
	vector<T> tmp = v;
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	vector<int> res(n);
	for (int i = 0; i < n; i++) res[i] = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
	return res;
}

vector<mint> fac, inv, facinv;

void modcalc(int n) {
	fac.resize(n); inv.resize(n); facinv.resize(n);
	fac[0] = 1; fac[1] = 1; inv[1] = 1;
	facinv[0] = 1; facinv[1] = 1;
	for (ll i = 2; i < n; i++) {
		fac[i] = fac[i - 1] * i;
		inv[i] = -inv[mod % i] * (mod / i);
		facinv[i] = facinv[i - 1] * inv[i];
	}
}

mint comb(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[k] * facinv[n - k];
}

mint perm(ll n, ll k) {
	if (n < 0 || k < 0 || n < k) return 0;
	return fac[n] * facinv[n - k];
}

mint hom(ll n, ll k) {
	if (n < 0 || k < 0 || n == 0 && k > 0) return 0;
	if (n == 0 && k == 0) return 1;
	return fac[n + k - 1] * facinv[k] * facinv[n - 1];
}

class EulerTour {
public:
	vector<vector<int>> graph;
	vector<int> tour, in, out;
	vector<int> dep;
	void dfs(int n, int p, int d) {
		tour.push_back(n);
		dep[n] = d;
		for (int i : graph[n]) {
			if (i == p) continue;
			dfs(i, n, d + 1);
			tour.push_back(n);
		}
	}
	EulerTour(vector<vector<int>> graph_, int root) {
		graph = graph_;
		int n = graph.size();
		dep.resize(n);
		dfs(root, -1, 0);
		int sz = tour.size();
		in.resize(n);
		out.resize(n);
		rep(i, n) in[i] = -1;
		rep(i, sz) {
			if (in[tour[i]] == -1) in[tour[i]] = i;
			out[tour[i]] = i;
		}
	}
	EulerTour(vector<vector<int>> graph_, vector<int> root) {
		graph = graph_;
		int n = graph.size();
		dep.resize(n);
		for (int r : root) dfs(r, -1, 0);
		int sz = tour.size();
		in.resize(n);
		out.resize(n);
		rep(i, n) in[i] = -1;
		rep(i, sz) {
			if (in[tour[i]] == -1) in[tour[i]] = i;
			out[tour[i]] = i;
		}
	}
	bool subtree(int u, int v) {
		return in[u] <= in[v] && out[v] <= out[u];
	}
	P<int> get_interval(int u, int v) {
		int l, r;
		if (out[u] < in[v]) l = out[u], r = in[v];
		else if (out[v] < in[u]) l = out[v], r = in[u];
		else if (subtree(u, v)) l = in[u], r = in[v];
		else l = in[v], r = in[u];
		return { l,r };
	}
};

template<class T> class segtree {
	int n;
	vector<T> data;
	T id = { inf, 0 };
	T operation(T a, T b) { return min(a, b); }
public:
	segtree(int _n) {
		n = 1;
		while (n < _n + 2) n <<= 1;
		data = vector<T>(2 * n, id);
	}
	segtree(vector<T> vec) {
		int _n = vec.size();
		n = 1;
		while (n < _n + 2) n <<= 1;
		data = vector<T>(2 * n, id);
		for (int i = 0; i < _n; i++) data[i + n] = vec[i];
		for (int i = n - 1; i >= 1; i--) data[i] = operation(data[i << 1], data[i << 1 | 1]);
	}
	void change(int i, T x) {
		i += n;
		data[i] = x;
		while (i > 1) {
			i >>= 1;
			data[i] = operation(data[i << 1], data[i << 1 | 1]);
		}
	}
	void add(int i, T x) { change(i, data[i + n] + x); }
	T get(int a, int b) {
		T left = id; T right = id;
		a += n; b += n;
		while (a < b) {
			if (a & 1) left = operation(left, data[a++]);
			if (b & 1) right = operation(data[--b], right);
			a >>= 1; b >>= 1;
		}
		return operation(left, right);
	}
	T get_all() { return data[1]; }
	T operator[](int i) { return data[i + n]; }
};

const int A = 2 * ten(7) + ten(2);
vector<int> pf(A);

struct sieve {
	sieve() {
		for (int i = 2; i < A; i++) {
			if (pf[i] != 0) continue;
			for (int j = i; j < A; j += i) pf[j] = i;
		}
	}
}sieve_;

int main() {

	// 入力を全部受け取る前に continue をしない

	const int B = 220;

	vector<vector<bool>> ep(B, vector<bool>(B));
	ep[0][0] = true;
	rep(i, B) {
		rep(j, B) {
			if (gcd(i, j) != 1) continue;
			if (i != 0 && ep[i - 1][j]) ep[i][j] = true;
			if (j != 0 && ep[i][j - 1]) ep[i][j] = true;
		}
	}

	int T = 1;
	cin >> T;
	while (T--) {
		ll n, m, l, f;
		cin >> n >> m >> l >> f;
		if (l > f) swap(l, f);
		if (n < 100) {
			ll ans = 0;
			rep(i, n + 1) rep(j, n + 1) if (ep[i][j]) chmax(ans, i * l + j * f);
			cout << ans << '\n';
			continue;
		}
		vector<int> pr;
		for (int i = n; i >= max(2, int(n - B)); i--) {
			if (pf[i] == i) pr.push_back(i);
		}
		reverse(all(pr));
		int ofs = pr[0];
		int s = n - pr[0] + 1;
		vector<vector<bool>> dp(s, vector<bool>(s));
		int sz = pr.size();
		rep(i, sz - 1) {
			for (int j = pr[i]; j < pr[i + 1]; j++) {
				dp[j - ofs][pr[i + 1] - ofs] = true;
			}
		}
		rep(i, s) {
			rep(j, s) {
				if (i > j) continue;
				if (gcd(i + ofs, j + ofs) != 1) continue;
				if (i != 0 && dp[i - 1][j]) dp[i][j] = true;
				if (j != 0 && dp[i][j - 1]) dp[i][j] = true;
			}
		}
		ll ans = 0;
		rep(i, s) rep(j, s) {
			if (dp[i][j]) chmax(ans, (i + ofs) * l + (j + ofs) * f);
		}
		cout << ans << '\n';
	}
}