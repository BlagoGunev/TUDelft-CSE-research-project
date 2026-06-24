#include <bits/stdc++.h>

#pragma GCC optimize ("O3")

#pragma GCC optimize ("unroll-loops")

using namespace std;

using ll = int64_t;



constexpr size_t nmax = 100000 + 15;



void do_work();



ll n;

struct rr {

	ll a = 0, b = 0;

	ll ind = 0;

	bool operator<(const rr& rhs) const {

		return this->a < rhs.a;

	}

};



rr a[nmax];

ll ma[nmax];



ll recur(ll indice) {

	if (indice == 1) return a[indice].a;

	ll ret = max(recur(indice - 1), ma[indice - 2]);

	return max(min(ret, a[indice].a) + a[indice].b, a[indice].a);

}



void do_work() {

	cin >> n;

	ll k; cin >> k;



	for (ll i = 1; i <= n; ++ i) {

		cin >> a[i].a >> a[i].b;

		a[i].ind = i;

	}



	sort(a + 1, a + n + 1);



	for (ll i = 1; i <= n; ++ i) {

		ma[i] = max(ma[i - 1], a[i].a + a[i].b);

	}



	auto yes = [] () -> void { cout << "YES"; return; };

	auto no  = [] () -> void { cout << "NO";  return; };



	for (ll i = 1; i < n; ++ i) {

		if (a[i].a + a[i].b >= k) {

			if (a[i].ind == 1) return yes();

		}

	}



	if (a[n].ind == 1) if (recur(n) >= k) return yes();

	return no();



}



int32_t main() {

	std::ios_base::sync_with_stdio(false);

	std::cin.tie(nullptr); std::cout.tie(nullptr);

	ll t; cin >> t;

	for (; t -- > 0;) {

		do_work();

		cout << "\n";

	}

	return 0x0;

}



/// code by Eastern Tra Tra