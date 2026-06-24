#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#define R register
#define ll long long
using namespace std;
const int N = 110000;

int n, m, a[N], b[N];
ll ans;

template <class T> inline void read(T &x) {
	x = 0;
	char ch = getchar(), w = 0;
	while (!isdigit(ch))
		w = (ch == '-'), ch = getchar();
	while (isdigit(ch))
		x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x = w ? -x : x;
	return;
}

int main() {
	int maxA = 0, minB = 1e9, secA = 0;
	read(n), read(m);
	for (R int i = 1; i <= n; ++i) {
		read(a[i]);
		if (a[i] > maxA)
			secA = maxA, maxA = a[i];
		else
			secA = max(secA, a[i]);
		ans += (ll) a[i] * m;
	}
	for (R int i = 1; i <= m; ++i)
		read(b[i]), minB = min(minB, b[i]);
	if (maxA > minB) {
		cout << -1;
		return 0;
	}
	for (R int i = 1; i < m; ++i)
		ans += b[i] - maxA;
	cout << (ans + b[m] - (maxA == minB ? maxA : secA));
	return 0;
}