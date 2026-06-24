#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto x : v) cerr << x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int i = 0; i < (n); ++i) cerr << a[i] << ", "; cerr << endl
typedef long long ll;
typedef long double ld;
ll A[200005];
// Factorization
ll modmul(ll a, ll b, ll mod) {
	if (!b) return 0;
	if (b & 1) return (a + modmul(a, b - 1, mod)) % mod;
	ll v = modmul(a, b / 2, mod);
	return (v + v) % mod;
}
ll modex2(ll a, ll p, ll mod) {
	if (!p) return 1;
	if (p & 1) return modmul(a, modex2(a, p - 1, mod), mod);
	ll v = modex2(a, p / 2, mod);
	return modmul(v, v, mod);
}
mt19937_64 rng;
// O(log^2 n)
bool miller(ll d, ll n) {
	ll a = 1 + (rng() % (n - 1));
	ll x = modex2(a, d, n);
	if (x == 1 || x == n - 1) return true;
	while (d < n - 1) {
		x = modmul(x, x, n);
		d *= 2;
		if (x == n - 1) return true;
	}
	return false;
}
// O(20 * log^2 n)
bool isPrime(ll n) {
	if (n <= 1)  return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	ll d = n - 1;
	while (d % 2 == 0) d /= 2;
	// Fact: >= 75% of n will test false if n composite
	// Easy to prove: > 50% of n will test false if n composite
	for (int i = 0; i < 20; ++i)
		if (!miller(d, n)) return false;
	return true;
}
// Finds a factor in expected O(n^0.25)
ll pollardRho(ll a) {
	for (;;) {
		ll x = rng() % a;
		ll y = x;
		ll c = rng() % a;
		ll g = 1;
		while (g == 1) {
			x = (modmul(x, x, a) + c) % a;
			y = (modmul(y, y, a) + c) % a;
			y = (modmul(y, y, a) + c) % a;
			g = __gcd(abs(x - y), a);
		}
		if (g != a) return g;
	}
}
// O(log n * max(20 * log^2 n, n^0.25)))
void factorize(ll a, vector<ll> &factors) {
	if (a == 1) return;
	if (a % 2 == 0) {
		factors.push_back(2);
		factorize(a / 2, factors);
		return;
	}
	if (isPrime(a)) {
		factors.push_back(a);
		return;
	}
	ll f = pollardRho(a);
	factorize(f, factors);
	factorize(a / f, factors);
}
void primeFactorize(ll a, vector<pair<ll, int>> &pfac) {
	vector<ll> facs;
	factorize(a, facs);
	map<ll, int> mp;
	for (ll f : facs) ++mp[f];
	for (auto &m : mp) pfac.emplace_back(m.first, m.second);
}
int sos[1 << 18];
int main() {
	int n;
	ll x, y;
	scanf("%d%lld%lld", &n, &x, &y);
	vector<pair<ll, int>> yfacs;
	primeFactorize(y, yfacs);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &A[i]);
	}
	if (y % x) {
		printf("0\n");
		return 0;
	}
	int N = yfacs.size();
	for (int i = 0; i < n; ++i) {
		if (A[i] % x) continue;
		ll a = A[i] / x;
		int has = 0;
		for (int k = 0; k < yfacs.size(); ++k) {
			auto &f = yfacs[k];
			if (a % f.first == 0) has |= 1 << k;
		}
		// require v to not contain prime factors from has
		++sos[has];
	}
	for (int j = 0; j < N; ++j)
		for (int k = (1 << N) - 1; k >= 0; --k)
			if (k & (1 << j)) sos[k] += sos[k ^ (1 << j)];
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (y % A[i]) continue;
		// a = lcm(A[i], x)
		ll a = A[i] / __gcd(A[i], x);
		a *= x;
		int sub = 0;
		for (int k = 0; k < yfacs.size(); ++k) {
			auto &f = yfacs[k];
			ll val = 1;
			for (int j = 0; j < f.second; ++j) val *= f.first;
			if (a % val) sub |= 1 << k;
		}
		// require v to contain prime factors from sub
		ans += sos[(1 << N) - 1 - sub];
	}
	printf("%lld\n", ans);
}