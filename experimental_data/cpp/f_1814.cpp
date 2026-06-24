#include <bits/stdc++.h>
//   #pragma GCC optimize ("Ofast,unroll-loops")
// #pragma GCC target ("avx2")
 using namespace std;
  typedef long long ll;
   typedef pair<int, int> pp;
     #define per(i,r,l) for(int i = (r); i >= (l); i--)
       #define rep(i,l,r) for(int i = (l); i < (r); i++)
          #define all(x) begin(x), end(x)
             #define sz(x) (int)(x).size()
                 #define pb push_back
                     #define ss second
                          #define ff first
                                  void err(istringstream *iss){}template<typename T,typename ...Args> void err(istringstream *iss,const T &_val, const Args&...args){string _name;*iss>>_name;if(_name.back()==',')_name.pop_back();cerr<<_name<<" = "<<_val<<", ",err(iss,args...);}
void IOS(){
     cin.tie(0) -> sync_with_stdio(0);
     #ifndef ONLINE_JUDGE
          #define er(args ...) cerr << __LINE__ << ": ", err(new istringstream(string(#args)), args), cerr << endl
          freopen("inp.txt", "r", stdin);
          freopen("out.txt", "w", stdout);
     #else
          #define er(args ...) 0
     #endif
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7, maxn = 2e5 + 5, lg = 22, inf = ll(1e18) + 5;
ll pw(ll a,ll b,ll md=mod){if(!b)return 1;ll k=pw(a,b>>1ll,md);return k*k%md*(b&1ll?a:1)%md;}

pp par[maxn];
int cnt[maxn];
vector<pair<pp, int>> his;
vector<int> adj[maxn];
bool vis[maxn];

void dfs2(int r){
     vis[r] = true;
     for(int c: adj[r]) if(!vis[c]){
          dfs2(c);
     }
}

pp get(int x){
     return par[x].ff == x? par[x]: get(par[x].ff);
}

void unite(int a, int b){
     auto[u, wu] = get(a);
     auto[v, wv] = get(b);
     if(u == v){
          his.pb({{-1, -1}, -1});
          return;
     }
     if(cnt[u] < cnt[v]) swap(u, v), swap(wu, wv);
     par[v].ff = u;
     cnt[u] += cnt[v];
     if(vis[wu]){
          par[u].ss = wv;
          his.pb({{u, v}, wu});
          adj[wv].pb(wu);
     } else{
          his.pb({{u, v}, -1});
          adj[wu].pb(wv);
     }
     int g = get(0).ff;
     if(u == g || v == g){
          dfs2(par[u].ss);
     }
}

void undo(){
     auto[p, w] = his.back(); his.pop_back();
     auto[u, v] = p;
     if(u + 1){
          par[v].ff = v;
          cnt[u] -= cnt[v];
          adj[par[u].ss].pop_back();
          if(w + 1){
               par[u].ss = w;
          }
     }
}

vector<pp> seg[maxn<<2];

void add(int l, int r, pp p, int x = 1, int lx = 0, int rx = maxn){
     if(l <= lx && r >= rx){
          seg[x].pb(p);
          return;
     }
     int mid = (lx + rx)>>1;
     if(l < mid) add(l, r, p, x<<1, lx, mid);
     if(mid < r) add(l, r, p, x<<1|1, mid, rx);
}

void dfs(int x = 1, int lx = 0, int rx = maxn){
     for(auto[u, v]: seg[x]){
          unite(u, v);
     }
     if(lx + 1 < rx){
          int mid = (lx + rx)>>1;
          dfs(x<<1, lx, mid);
          dfs(x<<1|1, mid, rx);
     } 
     for(auto[u, v]: seg[x]) undo();
}
 
pp edg[maxn<<1];
int l[maxn], r[maxn];

int main(){ IOS();
     int n, m; cin >> n >> m;
     rep(i,0,n){
          cin >> l[i] >> r[i];
     }
     rep(i,0,m){
          int u, v; cin >> u >> v; u--, v--;
          edg[i] = {u, v};
          int L = max(l[u], l[v]);
          int R = min(r[u], r[v]);
          if(L <= R){
               add(L, R + 1, edg[i]);
          }
     }
     rep(i,0,n){
          par[i] = {i, i};
          cnt[i] = 1;
     }
     vis[0] = true;
     dfs();
     rep(i,0,n){
          if(vis[i]){
               cout << i + 1 << ' ';
          }
     }
     cout << '\n';
     return 0-0;
}