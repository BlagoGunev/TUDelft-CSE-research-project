#include <bits/stdc++.h> 

#define ll  long long 

#define MP make_pair 

#define PB push_back

#define N 100009

#define MOD 1000000007

#define f  first

#define s  second  

#define wt(x) cout << # x <<" = " << x << endl 

#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

#define endl "\n"

#define inf 1e15

using namespace std;

void read(ll a= 0 )

{freopen("in","r",stdin);       if (a)  freopen("out","w",stdout); }

int main () 

{

    ll  a , b , x , y ;

    cin >> a >> b >> x >> y ;

    ll u  ,  v;

    u = x  / __gcd ( x , y ) ;

    v = y / __gcd ( x , y); 

    //if  ( a < u || b < v ) return cout <<"0 0" , 0 ;

    ll lo = 0 , hi  = MOD ; 

    while ( lo < hi )

    {

        ll mid = ( lo + hi + 1 ) >> 1 ;

        if ( mid * u <= a && mid * v <= b )lo  = mid ;

        else hi = mid - 1 ;

    }

    cout << lo  * u <<" " << lo * v ;

}