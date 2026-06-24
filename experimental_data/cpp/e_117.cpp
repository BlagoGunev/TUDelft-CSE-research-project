// whats 1000 minus 7 ?
// I'm bad, and that's good. I will never be good, and that's not bad. There's no one I'd rather be than me.
#include <bits/stdc++.h>
using namespace std;
inline int in(){int32_t x ; scanf("%d",&x) ; return x ; }
inline string get(){char ch[1000010] ; scanf("%s",ch) ; return ch;}
const int MAX_LG = 21;
//#define int long long
//#define x first
//#define y second
#define endl "\n"
#define mp make_pair
typedef pair<int , int > pii;
typedef long double ld;
typedef long long ll;
const int maxn = 2e5 + 100;
const int base = 29;
const int mod = 1e9 + 7;
const int INF = 2e9 + 100;
vector<int> adj[maxn] , cycle ;
int tree_pos[maxn]  , cur , head[maxn] , en[maxn] , stree[4*maxn ] , sz[maxn] , heavy[maxn] , mark[maxn] , h[maxn] , pre[maxn];
bool lazy[4 * maxn];

bool on_cycle[maxn];
inline int findhead(int v , int pr = -1) // finding the head of cycle
{
    mark[v] = (int)cycle.size();
    cycle.push_back(v);
    for (auto u : adj[v])
    {
        if (mark[u] == -1)
        {
            int x = findhead(u,v);
            if (x != -1)
                return x;
        }
        else if (u != pr)
            return mark[u];
    }
    cycle.pop_back();
    return -1;
}
inline void dfs_hld(int v , int pr = -1)
{
    sz[v] = 1;
    int maxi = 0;
    for (auto u : adj[v])
    {
        if (u != pr && on_cycle[u] == 0)
        {
            en[u] = en[v];
            h[u] = h[v] + 1;
            pre[u] = v;
            dfs_hld(u,v);
            sz[v] += sz[u];
            if (sz[u] > maxi)
                maxi = sz[u] , heavy[v] = u;
        }
    }
}
inline void shift(int p , int l  ,int r)
{
    if (lazy[p] == 0)
        return;
    lazy[2 * p + 1] ^= 1;
    lazy[2 * p + 2] ^= 1;
    int mid = (l + r) >> 1;
    stree[2 * p + 1] = (mid - l + 1) - stree[2 * p + 1];
    stree[2 * p + 2] = (r - mid) - stree[2 * p + 2];
    lazy[p] = 0;
}
inline int get(int ql , int qr , int p  = 0 , int l = 0 , int r = cur - 1)
{
    if (ql > qr) return 0;
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return stree[p];
    int mid = (l + r) >> 1;
    shift(p,l,r);
    return get(ql , qr , 2 * p + 1 , l , mid) + get(ql , qr , 2 * p + 2 , mid + 1 , r);
}
inline void update(int ql , int qr , int p = 0 , int l = 0 , int r = cur - 1)
{
    if (ql > qr) return;
    if (l > qr || r < ql) return ;
    if (l >= ql && r <= qr)
    {
        lazy[p] ^= 1;
        stree[p] = (r - l + 1) - stree[p];
        return;
    }
    shift(p,l,r);
    int mid = (l + r) >> 1;
    update(ql , qr , 2 * p + 1 , l , mid);
    update(ql , qr , 2 * p + 2 , mid + 1 , r);
    stree[p] = stree[2 * p + 1] + stree[2 * p + 2];
}
inline void update_path(int v , int u)
{
    while (head[v] != head[u])
    {
        if (h[head[u]] > h[head[v]]) swap(v,u);
        update(tree_pos[head[v]] , tree_pos[v]);
        v = pre[head[v]];
    }
    if (h[u] > h[v]) swap(v,u);
    update(tree_pos[u] + 1 , tree_pos[v]);
}
int n , m , cycle_size;

inline void out()
{
    int cntCycle = max(cycle_size - get(0 , cycle_size - 1),1);
    int cntTree = n - get(cycle_size , cur - 1);
    int tot = cntCycle + cntTree - cycle_size;
    printf("%d\n",tot);
}
int32_t main()
{
    memset(mark,-1,sizeof mark);
    memset(heavy,-1,sizeof heavy);
    memset(pre,-1,sizeof pre);
    n = in() , m = in() ;
    for (int i = 0 ; i < n ; i ++)
    {
        int v = in() , u = in();
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    int x = findhead(1);
    cycle.erase(cycle.begin(),cycle.begin()+x);
    for (auto v : cycle ) on_cycle[v] = true;
    for (auto v : cycle)
    {
        pre[v] = v;
        tree_pos[v] = cur ++;
        head[v] = en[v] = v;
        dfs_hld(v);
    }
    for (int i = 1 ; i <= n ; i ++)
    {
        if (on_cycle[i] || (!on_cycle[pre[i]] && heavy[pre[i]] == i)) continue;
        for (int u = i ; u != -1 ; u = heavy[u])
            tree_pos[u] = cur ++ , head[u] = i;
    }
    cycle_size = (int)cycle.size();
    while(m --)
    {
        int v = in() , u = in();
        update_path(v,en[v]);
        update_path(u,en[u]);
        if (en[v] == en[u]){
            out();
            continue;
        }
        v = en[v] , u = en[u];
        int len1 , len2;
        bool changed = 0;
        bool tp = 0;
        if (tree_pos[v] > tree_pos[u]) swap(v,u) , changed = true;
        len1 = tree_pos[u] - tree_pos[v];
        len2 = cycle_size - len1;
        if (len1 == len2)
        {
            if (!changed)
            {
                int nxt = cycle[(tree_pos[v] + 1)%cycle_size];
                int pre = cycle[(tree_pos[v] - 1 + cycle_size) % cycle_size];
                if (nxt > pre)
                    tp = 1;
            }
            else
            {
                int nxt = cycle[(tree_pos[u] + 1)%cycle_size];
                int pre = cycle[(tree_pos[u] - 1 + cycle_size) % cycle_size];
                if (nxt < pre)
                    tp = 1;
            }
        }
        else
        {
            if (len1 > len2)
                tp = 1;
        }
        if (tp == 0)
            update(tree_pos[v] + 1 , tree_pos[u]);
        else
        {
            update(tree_pos[cycle[0]] , tree_pos[v]);
            update(tree_pos[u] + 1 , tree_pos[cycle.back()]);
        }
        out();
    }
}