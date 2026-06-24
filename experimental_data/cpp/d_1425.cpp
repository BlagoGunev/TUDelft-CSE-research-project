#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Fr = 0;
template<class T>inline void Read(T &x) {
	x = Fr = 0;
	T f = 1;
	char p = getchar();
	for(; !isdigit(p); p = getchar()) {
		if(p == EOF)
			return;
		if(p == '-')
			f = -1;
	}
	for(; isdigit(p); p = getchar())
		x = x * 10 + (p - 48);
	x *= f, Fr = 1;
}
/*================Header Template==============*/
const int maxn = 2005, mod = 1e9 + 7, lim = 1000;
int c[maxn][maxn], n, m, R, x[maxn], y[maxn], b[maxn], cnt[maxn >> 1][maxn >> 1], all[maxn];
inline int Add(int x, int y) {
	return (x += y) >= mod ? x - mod : x;
}
inline int Sub(int x, int y) {
	return (x -= y) < 0 ? x + mod : x;
}
inline int Mul(int x, int y) {
	return 1ll * x * y % mod;
}
inline int Pow(int x, int y) {
	int res = 1;
	for(; y; x = Mul(x, x), y >>= 1)
		if(y & 1)
			res = Mul(res, x);
	return res;
}
inline int Sum(int l, int d, int r, int u) {
	if(l > r || d > u)
		return 0;
	return cnt[r][u] - cnt[r][d - 1] - cnt[l - 1][u] + cnt[l - 1][d - 1];
}
inline int Solve(int n, int x) {
//	cerr << " Solve (" << x << ")" << endl;
	return Sub(c[n][m], c[n - x][m]);
}
int main() {
	for(int i = 0; i < maxn; ++ i) {
		c[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			c[i][j] = Add(c[i - 1][j - 1], c[i - 1][j]);
	}
//	for(int i = 0; i < 6; ++ i, puts(""))
//		for(int j = 0; j <= i; ++j)
//			cerr << c[i][j] << " ";
	Read(n), Read(m), Read(R);
	for(int i = 1; i <= n; ++ i)
		Read(x[i]), Read(y[i]), Read(b[i]), ++ cnt[x[i]][y[i]];
	for(int i = 1; i <= lim; ++ i)
		for(int j = 1; j <= lim; ++ j)
			cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
	int ans = 0;
	for(int i = 1; i <= n; ++ i)
		all[i] = Sum(max(1, x[i] - R), max(1, y[i] - R), min(lim, x[i] + R), min(lim, y[i] + R));
	for(int i = 1; i <= n; ++ i) {
		// cerr << all[i] << endl;
		ans = Add(ans, Mul(Mul(b[i], b[i]), Sub(c[n][m], c[n - all[i]][m])));
		// cerr << " Go " << i << ": " << Sub(c[n][m], c[n - all[i]][m]) << endl;
		for(int j = i + 1; j <= n; ++ j) {
			int l = max(1, max(x[i] - R, x[j] - R)), r = min(lim, min(x[i] + R, x[j] + R)),
				d = max(1, max(y[i] - R, y[j] - R)), u = min(lim, min(y[i] + R, y[j] + R)), tot = Sum(l, d, r, u);
			ans = Add(ans, Mul(Mul(2, Mul(b[i], b[j])), Sub(Sub(Solve(n, all[i] + all[j] - tot), Solve(n - all[j], all[i] - tot)), Solve(n - all[i], all[j] - tot))));
			// cerr << i << " and " << j << " " << tot << " Ways :" << Solve(n, all[i] + all[j] - tot) - Solve(n - all[j], all[i] - tot) - Solve(n - all[i], all[j] - tot) << endl;
		}
	}
	printf("%d\n", ans);
}