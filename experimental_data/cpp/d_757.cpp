//by tzupengwang™
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<iostream>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n ;
char s[ 100 ] ;
const int mod = 1000000007 ;

void add( int &x , int y ) {
  x += y ;
  if ( x >= mod ) x -= mod ;
}

int nxz[ 100 ] ;

void init() {
  scanf( "%d%s" , &n , s + 1 ) ;
  for ( int i = 0 ; i <= n ; i ++ ) {
    nxz[ i ] = -1 ;
    for ( int j = i + 1 ; j <= n ; j ++ ) {
      if ( s[ j ] == '1' ) {
        nxz[ i ] = j ;
        break ;
      }
    }
  }
}

int dp[ 76 ][ ( 1 << 20 ) ] ;

void process() {
  memset( dp , 0 , sizeof dp ) ;
  for ( int i = 0 ; i <= n ; i ++ ) {
    dp[ i ][ 0 ] = 1 ;
  }
  int ans = 0 ;
  for ( int i = 0 ; i <= n ; i ++ ) {
    if ( nxz[ i ] != -1 ) {
      for ( int j = 0 ; j < ( 1 << 20 ) ; j ++ ) if ( dp[ i ][ j ] ) {
        int tmp = 0 ;
        int bnd = min( nxz[ i ] + 4 , n ) ;
        for ( int k = nxz[ i ] ; k <= bnd ; k ++ ) {
          tmp = tmp * 2 + s[ k ] - '0' ;
          if ( tmp && tmp <= 20 ) {
            add( dp[ k ][ j | ( 1 << ( tmp - 1 ) ) ] , dp[ i ][ j ] ) ;
          }
        }
      }
    }
    for ( int j = 1 ; j <= 20 ; j ++ ) {
      // printf( "%d %d: %d\n" , i , j , dp[ i ][ ( 1 << j ) - 1 ] ) ;
      add( ans , dp[ i ][ ( 1 << j ) - 1 ] ) ;
    }
  }
  printf( "%d\n" , ans ) ;
}

int main() {
/*
#ifdef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
  int Cases;
  scanf( "%d" , &Cases ) ;
  for ( int cases = 1 ; cases <= Cases ; cases ++ ) {
*/
    init() ;
    process() ;
/*
  }
*/
  return 0 ;
}