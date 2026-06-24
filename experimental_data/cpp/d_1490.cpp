#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define ppb pop_back()
#define pf push_front
#define ppf pop_front()
#define fi first
#define se second
#define pi pair<int, int>
#define ppi pair<pi, pi>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define REP(i, a, n) for(int i = a; i < n; i++)
#define per(i, a, n) for(int i = a; i >= n; i--)
#define PER(i, a, n) for(int i = a; i > n; i--)
#define pqi priority_queue<int>
#define Y "YES"
#define N "NO"
#define PI 3.141592653589793238462643383279502884197
using namespace std;

ll T, n, x, y;
string s;

ll maxx(ll a, ll b) {
	return ((a > b) ? a : b);
}

ll minn(ll a, ll b) {
	return ((a < b) ? a : b);
}

void p(ll a[], vector<ll>& b, ll i, ll s, ll e) {
	if (e <= s) return;
	int max = 0;
	int in = -1;
	REP(j, s, e) {
		if (a[j] > max) {
			max = a[j];
			in = j;
		}
	}
	b[in] = i;
	p(a, b, i + 1, s, in);
	p(a, b, i + 1, in+1, e);
}

void solve() {
	cin >> n;
	ll a[n];
	REP(i, 0, n) {
		cin >> a[i];
	}
	vector<ll> b(n, -1);
	p(a, b, 0, 0, n);
	for (auto x : b) cout << x << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		solve();
		cout << '\n';
	}
}