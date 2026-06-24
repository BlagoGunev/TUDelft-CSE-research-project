#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
using ll = long long;
using LL = long long;
using i64 = long long;
#define double long double
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define lowbit(x) (x & (-(x)))
template <int x> using arr = array<int, x>;
constexpr ll mod = 998244353;
constexpr ll inf = 1e16 + 7;
constexpr ll M = 2e5 + 3;

int col[M], tot;
vector<int> edge[M];
vector<int> siz(M), dep(M), L(M), R(M), pos(M);
vector<int> hson(M);
void dfs(int u, int fa = 0)
{
    L[u] = ++tot, pos[tot] = u;
    siz[u] = 1;
    for(auto& v : edge[u])
    {
        if(v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
        if(siz[hson[u]] < siz[v]) hson[u] = v;
    }
    R[u] = tot;
}

gp_hash_table<int, int> cotp, cotq;
set<int> pp, qq;
void add(int u)
{
    if(++cotp[col[u]] == 2) pp.insert(col[u]);
    if(--cotq[col[u]] == 1) qq.erase(col[u]);
}

void del(int u)
{
    if(--cotp[col[u]] == 1) pp.erase(col[u]);
    if(++cotq[col[u]] == 2) qq.insert(col[u]);
}

// consider now and fa -> 
map<arr<2>, int> ans;
void dsu(int u, int fa = 0, int kep = 0)
{
    for(auto& v : edge[u])
        if(v != hson[u] and v != fa)
            dsu(v, u, false);
    if(hson[u])
        dsu(hson[u], u, true);

    add(u);
    for(auto& v : edge[u])
        if(v != hson[u] and v != fa)
            for(int i = L[v];i <= R[v];++i)
                add(pos[i]);
    int res = 0;
    // cout << u << endl;
    // for(auto& [e, v] : cotp) cout << e << ' ' << v << endl;
    // cout << endl;
    // for(auto& [e, v] : cotq) cout << e << ' ' << v << endl;

    if(not pp.empty()) res = max(res, *pp.rbegin());
    if(not qq.empty()) res = max(res, *qq.rbegin());
    // cout << "pp" << endl;
    // for(auto& e : pp) cout << e << endl;
    // cout << "qq" << endl;
    // for(auto& e : qq) cout << e << endl;

    // cout << '#' << u << ' ' << fa << endl;

    if (min(u, fa)) ans[{min(u, fa), max(u, fa)}] = res;
    if(not kep)
        for(int i = L[u];i <= R[u];++i)
            del(pos[i]);
}
map<arr<2>, int> idx;
void slove()
{
    int n; cin >> n;
    int u, v;
    for(int i = 1;i < n;++i)
        cin >> u >> v, edge[u].push_back(v), edge[v].push_back(u),
        idx[{min(u, v), max(u, v)}] = i;

    for(int i = 1;i <= n;++i)
    {
        cin >> col[i], ++cotq[col[i]];
        if(cotq[col[i]] == 2) qq.insert(col[i]);
    }
    dfs(1);
    dsu(1);
    vector<int> res(n + 1);
    for(auto [u, v] : ans)
        res[idx[u]] = v;

    for(int i = 1;i < n;++i)
        cout << res[i] << endl;

}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int t = 1;  
    // cin >> t;
    // init();
    while(t--)
        slove();
    return 0;
}