#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define fo(i, a, b) for(int i = a; i <= b; i++)
#define _fo(i, a, b) for(int i = a; i >= b; i--)
#define foa(i, a) for (auto &i : a)
#define sz(a) ((int) a.size())
#define all(a) begin(a), end(a)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mk(x, y) make_pair(x, y)  
 
typedef int64_t ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int MAX = 1e5+5;
const int MOD = 1e9+7;
const ll INF = INT_MAX;
const ll _INF = INT_MIN;
 
ll upper(ll val) {
	ll l = 0, r = 100000;
	while(l < r) {
		ll m = (l+r)/2, temp = (m*(m+1)) / 2;
		if(temp < val) l = m+1;
		else r = m;
	}
	
	return l;
}
 
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll a, b, val, temp;
		cin >> a >> b;
		
		val = abs(a-b);
		temp = upper(val);
		ll odd = ((temp+1)/2);
		
		if((val % 2) == (odd % 2)) cout << temp;
		else {
			cout << temp + 1 + (odd > temp-odd);
		}
		cout << "\n";
	}
}