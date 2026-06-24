// Program written by Liu Zhaozhou ~~~
#include <bits/stdc++.h>
#include <tr1/unordered_map>
#define lowbit(x) (x & -x)

using namespace std;

inline char gc(void) {
	static char buf[100000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

#define gc() getchar()

template <class T> inline void read(T &x) {
	T f = 1; x = 0; static char c = gc();
	for (; !isdigit(c); c = gc()) if (c == '-') f = -f;
	for (; isdigit(c); c = gc()) x = (x << 1) + (x << 3) + (c & 15);
	x *= f;
}

inline void readstr(char *s) {
	do *s = gc(); while ((*s == ' ') || (*s == '\n') || (*s == '\r'));
	do *(++s) = gc(); while ((~*s) && (*s != ' ') && (*s != '\n') && (*s != '\r'));
	*s = 0; return;
}

inline void readch(char&x) { while (isspace(x = gc())); }

template <class T> inline void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

template <class T> inline void writeln(T x, char c = '\n') { write(x); putchar(c); }
template <class T> inline void chkmax(T &x, const T y) { x > y ? x = x : x = y; }
template <class T> inline void chkmin(T &x, const T y) { x < y ? x = x : x = y; }

#define Ms(arr, opt) memset(arr, opt, sizeof(arr))
#define Mp(x, y) make_pair(x, y)

typedef long long ll;

const int Maxn = 105;
int T, n, m; ll a[Maxn][Maxn], b[10];

signed main(void) {
	for (read(T); T; T--) {
		read(n), read(m); ll ans = 0;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) read(a[i][j]);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				b[1] = a[i][j], b[2] = a[n - i + 1][j];
				b[3] = a[i][m - j + 1], b[4] = a[n - i + 1][m - j + 1];
				sort(b + 1, b + 5); ll ret = 0; for (int k = 1; k <= 4; k++) ret += abs(b[k] - b[2]);
				a[i][j] = a[n - i + 1][j] = a[i][m - j + 1] = a[n - i + 1][m - j + 1] = b[2];
				if (n - i + 1 == i || m - j + 1 == j) ret >>= 1; ans += ret;
			}
		} writeln(ans);
	}
	return 0;
}

/**/