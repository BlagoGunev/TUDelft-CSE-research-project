#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include<cmath>
#include <map>
#include<stack>
#include<random>

using namespace std;

#define all(v) v.begin(), v.end()
#define pb push_back


typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector < string > vs;


void solve() {
	int n;
	cin >> n;
	//vi a(n); for (int i = 0; i < n; ++i) cin >> a[i];
	//ll ans = 0;
	// string s; cin >> s; n = s.length();
	//for (int i = 0; i < n; ++i) {}
	//cout << ans;
	string s;
	for (int i = 0; i < n; ++i) s += '0';
	vi d;
	char nw = 'a';
	int mn = n + 1;
	for (int i = 2; i <= n; ++i) {
		if (n % i == 0) d.push_back(i);
		else mn = min(mn, i);
	}

	for (int i = 0; i < mn; ++i) {
		for (int j = i; j < n; j += mn) s[j] = nw;
		nw++;
	}
	cout << s;
	// cout << (ans ? "YES" : "NO");
	// for(auto x : ans) cout << x << ' ';
	// for(auto p : ans ) cout << ans.first << ' ' << ans.second << "\n";
	cout << "\n";
}


signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//int k; cin >> k;
	//vi napr(k); for (int i = 0; i < k; ++i) cin >> napr[i];
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

}