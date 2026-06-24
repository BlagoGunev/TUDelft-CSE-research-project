#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define ff first
#define ss second
#define pb push_back
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
// debug template
#ifdef POTATO
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif
// convenient functions
inline void yes() { cout << "YES\n"; return; }
inline void no() { cout << "NO\n"; return; }
template <class T>
inline void out(T temp) { cout << temp << '\n'; return; }
// globals
#define int long long
void init() {
	// initialize
	
}
void solve() {
	// solve
	int n; cin >> n;
	string str; cin >> str;
	if (n == 1) return out(1);
	str = 'X' + str;
	int ans = n * (n + 1) / 2;
	int cnt = 0;
	for (int i = n; i >= 1; i--) {
		bool take = false;
		if (str[i] == '1') {
			if (i - 1 >= cnt + 1) {
				take = true;
			}
		}
		if (take) {
			cnt++;
			ans -= i;
		} else {
			cnt = max(0LL, cnt - 1);
		}
	}
	cout << ans << '\n';
}
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef POTATO
		auto start = chrono::high_resolution_clock::now();
	#endif

	init();
	int t = 1;
	cin >> t;
	while (t--) solve();

	#ifdef POTATO
		auto end = chrono::high_resolution_clock::now();
		cerr << "Execution time: "
			<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
			<< " ms" << endl;
	#endif
}
/*

*/