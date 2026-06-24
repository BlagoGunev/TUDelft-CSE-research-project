#include <bits/stdc++.h>
#define il inline
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define mid ((l+r)>>1)
#define MAXN 200050
#define MAXM 
#define mod 998244353
#define inf (1<<30)
#define eps (1e-6)
#define alpha 0.75
#define rep(i, x, y) for(register int i = x; i <= y; ++i)
#define repd(i, x, y) for(register int i = x; i >= y; --i)
#define file(s) freopen(s".in", "r", stdin), freopen(s".my", "w", stdout)
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
int n, deg[MAXN];
ll fac[MAXN];
int main() {
	read(n), fac[0] = 1; int u, v;
	rep(i, 1, n) fac[i] = fac[i-1] * i % mod;
	rep(i, 1, n-1) read(u, v), ++deg[u], ++deg[v];
	ll ans = 1;
	rep(i, 1, n) ans = ans * fac[deg[i]] % mod;
	ans = ans * n % mod;
	cout << ans << endl;
	return 0;
}