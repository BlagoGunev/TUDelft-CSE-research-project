#include <bits/stdc++.h>
#define i16 int16_t

using namespace std;
const int N = 100'000 + 1,
          Q = 300 + 1;
const long long INF = 1e14;

using ii = pair<int, int>;
#define fi first
#define se second

int n, q, a[N], cur = 0, nxt = 1, mn[3][Q][Q];
long long f[2][Q][Q][Q];
bool on[3];
vector<ii> v;

void init(){
  on[0] = on[1] = on[2] = true;

  for(int i = 0; i <= q; i++)
    for(int j = 0; j <= q; j++){
      for(i16 k = 0; k <= 2; k++) mn[k][i][j] = N;
      for(int k = 0; k <= q; k++) f[0][i][j][k] = f[1][i][j][k] = INF;
    }
  f[0][0][0][0] = 0;

  v.push_back({0, 1});
}

void query(int &t, int &x, int &y, ii &i, ii &j, ii &k){
  if(f[cur][i.fi][j.fi][k.fi] == INF) return;
  long long &val = f[cur][i.fi][j.fi][k.fi];

  if(on[0]){
    long long &ret = f[nxt][t][j.fi][k.fi];
    ret = min(ret, val + 1LL * mn[0][i.fi][t] * abs(i.se - x) + 1LL * a[t] * abs(x - y));
  }
  if(on[1]){
    long long &ret = f[nxt][i.fi][t][k.fi];
    ret = min(ret, val + 1LL * mn[1][j.fi][t] * abs(j.se - x) + 1LL * a[t] * abs(x - y));
  }
  if(on[2]){
    long long &ret = f[nxt][i.fi][j.fi][t];
    ret = min(ret, val + 1LL * mn[2][k.fi][t] * abs(k.se - x) + 1LL * a[t] * abs(x - y));
  }
  f[cur][i.fi][j.fi][k.fi] = INF;
}

int32_t main(){
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  
  cin >> n >> q;
  for(int i = 1; i <= q; i++) cin >> a[i];

  init();

  for(int t = 1; t <= q; t++){
    i16 ty; cin >> ty;
    if(ty == 1){
      int x, y; cin >> x >> y;

      int lim = max((int)v.size() - 1, 1);

      for(i16 i = 0; i <= 2; i++)
        for(int l = 0; l <= t; l++){
          mn[i][l][t] = mn[i][l][t - 1];
          if(on[i]) mn[i][l][t] = min(mn[i][l][t], a[t]);
        }

      for(int i = 0; i < lim; i++)
        for(int j = 0; j < lim; j++){
          if(i == j && v[i].fi) continue;

          query(t, x, y, v.back(), v[i], v[j]);
          query(t, x, y, v[i], v.back(), v[j]);
          query(t, x, y, v[i], v[j], v.back());
        }

      swap(cur, nxt);
      v.push_back({t, y});
    }else{
      i16 p; cin >> p;
      on[p - 1] ^= 1;

      for(i16 i = 0; i <= 2; i++)
        for(int l = 0; l <= t; l++){
          mn[i][l][t] = mn[i][l][t - 1];
          if(on[i]) mn[i][l][t] = min(mn[i][l][t], a[t]);
        }
    }
  }
  long long res = INF;
  for(auto a : v)
    for(auto b : v){
      int &i = a.fi, &j = b.fi, &k = v.back().fi;
      res = min({res, f[cur][i][j][k], f[cur][i][k][j], f[cur][k][i][j]});
    }

  cout << res << "\n";

  return 0;
}