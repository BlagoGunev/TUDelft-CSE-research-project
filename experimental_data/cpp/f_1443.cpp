#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define swap Swap
#define max Max
#define min Min

using namespace std;

inline char gc() {
	static char buf[1000010], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf)+fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

template<typename T> inline void read(T& x) {
	char ch = getchar(); T a = 0, b = 1;
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') ch = getchar(), b = -1;
	while (ch >= '0' && ch <= '9') a = a*10+ch-'0', ch = getchar();
	x = a*b;
}

template<typename T> inline void Swap(T& x, T& y) {x = x^y; y = x^y; x = x^y;}
template<typename T> inline void chkmin(T& x, T y) {x = (y < x ? y : x);}
template<typename T> inline void chkmax(T& x, T y) {x = (y > x ? y : x);}
template<typename T> inline T Min(T x, T y) {return x < y ? x : y;}
template<typename T> inline T Max(T x, T y) {return x > y ? x : y;}

const int maxn = 2e5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int T, n, m, k, ans, a[maxn+10], b[maxn+10], c[maxn+10];

int powe(int base, int p) {
	int res = 1;
	for (; p >= 1; p >>= 1, base = 1ll*base*base%mod)
		if (p&1) res = 1ll*res*base%mod;
	return res;
}

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	read(T);
	while (T--) {
		read(n); read(k);
		for (int i = 1; i <= n; ++i)
			c[i] = 0;
		for (int i = 1; i <= n; ++i)
			read(a[i]);
		for (int i = 1; i <= k; ++i)
			read(b[i]), c[b[i]] = i;
		int ok = 1;
		a[0] = a[n+1] = n+1; c[n+1] = inf;
		for (int i = 1; i <= n; ++i)
			if (c[a[i]] && c[a[i-1]] && c[a[i+1]] && c[a[i]] < c[a[i-1]] && c[a[i]] < c[a[i+1]]) {
				ok = 0; break;
			}
		if (ok) {
			int cnt = c[a[0]] = 0;
			for (int i = 1; i <= n; ++i)
				if (!c[a[i-1]] && c[a[i]]) ++cnt;
			if (c[a[1]]) --cnt;
			if (c[a[n]]) --cnt;
			printf("%d\n", powe(2, cnt));
		} else printf("0\n");
	}
	return 0;
}