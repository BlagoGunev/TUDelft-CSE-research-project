#include <cstdio>
#include <cstring>
namespace IO {
  const int IN_LEN = 1 << 18 | 1;
  static char buf[IN_LEN] , *s , *t;
  inline int Getchar( void ) { return s == t && ( t = ( s = buf ) + fread( buf , 1 , IN_LEN , stdin ) ) , s == t ? -1 : *s++; }
  template <class T> inline void read( T & x ) {
    static int c , f;
    for( c = Getchar() , f = 0 ; c < '0' || c > '9' ; c = Getchar() ) if( c == '-' ) f = 1;
    for( x = 0 ; c <= '9' && c >= '0' ; c = Getchar() ) x = x * 10 + c - 48;
    x = f ? -x : x;
  }
}using IO::read;
const int MAXN = 1e5 + 1 , MAXM = 6e5 + 1;
int n , m , head[MAXN] , edge_cnt , cnt1 , cnt2 , mark[MAXN] , vis1[MAXN] , vis2[MAXN];
struct EE { int next , to; } edge[MAXM];
inline void addedge( int f , int t ) { edge[++edge_cnt] = (EE) { head[f] , t }; head[f] = edge_cnt; }
int main( void ) {
  read( n ) , read( m );
  for( int i = 1 , u , v ; i <= m ; ++i ) {
    read( u ) , read( v );
    addedge( u , v ) , addedge( v , u );
  }
  for( int i = 1 ; i <= n ; ++i ) 
    if( !mark[i] ) {
      mark[i] = 1 , ++cnt1;
      for( int j = head[i] ; j ; j = edge[j].next )
        ++vis1[edge[j].to] , mark[edge[j].to] = 2;
    } 
  for( int i = 1 ; i <= n ; ++i )
    if( mark[i] == 2 && vis1[i] != cnt1 )
      return puts("-1"),0;
  for( int i = 1 ; i <= n ; ++i )
    if( mark[i] == 2 ) {
      mark[i] = 3 , ++cnt2;
      for( int j = head[i] ; j ; j = edge[j].next )
        if( mark[edge[j].to] != 1 ) 
          ++vis2[edge[j].to] , mark[edge[j].to] = 4;
    }
  if( cnt1 + cnt2 == n ) return puts("-1"),0;
  for( int i = 1 ; i <= n;  ++i )
    for( int j = head[i] ; j ; j = edge[j].next )
      if( mark[i] == mark[edge[j].to] )
        return puts("-1"),0;
  for( int i = 1 ; i <= n ; ++i )
    if( mark[i] == 4 && vis2[i] != cnt2 )
      return puts("-1"),0;
  for( int i = 1 ; i <= n ; ++i ) {
    if( mark[i] == 3 ) mark[i] = 2;
    if( mark[i] == 4 ) mark[i] = 3;
    printf("%d%c",mark[i]," \n"[i==n]);
  }
  return 0;
  
}