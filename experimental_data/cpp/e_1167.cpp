#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define Size(x) ((int)((x).size()))
#define rep(i, l, r) for(int (i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for(int (i) = (r); (i) >= (l); --(i))
#define chkmax(x, y) (x) = max((x), (y))
#define chkmin(x, y) (x) = min((x), (y))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> VI;
inline char gc() {
	static char now[1 << 16], *S, *T;
	if (S == T) {T = (S = now) + fread(now, 1, 1 << 16, stdin); if (S == T) return EOF;}
	return *S ++;
}
#define gc getchar
inline int read() {
	int x = 0, f = 1; char c = gc();
	while (c < '0' || c > '9') {(c == '-') ? (f = 0) : 0; c = gc();}
	while (c >= '0' && c <= '9') {x = (x << 3) + (x << 1) + (c ^ 48); c = gc();}
	return f ? x : ((~ x) + 1);
}

const int N = 1000010;

int n, X, a[N];

int mx[N], mn[N], f[N], g[N];

int s[N];

int main() {
	n = read(); X = read();
	memset(mn, 63, sizeof(mn));
	rep(i, 1, n) {
		a[i] = read();
		chkmax(mx[a[i]], i);
		chkmin(mn[a[i]], i);
	}
	
	rep(i, 1, X) {
		if (!mx[i]) f[i] = f[i - 1];
		else if (mn[i] > f[i - 1]) f[i] = mx[i];
		else {
			for (; i <= X; ++ i) f[i] = -1;
		}
	}
	
	g[X + 1] = n + 1;
	per(i, X, 1) {
		if (!mx[i]) g[i] = g[i + 1];
		else if (mx[i] < g[i + 1]) g[i] = mn[i];
		else {
			for (; i; -- i) g[i] = -1;
		}
	}
	s[0] = 1;
	rep(i, 1, X) s[i] = s[i - 1] + (g[i] != -1);
	s[X + 1] = s[X] + 1;
	
	ll ans = 0;
	
//	rep(i, 0, X + 1) printf("%d ", f[i]); puts("");
//	rep(i, 0, X + 1) printf("%d ", g[i]); puts("");
	
	rep(i, 0, X) {
		if (f[i] == -1) continue ;
		int p = lower_bound(g + i + 1, g + X + 2, f[i]) - g;
//		printf("$ %d\n", p);
		if (p <= X + 1) ans += s[X + 1] - s[p - 1];
		if (i + 1 == p) -- ans;
	}
	printf("%lld\n", ans);
	
	return 0;
}