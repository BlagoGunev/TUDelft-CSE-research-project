#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

#include <string>

#include <cmath>

#include <cstdlib>

#include <vector>

#include <queue>

#include <stack>

#include <set>

#include <map>

#include <bitset>

//#pragma comment(linker, "/STACK:1024000000,1024000000")



using namespace std;



#define ll long long

#define SZ(x) ((int)(x).size()) 

#define ALL(v) (v).begin(), (v).end()

#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)

#define reveach(i, v) for (__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++ i) 

#define REP(i,a,n) for ( int i=a; i<int(n); i++ )

#define FOR(i,a,n) for ( int i=n-1; i>= int(a);i-- )

#define lson rt<<1, L, m

#define rson rt<<1|1, m, R

typedef pair<int, int> pii;

typedef pair<int, int> pll;

#define mp(x, y) make_pair(x, y)

#define pb(x) push_back(x)

#define fi first

#define se second

#define CLR(a, b) memset(a, b, sizeof(a))

#define Max(a, b) a = max(a, b)

#define Min(a, b) a = min(a, b)

const ll INF = 1e18 + 7;



ll m;

int k;

ll C(int n, int m){

    if(n < m) return 0;

    ll res = 1;

    REP(i, 0, m) res = res * (n - i) / (i + 1);

    return res;

}

ll solve(ll n){

    ll res = 0;

    int c = 0;

    FOR(i, 0, 63){

        if(n & (1ll << i)){

            res += C(i, k - c);

            c ++;

        }

    }

    return res;

}

bool ok(ll x){

    ///*

    ll a = solve(x * 2);

    ll b = solve(x);

    ll res = a - b;

    //*/

    /*

    ll res = 0;

    int c = 0;

    FOR(i, 0, 63){

        if(x & (1ll << i)){

            res += C(i + 1, k - c) - C(i, k - c);

            c ++;

            //if(res <= m) return true;

        }

    }

    */

    if(res <= m) return true;

    return false;

}

int main(){

#ifdef ac

	freopen("in.txt","r",stdin);

#endif

	//freopen("out.txt","w",stdout);

    scanf("%lld%d", &m, &k);

    //cout << ok(5) << endl;

    ll l = 1, r = INF;

    while(l + 1 < r){

        ll m = (l + r) >> 1;

        if(ok(m)) l = m;

        else r = m;

    }

    printf("%lld\n", l);

    return 0;

}