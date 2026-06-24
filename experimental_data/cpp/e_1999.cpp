// Problem: E. Triple Operations
// Contest: Codeforces - Codeforces Round 964 (Div. 4)
// URL: https://codeforces.com/contest/1999/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[200005], b[200005];
void solve() {
	int l, r; cin >> l >> r;
	// l -> 0 的次数
	cout << a[l] + b[r] - b[l - 1] << '\n';
}

int main() {
	a[0] = 0;
	a[1] = 1;
	for(int i = 2; i <= 200000; i++) a[i] = a[i / 3] + 1;
	b[0] = 0;
	for(int i = 1; i <= 200000; i++) b[i] = b[i - 1] + a[i];
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t; while(t--)
	solve();	
	return 0;
}