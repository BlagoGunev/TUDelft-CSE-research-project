//**Template_begin**//

#include<bits/stdc++.h>



#include<ext/pb_ds/assoc_container.hpp>

#include<ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;



typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

 

#define ll long long

#define ld long double

#define int unsigned int

#define inf 1000000000000000005

#define mod 1000000007

typedef pair<int, int> pii;

typedef vector<int> vii;

typedef vector<ll> vll;

typedef pair<ll, ll> pll;

#define pb push_back

#define ppb pop_back

#define puf push_front

#define pof pop_front

#define lb lower_bound

#define ub upper_bound

#define fi first

#define se second

#define sz(x) (ll)x.size()

#define _BENZ_ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 1e6 + 10;

 

// std::cout << std::fixed;

// std::cout << std::setprecision(12);

// floor(2.3)

// ceil(2.3)

 

//******//

//**Template_end***//



struct custom_hash {

    static uint64_t splitmix64(uint64_t x) {

        // http://xorshift.di.unimi.it/splitmix64.c

        x += 0x9e3779b97f4a7c15;

        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;

        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;

        return x ^ (x >> 31);

    }

 

    size_t operator()(uint64_t x) const {

        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64(x + FIXED_RANDOM);

    }

}; // unordered_map<ll , ll , custom_hash> mp;



ll expo(ll a, ll b, ll mod1) {ll res = 1; while (b > 0) {if (b & 1ll)res = (res * a) % mod1; a = (a * a) % mod1; b = b >> 1ll;} return res;}



vector<vll> adj1 , adj2;



void solve(){

    ll n , m;

    cin >> n >> m;



    adj1.assign(n + 5ll , {});

    adj2.assign(n + 5ll , {});



    for(ll i = 1; i <= m; ++i) {

         ll x , y;

         cin >> x >> y;



         adj1[x].pb(y);

         adj2[y].pb(x);

    }



    ll k;

    cin >> k;



    vll v(k + 5ll , 0ll);



    for(ll i = 1; i <= k; ++i) {

        cin >> v[i];

    }



    ll start = v[k];



    vll dis(n + 5ll , -1ll);



    queue<ll> qu;



    qu.push(start);



    dis[start] = 0ll;



    while(sz(qu)) {

         ll fr = qu.front();

         qu.pop();



         for(auto &it : adj2[fr]) {

              if(dis[it] != -1ll) continue;



              dis[it] = dis[fr] + 1ll;

              qu.push(it);

         }

    }



    ll ans_mx = 0ll , ans_mn = 0ll;



    // for(ll i = 1; i <= n; ++i) {

    //     cout << dis[i] << " ";

    // }



    // cout << "\n";



    vll vis(n + 5ll , 0ll);



    for(ll i = 1; i <= k - 1ll; ++i) {

          

          vis[v[i]] = 1ll;



          if (dis[v[i]] != dis[v[i + 1]] + 1)

            ++ans_mn;



          for(auto &it : adj1[v[i]]) {

               if(it == v[i + 1ll]) continue;

               // if(vis[it]) continue;



               if(dis[it] <= dis[v[i + 1ll]]) {

                     ans_mx++;

                     break;

               }

          }

    }



    cout << ans_mn << " " << ans_mx << "\n";

}  

 

int32_t main(){

 

    _BENZ_

 

    ll t = 1;

    // cin >> t;

 

    while(t--){

        solve();

    } 



    // cout << "HELLO " << "\n";



 /*

   Think of the edge case (n == 1 ?).

   Don't get stuck on a single approach for a long time.

   Also don't get stuck on a single problem for a long time :).

 */   

 

    return 0;

}



/*



*/