#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
const int inf = 9e18;
const int mod = 1e9 + 7;
const int NUM = 1000030;
const int N = 10000000;
template <typename T, typename Y>
istream &operator>>(istream &is, pair<T, Y> &p)
{
    is >> p.first >> p.second;
    return is;
}
template <typename T, typename Y>
ostream &operator<<(ostream &os, pair<T, Y> p)
{
    os << p.first << ' ' << p.second << ' ';
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &i : v)
        is >> i;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v)
{
    for (auto &i : v)
        os << i << ' ';
    return os;
}
vector<int> lp, sieve;
vector<int> pr;
vector<int> power;
vector<int> fact;
void initpow(int x)
{
    power.resize(NUM);
    power[0] = 1;
    for (int i = 1; i < NUM; i++)
    {
        power[i] = (power[i - 1] * (x % mod)) % mod;
    }
}
void initFactorial()
{
    fact.resize(NUM);
    fact[0] = 1;
    for (int i = 1; i < NUM; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}
void calc_sieve()
{
    sieve.resize(NUM + 1, 0);
    for (int x = 2; x <= NUM; x++)
    {
        if (sieve[x])
            continue;
        for (int u = x; u <= NUM; u += x)
        {
            sieve[u] = x;
        }
    }
}
void primefactor()
{
    lp.resize(N + 1, 0);
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int binpow(int a, int b, int mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return ((a / gcd(a, b)) * b);
}
int inversemod(int a, int mod)
{
    return binpow(a, mod - 2, mod);
}
int divmod(int a, int b, int c)
{
    return ((a % c) * inversemod(b, c)) % c;
}
int combination(int n, int k)
{
    if (k > n)
        return 0;
    int p1 = (fact[n] * inversemod(fact[k], mod)) % mod;
    int p2 = (1 * inversemod(fact[n - k], mod)) % mod;
    return (p1 * p2) % mod;
}
#define DEBUG(x) cerr << #x << ": " << x << '\n'
vector<ll> adj[NUM];
vector<ll> tree[NUM];
ll dp[NUM];
ll ans;
ll big[NUM];
int n; // number of nodes
vector<bool> visited;
vector<int> tin, low;
int timer;
ll parent[NUM];
ll sz[NUM];
void IS_BRIDGE(int v, int to)
{
    // DEBUG(v);
    // DEBUG(to);
    if (dp[v] > dp[to])
    {
        swap(v, to);
    }
    ans = min(ans, (n * (n - 1)) / 2 - big[to] * (n - big[to]));
}
int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v])
    {
        if (to == p && !parent_skipped)
        {
            parent_skipped = true;
            continue;
        }
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges()
{
    timer = 0;
    visited.assign(n + 1, false);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}
void tree_dfs(ll u, ll e)
{
    big[u] = 1;
    for (auto &&i : tree[u])
    {
        if (i != e)
        {
            dp[i] = 1 + dp[u];
            tree_dfs(i, u);
            big[u] += big[i];
        }
    }
}
void solve()
{
    cin >> n;
    for (ll i = 0; i <= n; i++)
    {
        adj[i].clear();
        tree[i].clear();
        dp[i] = 0;
    }
    ll m;
    cin >> m;
    for (ll i = 1; i <= n; i++)
    {
        make_set(i);
    }
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        if (find_set(u) != find_set(v))
        {
            union_sets(u, v);
            tree[u].pb(v);
            tree[v].pb(u);
        }
    }
    tree_dfs(1, -1);
    ans = (n * (n - 1)) / 2;
    find_bridges();
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}