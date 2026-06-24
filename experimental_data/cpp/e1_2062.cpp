#define _GLIBCXX_DEBUG 1
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ll long long
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define printv(x) for (int iz = 0; iz < sz(x); iz++) cout << (x)[iz] << ((iz == sz(x)-1) ? '\n' : ' ')
#define printvv(x) for (int jz = 0; jz < sz(x); jz++) printv((x)[jz])

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1e15;
const double EPS = 0.0;

const int MOD = 998244353;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Node {
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = 0;
    Node(int lo, int hi) : lo(lo), hi(hi) {}
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(v, lo, mid); r = new Node(v, mid, hi);
            val = l->val + r->val;
        }
        else val = v[lo];
    }
    int query(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return val;
        push();
        return l->query(L, R) + r->query(L, R);
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset = x, val = x*(hi-lo), madd = 0;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = l->val + r->val;
        }
    }
    void add(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            if (mset != inf) mset += x;
            else madd += x;
            val += x * (hi - lo);
        }
        else {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = l->val + r->val;
        }
    }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo)/2;
            l = new Node(lo, mid); r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
        else if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};

template<class F>
int firstTrue(int lo, int hi, F f) {
    hi++;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
template<class F>
int lastTrue(int lo, int hi, F f) {
    lo--;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (f(mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

// void dijkstra(int s, vi& d, vi& p, vector<vector<pii>>& adj) {
//     int n = adj.size();
//     d.assign(n, inf);
//     p.assign(n, -1);
//     d[s] = 0;
//     priority_queue<pii, vector<pii>, greater<pii>> q;
//     q.push({0, s});
//     while (!q.empty())
//     {
//         int v = q.top().second, dv = q.top().first;
//         q.pop();
//         if (dv != d[v]) continue;
//         for (auto edge : adj[v]) {
//             int to = edge.first, len = edge.second;
//             if (d[v] + len < d[to]) {
//                 d[to] = d[v] + len;
//                 p[to] = v;
//                 q.push({d[to], to});
//             }
//         }
//     }    
// }

template<class F>
int ternSearch(int a, int b, F f) {
    assert(a <= b);
    while (b - a >= 5)
    {
        int mid = (a+b) / 2;
        if (f(mid) < f(mid+1)) a = mid;
        else b = mid+1;
    }
    
    rep(i, a+1, b+1) if (f(a) < f(i)) a = i;
    return a;    
}

int popCnt(signed num) { return __builtin_popcount(num); }
int popCnt(ll num) { return __builtin_popcountll(num); }
int msb(signed num) { return 31 - __builtin_clz(num); }
int msb(ll num) { return 63 - __builtin_clzll(num); }
int lsb(signed num) { return __builtin_ctz(num); }
int lsb(ll num) { return __builtin_ctzll(num); }

struct SegTree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) {
        return a + b;
    }
    vector<T> s; int n;
    SegTree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b%2) ra = f(ra, s[b++]);
            if (e%2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};
constexpr int SegTree::unit;

vi topoSort(const vector<vi>& gr) {
    vi indeg(sz(gr)), ret;
    for (auto& li : gr) for (int x : li) indeg[x]++;
    queue<int> q;
    rep(i, 0, sz(gr)) if (indeg[i] == 0) q.push(i);
    while (!q.empty())
    {
        int i = q.front();
        ret.push_back(i);
        q.pop();
        for (int x : gr[i])
            if (--indeg[x] == 0) q.push(x);
    }
    // return ret;
    return indeg;
}

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap == edges[id].flow)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u])
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int n, l, k;

int timer;
vector<int> tin, tout;
vector<int> depth;
vector<vector<int>> up;
vector<vector<int>> adj;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    if (v != p)
        depth[v] = depth[p]+1;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    if (v != 0 && adj[v].size() == 1)
        k++;

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int KAnc(int u, int k)
{
    for (int i = 0; i < l; i++)
    {
        if ((k >> i) & 1)
        {
            u = up[u][i];
        }
    }
    return u;
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    depth.resize(n);
    timer = 0;
    l = ceil(log2(n));
    k = 0;
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

// const int LIM = 2e5 + 10;
// bitset<LIM> isPrime;
// vi era() {
//     const int S = (int)round(sqrt(LIM)), R = LIM / 2;
//     // const int S = 12, R = 13;
//     vi pr = {2}, sieve(S+1); pr.reserve((int)(LIM/log(LIM)*1.1));
//     vector<pii> cp;
//     for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
//         cp.push_back({i, i*i / 2});
//         for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
//     }
//     for (int L = 1; L <= R; L += S) {
//         array<bool, S> block{};
//         for (auto &[p, idx] : cp)
//             for (int i = idx; i < S+L; idx = (i+=p)) block[i-L] = 1;
//         rep(i, 0, min(S, R - L))
//             if (!block[i]) pr.push_back((L + i) * 2 + 1);
//     }
//     for (auto i : pr) isPrime[i] = 1;
//     return pr;
// }


void z_function(const string& s, vi& z)
{
    int n = s.size();
    z.assign(n, 0);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
}

ll extgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b) return x=1, y=0, a;
    ll d = extgcd(b, a%b, y, x);
    return y -= a/b * x, d;
}

void solve()
{
    cin >> n;

    adj.assign(n, vi());

    map<int, vi> m;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        m[x].push_back(i);
    }

    rep(i, 0, n-1)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (sz(m) == 1)
    {
        cout << "0\n";
        return;
    }

    preprocess(0);

    int node;
    if (prev(m.end())->second.size() == 1)
        node = prev(m.end())->second[0];
    else
    {
        node = lca(prev(m.end())->second[0], prev(m.end())->second[1]);
        for (int i = 2; i < sz(prev(m.end())->second); i++)
            node = lca(node, prev(m.end())->second[i]);
    }
    
    for (auto it = next(m.rbegin()); it != m.rend(); it++)
    {
        for (auto u : it->second)
        {
            if (!is_ancestor(u, node) && u != node)
            {
                cout << u+1 << '\n';
                return;
            }
        }
        if (it->second.size() == 1)
            node = it->second[0];
        else
        {
            node = lca(it->second[0], it->second[1]);
            for (int i = 2; i < sz(it->second); i++)
                node = lca(node, it->second[i]);
        }
    }

    cout << "0\n";
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--)
        solve();
    
}