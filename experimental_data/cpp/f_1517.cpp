#include <bits/stdc++.h>

using namespace std;



#define FOR(x,n) for(int x=0;x<n;x++)

using ll = long long;

using ii = pair<int,int>;



const int MX = 303;

const ll MOD = 998244353;

ll dp[MX][MX][2];

vector<int> adj[MX];

ll b;



ll mod_exp(ll x, ll y, ll mod) {

    ll res = 1;

    while(y > 0) {

        if(y & 1) res = res*x % mod;

        y >>= 1;

        x = x*x % mod;

    }

    return res;

}



ll get(int i, int j, int k) {

  if(j >= 0) return dp[i][j][k];

  return 0;

}



void dfs(int cur, int prev) {

  bool leaf = true;

  for(int c : adj[cur]) {

    if(c == prev) continue;

    leaf = false;

    dfs(c, cur);

    for(int i = 1; i <= b; i++) {

      dp[c][i][0] = (dp[c][i][0] + dp[c][i - 1][0]) % MOD;

      dp[c][i][1] = (dp[c][i][1] + dp[c][i - 1][1]) % MOD;

    }

  }

  

  if(leaf) {

    dp[cur][b][0] = 1;

    dp[cur][0][1] = 1;

    return;

  }

  

  dp[cur][b][0] = 1;

  for(int c : adj[cur]) {

    if(c == prev) continue;

    ll mult = (dp[c][b][0] + dp[c][b][1]) % MOD;

    dp[cur][b][0] = (dp[cur][b][0] * mult) % MOD;

  }

  

  FOR(j,b) {

    ll p1 = 1, p2 = 1;

    for(int c : adj[cur]) {

      if(c == prev) continue;

      ll c1 = (get(c, j - 1, 1) + get(c, j + 1, 0)) % MOD;

      ll c2 = (get(c, j - 1, 1) + get(c, j, 0)) % MOD;

      p1 = (p1 * c1) % MOD;

      p2 = (p2 * c2) % MOD;

    }

    dp[cur][j][0] = (p1 - p2 + MOD) % MOD;

  }

  

  FOR(j,b) {

    ll p1 = 1, p2 = 1;

    for(int c : adj[cur]) {

      if(c == prev) continue;

      if(j) {

        ll c1 = (get(c, j - 1, 1) + get(c, j, 0)) % MOD;

        ll c2 = (get(c, j - 2, 1) + get(c, j, 0)) % MOD;

        p1 = (p1 * c1) % MOD;

        p2 = (p2 * c2) % MOD;

      }

      else {

        p1 = (p1 * dp[c][0][0]) % MOD;

      }

    }

    dp[cur][j][1] = j ? ((p1 - p2 + MOD) % MOD) : p1;

  }

}



int main() {

  ios_base::sync_with_stdio(false);

  cin.tie(NULL);

  // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  

  int n;

  cin >> n;

  FOR(i,n-1) {

    int u, v;

    cin >> u >> v;

    u--; v--;

    adj[u].push_back(v);

    adj[v].push_back(u);

  }

  

  ll ans = MOD - 1, pv = 1;

  for(ll i = 1; i <= n; i++) {

    b = i;

    memset(dp, 0, sizeof dp); 

    dfs(0, -1);

    ll here = 0;

    FOR(j,b+1) here = (here + dp[0][j][0]) % MOD;

    ans = (ans + (here - pv + MOD) * (b - 1)) % MOD;

    pv = here;

  }

  

  ll d = mod_exp(2, n, MOD);

  d = mod_exp(d, MOD - 2, MOD);

  ans = (ans + n) % MOD;

  ans = (ans * d) % MOD;

  

  cout << ans << '\n';

}