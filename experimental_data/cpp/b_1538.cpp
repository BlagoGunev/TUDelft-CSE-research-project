#include <bits/stdc++.h>
#define int long long
#define ld long double
#define ul unsigned long long
#define eb emplace_back
#define pb push_back

#define vi vector<int>
#define vii vector<vi>
#define viii vector<vii>
#define viiii vector<viii>
#define vc vector<char>
#define vcc vector<vc>
#define vb vector<bool>
#define vbb vector<vb>
#define vbbb vector<vbb>

#define pa pair<int, int>
#define f first
#define s second
#define vpp vector<vector<pair<int, pa>>>

#define all(a) a.begin(), a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define cd complex<double>
#define sz(a) a.size()
using namespace std;

const int inf = 1e17;
const int MAX = 2e5 + 5;
const int mod = 998244353;
const int PI = 3.14159265358;
const double pi = acos(-1);

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}

template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}

void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

// int fact[MAX], rinv[MAX];

// void euc_ext(int a, int b, int *x, int *y)
// {
//     if (a == 0)
//     {
//         *x = 0, *y = 1;
//         return;
//     }
//     int x1, y1;
//     euc_ext(b % a, a, &x1, &y1);
//     *y = x1, *x = y1 - (b / a) * x1;
// }

// int m_inv(int a, int p)
// {
//     int x, y;
//     euc_ext(a, p, &x, &y);
//     int res = (x % p + p) % p;
//     return res;
// }

// void eva()
// {
//     fact[0] = 1, rinv[0] = 1;
//     for (int i = 1; i < MAX; i++)
//     {
//         fact[i] = i * fact[i - 1];
//         fact[i] %= mod;
//     }
//     for (int i = 1; i < MAX; i++)
//     {
//         rinv[i] = (m_inv(i, mod)) * (rinv[i - 1]);
//         rinv[i] %= mod;
//     }
// }

// int poww(int x, int y)
// {
//     int res = 1;

//     while (y > 0)
//     {
//         if (y & 1)
//             res = res * x;
//         res %= mod;
//         y = y >> 1;
//         x = x * x;
//         x %= mod;
//     }
//     return res;
// }

// vi spf(MAX);
// void sieve()
// {
//     spf[1] = 1;
//     for (int i = 2; i < MAX; i++)

//         // marking smallest prime factor for every
//         // number to be itself.
//         spf[i] = i;

//     // separately marking spf for every even
//     // number as 2
//     for (int i = 4; i < MAX; i += 2)
//         spf[i] = 2;

//     for (int i = 3; i * i < MAX; i++)
//     {
//         // checking if i is prime
//         if (spf[i] == i)
//         {
//             // marking SPF for all numbers divisible by i
//             for (int j = i * i; j < MAX; j += i)

//                 // marking spf[j] if it is not
//                 // previously marked
//                 if (spf[j] == j)
//                     spf[j] = i;
//         }
//     }
// }

// void build(int v, int tl, int tr, vi &arr)
// {
//     if (tl == tr)
//     {
//         arr[v] = 0;
//     }
//     else
//     {
//         int tm = (tl + tr) / 2;
//         build(v * 2, tl, tm, arr);
//         build(v * 2 + 1, tm + 1, tr, arr);
//         arr[v] = __gcd(arr[v * 2], arr[v * 2 + 1]);
//     }
// }
// int hcf(int v, int tl, int tr, int l, int r, vi &arr)
// {
//     if (l > r)
//         return 0;
//     if (tr < l || tl > r)
//     {
//         return 0;
//     }
//     if (l <= tl && r >= tr)
//     {
//         return arr[v];
//     }
//     int tm = (tl + tr) / 2;
//     return __gcd(hcf(v * 2, tl, tm, l, r, arr), hcf(v * 2 + 1, tm + 1, tr, l, r, arr));
// }

// void update(int v, int tl, int tr, int pos, int new_val, vi &arr)
// {
//     if (tl == tr)
//     {
//         arr[v] = new_val;
//     }
//     else
//     {
//         int tm = (tl + tr) / 2;
//         if (pos <= tm)
//             update(v * 2, tl, tm, pos, new_val, arr);
//         else
//             update(v * 2 + 1, tm + 1, tr, pos, new_val, arr);
//         arr[v] = __gcd(arr[v * 2], arr[v * 2 + 1]);
//     }
// }
// void dfs(int u, int par, int load, int cost, vpp &adj, vector<vector<pa>> &track, vi &arr, vi &ans)
// {
//     update(1, 1, MAX, load, cost, arr);
//     for (auto it : track[u])
//     {
//         ans[it.s] = hcf(1, 1, MAX, 1, it.f, arr);
//     }
//     for (auto it : adj[u])
//     {
//         if (it.f != par)
//         {
//             dfs(it.f, u, it.s.f, it.s.s, adj, track, arr, ans);
//         }
//     }
//     update(1, 1, MAX, load, 0, arr);
// }

void solve()
{
    int n; cin>>n;
    vi a(n);
    int tot=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        tot+=a[i];
    }
    if(tot%n!=0)cout<<-1;
    else{
        tot/=n;
        int ans=0;
        for(int i=0;i<n;i++){
            if(a[i]>tot){
                ans++;
            }
        }
        cout<<ans;
    }
    cout<<'\n';
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, tt;
    cin >> t;
    tt = t;
    while (tt--)
    {
        solve();
    }
    //solve();
}