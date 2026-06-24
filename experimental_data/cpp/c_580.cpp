/*
  by asas
*/
#include <bits/stdc++.h>
#define CASET int ___T, Case = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define PHB push_back
#define PPB pop_back
#define LL long long
#define ULL unsigned long long
#define ALL(X) (X).begin(), (X).end()
#define MP make_pair
#define PII pair<int,int>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define F first
#define S second
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define DRI(X) int (X) = in()
#define DRII(X, Y) int X = in() , Y = in()
#define DRIII(X, Y, Z) int X = in() , Y = in() , Z = in()
using namespace std ;
const int MOD = 1e9+7;
const int SIZE = 1e5+10;
inline int in(int d=0,char q=0,int c=1){while(q!='-'&&q!=EOF&&(q<48||q>57))q=getchar();if(q==EOF)return EOF;if(q=='-')c=-1,q=getchar();do d=d*10+(q^48),q=getchar();while(q<58&&q>47);return c*d;}
// template end here
vector<int> V[ 100000 ] ;
vector<int> cat ;
int n , res , limit ;
void dfs( int d , int m )
{
	if ( m > limit ) return ;
	cat[ d ] = -1 ;
	int i , k = 0 ;
	for ( i = 0 ; i < SZ( V[ d ] ) ; i ++ )
	{
		if ( cat[ V[ d ][ i ] ] == -1 ) ;
		else
		{
			if ( cat[ V[ d ][ i ] ] == 1 )
			{
				dfs( V[ d ][ i ] , m + 1 ) ;
			}
			else
			{
				dfs( V[ d ][ i ] , 0 ) ;
			}
			k ++ ;
		}
	}
	if ( !k ) res ++ ;
}
int main()
{
	n = in() , limit = in() ;
	cat.PHB( 0 ) ;
	for ( int i = 0 ; i < n ; i ++ )
	{
		cat.PHB( in() ) ;
	}
	for ( int i = 1 , a , b ; i < n ; i ++ )
	{
		a = in() , b = in() ;
		V[ a ].PHB( b ) ;
		V[ b ].PHB( a ) ;
	}
	dfs( 1 , cat[ 1 ] == 1 ) ;
	cout << res << endl ;
	return 0 ;
}