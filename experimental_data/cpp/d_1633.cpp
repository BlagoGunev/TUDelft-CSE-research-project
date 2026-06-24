#include <bits/stdc++.h>
/**

 *         					 Amit gangani

**/

// Header Files

#include<iostream>

#include<iomanip>

#include<algorithm>

#include<vector>

#include<utility>

#include<set>

#include<unordered_set>

#include<list>

#include<iterator>

#include<deque>

#include<queue>

#include<stack>

#include<set>

#include<bitset>

#include<random>

#include<map>

#include<unordered_map>

#include<stdio.h>

#include<complex>

#include<math.h>

#include<cstring>

#include<chrono>

#include<string>

#include "ext/pb_ds/assoc_container.hpp"

#include "ext/pb_ds/tree_policy.hpp"

// Header Files End

 

using namespace std;

using namespace __gnu_pbds;

template<class T>

using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

 

template<class key, class value, class cmp = std::less<key>>

using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order(k)  returns iterator to kth element starting from 0;

// order_of_key(k) returns count of elements strictly smaller than k;



#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define endl '\n'

#define ld long double

#define ll long long 

#define fi first

#define se second

#define umap unordered_map

#define uset unordered_set

#define lb lower_bound

#define ub upper_bound

#define fo(i,a,b) for(ll i=a;i<b;i++)

#define all(v) (v).begin(),(v).end()

#define all1(v) (v).begin()+1,(v).end()

#define allr(v) (v).rbegin(),(v).rend()

#define allr1(v) (v).rbegin()+1,(v).rend()

#define sort0(v) sort(all(v))

typedef pair<int, int> pii;

typedef vector<int> vi;

typedef vector<ll> vll;

typedef pair<ll, ll> pll;

#define sz(x) (ll)x.size()

#define pb push_back

#define ppb pop_back

#define mkp make_pair

#define inf 1000000000000000005

const ll mod = 1e9+7;

inline void Y(){ cout << "YES" << endl; }

inline void N(){ cout << "NO"  << endl; }



ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}

 

ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

 

ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

 

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

 

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

 

ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}

//****************************Template Ends*******************************//



int nn=1005;

vi dis(nn,INT_MAX);



void once(){

    dis[1]=0;

    

    fo(i,1,nn){

        fo(j,1,i+1){

            if(i + (i/j) <= nn) dis[i+(i/j)] = min(dis[i]+1,dis[i+(i/j)]);

        }

    }

}



void solve(){

    int n,k;

    cin >> n >> k;

    k = min(k,12000);

    vi a(n),v(n),w(n);

    

    fo(i,0,n){

        cin >> a[i];

        w[i]=dis[a[i]];

    }

    fo(i,0,n){

        cin >> v[i];

    }

    

    vector<vi> dp(n,vi(k+1));

    

    dp[0][0]=0;

    if(w[0]<=k)

        dp[0][w[0]]=v[0];

    

    fo(i,1,n){

        fo(j,0,k+1){

            dp[i][j] = dp[i-1][j];

            if(j - w[i]>=0)

                dp[i][j] = max(dp[i][j],v[i] + dp[i-1][j - w[i]]);

        }

    }

    

    int ans=0;

    fo(i,0,k+1){

        ans=max(ans,dp[n-1][i]);

    }

    

    cout << ans << endl;

}





int main(){

    fastio;

    ll t;

    t=1;

    cin >> t;

    once();

    while(t--){

        solve();

    }

    return 0;

}