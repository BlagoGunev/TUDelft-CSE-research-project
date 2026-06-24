#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#define TASK "movetofront"
#pragma comment(linker, "/STACK:810886422")
#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <complex>
using namespace std;

const int MOD = 1000000007;
const int INF = 1000000017;
const double EPS = 1e-9;
const int HASH_POW = 29;
const long double PI = acos(-1.0);
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

long long nextLong(long long l, long long r) {
	uniform_int_distribution <long long> foo(l, r);
	return foo(rnd);
}

double nextDouble(double l, double r) {
	uniform_real_distribution <double> foo(l, r);
	return foo(rnd);
}

double workTime() {
	return double(clock()) / CLOCKS_PER_SEC;
}

void myReturn(int code = 0) {
#ifdef MYDEBUG
	cout << "\nTime = " << fixed << setprecision(3) << workTime() << endl;
#endif
	exit(code);
}

vector <int> pr;
void precalc() {
	bool p[100010];
	memset(p, true, sizeof p);
	for (int i = 2; i*i <= 100000; ++i) {
		if (p[i]) {
			for (int j = i*i; j <= 100000; j += i) {
				p[j] = false;
			}
		}
	}
	for (int i = 2; i <= 100000; ++i) {
		if (p[i]) {
			pr.push_back(i);
		}
	}
}
long long gcd(long long a, long long b) {
	if (!b) {
		return a;
	}
	return gcd(b, a % b);
}
long long binMult(long long a, long long b, long long p) {
	long long res = 0;
	while (b) {
		if (b & 1) {
			res = (res + a) % p;
		}
		b >>= 1;
		a = (a + a) % p;
	}
	return res;
}
long long binPow(long long a, long long k, long long p) {
	long long res = 1;
	while (k) {
		if (k & 1) {
			res = binMult(res, a, p);
		}
		k >>= 1;
		a = binMult(a, a, p);
	}
	return res;
}
bool isProbablyPrime(long long p) {
	if (p == 2) return true; if (p == 1 || p % 2 == 0) return false;
	long long s = p - 1; while (s % 2 == 0) s /= 2;
	for (int iter = 0; iter < 20; ++iter) { // 15-20 iterations should be enough
		long long a = nextLong(1, p - 1), tmp = s, mod = binPow(a, tmp, p);
		while (tmp != p - 1 && mod != 1 && mod != p - 1) { mod = binMult(mod, mod, p); tmp *= 2; }
		if (mod != p - 1 && tmp % 2 == 0) return false;
	}
	return true;
}
long long f(long long a, long long n, long long &has) { return (binMult(a, a, n) + has) % n; }
vector <long long> factor(long long d) {
	vector <long long> res;
	for (int i = 0; i < pr.size() && pr[i] * 1ll * pr[i] <= d; ++i) {
		if (d % pr[i] == 0) {
			while (d % pr[i] == 0)
				d /= pr[i];
			res.push_back(pr[i]);
		}
	}
	if (d > 1) { // now d have at most 2 prime factors
		if (isProbablyPrime(d))
			res.push_back(d);
		else while (true) {
			long long has = nextLong(47, 2367), x = 2, y = 2, c = 1;
			for (; c == 1; c = gcd(abs(x - y), d)) {
				x = f(x, d, has),
					y = f(f(y, d, has), d, has);
			}
			if (c != d) {
				res.push_back(c);
				d /= c;
				if (d != c)
					res.push_back(d);
				break;
			}
		}
	}
	return res;
}

int rev[101], dp[10001][60];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef MYDEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	/*freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);*/
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
#endif

	precalc();
	for (int i = 1; i <= 100; ++i) {
		rev[i] = binPow(i, MOD - 2, MOD);
	}
	long long n;
	int k;
	cin >> n >> k;

	vector <long long> a = factor(n);
	vector <int> b(a.size());
	long long foo = n;
	for (int i = 0; i < a.size(); ++i) {
		while (foo % a[i] == 0) {
			++b[i];
			foo /= a[i];
		}
	}

	int ans = 1;
	for (int i = 0; i < a.size(); ++i) {
		memset(dp, 0, sizeof dp);
		dp[0][b[i]] = 1;
		for (int x = 0; x < k; ++x) {
			for (int y = 0; y <= b[i]; ++y) {
				for (int z = 0; z <= y; ++z) {
					dp[x + 1][z] = (dp[x + 1][z] + dp[x][y] * 1ll * rev[y + 1]) % MOD;
				}
			}
		}
		int cur = 0, mult = 1;
		for (int y = 0; y <= b[i]; ++y) {
			cur = (cur + mult * 1ll * dp[k][y]) % MOD;
			mult = binMult(mult, a[i], MOD);
		}
		ans = binMult(ans, cur, MOD);
	}
	cout << ans << endl;

	myReturn();
}