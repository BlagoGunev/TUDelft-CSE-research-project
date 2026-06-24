// LUOGU_RID: 96701848
#include <bits/stdc++.h>

using namespace std;

#define int long long

#define mp make_pair

#define inf 1e9

#define pii pair <int, int>

const int mod = 1e9 + 7;

inline int read () {

	int x = 0, f = 1;

	char ch = getchar ();

	while (ch < '0' || ch > '9') f = ((ch == '-') ? -1 : f), ch = getchar ();

	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar ();

	return x * f;

}

inline void write (int x) {

	if (x < 0) x = -x, putchar ('-');

	if (x >= 10) write (x / 10);

	putchar (x % 10 + '0');

}

inline int Abs(int x) {

	if(x > 0) return x;

	return -x;

}

int n, bas, Ans;

int a[200005], b[200005], sb[200005];

signed main () {

//	freopen (".in", "r", stdin);

//	freopen (".out", "w", stdout);

	n = read();

	for(int i = 1; i <= n; i++) a[i] = read();

	for(int i = 1; i <= n; i++) b[i] = read();

	sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);

	for(int i = 1; i <= n; i++) sb[i] = sb[i-1] + b[i];

	for(int i = 1; i <= n; i++) {

		int p = lower_bound(b + 1, b + 1 + n, a[i]) - b - 1;

		bas += (a[i] * p - sb[p]) + (sb[n] - sb[p] - a[i] * (n - p));

	}

	for(int i = 1; i <= n; i++) Ans += Abs(a[i] - b[i]);

	write(Ans + bas - Ans * n), putchar('\n');

	return 0;

}

/*

*/