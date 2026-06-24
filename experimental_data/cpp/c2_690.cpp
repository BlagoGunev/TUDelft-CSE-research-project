#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define red(i, a, b) for(int i = (a); i >= (b); i--)
#define LD long double
#define ll long long
#define ull unsigned long long
#define abs ABS
#define sqr SQR
#define PII pair<int, int>
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
template<typename tn> void read(tn& a) {
    tn x = 0, f = 1; char c = getchar();
    while(!isdigit(c)) {
        if (c == '-') f = -1;
        c = getchar();
    }
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    a = x * f;
}
template<typename tn> void cmax(tn& a, tn b) { if (b > a) a = b; }
template<typename tn> void cmin(tn& a, tn b) { if (b < a) a = b; }
template<typename tn> tn abs(tn a) { return a < 0 ? -a : a; }
template<typename tn> tn sqr(tn a) { return a * a; }

const int N = 110000;
vector<int> E[N];
int d[N], vis[N], q[N];
int n, m;
int BFS(int s) {
	int l, r;
	memset(vis, 0, sizeof(vis));
	memset(d, 0, sizeof(d));
	d[s] = 0; vis[s] = 1;
	q[l = r = 1] = s;
	while(l <= r) {
		int x = q[l++];
		for(int i = 0; i < E[x].size(); i++) {
			int v = E[x][i];
			if (vis[v]) continue;
			d[v] = d[x] + 1;
			q[++r] = v; vis[v] = 1;
		}
	}
	int mx = 0, mxv = 0;
	rep(i, 1, n) if (d[i] > mx) mx = d[i], mxv = i;
	return mxv;
}
int main() {
	read(n); read(m);
	rep(i, 1, m) {
		int u, v; read(u); read(v);
		E[u].PB(v); E[v].PB(u);
	}
	int rt = BFS(1);
	int v = BFS(rt);
	printf("%d\n", d[v]);
	return 0;
}