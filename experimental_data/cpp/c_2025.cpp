#include "bits/stdc++.h"
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long

#define OPEN freopen ("t3.in", "r", stdin); freopen ("t3.out", "w", stdout);
#define DATA freopen ("t3.in", "w", stdout);

#define pc __builtin_popcount
#define db double
#define pii pair<int, int>
#define fi first
#define se second

#define F(i,x,y) for (int i = (x); i <= (y); ++i)
#define D(i,x,y) for (int i = (x); i >= (y); --i)

using namespace std;

const ll inf = 1ll * 1e18;
// const ll mod = 998244353ll;
const ll mod = 1ll * 1e9 + 7ll;

namespace FastIO {
	inline void Rd(int& x) {
		int f = 1;
		x = 0;
		char c = getchar();
		while (c < '0' || c > '9') {
			if (c == '-') f = -1;
			c = getchar();
		}
		while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c - 48), c = getchar();
		x *= f;
	}

	inline void Wt(int x) {
		if (x < 10) {
			putchar(x + 48);
			return;
		}
		Wt(x / 10);
		putchar((x % 10) + 48);
	}
}

namespace Maths {
	ll fac[560000];

	void init() {

		fac[0] = 1ll;

		F(i, 1, 500000) fac[i] = fac[i - 1] * i % mod;
	}

	ll qpow(ll x, ll y) {
		if (y == 0ll) return 1ll;

		ll w = qpow(x, y / 2ll);

		if (y % 2ll) return (w * w % mod) * x % mod;
		else return w * w % mod;
	}

    ll qpow(ll x, ll y, ll p) {
        if (y == 0ll) return 1ll;
        ll w = qpow(x, y / 2ll, p);
        if (y % 2ll) return (w * w % p) * x % p;
        else return w * w % p;
    }

	inline ll C(ll x, ll y) {
		return (fac[x] * qpow(fac[y], mod - 2ll) % mod) * qpow(fac[x - y], mod - 2ll) % mod;
	}

	inline ll div(ll x) {
		return qpow(x, mod - 2ll);
	}
}

int n, k;

int a[310000];

void Main() {
	cin >> n >> k;
	F (i, 1, n) cin >> a[i];
	sort (a + 1, a + n + 1);
	int mx = 0;
	// F (i,1,n)cerr<<a[i]<<' ';cerr<<'\n';
	for (int l = 1, r = 1; r <= n; ++ r) {
		if (a[r] - a[r - 1] > 1) l = r;
		while ((a[r] - a[l] + 1) > k) ++ l;
		mx = max (mx, r - l + 1);
		// cerr<<l<<' '<<r<<'\n';
	}
	cout << mx << '\n';
}

int main() {
	int T;
	// IOS
	cin >> T; while (T --> 0) Main();
}