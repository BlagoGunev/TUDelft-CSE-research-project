#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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

const int N = (int)1e7 + 77;
char a[N], b[N];
int n, m;


int main() {
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	scanf("%s", a);
	scanf("%s", b);
	int P = 0, Q = 0;
	while(P < n && a[P] == b[P]) P++;
	while(Q < n && a[n - 1 - Q] == b[m - 1 - Q]) Q++;
	if (P + Q <= n) {
		printf("0\n");
		return 0;
	}
	int X = m - n;
	vector<int> d;
	for (int i = 1; i * i <= X; i++) if (X % i == 0) {
		d.push_back(i);
		if (i * i != X) d.push_back(X / i);
	}
	ll ans = 0;
	for (int x : d) {
		if (P + Q - n < x) continue;
		if (memcmp(b + P - x, b + P, m - n) == 0)
			ans += P + Q - n - x + 1;
	}
	printf("%lld\n", ans);

	return 0;
}