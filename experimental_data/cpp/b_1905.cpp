#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define forl(i, a, e) for (ll i = a; i < e; i++)
#define ln "\n"
#define ull unsigned long long int
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define vll vector<ll>
#define prll vector<pair<ll, ll>>
#define mpll map<ll, ll>
#define graph map<ll, vll>
#define graphw map<ll, prll>
#define graph1 unordered_map<ll, vll>
#define graphw1 unordered_map<ll, prll>
// #define dbg(x) cout << #x << " = " << x << ln
/*------------------------------DEBUG TEMPLATE------------------------------*/
#ifndef ONLINE_JUDGE
#define dbg(x)         \
    cerr << #x << "="; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x) ;
#endif

void _print(int t)
{
    cerr << t;
}
void _print(ll t) { cerr << t; }
void _print(ull t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);

template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

/*--------------------------------------------------------------------------*/

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
const int M = 1e9 + 7;

long long mod(long long x)
{
    return ((x % M + M) % M);
}
long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}
long long mul(ll a, ll b)
{
    return mod(mod(a) * mod(b));
}
long long modPow(ll x, ll y)
{
    if (y == 0)
        return 1LL;
    if (y == 1)
        return mod(x);
    long long res = 1;
    while (y)
    {
        if (y % 2 == 1)
            res = mul(res, x);
        x = mul(x, x);
        y /= 2;
    }
    return res;
}

/*
Rashu123- Lawde ka career.............
*/

/*

*/

long long bpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void try_to_kr()
{
    ll i, j, c0 = 0, c1 = 0, c2 = 0, c3, c4;
    ll t1, t2, t3, t4;
    ll n;
    cin >> n;
    mpll mpp;
    forl(i, 0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        mpp[u]++;
        mpp[v]++;
    }
    ll ans = 0;
    for (auto &&i : mpp)
    {
        if (i.second == 1)
        {
            ans++;
            //  cout<<i.first<<" ";
        }
    }
    cout << (ans + 1) / 2 << ln;
}
int main()
{
    fast_cin();
    ll t;
    /////   precalc();
    cin >> t;
    // t = 1;
    //  orz orz
    while (t--)
    {
        try_to_kr();
    }
}