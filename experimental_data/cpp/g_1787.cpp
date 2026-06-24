/* Author : Mychecksdead */

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define MOD (1000000000+7)

#define MOD1 (998244353)

#define PI 3.1415926535

#define pb push_back

#define all(x) x.begin(), x.end()

const int N = 1e6+100, M = 1e5+10, K = 20;





int n, q;

vector<array<ll, 3>> g[N];

vector<bool> good, active, open;

multiset<ll> s;

multiset<ll> lca[N];

vector<ll> sz, color, online, original;

vector<pair<int, int>> root;



void dfs(int v, int p, int up, int start){

  for(auto U: g[v]){

    int u = U[0], c = U[2];

    if(u == p) continue;

    color[u] = c;

    online[c]++;

    if(up == c){

      sz[c] += U[1];

      dfs(u, v, up, start);

    }else{

      if(root[c].first != 0 && root[c].first != v){

        good[c] = 0;

      }

      root[c] = {v, root[c].second + 1};

      if(root[c].second > 2){

        good[c] = 0;

      }

      sz[c] += U[1];

      dfs(u, v, c, v);

    }

  }

}

ll get_answer(){

  return (s.empty() ? 0 : *(--s.end()));

}



void case1(){

  for(int i = 0; i < q; ++i){

    int x; cin >> x >> x;

    cout << 0 << '\n';

  }

  exit(0);

}



void solve(){

  cin >> n >> q;

  

  if(n == 1){

    case1();

  }



  for(int i = 0; i < n - 1; ++i){

    int u, v, w, c; cin >> u >> v >> w >> c;

    g[u].pb({v, w, c});

    g[v].pb({u, w, c});

  }



  root.resize(n + 1);

  good.resize(n + 1, 1);

  color.resize(n + 1);

  sz.resize(n + 1);

  online.resize(n + 1);

  active.resize(n + 1, 1);

  open.resize(n + 1, 1);



  active[0] = good[0] = 0;



  dfs(1, 0, 0, 0);



  original = online;



  for(int i = 1; i <= n; ++i){

    if(sz[i] > 0 && good[i]){

      lca[root[i].first].insert(sz[i]);

    }

  }

  for(int i = 1; i <= n; ++i){

    if(!lca[i].empty()) s.insert(*(--lca[i].end()));

  }  

  for(int i = 1; i <= q; ++i){

    int tp, v; cin >> tp >> v;

    if(tp == 0){

      online[color[v]]--;

      open[v] = 0;



      if(!lca[v].empty())

        s.erase(s.find(*(--lca[v].end())));



      if(active[color[v]] && good[color[v]]){

        active[color[v]] = 0;

        int r = root[color[v]].first;



        if(!lca[r].empty() && open[r]) 

          s.erase(s.find(*(--lca[r].end())));



        lca[r].erase(lca[r].find(sz[color[v]]));

        

        if(!lca[r].empty() && open[r]) 

          s.insert(*(--lca[r].end()));

      }

    }else{

      online[color[v]]++;

      open[v] = 1;



      if(!lca[v].empty())

        s.insert(*(--lca[v].end()));

      

      if(!active[color[v]] && online[color[v]] == original[color[v]] && good[color[v]]){

        active[color[v]] = 1;

        int r = root[color[v]].first;

        if(!lca[r].empty() && open[r])

          s.erase(s.find(*(--lca[r].end())));



        lca[r].insert(sz[color[v]]);



        if(!lca[r].empty() && open[r]) 

          s.insert(*(--lca[r].end()));

      }

    }

    cout << get_answer() << '\n';

  }

}





int main(){

  cin.tie(0); ios::sync_with_stdio(0);

  int T = 1, aa;

  // cin >> T;aa=T;

  while(T--){

    // cout << "Case #" << aa-T << ": ";

    solve();

    cout << '\n';

  }

  return 0;

 

}