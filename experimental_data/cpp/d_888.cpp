#include <bits/stdc++.h>
using namespace std;
long long answer , n , k , dp[10] ; 
int main ()
{
	cin >> n >> k ; 
	dp[0] = 1 ;
	dp[1] = (n * (n - 1 ) / 2 )  ; 
	dp[1] += dp[0] ; 
	dp[2] = (n * ( n - 1 ) * (n - 2 ) / 3) + dp[1] ; 
	dp[3] = (n * ( n - 1 ) * ( n - 2 ) * ( n - 3 ) / 24 ) * 9 ;
	dp[3] += dp[2] ;
	answer = dp[k - 1 ] ; 
	cout << answer ;
	return  0 ;
}