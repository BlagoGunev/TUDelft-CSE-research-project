/* Author : Chaitanya Darwai */

#include <bits/stdc++.h>

using namespace std;



// #include <ext/pb_ds/assoc_container.hpp>

// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

// template<class T>

// using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// // cmp -> less_equal<T> : for multiset



#pragma GCC optimize("O3,unroll-loops")

#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")



#define ION                  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

// #define ci                   cin >>

// #define co                   cout <<

// #define edl                  << '\n'

// #define elif                 else if

// #define cnu                  continue

#define rep(i,a,b,c)         for(int i=a; i<b; i+=c)

#define rrep(i,a,b)          for(int i=b-1; i>=a; i--)

#define vec                  vector 

#define str                  string

#define pb                   push_back

#define all(x)               (x).begin(),(x).end()

#define sz(x)                (int)((x).size())

#define ff                   first

#define ss                   second

#define ppc                  __builtin_popcount

#define ppcll                __builtin_popcountll

typedef long long            ll;

typedef vec<int>             vi;

typedef vec<ll>              vl;

typedef pair<int,int>        pii;

typedef pair<ll,ll>          pll;

typedef vec<pii>             vii;

typedef vec<pll>             vll;

const double eps = 1e-8;

const ll linf = (ll)(1e18)+1;

const int P = 1e9+7;

// const int P = 998244353;

const int N = 1e5+1;

// Before getline(cin, str) : cin.ignore(numeric_limits<streamsize>::max(),'\n');

// For float precision :  cout << fixed << setprecision(8) <<

/*******************************************************************************/



void solve(int tcn){

    int n;

    cin >> n;

    vl a(n);

    for(auto &i : a) cin >> i;

    sort(all(a));

    ll ans = a[n-1];

    rep(i,0,n,1){

        ans += a[i]*(n-i-1);

        ans -= a[i]*(i);

    }

    cout << ans << '\n';

}



signed main(){

    ION;



    // freopen("input.txt","r",stdin);

    // freopen("output.txt","w",stdout);



    int test = 1;

    cin >> test;

    rep(i,0,test,1){

        solve(i+1);

    }

    return 0;

}