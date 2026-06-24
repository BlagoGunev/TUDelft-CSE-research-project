#include<bits/stdc++.h>
using namespace std ;

int n, k, x ;

int a[5010] ;

long long dp[5010][5010] ;

deque < int > q ;

int main(){
	#define NAME "example"
	//freopen( NAME".inp" , "r" , stdin ) ; freopen( NAME".out" , "w" , stdout ) ;

	ios_base :: sync_with_stdio(false) ;

	cin >> n >> k >> x ;

	for (int i = 1; i <= n; ++ i) cin >> a[i] ;

	memset(dp, -0x3f, sizeof(dp)) ;
	
	dp[0][0] = 0 ;

	for (int i = 1; i <= x; ++ i){
		for (int j = 1; j <= n; ++ j){
			while(!q.empty() && q.front() + k < j) q.pop_front() ;
			while(!q.empty() && dp[i - 1][q.back()] <= dp[i - 1][j - 1]) q.pop_back() ;
			q.push_back(j - 1) ;
			dp[i][j] = dp[i - 1][q.front()] + 1ll * a[j] ;
		}
		while(!q.empty()) q.pop_back() ;
	}

	long long res = -(long long)1e18 ;

	for (int i = n - k + 1; i <= n; ++ i) res = max(res, dp[x][i]) ;

	if(res < 0) cout << -1 ;
	else cout << res ;

	return 0 ;
}