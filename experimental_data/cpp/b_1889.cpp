#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define int long long
#define pb push_back
#define s second
#define f first
#define pf push_front
#define inf 100000000000000000
#define bitebi __builtin_popcountll
#define FOR( i , n ) for( int i = 0 ; i < n ; i ++ )
#define YES cout <<"YES\n"
#define NO cout << "NO\n"
#define debug cout << "Here Fine" << endl ;
#define pr pair < int , int >
#define fbo find_by_order // returns iterator
#define ook order_of_key // returns strictly less numbers than key
using namespace std ;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
const double Pi=acos(-1.0);
const double EPS=1E-8;
const int mod =  1000000007 ;
const int mod1 = 998244353 ;
const int N = 2e5 + 10 ;
mt19937 R(time(0));
map < int , int > ma , ma1 ;

void solve(){
	int n , c ; 
    cin >> n >> c ;
    int a[ n ] ;
    FOR( i , n ) cin >> a[ i + 1 ] ;
    multiset < pair < int , int > > se ;
	for( int j = 2 ; j <= n ; j ++ ){
		int xx = j * c ; 
		se.insert( { a[ j ] - xx , a[ j ] } ) ;
	}   
	 
	int cur = a[ 1 ] ;
    while( true ){
      if( se.size() == 0 ) break ; 
	  pair < int , int > p = *( --se.end() ) ;
	  //cout << cur << " " << abs( p.f ) << endl ;
	  if( cur >= ( - p.f ) ){
	  	cur = cur + p.s ; 
	  	se.erase( --se.end() ) ; 
	  } 
	  else break ; 	
	}
    if( se.size() == 0 ) YES ;
    else NO ; 
}
signed main() {
   ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
   int t = 1 ;  cin >> t ;
   while( t -- ){
   	 solve() ;
   }

}