// Problem: C. Card Game
// Contest: Codeforces - Codeforces Round 899 (Div. 2)
// URL: https://codeforces.com/contest/1882/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<ll> v(n+1), suf(n+2);
		for(int i=1; i<=n; i++) cin >> v[i];
		ll ans = 0;
		for(int i=n; i>=1; i--){
			ll cur = suf[i+1];
			if(i % 2) cur += v[i];
			ans = max(ans, cur);
			suf[i] = suf[i+1];
			if(v[i] > 0) suf[i] += v[i];
		}
		cout << ans << endl;
	}
}