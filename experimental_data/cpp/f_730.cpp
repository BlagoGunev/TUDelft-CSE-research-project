#include <bits/stdc++.h>

using namespace std ;



typedef long long LL ;

typedef pair < int , int > pii ;

typedef unsigned long long ULL ;



#define clr( a , x ) memset ( a , x , sizeof a )



const int MAXN = 5005 ;

const int MAXM = 10005 ;

const int INF = 0x3f3f3f3f ;



short fa[MAXN][MAXM] ;

int dp[2][MAXM] ;

int a[MAXN] ;

int n , m ;



void solve () {

	clr ( dp , INF ) ;

	clr ( fa , 0 ) ;

	dp[0][0] = 0 ;

	int sum = 0 , o = 1 ;

	for ( int i = 1 ; i <= n ; ++ i , o ^= 1 ) {

		scanf ( "%d" , &a[i] ) ;

		int M = ( sum + a[i] ) / 10 ;

		for ( int j = 0 ; j <= M ; ++ j ) {

			dp[o][j] = INF ;

		}

		for ( int j = 0 ; j <= M ; ++ j ) if ( dp[o ^ 1][j] != INF ) {

			int w = dp[o ^ 1][j] ;

			int has = m + j - ( sum - w ) ;

			int t = min ( has , a[i] / 2 ) ;

			for ( int k = 0 ; k <= t ; ++ k ) {

				int nxtw = w + a[i] - k ;

				int nxtj = j + ( a[i] - k ) / 10 ;

				if ( dp[o][nxtj] > nxtw ) {

					dp[o][nxtj] = nxtw ;

					fa[i][nxtj] = a[i] - k ;

				}

			}

		}

		sum += a[i] ;

	}

	int ans = INF , pos ;

	for ( int i = 0 ; i < MAXM ; ++ i ) {

		if ( ans > dp[o ^ 1][i] ) {

			ans = dp[o ^ 1][i] ;

			pos = i ;

		}

	}

	vector < int > res ;

	for ( int i = n ; i >= 1 ; -- i ) {

		res.push_back ( fa[i][pos] ) ;

		pos -= fa[i][pos] / 10 ;

	}

	reverse ( res.begin () , res.end () ) ;

	printf ( "%d\n" , ans ) ;

	for ( int i = 0 ; i < n ; ++ i ) {

		printf ( "%d%c" , a[i + 1] - res[i] , i < n - 1 ? ' ' : '\n' ) ;

	}

}



int main () {

	while ( ~scanf ( "%d%d" , &n , &m ) ) solve () ;

	return 0 ;

}