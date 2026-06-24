#include <cmath>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 300007
using namespace std;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = 1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = x * 10 + (c ^ 48);
		c = getchar();
	}
	return f ? -x : x;
}

int n, q, a[N];

long long ans;

inline void del(int p) {
	if (a[p] > a[p - 1]) ans -= a[p] - a[p - 1];
	if (a[p + 1] > a[p]) ans -= a[p + 1] - a[p];
}

inline void add(int p) {
	if (a[p] > a[p - 1]) ans += a[p] - a[p - 1];
	if (a[p + 1] > a[p]) ans += a[p + 1] - a[p];
}

inline void work() {
	ans = 0;
	n = rd(); q = rd();
	for (int i = 1; i <= n; ++i) {
		a[i] = rd();
		ans += max(0, a[i] - a[i - 1]);
	}
	a[n + 1] = 0;
	printf("%lld\n", ans);
	for (int i = 1, l, r; i <= q; ++i) {
		l = rd(); r = rd();
		del(l); del(r);
		if (l == r - 1) ans += max(0, a[r] - a[l]);
		swap(a[l], a[r]);
		add(l); add(r);
		if (l == r - 1) ans -= max(0, a[r] - a[l]);
		printf("%lld\n", ans);
	}
}

int main() {
	int t = rd();
	while (t--) work();
	return 0;
}