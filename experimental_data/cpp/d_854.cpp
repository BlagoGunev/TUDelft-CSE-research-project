#include<bits/stdc++.h>
template <class T> inline void read(T &x) {
	int t; while (((t = getchar()) < '0' || t > '9') && t != '-') ;
	bool flag = false;
	if (t == '-') flag = true, t = getchar(); x = t - '0';
	while ((t = getchar()) >= '0' && t <= '9') x = x * 10 + (t - '0');
	if (flag) x = -x;
}
using namespace std;
typedef long long LL;
typedef pair<int, int> Pii;
const int maxn = 100010;
const int maxt = 1000010;
struct Node {
	int d, f, t, c;
	Node () {}
	Node (int a, int b, int c_, int d_) {
		d = a, f = b, t = c_, c = d_;
	}
	bool operator < (Node B)const {
		return d < B.d;
	}
} t[maxn];
int n, m, k;
LL x[maxn], y[maxn];
int mn[maxn];
bool vis[maxn];
int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	read(n), read(m), read(k);
	for (int i = 1, a, b, c, d; i <= m; ++i) {
		read(a), read(b), read(c), read(d);
		t[i] = Node(a, b, c, d);
	}
	sort(t + 1, t + m + 1);
	memset(x, -1, sizeof x);
	memset(y, -1, sizeof y);
	int cnt = 0;
	LL tot = 0;
	for (int i = 1; i <= m; ++i) {
		if (t[i].t == 0) {
			if (!vis[t[i].f]) {
				vis[t[i].f] = true;
				mn[t[i].f] = t[i].c;
				++cnt;
				tot += t[i].c;
			} else {
				if (t[i].c < mn[t[i].f]) {
					tot -= mn[t[i].f];
					tot += t[i].c;
					mn[t[i].f] = t[i].c;
				}
			}
		}
		if (cnt == n) {
			x[i] = tot;
			//cout << i << ' ' << x[i] << endl;
		}
	}
	tot = cnt = 0;
	LL ans = -1;
	memset(vis, false, sizeof vis);
	for (int i = m; i >= 2; --i) {
		if (t[i].f == 0) {
			if (!vis[t[i].t]) {
				vis[t[i].t] = true;
				mn[t[i].t] = t[i].c;
				++cnt;
				tot += t[i].c;
			} else {
				if (t[i].c < mn[t[i].t]) {
					tot -= mn[t[i].t];
					tot += t[i].c;
					mn[t[i].t] = t[i].c;
				}
			}
		}
		if (cnt == n) {
			int l = 1, r = i - 1, mid;
			while (l < r) {
				mid = (l + r + 1) >> 1;
				if (t[mid].d < t[i].d - k) {
					l = mid;
				} else {
					r = mid - 1;
				}
			}
			if (t[l].d >= t[i].d - k || x[l] == -1) continue;
			if (ans == -1 || tot + x[l] < ans)
				ans = tot + x[l];
		}
	}
	cout << ans << endl;
	return 0;
}