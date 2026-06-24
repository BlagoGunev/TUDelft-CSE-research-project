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

const int N = 55;
const int K = 14;
char s[N][N];
int p3[K];
int n, m, k;
int dp[(1 << K) + 3];
int c[K];

void calcRad(int x, int y) {
	for (int k = 0; k < K; k++)
		c[k] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (s[i][j] == '#') {
			int d = sqr(i - x) + sqr(j - y);
			for (int k = 1; k <= K; k++) if (d <= k * k)
				c[k - 1]++;
		}
}

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int mask = 0; mask < (1 << K); mask++)
		dp[mask] = 0;
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	while(k--) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		x--;y--;
		calcRad(x, y);
		for (int mask = 0; mask < (1 << K); mask++)
			for (int k = 0; k < K; k++) if ((mask >> k) & 1)
				dp[mask ^ (1 << k)] = max(dp[mask ^ (1 << k)], dp[mask] + w * c[k] - p3[k]);
	}
	printf("%d\n", dp[0]);
}

int main() {
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	p3[0] = 3;
	for (int k = 1; k < K; k++)
		p3[k] = p3[k - 1] * 3;

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		eprintf("--- Case #%d start ---\n", i);
		//printf("Case #%d: ", i);

		solve();

		//printf("%lld\n", (ll)solve());

		/*
		if (solve()) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
		*/

		eprintf("--- Case #%d end ---\n", i);
		eprintf("time = %.5lf\n", getCurrentTime());
		eprintf("++++++++++++++++++++\n");
	}


	return 0;
}