#include <bits/stdc++.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef tuple<ll, ll, ll> t64;
typedef vector<t64> vt64;
typedef vector<vt64> vvt64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef vector<bool> vb;
ll mod =  1e9+7;
double eps = 1e-12;
// #define forn(i,e) for(ll i = 0; i < e; i++)
#define FOR(s, e, i) for(ll i = s; i <= e; i++)
// #define rforn(i,s) for(ll i = s; i >= 0; i--)
#define ROF(s ,e, i) for(ll i = s; i >= e; i--)
#define coutAll(A) for(auto asdafas : A) cout <<  asdafas << " "; cout << "\n";
#define cinAll(A) for(auto &asdafas : A) cin >>  asdafas;
#define minpq priority_queue<ll, v64, greater<ll>>
#define maxpq priority_queue<ll> 
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef pair<ll, ll> pll;
typedef pair<ll, ll> pii;
//#define MAXN 1000000

struct DSU
{
    vector<ll> e;

    ll comp;
    DSU(ll N)
    {
        e = vector<ll>(N, -1);
        //used = vb(N, false);
    }

    // get representive component (uses path compression)
    ll get(ll x)
    {
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }

    bool same_set(ll a, ll b)
    {
        return get(a) == get(b);
    }

    ll size(ll x)
    {
        return -e[get(x)];
    }


    bool unite(ll x, ll y)    // union by size
    {

        x = get(x), y = get(y);
        if (x == y)
        {
            return false;
        }

        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};


bool valid(p64 x, ll &n, ll &m)
{
    return (x.fi  >= 0 && x.fi < n) && (x.se  >=0 && x.se< m);
}

ll mex(v64 A)
{
    ll x = 0;
    sort(all(A));
    ll prev = 0;
    for(ll y : A)
    {
        if(x == y) x++;
        else if(x < y) break;
    }
    return x;
}
ll digSum(ll n)
{
    ll ans =0;
    while(n) ans += n%10, n/=10;
    return ans;
}ll powMod(ll x, ll y, ll p = mod)
{
    ll res = 1;
    x %= p;
    while(y > 0)
    {
        if(y & 1)
            res = (res * x) % p;
            y >>= 1;
            x = (x * x) % p;
    }
    return res;
}


ll modInverse(ll n, ll p = mod)
{
    return powMod(n, p - 2, p);
}


ll ncr(ll n, ll r, ll p = mod)
{
    if(n < r) return 0;
    if(r == 0) return  1;
    v64 fact(n + 1, 0);
    fact[0] = 1;
    FOR(1, n, i)
    {
        fact[i] = (fact[i - 1] * i) % p;
    }
    return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n-r], p) % p) % p;
}
// ll ans, x;
// void dfs(ll s, ll n, vv64 &A, vb &used){
//        if(x == 2*n) ans = max(ans, s);
//         //cout << x << " ";
//         FOR(0, 2*n-2, i)
//         {
//             if(!used[i]){
//                 used[i] = true;
//                 FOR(i + 1, 2*n-1, j){
//                     if(!used[j]){
//                         used[j] = true;
//                         s ^= A[i][j];
//                         //ans = max(ans, s);
//                         x += 2;
//                         dfs(s, n, A, used);
//                         x -= 2;
//                         s ^= A[i][j];
//                         used[j] = false;
//                         //break;
//                     }
//                 }
//                 used[i] = false;
//                 break;
//             }

//         }
//         //cout << s << " ";
//         //ans = max(ans, s);
//    }
template< typename T >
T pow_mod(T x, T n, const T &p) {
  T res = 1;
  while(n > 0) {
    if(n & 1) (res *= x) %= p;
    (x *= x) %= p;
    n >>= 1;
  }
  return res;
}



bool wonFirst(char a, char b)
{
    //if(a == b) return true;
    return (a=='R'&&b=='S')||(a=='S'&&b=='P')||(a=='P'&&b=='R')||(a==b);
}

char bruteAns(string &a, ll from, ll to)
{
    if(to == from) return a[to];
    ll mid = (from + to)/2;
    char x = bruteAns(a, from, mid-1);
    char y = bruteAns(a, mid, to);
    if(wonFirst(x, y)) return x;
    return y;
}
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
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
    return z;
}
/*
15
4 5
100 100
100 100
100 100
100
*/
v64 B(3e5);
bool cmp(ll x, ll y)
{
    return B[x] < B[y];

}
string rev(string s, ll n)
{
    string temp;
    FOR(0, n - 1, i) temp += (s[i] == '0' ? '1' : '0');
    reverse(all(temp));
    FOR(n, s.size()-1, i) temp += s[i];
    return temp;
}

