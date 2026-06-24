#include <bits/stdc++.h>

using namespace std;

#define int long long

#define mp make_pair

#define inf 1e9

#define pii pair <int, int>

const int mod = 998244353;

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

inline int add(int x, int y) {

	x += y;

	if(x >= mod) x -= mod;

	return x;

}

inline int dec(int x, int y) {

	x -= y;

	if(x < 0) x += mod;

	return x;

}

inline void Add(int &x, int y) {

	x += y;

	if(x >= mod) x -= mod;

}

inline void Dec(int &x, int y) {

	x -= y;

	if(x < 0) x += mod;

}

inline int deal(int x) {

	return (x % mod + mod) % mod;

}

int n;

int a[1000005];

namespace Sub1 {

	int s[1000005];

	int sta[1000005], R[1000005], top;

	int solve() {

		int Ans = 0, s1 = 0, s2 = 0;

		for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];

		

		sta[top = 1] = 0;

		for(int i = 1; i <= n; i++) {

			if(a[i] >= 0) {

				while(top && s[sta[top]] <= s[i]) Dec(s1, (R[top] - R[top-1]) * deal(s[sta[top]]) % mod), top--;

				sta[++top] = i, R[top] = i, Add(s1, (R[top] - R[top-1]) * deal(s[sta[top]]) % mod);

				Add(s2, deal(s[i-1]));

				Add(Ans, dec(s1, s2));	

			}

			else {

				Add(Ans, dec(s1, s2));

				Add(s2, deal(s[i-1]));

				while(top && s[sta[top]] <= s[i]) Dec(s1, (R[top] - R[top-1]) * deal(s[sta[top]]) % mod), top--;

				R[top] = i, sta[++top] = i, R[top] = i, Add(s1, deal(s[sta[top-1]]) % mod);

			}

		}

		return Ans;

	}

};

namespace Sub2 {

	int f[1000005], g[1000005];

	int solve(int l, int r) {

		if(l == r) return (a[l] > 0) ? a[l] : 0;

		int mid = (l + r) / 2, Ans = 0;

		

		for(int i = mid, s = 0, mx = 0; i >= l; i--) s += a[i], mx = max(mx, s), s = (s < 0) ? 0 : s, f[i] = mx;

		for(int i = mid + 1, s = 0, mx = 0; i <= r; i++) s += a[i], mx = max(mx, s), s = (s < 0) ? 0 : s, f[i] = mx;

		

		for(int i = mid, s = 0; i >= l; i--) s += a[i], g[i] = max((i == mid) ? 0 : g[i+1], s);

		for(int i = mid + 1, s = 0; i <= r; i++) s += a[i], g[i] = max((i == mid + 1) ? 0 : g[i-1], s);

		

		int j = mid + 1, k = mid + 1;

		

		int sgj = 0, sfj = 0;

		for(int i = mid + 1; i <= r; i++) Add(sfj, deal(f[i]));

		

		for(int i = mid; i >= l; i--) {

			while(j <= r && f[i] >= max(f[j], g[i] + g[j])) {

				Dec(sgj, deal(g[j]));

				j++;

			}

			while(k <= r && (k < j || g[i] + g[k] >= f[k])) {

				Dec(sfj, deal(f[k])), Add(sgj, deal(g[k]));

				k++;

			}

			Add(Ans, deal(f[i]) * (j - mid - 1) % mod);

			Add(Ans, add(sgj, (k - j) * deal(g[i]) % mod));

			Add(Ans, sfj);

		}

		

		return add(add(solve(l, mid), solve(mid + 1, r)), Ans);	

	}

};

signed main () {

//	freopen (".in", "r", stdin);

//	freopen (".out", "w", stdout);

	int T = read();

	while(T--) {

		n = read();

		for(int i = 1; i <= n; i++) a[i] = read();

		write(add(Sub1 :: solve(), Sub2 :: solve(1, n))), putchar('\n');

	}

	return 0;

}

/*

*/