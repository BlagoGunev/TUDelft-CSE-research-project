//                                        الله العزه

#include <iostream>

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define nd "\n"

#define all(x) (x).begin(), (x).end()

#define lol cout <<"i am here"<<nd;

#define py cout <<"YES"<<nd;

#define pp  cout <<"ppppppppppppppppp"<<nd;

#define pn cout <<"NO"<<nd;

#define ld long double

#define popcount(x)  __builtin_popcount(x)

#define clz(n) __builtin_clz(n)//31 -x

const  double PI = acos(-1.0);

double EPS = 1e-9;

#define print2(x , y) cout <<x<<' '<<y<<nd;

#define print3(x , y , z) cout <<x<<' '<<y<<' '<<z<<nd;

#define watch(x) cout << (#x) << " = " << x << nd;

#define ull unsigned long long

template<class container>

void print(container v) { for (auto& it : v) cout << it<< ' '; cout << '\n'; }



void printpr(priority_queue<ll>&arr){ while(!arr.empty()){ cout <<arr.top()<<" "; arr.pop();}cout <<nd;}

const int N = 2e5+100;



// a few against many // 20 days of return can we? // 24 hours a day 7 days a week

ll fp(ll a , ll p){ if(!p) return 1; ll v = fp(a , p/2); v*=v;return p & 1 ? v*a : v;  }

ll  SEG = 2 << (int) ceil(log2(N)) ,  inf = 1e9;int t =1;



///template<typename T>

///vector<vector<T>>arr;

vector<vector<ll>>adj(N); vector<ll>cost(N) ,dp(N);

vector<bool>vis(N) , inStack(N);

ll n , m , k;

bool is_cyclic = 0;



ll dfs(int node , ll mx){

    inStack[node] = vis[node] = true;

    ll ans = 0;

    for (auto &ch : adj[node]){ if (cost[ch] > mx) continue;

        if (!vis[ch])

           ans = max(dfs(ch , mx) , ans);

        else is_cyclic|= inStack[ch];

        dp[node] = max(dp[node] , dp[ch]+1);

    }

    inStack[node] = false;

    dp[node] =max(dp[node] , 1ll);

    ans = dp[node];

    return ans;

}





void solve(){

    cin >>n>>m>>k;

    for (int i = 1; i <= n; ++i) adj[i].clear() , vis[i]= {} , dp[i]= {} ;



    for (int i = 1; i <= n; ++i){

        cin >>cost[i];

    }

    for (int i = 1; i <= m; ++i){

        int u , v; cin >>u>>v; adj[u].emplace_back(v);

    }



    auto go=[&](ll mx)->bool{

        is_cyclic = 0;

        for (int i = 1; i <= n; ++i){ vis[i]= {} , dp[i]= {};}

         for (int i = 1; i <= n; ++i){

             if (cost[i] > mx|| vis[i]) continue;

             ll ret = dfs(i , mx);

             if (ret >= k || is_cyclic) return true;

         }



        return false;

    };



    







    vector<ll>sorted = cost;

    sort(all(sorted)) , sorted.resize(unique(all(sorted))-sorted.begin());

    ll st = 0 ,end = (int)sorted.size()-1;

    ll ans = -1;

    while (st <=end){

        ll mid = st + end >> 1;

        bool ac = go(sorted[mid]);

      ///  cout <<ac<<' '<<sorted[mid]<<' '<<"oo  "<<nd;

        if (ac){

            ans = sorted[mid]; end = mid-1;

        }else{

            st = mid+1;

        }

    }

    cout <<ans<<nd;

















}





int main(){

    //create();

    ios_base::sync_with_stdio(0); cin.tie(0);

    //// freopen("input.txt","r",stdin);

    //  freopen("output.txt","w",stdout);

  /// cin >>t;

    while(t--)//while(t)//

        solve();

#ifndef ONLINE_JUDGE

    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";

#endif

    return 0;

}