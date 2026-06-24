#include<bits/stdc++.h>

#define fec(i, x, y) (int i = head[x], y = g[i].to; i; i = g[i].ne, y = g[i].to)
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define File(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)
#define fi first
#define se second
#define pb push_back

template<typename A, typename B> inline char smax(A &a, const B &b) {return a < b ? a = b , 1 : 0;}
template<typename A, typename B> inline char smin(A &a, const B &b) {return b < a ? a = b , 1 : 0;}

typedef long long ll; typedef unsigned long long ull; typedef std::pair<int, int> pii;

template<typename I>
inline void read(I &x) {
	int f = 0, c;
	while (!isdigit(c = getchar())) c == '-' ? f = 1 : 0;
	x = c & 15;
	while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c & 15);
	f ? x = -x : 0;
}

const int N = 2e5 + 7;
const int P = 998244353;

int n;
int fac[N], deg[N];

inline void work() {
	int ans = 1;
	fac[0] = 1; for (int i = 1; i <= n; ++i) fac[i] = (ll)fac[i - 1] * i % P;
	for (int i = 1; i <= n; ++i) ans = (ll)ans * deg[i] % P * fac[deg[i] - 1] % P;
	ans = (ll)ans * n % P;
	printf("%d\n", ans);

}

inline void init() {
	read(n);
	for (int i = 1; i < n; ++i) {
		int x, y;
		read(x), read(y);
		++deg[x], ++deg[y];
	}
}

int main() {
	#ifdef hzhkk
//	freopen("hkk.in", "r", stdin);
	#endif
	init();
	work();
	fclose(stdin), fclose(stdout);
}