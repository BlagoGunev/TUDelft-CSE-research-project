// Hydro submission #6711d12cf512b2475ea1479f@1729220908911
#include <bits/stdc++.h>

#define ms(x, v) memset(x, v, sizeof(x))

#define il __attribute__((always_inline)) static

#define U(i,l,r) for(int i(l),END##i(r);i<=END##i;++i)

#define D(i,r,l) for(int i(r),END##i(l);i>=END##i;--i)

using namespace std;

using ll = long long;



#define IC isdigit(c)

#define GC c=getchar()

void rd(auto &x) { x = 0; char GC; bool f = 0;

	for (; !IC; GC) f |= c == '-';

	for (; IC; GC) x = x * 10 + c - 48;

	if (f) x = -x;

}

void rd(auto &x, auto &...y) { rd(x); rd(y...); }

#define meow(...) fprintf(stderr, __VA_ARGS__)

#define Assert(e, v) if (!(e)) { meow("AF@%d\n", __LINE__ ); exit(v); }



#define vc vector

#define eb emplace_back

#define pb push_back



const int N = 35005;

int n; ll A[N], L[N], R[N];



ll calc(ll x1) {

	priority_queue<ll, vc<ll>, greater<ll>> qr;

	priority_queue<ll> ql;

	ll dl = x1, dr = x1, b = abs(x1); // b: 维护 dl 处的点值

	U (i, 1, n + 5) ql.push(0), qr.push(0);

	ll k = -(n + 5);

	U (i, 2, n) {

		dl -= R[i] - A[i]; dr += A[i] - L[i];

		assert(dl <= dr);

		

		--k; b += abs(dl);

		if (0 <= ql.top() + dl) {

			ql.push(0 - dl);

			ql.push(0 - dl);

		} else {

			qr.push(0 - dr);

			qr.push(0 - dr);

		}

		

		while (ql.size() > -k) {

			ll x = ql.top() + dl; ql.pop();

			qr.push(x - dr);

		}

		while (ql.size() < -k) {

			ll x = qr.top() + dr; qr.pop();

			ql.push(x - dl);

		}

	}

	

	vc<ll> pt;

	while (ql.size()) {

		ll x = ql.top(); ql.pop();

		pt.pb(x + dl);

	}

	reverse(pt.begin(), pt.end());

	while (qr.size()) {

		ll x = qr.top(); qr.pop();

		pt.pb(x + dr);

	}

//	if (!is_sorted(pt.begin(), pt.end()))

//		puts("fuck");

//	assert(is_sorted(pt.begin(), pt.end()));

	

	ll l = L[1] - A[1] + x1, r = R[1] - A[1] + x1;

	ll res = 1e18;

	U (i, 0, pt.size() - 2) {

		ll u = pt[i], v = pt[i + 1];

		++k;

		if (u < dl) continue;

		if (v > dr) break;

		if (!(r < u || l > v)) {

			if (l <= u)

				res = min(res, b);

			else

				res = min(res, b + (l - u) * k);

			if (r >= v)

				res = min(res, b + (v - u) * k);

			else

				res = min(res, b + (r - u) * k);

		}

		b += k * (v - u);

	}

	return res;

}



int main() {

//	freopen("ava.in", "r", stdin);

	

	rd(n);

	U (i, 1, n) rd(A[i], L[i], R[i]);

	

	ll l = -2e9, r = 2e9, ans = 1e18;

	while (l < r) {

		if (r - l <= 3) {

			U (i, l, r)

				ans = min(ans, calc(i));

			break;

		}

		ll x1 = l + (r - l) / 3, x2 = r - (r - l) / 3;

		ll v1 = calc(x1),

			v2 = calc(x2);

		if (v2 <= v1) l = x1;

		else r = x2;

	}

//	ans = calc(0);

	

	printf("%lld\n", ans);

}

// mamashengde