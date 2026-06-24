//*Bismillahir Rahmanir Raheem

//! BlackBeard

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#define NFS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace __gnu_pbds;

using namespace std;

template <typename DT>

using oset = tree<DT, null_type, less<DT>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename DT, typename FUNC>

using o_set = tree<DT, null_type, FUNC, rb_tree_tag, tree_order_statistics_node_update>;

template <typename DT1, typename DT2>

using omap = tree<DT1, DT2, less<DT1>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename DT1, typename DT2, typename FUNC>

using o_map = tree<DT1, DT2, FUNC, rb_tree_tag, tree_order_statistics_node_update>;



#define YES cout << "YES" << endl

#define Yes cout << "Yes" << endl

#define yes cout << "yes" << endl

#define No cout << "No" << endl

#define NO cout << "NO" << endl

#define no cout << "no" << endl



#define ll long long

#define lld long double

#define ull unsigned long long

#define pii pair<int, int>

#define pll pair<ll, ll>

#define vi vector<int>

#define vl vector<ll>

#define vii vector<pii>

#define vll vector<pll>

#define pb push_back

#define ff first

#define ss second



#define PQiimn priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>

#define PQllmn priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>

#define PQiimx priority_queue<pair<int, int>>

#define PQllmx priority_queue<pair<ll, ll>>

#define PQ priority_queue<int>



#define FILL(x, y) memset(x, y, sizeof(x))

#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()

#define fore(arr) for (auto &x : (arr))

#define max3(a, b, c) max(a, max(b, c))

#define min3(a, b, c) min(a, min(b, c))

#define gcd(x, y) __gcd(x, y)

#define lcm(x, y) x *(y / gcd(x, y))

#define preci(x) fixed << setprecision(x)

#define PI (acos(-1.0))

#define SZ(x) (int)x.size()

#define EPS (1e-9)

#define bug cout << "*_*\n"



const ll MAXLL = 1e18 + 5;

const ll MAXIN = 1e9 + 5;

const ll MOD = 1e9 + 7;

const ll N = 1000000000000;



ll bin_expo(ll a, ll b)

{

    ll s = 1;

    while (b > 0)

    {

        if (b % 2 == 1)

            s = ((s % MOD) * (a % MOD)) % MOD;

        a = ((a % MOD) * (a % MOD)) % MOD;

        b = b >> 1;

    }

    return s % MOD;

}

inline ll mod(ll a) { return (a % MOD + MOD) % MOD; }

inline ll modAdd(ll a, ll b) { return mod(mod(a) + mod(b)); }

inline ll modSub(ll a, ll b) { return mod(mod(a) - mod(b)); }

inline ll modMul(ll a, ll b) { return mod(mod(a) * mod(b)); }

inline ll modInv(ll a) { return bin_expo(a, MOD - 2); }

int dx[] = {0, 0, -1, 1};

int dy[] = {1, -1, 0, 0};

int dxk[] = {-2, -2, -1, -1, 1, 2, 2, 1};

int dyk[] = {1, -1, 2, -2, 2, 1, -1, -2};

int dx1[] = {0, 1, 1, 1, 0, -1, -1, -1};

int dy1[] = {1, 1, 0, -1, -1, -1, 0, 1};

int cs = 1;

template <class T>

inline void print(vector<T> v) { fore(v) cout << x << ' '; }

inline ll ciel(double a, double b) { return (a + (b - 1)) / b; }

inline void CASE() { cout << "Case " << cs++ << ":"; }

inline int numOfDigit(ll n) { return log10(n) + 1; }

inline int bitsInBinary(ll n) { return log2(n) + 1; }



ll POW(ll b, ll p)

{

    ll r = 1;

    for (int i = 0; i < p; i++)

        r *= b;

    return r;

}



void solve()

{

    int n;

    cin >> n;

    vector<int> v(n), a(n), b(n);

    fore(v) cin >> x;

    a[0] = b[0] = v[0];

    int arr[n + 1] = {0};

    arr[v[0]] = 1;

    for (int i = 1; i < n; i++)

    {

        if (v[i] != v[i - 1])

        {

            a[i] = b[i] = v[i];

            arr[v[i]] = 1;

        }

        else

            a[i] = -1, b[i] = -1;

    }

    vector<int> vs;

    set<int> s;

    for (int i = 1; i <= n; i++)

    {

        if (!arr[i])

            vs.pb(i), s.insert(i);

    }

    int x = 0;

    for (int i = 1; i < n; i++)

    {

        if (a[i] == -1)

            a[i] = vs[x++];

    }

    for (int i = 1; i < n; i++)

    {

        if (b[i] == -1)

        {

            auto it = s.lower_bound(v[i]);

            it--;

            b[i] = *it;

            s.erase(it);

        }

    }

    print(a);

    cout << endl;

    print(b);

    cout << endl;

}

int main()

{

    NFS;

#ifndef ONLINE_JUDGE

    freopen("D:/Entertainment/code/C++/OJ/in.txt", "r", stdin);

    freopen("D:/Entertainment/code/C++/OJ/out.txt", "w", stdout);

#endif

    int t = 1;

    cin >> t;

    while (t--)

    {

        solve();

    }

}