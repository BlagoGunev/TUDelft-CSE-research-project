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
const int N = 100010;
int n, m, a[N], b[N], c[N], id[N], tot = 0;
vector<pii> con[522]; int num[522];
bool vis[522];
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(); m = read();
	rep(i, 1, n) {
		int cnt = read();
		rep(j, 1, cnt) {
			a[i] |= (1 << (read() - 1));
		}
		num[a[i]] ++;
	}
	rep(i, 1, m) {
		c[i] = read();
		int cnt = read();
		rep(j, 1, cnt) {
			b[i] |= (1 << (read() - 1));
		}
		con[b[i]].pb(mk(c[i], i));
	}
	rep(i, 0, 511) {
		sort(con[i].begin(), con[i].end());
		for (int j = 0; j < 2 && j < Size(con[i]); ++ j) {
			id[++ tot] = con[i][j].se;
		}
	}
	pii ans = mk(0, 0x7fffffff);
	int ans1 = 0, ans2 = 0;
	rep(i, 1, tot) {
		rep(j, 1, i - 1) {
			int cost = c[id[i]] + c[id[j]], ss = 0;
			int s1 = b[id[i]], s2 = b[id[j]];
			
			int s = s1 | s2;
			for (int x = s; x; x = (x - 1) & s) {
				ss += num[x];
			}
			ss += num[0];
			
//			for (int x = (s1 - 1) & s1; x; x = (x - 1) & s1) {
//				assert((x & s1) == x);
//				if (vis[x]) continue ;
//				vis[x] = 1;
//				ss += num[x];
//			}
//			ss += num[0];
//			for (int x = (s2 - 1) & s2; x; x = (x - 1) & s2) {
//				assert((x & s2) == x);
//				if (vis[x]) continue ;
//				vis[x] = 1;
//				ss += num[x];
//			}
			if (ans.fi < ss) ans = mk(ss, cost), ans1 = id[i], ans2 = id[j];
			else if (ans.fi == ss) {
				if (ans.se > cost) {
					ans.se = cost;
					ans1 = id[i], ans2 = id[j];
				}
			}
			
//			for (int x = (s1 - 1) & s1; x; x = (x - 1) & s1) {
//				vis[x] = 0;
//			}
//			for (int x = (s2 - 1) & s2; x; x = (x - 1) & s2) {
//				vis[x] = 0;
//			}
			
		}
	}
//	printf("%d\n", ans.fi);
	printf("%d %d\n", ans1, ans2);
	return 0;
}