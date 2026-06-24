#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
#include "cmath"
#include "vector"
#include "map"
#include "set"
#include "queue"
#include "cassert"
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x) (x).begin() , (x).end()
#define mem( a ) memset( a , 0 , sizeof a )
typedef long long ll;
const int P = 998244353;
const int MAXN = 5e5 + 20;
int n , k , l;
int A[MAXN] , B[MAXN] , idx[MAXN];

void solve() {
    cin >> n;
    int sa = 0 , sb = 0;
    rep( i , 1 , n ) {
        cin >> A[i] >> B[i];
        sa += A[i] , sb += B[i];
        idx[i] = i;
    }
    sort( idx + 1 , idx + 1 + n , [&]( int i , int j ) {
        int ti = ( A[i] < B[i] ) , tj = ( A[j] < B[j] );
        if( ti != tj ) return !!ti;
        ti = ( A[i] == B[i] ) , tj = ( A[j] == B[j] );
        if( ti != tj ) return !!ti;
        if( A[i] < B[i] ) {
            // cout << i << ' ' << j << ' ' << A[i] << ' ' << B[i] << endl;
            return A[i] == A[j] ? B[i] > B[j] : A[i] < A[j];
        } else {
            return B[i] == B[j] ? A[i] < A[j] : B[i] > B[j];
        }
    } );
    set<pii> S;
    int sp = 0 , w = 0;
    int dir = 0;
    rep( ti , 1 , n ) {
        int i = idx[ti];
        if( S.size() ) {
            auto it = S.upper_bound( mp( dir + A[i] , 0 ) ) , itr = it;
            if( it != S.begin() ) {
                int as = 1e18;
                while( it != S.begin() ) {
                    -- it;
                    as = min( as , it -> second + A[i] - ( it -> first - dir ) );
                }
                S.erase( it , itr );
                S.insert( mp( dir + A[i] , as ) );
            }
        }
        dir += A[i] - B[i];
        if( B[i] <= sb - sa )
            S.insert( mp( sp + dir , w ) );
        if( sp < A[i] ) {
            w += A[i] - sp , sp = 0;
        } else sp -= A[i];
        sp += B[i];
    }
    if( S.size() ) {
        int ans = 1e18;
        for( auto it : S ) ans = min( ans , it.second );
        cout << ans + sa << endl;
    } else {
        cout << -1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin >> T;while( T-- )solve();
}