#include <bits/stdc++.h>

using namespace std;



#define MOD 1000000007

#define INF 0x3f3f3f3f

#define f first

#define s second

#define rep(i,a,b) for (int i=a; i<b; ++i)

#define setpr(x) cout<<setprecision(x)<<fixed

#define sz(v) int(v.size())

#define all(v) v.begin(),v.end()

#define int ll



typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;



template <typename T> T mod(T a, T mod = MOD){ a %= mod; if (a<0) a += mod; return a; }

template <typename T> T add(T a, T b, T mod = MOD){ return (a+b)%mod; }

template <typename T> T sub(T a, T b, T mod = MOD){ return (a-b+mod)%mod; };

template <typename T> T mul(T a, T b, T mod = MOD){ return (a * 1ll * b) % mod; }

template <typename T> T binPow(T a, T b, T mod = MOD){ T res = 1; while (b>0){ if (b&1) res = mul<T>(res, a, mod); a = mul<T>(a,a, mod); b >>= 1; } return res; }

template <typename T> T binPowNoMod(T a, T b){ T res = 1; while (b>0){ if (b&1) res *= a; a *= a; b >>= 1; } return res; }

template <typename T> T divMod(T a, T b, T mod = MOD){ return mul(a, binPow(b, mod-2, mod), mod); }



const ld ep = 0.0000001;

const ld pi = acos(-1.0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



const int N = 505;



void solve(){

  string a,b;

  cin>>a>>b;

  

  int n = sz(a), m = sz(b);

  vector<int> start(n+5);

  

  rep(i,0,n-m+1){

    if (a.substr(i,m) == b) start[i] = 1;

  }

  

  vector<int> dp(n+5);

  vector<int> ways(n+5);

  

  dp[n] = 0;

  ways[n] = 1;

  for (int i=n-1;i>=0;i--){

    if (!start[i]){

      dp[i] = dp[i+1];

      ways[i] = ways[i+1];

      continue;

    }

    

    vector<pii> adj;

    rep(j,i,i+m){

      if (start[j]){

        adj.push_back({1+dp[j+m], ways[j+m]});

      }

    }

    

    sort(all(adj));

    dp[i] = adj[0].f;

    for (auto [moves, w]: adj){

      if (moves!=adj[0].f) break;

      

      ways[i] = add(ways[i],w);

    }

  }

  

  cout<<dp[0]<<" "<<ways[0]<<"\n";

}



#undef int

int main(int argc, const char * argv[]) {

  ios_base::sync_with_stdio(false);

  cin.tie(NULL);

  

  int t=1;

  cin>>t;

  for (int i=0;i<t;i++){

    solve();

  }

  

  return 0;

}