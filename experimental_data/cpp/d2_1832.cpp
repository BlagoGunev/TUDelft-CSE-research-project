#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair < int , int > pii ; 
typedef vector<int> vi;
typedef vector < long long > vl ;
typedef unsigned int uint ;
#define fi first
#define se second
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()


const int MAXN = 2e5 + 7 ;
const int inf = 1e9 + 7 ;

ll n , q ;
ll a[ MAXN ] ;
ll b[ MAXN ] ;
ll min_add[ MAXN ] ;
ll sm_all = 0 ;

ll up_to ( ll up ) {
    return ( up * ( up + 1 ) / 2 ) ;
}

ll calc ( ll tot ) {
    ll sm = sm_all ;
    ll en_pos = tot ;
    if ( tot <= n ) { en_pos = tot ; }
    else {
        if ( ( tot - n ) % 2 == 0 ) { en_pos = n ; }
        else { en_pos = n - 1 ; }
    }
    ll aux = a[ 1 ] + tot + min_add[ en_pos ] ;
    if ( en_pos != n ) {
        aux = min ( aux , a[ en_pos + 1 ] ) ;
    }
    if ( tot <= n ) { return aux ; }
    sm += up_to ( tot ) ;
    if ( ( tot - n ) % 2 == 0 ) { tot -= n ; }
    else { tot -= ( n - 1 ) ; }
    sm -= up_to ( tot ) ;

    
    tot /= 2 ;
    ll l , r , mid ;
    l = -inf , r = aux ;
    while ( l < r ) {
        mid = ( l + r + 1 ) / 2 ;
        ll mx = sm - n * mid ;
        if ( mx >= tot ) { l = mid ; }
        else { r = mid - 1 ; }
    }
    return l ;    
}

void solve ( ) {
    cin >> n >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        sm_all += a[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    min_add[ 1 ] = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        ll diff = a[ i ] - a[ 1 ] ;
        min_add[ i ] = min ( min_add[ i - 1 ] , diff - ( i - 1 ) ) ;
    }
    while ( q -- ) {
        ll k ; cin >> k ;
        cout << calc ( k ) << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}