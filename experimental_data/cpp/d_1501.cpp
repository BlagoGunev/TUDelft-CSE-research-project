#include <bits/stdc++.h>



using namespace std;

using ll = long long;



int ____ = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), 1);



// END OF HEADER | Author: Roger Young



using i128 = __int128_t;



std::tuple<ll, ll, ll> exgcd(ll a, ll b) {

	if (!b) {

		return {1, 0, a};

	}

	auto [y, x, g] = exgcd(b, a % b);

	return {x, y - a / b * x, g};

}



template <class Comp> // last true

ll lower(ll l, ll r, Comp check) {

	if (!check(l))

		return l - 1;

	while (l < r) {

		ll m = (l + r + 1) >> 1;

		if (check(m))

			l = m;

		else

			r = m - 1;

	}

	return l;

}



template <class Comp> // first true

ll upper(ll l, ll r, Comp check) {

	if (!check(r))

		return r + 1;

	while (l < r) {

		ll m = (l + r) >> 1;

		if (check(m))

			r = m;

		else

			l = m + 1;

	}

	return l;

}



ll excrt(ll m1, ll m2, ll a1, ll a2) { //解决模数不互质的情况

	ll M = m1;

	ll ans = a1;

	ll B = (a2 - ans % m2 + m2) % m2;

	auto [x, y, gcd] = exgcd(m1, m2);

	if (B % gcd != 0)

		return -1;

	x = (i128)x * (B / gcd) % (m2 / gcd); //把方程右侧化为

	y = m2 / gcd;

	// x = (x % y + y) % y; //求最小正整数解

	ans += x * M;

	M *= m2 / gcd;

	ans = (ans + M) % M;

	return ans; //解x

}



ll excrt(const vector<ll> &aa, const vector<ll> &mm) {

	ll ans = aa[0], M = mm[0];

	for (int i = 1; i < aa.size(); i++) {

		if (M % mm[i] == 0 && ans % mm[i] == aa[i])

			continue;

		ll B = (aa[i] - ans % mm[i] + mm[i]) % mm[i];

		auto [x, y, gcd] = exgcd(M, mm[i]);

		if (B % gcd != 0)

			return -1;

		x = (i128)x * (B / gcd) % (mm[i] / gcd);

		ans += M * x;

		M *= mm[i] / gcd;

		ans = (ans + M) % M;

	}

	return ans;

}



int main() {

	ll n, m, k;

	cin >> n >> m >> k;

	vector<int> a(n), b(m);

	for (auto &ai : a) {

		cin >> ai;

	}

	for (auto &bi : b) {

		cin >> bi;

	}

	ll cyc = n * m / std::__gcd(n, m);

	vector<int> tong(2 * (n + m + 1), -1);

	for (int i = 0; i < n; i++) {

		tong[a[i]] = i;

	}

	vector<ll> pos;

	for (int i = 0; i < m; i++) {

		int num = tong[b[i]];

		if (num == -1)

			continue;

		// ll p = excrt({num, i}, {n, m});

		// if (p != -1)

		// 	pos.push_back(p % cyc);



		// ll p = excrt(n, m, num, i);

		ll p = excrt({num, i}, {n, m});

		// assert(p == p2);

		if (p >= 0)

			pos.push_back(p);

		// cerr << p << endl;

		// cerr << p2 << endl;

	}

	sort(pos.begin(), pos.end());

	auto get = [&](ll p) -> ll {

		if (pos.empty())

			return 0;

		ll rem = p % cyc;

		ll sum = lower(1, pos.size(), [&](int i) {

			return pos[i - 1] <= rem;

		});

		return p / cyc * pos.size() + sum;

	};

	cout << upper(1, 1E18, [&](ll x) {

		return x - get(x - 1) >= k;

	});



	return 0;

}