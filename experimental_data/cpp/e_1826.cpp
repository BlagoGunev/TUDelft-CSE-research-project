#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ld long double
#define  vll vector<ll>
#define pb push_back
#define vp vector<pll>
#define vi vector<int>
#define ckmin(a,b) a = min(a,b)
#define ckmax(a,b) a = max(a,b)
#define all(x) (x).begin(), (x).end()
#define tc ll t; cin >> t; for(ll i = 0; i < t; i++){solve(i, t);}
#define mpvll map<ll, vll>
#define vfast vll a(n); for (ll i = 0; i < n; i++) { cin >> a[i]; }
#define mpll map<ll,ll>
#define pll pair<ll,ll>
#define vll2 vector<vector<ll>> dp(n, vector<ll>(m));b
#define FIXED(A) cout << fixed; cout.precision(20); cout << A << "\n";
#define mp(A, B) make_pair(A, B)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define F first
#define tc1 solve(1, 1);
#define S second
template <typename num_t>
using indexed_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
void setIO(string name) {freopen((name+".in").c_str(),"r",stdin);freopen((name+".out").c_str(),"w",stdout);}
void Case(ll TC){cout << "Case #" << TC+1 << ": ";}
ll rd(ll a, ll b){return (a+b-1) / b;}
ll isqrt(ll x){ll ans = 0; for( long long k = 1LL << 31; k != 0; k /= 2){if ((ans + k) * (ans + k) <= x) {ans += k;} } return ans;   }
vll prime(ll x){ll n = x; vll ans; while (n % 2 == 0) {ans.pb(2);n = n/2;} for (int i = 3; i <= sqrt(n); i = i + 2) {while (n % i == 0){ans.pb(i);n = n/i;}}if (n > 2){ans.pb(n);} return ans;}
ll binpow(ll a, ll b, ll m) { a %= m; ll res = 1; while (b > 0) { if (b & 1){res = res * a % m;}a = a * a % m; b >>= 1;} return res;}
ll lg2(ll n){ll cnt=0;while(n){cnt++;n/=2;}return cnt;}
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


struct DiGraph{
    int n;
    vector<vector<int>> g, gt;
    DiGraph() {}
    DiGraph(int n) : n(n), g(n), gt(n) {}
    void add_edge(int u,int v){
        g[u].push_back(v);
        gt[v].push_back(u);
    }
private:
    vector<int> _ts;
    vector<uint8_t> _ts_vis;
    void _ts_dfs(int u){
        _ts_vis[u] = 1;
        for(auto &v : g[u]){
            if(_ts_vis[v]) continue;
            _ts_dfs(v);
        }
        _ts.push_back(u);
    }
public:
    vector<int> topological_sort(){
        _ts_vis.assign(n, 0);
        _ts.assign(0, 0);
        _ts.reserve(n);
        for(int i=0;i<n;i++) if(!_ts_vis[i]) _ts_dfs(i);
        reverse(_ts.begin(), _ts.end());
        return std::move(_ts);
    }
private:
    vector<int> _scc_label;
    int scc_count = 0;
    void _scc_dfs(int u){
        _scc_label[u] = scc_count;
        for(auto &v : gt[u]){
            if(_scc_label[v] != -1) continue;
            _scc_dfs(v);
        }
    }
public:
    pair<DiGraph, vector<int>> decompose_scc(){
        _scc_label.assign(n, -1);
        vector<int> ord = topological_sort();
        for(auto &v : ord) if(_scc_label[v] == -1){
                _scc_dfs(v);
                ++scc_count;
            }
        DiGraph scc_graph(scc_count);
        for(int i=0;i<n;i++){
            for(auto &v : g[i]) if(_scc_label[i] != _scc_label[v])
                    scc_graph.add_edge(_scc_label[i], _scc_label[v]);
        }
        return pair(std::move(scc_graph), std::move(_scc_label));
    }
    vector<int>& operator[](int u){
        return g[u];
    }
    vector<int>& operator()(int u){
        return gt[u];
    }
    int size(){
        return n;
    }
};

void solve(ll TC, ll TC2) {

    ll n,m; cin >> m >> n;
    vll a(n); for(ll i = 0; i < n; i++){cin >> a[i];}
    vector<bitset<5000>> bit(n);
    for(ll i = 0; i < n; i++){bit[i].set();}
    for(ll i = 0; i < m; i++){
        bitset<5000> ok; ok.set();
        vector<vll> pos(n+1);
        vll r(n); for(ll j = 0; j < n; j++){cin >> r[j]; pos[r[j]].pb(j);}
        for(ll j = 1; j <= n; j++){
            for(ll x: pos[j]){ok[x]=0;}
            for(ll x: pos[j]){bit[x]&=ok;}
        }
    }


    vll mx = a, vis(n,-1);
    DiGraph d(n);
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            if(bit[i][j]){d.add_edge(i,j);}
        }
    }

    auto topo = d.topological_sort();



    for(ll u: topo){
        for(ll v: d.g[u]){
            ckmax(mx[v],mx[u]+a[v]);
        }
    }

    cout << *max_element(all(mx)) << '\n';

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    tc1
}