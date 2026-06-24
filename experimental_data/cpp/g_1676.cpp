#include<bits/stdc++.h>



using namespace std;



#define ll long long

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)



const int INF = 0x3f3f3f3f, NINF = 0xf7f7f7f7;

const ll LINF = 0x3f3f3f3f3f3f3f3f, LNINF = 0xf7f7f7f7f7f7f7f7;

const int MOD1 = 1e9+7, MOD2 = 1e9+9;



ll memo1[4010], memo2[4010];



ll b(ll v, vector<vector<ll>>& g, string& s){

  if(memo1[v] != -1) return memo1[v];

  if(!g[v].size()){

    return (memo1[v] = (s[v-1] == 'B' ? 1 : 0));

  }

  ll r = 0;

  for(auto x : g[v])

    r += b(x, g, s);

  return (memo1[v] = (s[v-1] == 'B' ? r+1 : r));

}



ll w(ll v, vector<vector<ll>>& g, string& s){

  if(memo2[v] != -1) return memo2[v];

  if(!g[v].size()){

    ll r = (s[v-1] == 'W' ? 1 : 0);

    return (memo2[v] = (s[v-1] == 'W' ? 1 : 0));

  }

  ll r = 0;

  for(auto x : g[v])

    r += w(x, g, s);

  return (memo2[v] = (s[v-1] == 'W' ? r+1 : r));

}



void solve(){

  memset(memo1, -1, sizeof(memo1));

  memset(memo2, -1, sizeof(memo2));

  ll n; cin >> n;

  vector<ll> v(n);

  for(ll i = 1; i < n; ++i)

    cin >> v[i];

  string s; cin >> s;

  vector<vector<ll>> g(n+1, vector<ll>());

  for(ll i = 1; i < n; ++i){

    g[v[i]].push_back(i+1);

  }

  queue<ll> q;

  q.push(1);

  ll resp = 0;

  while(!q.empty()){

    ll vt = q.front();

    q.pop();

    if(b(vt, g, s) == w(vt, g, s))

     resp++;

    for(auto x : g[vt])

      q.push(x);

  }

  cout << resp << '\n';

}



int main(){

  ios_base::sync_with_stdio(0), cin.tie(0);

  ll t;

  cin >> t;

  while(t--){

    solve();

  }

}