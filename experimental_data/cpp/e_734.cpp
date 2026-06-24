//by tzupengwang™
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n ;
int s[ 200005 ] ;
vector< int > v[ 200005 ] ;

void init() {
  scanf( "%d" , &n ) ;
  for ( int i = 1 ; i <= n ; i ++ ) {
    scanf( "%d" , &s[ i ] ) ;
  }
  for ( int i = 1 ; i < n ; i ++ ) {
    int x , y ;
    scanf( "%d%d" , &x , &y ) ;
    v[ x ].push_back( y ) ;
    v[ y ].push_back( x ) ;
  }
}

bool vs[ 200005 ] ;
int dp[ 200005 ] ;
int ans ;
// 0: all white
// 1: all black
// 2: top white
// 3: top black
void dfs( int now ) {
  vs[ now ] = true ;
  int t1 = 0 , t2 = 0 ;
  for ( int nxt : v[ now ] ) if ( !vs[ nxt ] ) {
    dfs( nxt ) ;
    if ( s[ nxt ] == s[ now ] ) {
      if ( dp[ nxt ] > t1 ) t2 = t1 , t1 = dp[ nxt ] ;
      else if ( dp[ nxt ] > t2 ) t2 = dp[ nxt ] ;
    } else {
      if ( dp[ nxt ] + 1 > t1 ) t2 = t1 , t1 = dp[ nxt ] + 1 ;
      else if ( dp[ nxt ] + 1 > t2 ) t2 = dp[ nxt ] + 1 ;
    }
  }
  ans = max( ans , t1 + t2 + 1 ) ;
  dp[ now ] = t1 ;
}

void process() {
  ans = 0 ;
  dfs( 1 ) ;
  ans = ( ans / 2 ) ;
  printf( "%d\n" , ans ) ;
}

int main() {
  init() ;
  process() ;
  return 0 ;
}