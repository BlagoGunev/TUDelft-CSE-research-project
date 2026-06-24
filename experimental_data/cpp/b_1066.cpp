/*
 * author: vamsi3
 * filename: sample.cpp
 * module: competitive-programming
 *
*/


#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> tll;

typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<vpll> vvpll;

typedef deque<ll> dll;
typedef deque<pll> dpll;
typedef deque<dll> ddll;

typedef long double ld;
typedef complex<ld> cd;
typedef vector<cd> vcd;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back

const ll mod = 1000000007;

// ----------------------------------------------------

ll func(ll num) {
	ll n, r; cin >> n >> r;
	ll a[n];
	for (ll i=0; i<n; i++) cin >> a[i];
	ll i=0, cnt=0, lasti = -10000;
	while (i < n) {
		ll j = min(n-1, i+r-1);
		ll f = 0;
		while (j > lasti) {
			if (j < 0 or j >= n) return -1;
			if (a[j] == 1) {
				cnt++;
				lasti = i;
				i = j+r;
				f = 1;
				break;
			}
			j--;
		}
		if (f == 0) {
			return -1;
		}
	}
	return cnt;
}

int main() {
	fast_io;
	ll t = 1; // cin >> t;
	for (ll num=1; num<=t; num++) {
		cout << func(num) << endl;
	}
}