v64 prime;
void sieve()
{
    vb primes(1e5 + 1, true);
    primes[0] = primes[1] = false;
    for(int i = 2; i <= 1e5; i++)
    {
        if(primes[i]){
                prime.pb(i);
        for(int j = 2; j * i <= 1e5; j++)
        {
            primes[j*i] = false;

        }}
    }

}
void toBin(ll n)
{
    v64 A;
    while(n)
    {
        A.pb(n%2);
        n/=2;
    }
    reverse(all(A));
    for(ll x : A) cout << x;
    cout << "\n";
    cout << A.size() << "\n";
}

void dfs1(stack<ll>&st, vb &used, ll v, vv64 &adj)
{
    used[v] = true;
    for(ll u : adj[v])
    {
        if(!used[u])
        {
            dfs1(st, used, u, adj);
        }
    }
    st.push(v);
}

void dfs2(vb& used, ll v, vv64 &adjT, v64 &comp)
{
    used[v] = true;
    for(ll u : adjT[v])
    {
        if(!used[u])
        {
            dfs2(used, u, adjT, comp);
        }
    }
    comp.pb(v);
}
void kosaraju(vv64 &adj, vv64 &adjT, ll n, vv64 &compo)
{
    stack<ll>st;
    vb used(n, false);
    FOR(0, n - 1, i)
    {
        if(!used[i])
        {
            dfs1(st, used, i, adj);
        }
    }   
    FOR(0, n - 1, i) used[i] = false; 
    while(!st.empty())
    {
        ll v = st.top();
        st.pop();
        if(!used[v])
        {
            v64 comp;
            dfs2(used, v, adjT, comp);
            compo.pb(comp);
        }
    }

}
typedef pair<ll, ll> pll;

v64 dijkstra(vector<vector<pll>>& graph, ll source) { // it's 0-indexed algorithm, so fit it in accordance :)
    ll V = graph.size();
    vector<ll> dist(V, LLONG_MAX);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        // Skip if the current distance is already greater than the stored distance
        if (d > dist[u])
            continue;

        for (auto& neighbor : graph[u]) {
            ll v = neighbor.first;
            ll weight = neighbor.second;

            // Relax the edge if a shorter path is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
    // Print the shortest distances from the source to all vertices
    // for (ll i = 0; i < V; i++) {
    //     cout << dist[i] << ' ';
    // }
}
bool ok(v64 &A, ll k, ll m)
{
    ll s = 0;
    for(ll x : A)
    {
        s += min(m, x);
    }
    return s <= k;
}


ll give(vp64 A, v64 fact)
{
    if(A.size()==0) return 1;
    mod = 998244353;
    DSU dsu(50);
    FOR(0, A.size()-1, i)
    {
        dsu.unite(A[i].fi, A[i].se);
    }
    map<ll, ll>m;
    FOR(0, A.size()-1, i)
    {
        m[dsu.get(A[i].fi)] = dsu.size(A[i].fi);
    }
    ll ans = 1;
    for(auto x : m)
    {
        (ans *= fact[x.se]) %= mod;
    }
    return (ans);

}


ll make(string &s, map<char, ll>&m)
{
    ll n = 0;
    FOR(0, s.size() - 1, i)
    {
        n = n * 10 + m[s[i]];
    }
    return n;
}

void solve(ll it)
{
    //ifstream fin("testcase.txt");
    ll n, q; cin >> n >> q;
    v64 A(n);
    cinAll(A);
    set<ll>s;
    v64 B;
    FOR(0, q - 1, i)
    {
        ll x; cin >> x;
        if(s.count(x) == 0)
        {
            B.pb(x);
            s.insert(x);
        }
    }
    v64 p(40, 1);
    FOR(1, 35, i)
    {
        p[i] = p[i-1]*2;
    }
    for(ll x : B)
    {
        FOR(0, n - 1, i)
        {
            if(A[i] % p[x] == 0)
            {
                A[i] += p[x-1];
            }
        }

    }
    coutAll(A);






}

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif*/
    //
    fast_cin();

    //FOR(1, 10, i) cout << fact[2e5] << " ";
    ll t = 1;
    cin >> t;
    //sieve();
    //cout << prime.size() << "\n";
    for(int it=1; it<=t; it++)
    {
        //cout << "Case " << it << ": ";
        //cout << std::fixed << std::setprecision(0) << solve(it) << '\n';
        solve(it);
    }
    return 0;
}