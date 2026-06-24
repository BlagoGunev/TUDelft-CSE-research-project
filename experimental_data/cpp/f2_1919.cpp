// #include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <queue>
#define il inline
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define mid ((l+r)>>1)
#define MAXN 500005
#define MAXM 
#define mod 
#define inf (1ll << 30)
#define eps (1e-6)
#define alpha 0.75
#define rep(i, x, y) for( int i = x; i <= y; ++i)
#define repd(i, x, y) for( int i = x; i >= y; --i)
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
template <typename T> il bool chkmin(T &x, T y) {return x > y ? x = y, 1 : 0;}
template <typename T> il bool chkmax(T &x, T y) {return x < y ? x = y, 1 : 0;}
template <typename T> il void read(T &x) {
	char ch = getchar(); int f = 1; x = 0;
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = x*10+ch-'0', ch = getchar();
	x *= f;
}
template <typename T, typename... Args> il void read(T &x, Args &...args) {
	read(x), read(args...);
}
int n, q;
ll a[MAXN], b[MAXN], c[MAXN];
struct SGT {
	struct node {
		ll c0, c1, y0, y1;
	} t[MAXN << 2];
	node merge(node &x, node &y) {
		node r;
		r.c0 = x.c0 + min(y.c0 + x.y0, y.c1);
		r.c1 = min(x.c1 + min(y.c0 + x.y1, y.c1), ll(1e18));
		r.y0 = min(y.y1, max(0ll, x.y0 - (y.c1 - y.c0)) + y.y0);
		r.y1 = min(y.y1, max(0ll, x.y1 - (y.c1 - y.c0)) + y.y0);
		return r;
	}
	node create(ll a, ll b, ll c) {
		return node {min(a, b), b, min(max(a-b, 0ll), c), c};
	}
	void build(int u, int l, int r) {
		if(l == r) return (void)(t[u] = create(a[l], b[l], c[l]));
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		t[u] = merge(t[u << 1], t[u << 1 | 1]);
		// cout << u << ' ' << t[u].c0 << ' ' << t[u].c1 << ' ' << t[u].y0 << ' ' << t[u].y1 << endl;
	}
	void modify(int u, int l, int r, int x) {
		if(l == r) return (void)(t[u] = create(a[l], b[l], c[l]));
		if(x <= mid) modify(u << 1, l, mid, x);
		else modify(u << 1 | 1, mid + 1, r, x);		
		t[u] = merge(t[u << 1], t[u << 1 | 1]);
		// cout << u << ' ' << l << ' ' << r << ' ' << t[u].c0 << ' ' << t[u].c1 << ' ' << t[u].y0 << ' ' << t[u].y1 << endl;
	}
	ll ans() {
		return t[1].c0;
	}
} T;

int main() {
	read(n, q);
	rep(i, 1, n) read(a[i]);
	rep(i, 1, n) read(b[i]);
	rep(i, 1, n-1) read(c[i]);
	T.build(1, 1, n);
	ll p, x, y, z;
	while(q--) {
		read(p, x, y, z);
		a[p] = x, b[p] = y, c[p] = z;
		T.modify(1, 1, n, p);
		printf("%lld\n", T.ans());
	}
	return 0;
}