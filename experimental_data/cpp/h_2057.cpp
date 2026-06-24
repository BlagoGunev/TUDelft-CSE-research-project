#include <bits/stdc++.h>

namespace Initial {
	#define ll long long
	#define ull unsigned long long
	#define fi first
	#define se second
	#define mkp make_pair
	#define pir pair <ll, ll>
	#define pb push_back
	#define i128 __int128
	using namespace std;
	const ll maxn = 1e6 + 10, inf = 1e18, mod = 998244353;
	ll power(ll a, ll b = mod - 2, ll p = mod) {
		ll s = 1;
		while(b) {
			if(b & 1) s = 1ll * s * a %p;
			a = 1ll * a * a %p, b >>= 1;
		} return s;
	}
	template <class T>
	const inline ll pls(const T x, const T y) { return x + y >= mod? x + y - mod : x + y; }
	template <class T>
	const inline void add(T &x, const T y) { x = x + y >= mod? x + y - mod : x + y; }
	template <class T>
	const inline void chkmax(T &x, const T y) { x = x < y? y : x; }
	template <class T>
	const inline void chkmin(T &x, const T y) { x = x > y? y : x; }
} using namespace Initial;

namespace Read {
	char buf[1 << 22], *p1, *p2;
	// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 22) - 10, stdin), p1 == p2)? EOF : *p1++)
	template <class T>
	const inline void rd(T &x) {
		char ch; bool neg = 0;
		while(!isdigit(ch = getchar()))
			if(ch == '-') neg = 1;
		x = ch - '0';
		while(isdigit(ch = getchar()))
			x = (x << 1) + (x << 3) + ch - '0';
		if(neg) x = -x;
	}
} using Read::rd;

ll t, n, a[maxn], b[maxn], ans[maxn], stk[maxn], top;

void solve() {
	rd(n);
	for(ll i = 1; i <= n; i++) rd(a[i]), b[i] = a[i];
	top = 0;
	for(ll i = 1; i <= n; i++) {
		ans[i] = b[i];
		if(!b[i]) stk[++top] = i;
		else {
			ll w = b[i] - 1;
			while(top && w) {
				if(i - stk[top] + 1 <= w) {
					b[i + 1] += i - stk[top];
					w -= i - stk[top--] + 1;
				} else {
					b[i + 1] += w;
					stk[top] += w, w = 0;
				}
			}
			if(w && !top) {
				ll u = w % (i + 1), k = w / (i + 1);
				b[i + 1] += k * i + u;
				if(u) stk[top = 1] = u;
			}
		}
	} top = 0;
	for(ll i = 1; i <= n; i++) b[i] = 0;
	for(ll i = n; i; i--) {
		ans[i] += b[i], b[i] += a[i];
		if(!b[i]) stk[++top] = i;
		else {
			ll w = b[i] - 1;
			while(top && w) {
				if(stk[top] - i + 1 <= w) {
					b[i - 1] += stk[top] - i;
					w -= stk[top--] - i + 1;
				} else {
					b[i - 1] += w;
					stk[top] -= w, w = 0;
				}
			}
			if(w && !top) {
				ll u = w % (n - i + 2), k = w / (n - i + 2);
				b[i - 1] += k * (n - i + 1) + u;
				if(u) stk[top = 1] = n - u + 1;
			}
		}
	}
	for(ll i = 1; i <= n; i++) printf("%lld ", ans[i]); puts("");
}

int main() {
	rd(t); while(t--) solve();
	return 0;
}