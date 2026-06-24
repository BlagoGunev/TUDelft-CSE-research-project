#include <bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp> 
  
using namespace std;
//using namespace __gnu_pbds; 
  
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ff first
#define ss second
#define pb push_back
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
//#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
//#define double long double
template<class T, class U> inline bool chmin(T& a, const U& b) { if (a > b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmax(T& a, const U& b) { if (a < b) { a = b; return true; } return false; }
  
const int N = 1000010;
const int inf = 1e18;
const int mod = 1e9 + 7;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#define rnd(l, r) uniform_int_distribution <int> (l, r)(rng)


void solve(){
	//freopen("angry.in", "r", stdin);
	//freopen("angry.out", "w", stdout);
	string a, b, c;
	cin >> a >> b >> c;
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n+1, vector<int> (m+1, inf));
	dp[0][0] = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i < n)chmin(dp[i+1][j], dp[i][j] + (a[i] != c[i+j]));
			if(j < m)chmin(dp[i][j+1], dp[i][j] + (b[j] != c[i+j]));
		}
	}
	
	cout << dp[n][m] << '\n';
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    };
}