// Problem: D. Balanced Round
// Contest: Codeforces - Codeforces Round 886 (Div. 4)
// URL: https://codeforces.com/contest/1850/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// I'm back in action

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)

int32_t main() {
   int t;
   cin >> t;
   
   while (t--) {
   	int n, k;
   	cin >> n >> k;
   	
   	vector<int> a(n);
   	for (int i = 0; i < n; i++) {
   		cin >> a[i];
   	}
   	
   	sort(all(a));
   	
   	int mx = 0, cur = 0;
   	for (int i = 0; i < n - 1; i++) {
   		if (abs(a[i + 1] - a[i]) <= k) {
   			++cur;
   			mx = max(mx, cur);
   		} else cur = 0;
   	}
   	mx = max(mx, cur);
   	cout << n - mx - 1 << '\n';
   }
}