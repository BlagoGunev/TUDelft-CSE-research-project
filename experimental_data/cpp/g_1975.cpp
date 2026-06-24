//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <climits>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define mp make_pair
#define all(x) (x).begin(),(x).end()

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

ll floor_div(ll x, ll y) {
	assert(y != 0);
	if (y < 0) {
		y = -y;
		x = -x;
	}
	if (x >= 0) return x / y;
	return (x + 1) / y - 1;
}
ll ceil_div(ll x, ll y) {
	assert(y != 0);
	if (y < 0) {
		y = -y;
		x = -x;
	}
	if (x <= 0) return x / y;
	return (x - 1) / y + 1;
}
template<typename T>
T sqr(T x) {
	return x * x;
}

const int MAGIC = 100;

const uint MOD = 1484783617;
template<uint mod = MOD> struct mint { // 998244353
	uint x;

	mint() : x(0) {}
	mint(ll _x) {
		_x %= mod;
		if (_x < 0) _x += mod;
		x = _x;
	}

	mint& operator += (const mint &a) {
		x += a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator -= (const mint &a) {
		x += mod - a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator *= (const mint &a) {
		x = (ull)x * a.x % mod;
		return *this;
	}
	mint pow(ll pw) const {
		mint res = 1;
		mint cur = *this;
		while(pw) {
			if (pw & 1) res *= cur;
			cur *= cur;
			pw >>= 1;
		}
		return res;
	}
	mint inv() const {
		assert(x != 0);
		uint t = x;
		uint res = 1;
		while(t != 1) {
			uint z = mod / t;
			res = (ull)res * (mod - z) % mod;
			t = mod - t * z;
		}
		return res;
	}
	mint& operator /= (const mint &a) {
		return *this *= a.inv();
	}
	mint operator + (const mint &a) const {
		return mint(*this) += a;
	}
	mint operator - (const mint &a) const {
		return mint(*this) -= a;
	}
	mint operator * (const mint &a) const {
		return mint(*this) *= a;
	}
	mint operator / (const mint &a) const {
		return mint(*this) /= a;
	}

	bool sqrt(mint &res) const {
		if (mod == 2 || x == 0) {
			res = *this;
			return true;
		}
		if (pow((mod - 1) / 2) != 1) return false;
		if (mod % 4 == 3) {
			res = pow((mod + 1) / 4);
			return true;
		}
		int pw = (mod - 1) / 2;
		int K = 30;
		while((1 << K) > pw) K--;
		while(true) {
			mint t = myRand(mod);
			mint a = 0, b = 0, c = 1;
			for (int k = K; k >= 0; k--) {
				a = b * b;
				b = b * c * 2;
				c = c * c + a * *this;
				if (((pw >> k) & 1) == 0) continue;
				a = b;
				b = b * t + c;
				c = c * t + a * *this;
			}
			if (b == 0) continue;
			c -= 1;
			c *= mint() - b.inv();
			if (c * c == *this) {
				res = c;
				return true;
			}
		}
		assert(false);
	}

	bool operator == (const mint &a) const {
		return x == a.x;
	}
	bool operator != (const mint &a) const {
		return x != a.x;
	}
	bool operator < (const mint &a) const {
		return x < a.x;
	}
};
template<uint mod = MOD> struct Factorials {
	using Mint = mint<mod>;
	vector<Mint> f, fi;

	Factorials() : f(), fi() {}
	Factorials(int n) {
		n += 10;
		f = vector<Mint>(n);
		fi = vector<Mint>(n);
		f[0] = 1;
		for (int i = 1; i < n; i++)
			f[i] = f[i - 1] * i;
		fi[n - 1] = f[n - 1].inv();
		for (int i = n - 1; i > 0; i--)
			fi[i - 1] = fi[i] * i;
	}

	Mint C(int n, int k) {
		if (k < 0 || k > n) return 0;
		return f[n] * fi[k] * fi[n - k];
	}
};
template<uint mod = MOD> struct Powers {
	using Mint = mint<mod>;
	vector<Mint> p, pi;

	Powers() : p(), pi() {}
	Powers(int n, Mint x) {
		n += 10;
		if (x == 0) {
			p = vector<Mint>(n);
			p[0] = 1;
		} else {
			p = vector<Mint>(n);
			pi = vector<Mint>(n);
			p[0] = pi[0] = 1;
			Mint xi = x.inv();
			for (int i = 1; i < n; i++) {
				p[i] = p[i - 1] * x;
				pi[i] = pi[i - 1] * xi;
			}
		}
	}

	Mint pow(int n) {
		if (n >= 0)
			return p[n];
		else
			return pi[-n];
	}
};
template<uint mod = MOD> struct Inverses {
	using Mint = mint<mod>;
	vector<Mint> ii;

	Inverses() : ii() {}
	Inverses(int n) {
		n += 10;
		ii = vector<Mint>(n);
		ii[1] = 1;
		for (int x = 2; x < n; x++)
			ii[x] = Mint() - ii[mod % x] * (mod / x);
	}

	Mint inv(Mint x) {
		assert(x != 0);
		uint t = x.x;
		uint res = 1;
		while(t >= (int)ii.size()) {
			uint z = mod / t;
			res = (ull)res * (mod - z) % mod;
			t = mod - t * z;
		}
		return ii[t] * res;
	}
};
using Mint = mint<>;

const int LOG = 22; // CHECK!!!!
Powers W;
vector<int> binRev;
void initFFT() {
	binRev = vector<int>((1 << LOG) + 3, 0);
	Mint w = 2;
	while(true) {
		Mint x = w;
		for (int i = 1; i < LOG; i++)
			x *= x;
		if (x == -1) break;
		w += 1;
	}
	W = Powers(1 << LOG, w);
	for (int mask = 1; mask < (1 << LOG); mask++) {
		binRev[mask] = (binRev[mask >> 1] >> 1) ^ ((mask & 1) << (LOG - 1));
	}
}

static void fft(Mint* A, int k) {
	int L = 1 << k;
	for (int i = 0; i < L; i++) {
		int x = binRev[i] >> (LOG - k);
		if (i < x) swap(A[i], A[x]);
	}
	for (int lvl = 0; lvl < k; lvl++) {
		int len = 1 << lvl;
		for (int st = 0; st < L; st += (len << 1))
			for (int i = 0; i < len; i++) {
				Mint x = A[st + i], y = A[st + len + i] * W.pow(i << (LOG - 1 - lvl));
				A[st + i] = x + y;
				A[st + len + i] = x - y;
			}
	}
}

const int N = (int)2e6 + 77;
char a[N], b[N];
int n, m;
Mint F[7][(1 << LOG) + 5];

int findMatch(int len, int l, int L, int cand) {
	
	if (cand < MAGIC) {
		for (int i = 0; i < cand; i++) {
			bool ok = true;
			for (int j = 0; ok && j < len; j++) {
				char x = a[l + j], y = b[L + i + j];
				if (x != '-' && y != '-' && x != y)
					ok = false;
			}
			if (ok) return i;
		}
		return -1;
	}
	
	int k = 1;
	while((1 << k) <= cand + len + len) k++;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < (1 << k); j++)
			F[i][j] = 0;
	for (int i = 0; i < len; i++) {
		char c = a[l + i];
		assert(c != '*');
		if (c != '-') {
			int cc = (int)(c - 'a');
			F[1][len - i] += cc * cc;
			F[3][len - i] += cc;
			F[5][len - i] += 1;
		}
	}
	for (int i = 0; i < cand + len - 1; i++) {
		char c = b[L + i];
		assert(c != '*');
		if (c != '-') {
			int cc = (int)(c - 'a');
			F[2][i] += 1;
			F[4][i] += cc;
			F[6][i] += cc * cc;
		}
	}
	for (int i = 1; i < 7; i++)
		fft(F[i], k);
	for (int i = 0; i < (1 << k); i++) {
		F[0][i] = 0;
		for (int t = 1; t <= 3; t++) {
			Mint x = F[2 * t - 1][i] * F[2 * t][i];
			if (t == 2) x *= -2;
			F[0][i] += x;
		}
	}
	fft(F[0], k);
	reverse(F[0] + 1, F[0] + (1 << k));
	for (int i = 0; i < cand; i++) {
		if (F[0][len + i] == 0) return i;
	}
	return -1;
}
int findFirstMatch(int l, int r, int L, int R) {
	int p = r - l;
	while(L + p <= R) {
		int t = min(p, R - L - p + 1);
		int x = findMatch(p, l, L, t);
		if (x < 0 || x >= t) {
			L += t;
			continue;
		}
		return L + x;
	}
	return R;
}

bool isPrime(ll x) {
	for (ll y = 2; y * y <= x; y++) {
		if (x % y == 0)
			return false;
	}
	return true;
}

int main() {
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
/*
	ll x = (ll)(1.4e9) >> 23;
	while(!isPrime((x << 23) + 1)) x++;
	printf("%lld\n", (x << 23) + 1);
	return 0;
*/
	initFFT();

	scanf("%d%d", &n, &m);
	scanf("%s", a);
	scanf("%s", b);
	while(n > 0 && m > 0 && a[n - 1] != '*' && b[m - 1] != '*') {
		char x = a[n - 1];
		char y = b[m - 1];
		if (x != '-' && y != '-' && x != y) {
			printf("No\n");
			return 0;
		}
		n--;
		m--;
	}
	int p = 0, q = 0;
	while(p < n && q < m && a[p] != '*' && b[q] != '*') {
		char x = a[p];
		char y = b[q];
		if (x != '-' && y != '-' && x != y) {
			printf("No\n");
			return 0;
		}
		p++;
		q++;
	}
	if (p == n || q == m) {
		for (int i = p; i < n; i++) {
			if (a[i] != '*') {
				printf("No\n");
				return 0;
			}
		}
		for (int i = q; i < m; i++) {
			if (b[i] != '*') {
				printf("No\n");
				return 0;
			}
		}
		printf("Yes\n");
		return 0;
	}
	int mask = 0;
	for (int i = p; i < n; i++) {
		if (a[i] == '*') mask |= 1;
	}
	for (int i = q; i < m; i++) {
		if (b[i] == '*') mask |= 2;
	}
	if (mask == 3) {
		printf("Yes\n");
		return 0;
	}
	assert(mask > 0);
	if (mask == 2) {
		swap(a, b);
		swap(p, q);
		swap(n, m);
	}
	assert(a[p] == '*' && a[n - 1] == '*');
//	eprintf("HERE\n");
	while(p < n) {
		if (a[p] == '*') {
			p++;
			continue;
		}
		int r = p;
		while(a[r] != '*') r++;
		q = findFirstMatch(p, r, q, m);
		q += r - p;
		if (q > m) {
			printf("No\n");
			return 0;
		}
		p = r;
	}
	printf("Yes\n");

	return 0;
}