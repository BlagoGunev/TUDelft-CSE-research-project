#define _CRT_SECURE_NO_WARNINGS
#define TASK "painting"
#pragma comment(linker, "/STACK:210886422")
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
const int INF = 1000000001;
const double EPS = 1e-11;
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

	int n, x, y;
	string s;
	cin >> n >> x >> y >> s;

	int groupsZero = 0;
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && s[i] == s[j]) {
			++j;
		}
		if (s[i] == '0') {
			++groupsZero;
		}
	}
	if (groupsZero == 0) {
		cout << 0 << endl;
		myReturn();
	}

	long long ans = 1e18;
	for (int i = 1; i <= groupsZero; ++i) {
		ans = min(ans, (groupsZero - i) * 1ll * min(x, y) + i * 1ll * y);
	}
	cout << ans << endl;


	myReturn();
}