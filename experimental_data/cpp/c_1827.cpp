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
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 500500;
const int LOG = 19;
int p2[N];
char s[N];
int sparse[LOG][N];
int n;
int z[N];
int dp[N];

void setMax(int l, int r, int x) {
	int k = p2[r - l];
	sparse[k][l] = max(sparse[k][l], x);
	sparse[k][r - (1 << k)] = max(sparse[k][r - (1 << k)], x);
}
void solve() {
	scanf("%d %s", &n, s);
	for (int k = 0; k < LOG; k++)
		for (int i = 0; i <= n; i++)
			sparse[k][i] = -1;
	for (int i = 0; i <= n; i++)
		z[i] = 0;
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i < r)
			z[i] = min(r - i, z[l + r - i]);
		while(i - z[i] > 0 && i + z[i] < n && s[i - z[i] - 1] == s[i + z[i]]) z[i]++;
		if (i + z[i] > r) {
			r = i + z[i];
			l = i - z[i];
		}
	}
	for (int i = 1; i < n; i++) if (z[i] > 0)
		setMax(i + 1, i + z[i] + 1, i);
	for (int k = LOG - 2; k >= 0; k--)
		for (int i = 0; i + (1 << (k + 1)) <= n + 1; i++) {
			sparse[k][i] = max(sparse[k][i], sparse[k + 1][i]);
			sparse[k][i + (1 << k)] = max(sparse[k][i + (1 << k)], sparse[k + 1][i]);
		}
	for (int i = 0; i <= n; i++)
		dp[i] = 0;
	for (int i = 1; i <= n; i++) {
		int x = sparse[0][i];
		x = 2 * x - i;
		if (x < 0) continue;
		dp[i] = dp[x] + 1;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += dp[i];
	printf("%lld\n", ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++)
		p2[i] = p2[i / 2] + 1;

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