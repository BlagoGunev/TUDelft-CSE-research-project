#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
 
#define FOREACH(i, c) for(__typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for(__typeof(n) i = (a); i<(n); ++i)
#define REP(i, n, a) for(__typeof(n) i = (n); i>=(a); --i)
#define error(n) cout << #n << " = " << n << endl
#define all(c) c.begin(), c.end()
#define pb push_back
#define po pop_back
#define Size(n) ((int)(n).size())
#define pii pair<int, int>
#define X first
#define Y second
// #define X real()
// #define Y imag()

typedef long long   ll ;
typedef long double ld ;

const int MAXN = 1000 + 10 ;

ll n , m ;

ll a , r[MAXN] , c[MAXN] ;
ll bor[MAXN] , boc[MAXN] ;

ll Dist (ll a , ll b) {
    ll p0 = 4LL*a ;
    ll p1 = 4LL*b+2LL ;
    ll s = p0-p1 ;
    s = s*s ;
    return s ;
}

int main() {
    ios_base::sync_with_stdio(false) ;
    cin >> n >> m ;
    FOR (i,0,n) {
        FOR (j,0,m) {
            cin >> a ;
            r[i] += a ;
            c[j] += a ;
        }
    }
    FOR (i,0,n+1) {
        FOR (k,0,n) {
            bor[i] += r[k]*Dist(i,k) ;
        }
    }
    FOR (j,0,m+1) {
        FOR (k,0,m) {
            boc[j] += c[k]*Dist(j,k) ;
        }
    }
    ll ans = -1 ;
    ll x = 0 , y = 0 ;
    FOR (i,0,n+1) {
        FOR (j,0,m+1) {
            ll tmp = bor[i] + boc[j] ;
            if (ans == -1 || tmp < ans) {
                ans = tmp ;
                x = i ;
                y = j ;
            }
        }
    }
    cout << ans << endl << x << " " << y << endl ;
    return 0 ;
}