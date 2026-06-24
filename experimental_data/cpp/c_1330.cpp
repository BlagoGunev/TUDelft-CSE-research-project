#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#define fast cin.tie(0); cin.sync_with_stdio(0);

#define ll long long

#define ull unsigned long long

#define ld long double

#define oo (ll)1e9

#define OO (ll)1e18

#define PI acos(-1)

using namespace std;

using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;

const ll mod = 1e9 + 7;

const int MOD = 998244353;

int tt = 1;

int test;

const int N = 1e5 + 4;

int a[N];

ll suf[N];

int n , m;

void solve()

{

     cin >> n >> m;

     for(int i = 1 ; i <= m ; i++) cin >> a[i];

     for(int i = m ; i >= 1 ; i--) suf[i] = suf[i + 1]  + a[i];

     for(int i = 1 ; i <= m ; i++){

        if(n - a[i] < i - 1){

            cout << -1 << '\n';

            return;

        }

     }

     if(suf[1] < n) return void(cout << -1 << '\n');

     for(int i = 1 ; i <= m ; i++){

        cout << max(0ll + i , n - suf[i] + 1) << " \n"[i == m];

     }

}

int main()

{



    fast

//    cin >> tt;

    while(tt--)

        solve();

    return 0;

}