#include <stdlib.h>

#include <iostream>

#include <string>

#include <deque>

#include <vector>

#include <algorithm>

#include <iomanip>

#include <map>

#include <set>

#include <queue>

#include <fstream>

#include <stack>

#include <cmath>

#include <bitset>

#include <unordered_set>

#include <unordered_map>

#include <random>

using namespace std;

#define ll long long

#define ull unsigned ll

#define forn(i, n) for (ll i = 1; i <= n; i++)

#define dforn(i, a, b) for (ll i = a; i <= b; i++)

#define rforn(i, n) for (ll i = n; i >= 1; i--)

#define rdforn(i, a, b) for (ll i = b; i >= a; i--)

const ll mod = 998244353;

const ll N = 1e5 + 100;

const ll inf = 1e17;

const double eps = 1e-9;

const double pi = acos(-1);



ll bin_search(vector<ll> & p, ll val) {

	ll l = 0, r = p.size();

	while (r - l > 1) {

		ll m = (l + r) / 2;

		if (p[m] > val) {

			l = m;

		}

		else {

			r = m;

		}

	}

	if (p[l] < val) {

		l--;

	}

	return max(0LL, l);

}



void solve() {

	ll n, m;

	cin >> n >> m;

	vector<pair<ll, ll>> a(m + 1);

	vector<ll> p(m + 1), pref(m + 1);

	forn(i, m) {

		cin >> a[i].first >> a[i].second;

		p[i] = a[i].first;

	}

	sort(p.rbegin(), p.rend() - 1);

	forn(i, m) {

		pref[i] = pref[i - 1] + p[i];

	}

	ll ans = pref[min(n, m)];

	forn(i, m) {

		ll cur = a[i].first;

		ll pos = bin_search(p, a[i].second);

		ll curn = n - 1;

		if (a[i].first > a[i].second) {

			cur -= a[i].first;

			curn++;

		}

		cur += pref[min(pos, curn)];

		curn -= min(pos, curn);

		cur += curn * a[i].second;

		ans = max(ans, cur);

	}

	cout << ans << '\n';

}



int main()

{

	ios::sync_with_stdio(0);

	cin.tie(0);

	cout.tie(0);

	ll t = 1;

	cin >> t;

	while (t) {

		t--;

		solve();

	}

	return 0;

}