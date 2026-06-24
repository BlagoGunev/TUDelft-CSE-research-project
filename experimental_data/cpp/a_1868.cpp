#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define ff first
#define ss second
#define pb push_back
#pragma GCC optimize("O2")
using namespace std;
// debug template
#ifdef POTATO
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif
// convenient functions
inline void yes() { cout << "YES" << endl; return; }
inline void no() { cout << "NO" << endl; return; }
template <class T>
inline void out(T temp) { cout << temp << endl; return; }
// globals
const int mxN = 2e5 + 1;
bool horm[mxN], verm[mxN];
void init() {
	// initialize
	
}
void solve(int &case_no) {
	// solve
	int n, m;
	cin >> n >> m;
	if (m == 1) {
		for (int i = 0; i <= n; i++) cout << "0\n";
		return;
	}
	vector<vector<int>> ans(n);
	for (int i = 0; i < n; i++) {
		ans[i].resize(m);
		if (i + 1 >= m) {
			ans[i] = ans[i - 1];
			continue;
		}
		for (int j = 0; j < m; j++) {
			ans[i][j] = (i + j + 1) % m;
		}
	}
	// for (vector<int> &temp : ans) {
	// 	for (int &temp2 : temp) cout << temp2 << ' ';
	// 	cout << '\n';
	// }
	// cout << endl;

	for (int i = 0; i <= max(n, m); i++) verm[i] = false;
	for (int i = 0; i <= max(n, m); i++) horm[i] = false;
	for (int i = 0; i < m; i++) {
		int mex = 0;
		for (int j = 0; j < n; j++) {
			horm[ans[j][i]] = true;
			while (horm[mex]) mex++;
		}
		verm[mex] = true;
		for (int j = 0; j < n; j++) {
			horm[ans[j][i]] = false;
		}
	}
	int fin = 0;
	while (verm[fin]) fin++;
	cout << fin << '\n';
	for (vector<int> &temp : ans) {
		for (int &temp2 : temp) cout << temp2 << ' ';
		cout << '\n';
	}
}
int32_t main() {
	#ifdef POTATO
	// assert(freopen("input.txt", "r", stdin));
	// assert(freopen("output.txt", "w", stdout));
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	srand(time(NULL));
	#ifdef POTATO
		auto start = chrono::high_resolution_clock::now();
	#endif

	init();
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) solve(i);

	#ifdef POTATO
		auto end = chrono::high_resolution_clock::now();
		cerr << "Execution time: "
			<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
			<< " ms" << endl;
	#endif
}
/*

*/