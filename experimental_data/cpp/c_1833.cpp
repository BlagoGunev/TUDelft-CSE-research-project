#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long long;

// Constants
const lld pi = 3.141592653589793238;
const ll INF = LONG_LONG_MAX;
const ll mod = 1e9 + 7;

// TypeDEf
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;

// Macros
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pn cout << "NO\n";
#define pimp cout << "IMPOSSIBLE\n";
#define vr(v) v.begin(), v.end()
#define rv(v) v.end(), v.begin()
#define len(s) (int)s.size()
#define forn(i, n) for (int i = 0; i < int(n); i++)

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

// Utility functions
template <typename T>
void print(T &&t) { cout << t << "\n"; }

template <typename T>
void printvec(vector<T> v)
{
    ll n = v.size();
    fl(i, n) cout << v[i] << " ";
    cout << "\n";
}
template <typename T>
ll sumvec(vector<T> v)
{
    ll n = v.size();
    ll s = 0;
    fl(i, n) s += v[i];
    return s;
}

// Mathematical functions
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
} //__gcd
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
ll moduloMultiplication(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res + a) % mod;
        b >>= 1;
    }
    return res;
}
ll powermod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Graph-dfs
//  bool gone[MN];
//  vector<int> adj[MN];
//  void dfs(int loc){
//      gone[loc]=true;
//      for(auto x:adj[loc])if(!gone[x])dfs(x);
//  }

// Sorting
bool sorta(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
bool sortd(const pair<int, int> &a, const pair<int, int> &b) { return (a.second > b.second); }

void solution()
{
    ll n;
    cin >> n;
    vector<ll> v;

    fl(i, n)
    {
        int elem;
        cin >> elem;
        v.push_back(elem);
    }

    sort(v.begin(), v.end());

    int a = v[0], b = v[n - 2], c = v[1], d = v[n - 1];

    // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

    // 0 3 1 2

    ll ans = abs(a - b) + abs(b - c) + abs(c - d) + abs(d - a);

    cout << ans << endl;

    // Proof

    // 100(4) * 500 = 10^8 * 500 = 8 * 10^9 > 10^9 -> failed because of TLE
    // [1,2,,,6,9,,,10,15]
    // 1 + 8 + 5 + 14 = 9 + 19 = 28
    // 5 + 3 + 6 + 14 = 14 + 14 = 28

    // [1,2,,,4,8,,,10,15]
    // 1 + 8 + 5 + 14 = 9 + 19 = 28
    // 3 + 4 + 7 + 14 = 14 + 14 = 28

    // [1,3,6,18,20]
    // 2 + 3 + 14 + 19 = 5 + 14 + 19 = 19*2 = 38
    // 1 3 6 20 => 1 6 3 20 =>

    // 1 3 1 3

    //  2 2 2 2

    // 5 1 3 2 - 3 - 1 10 3
    // -3 -1 5 10
    // 0 3 1 2
    // -3 10 -1 5
    // 13 + 11 + 6 + 8 = 24 + 14 = 38

    // -1 2 1 2
    // 3 + 1 + 1 + 3 =
}

vector<int> triangular = {1, 3, 6, 10, 15};

void coins()
{
    ll n;
    cin >> n;

    ll ans = 1e9;

    for (int ones = 0; ones <= 2; ones++)
    {
        for (int threes = 0; threes <= 1; threes++)
        {
            for (int sixes = 0; sixes <= 4; sixes++)
            {
                for (int tens = 0; tens <= 2; tens++)
                {
                    int remSum = 1 * ones + 3 * threes + 6 * sixes + 10 * tens;
                    // lena tbhi jab remaining sum % 15 == 0 ho
                    // otherwise continue with previous sum only
                    if (remSum <= n && (n - remSum) % 15 == 0)
                    {
                        ans = min(ans, ones + threes + sixes + tens + (n - remSum) / 15);
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

void solve()
{
    // 1 4 6 7 9 => 1 3
    //  2 4 5 5
    // odd = 5 even = 2
    // even -> odd = we need odd
    // odd -> even = we need odd

    int n;
    cin >> n;

    vector<int> v(n, 0);

    fl(i, n)
    {
        cin >> v[i];
    }

    // if all even
    bool alleven = true, allodd = true;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2)
        {
            alleven = false;
        }
        else
        {
            allodd = false;
        }
    }

    if (alleven || allodd)
    {
        cout << "YES" << endl;
        return;
    }

    ll minElem = *min_element(v.begin(), v.end());

    if (minElem % 2 != 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

// Main
int main()
{
    ll t;
    cin >> t;
    fl(i, t)
    {
        solve();
    }

    return 0;
}

// Rashid Siddiqui
// NSUT