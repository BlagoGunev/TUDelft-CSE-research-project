// clang-format off
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <fstream>
#include <string>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <iostream>
#include <stack>
#include <map>
#include <cstring>
#include <list>
#include <deque>
#include <sstream>
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <iterator>
#include <functional>
#include <limits>
#include <numeric>
#include <cassert>
#include <unordered_map>
#include <random>
#include <bitset>
using namespace std;

typedef long long ll;
typedef long double dl;
ll gcd(ll a, ll b)
{
    if (a == 0 || b == 0) return a + b;
    if (a > b) return gcd(a % b, b);
    return gcd(a, b % a);
}
ll power(ll a, ll p, ll mod) {
    if (p == 0) return 1ll;
    ll prew = power(a, p / 2, mod);
    if (p & 1) return ((prew * prew) % mod * a) % mod;
    return (prew * prew) % mod;
}
bool prime(ll n) {
    if (n <= 1) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
ll factmod(ll n, ll mod) {
    ll res = 1;
    while (n > 1) {
        if ((n / mod) & 1) res = (res * (mod - 1)) % mod;
        for (ll i = 2; i <= n % mod; i++) res = (res * i) % mod;
        n /= mod;
    }
    return res % mod;
}
ll get_hash(ll l, ll r, vector <ll>& pows, vector <ll>& h, ll mod)
{
    return ((h[r + 1] - pows[r - l + 1] * h[l]) % mod + mod) % mod;
}
vector <ll> pref_func(string& s)
{
    ll n = s.size();
    vector <ll> p(n);
    for (ll i = 1; i < n; i++)
    {
        p[i] = p[i - 1];
        while (p[i] > 0 && s[i] != s[p[i]]) p[i] = p[p[i] - 1];
        if (s[i] == s[p[i]]) p[i]++;
    }
    return p;
}
vector <ll> z_func(string& s)
{
    ll n = s.size(), l = 0, r = 0;
    vector <ll> z(n);
    for (ll i = 1; i < n; i++)
    {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (z[i] + i < n && s[z[i]] == s[z[i] + i]) z[i]++;
        if (z[i] + i - 1 > r)
        {
            l = i;
            r = z[i] + i - 1;
        }
    }
    return z;
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
vector <ll> sufmas(string& s)
{
    ll n = s.size();
    vector <ll> d(n);
    for (ll i = 0; i < n; i++) d[i] = s[i] - 'a' + 1;
    d.push_back(0);
    n++;
    vector <pair <ll, ll>> a(n);
    for (ll i = 0; i < n; i++) a[i] = { d[i], i };
    sort(a.begin(), a.end());
    vector <ll> c(n), p(n);
    for (ll i = 0; i < n; i++) p[i] = a[i].second;
    c[p[0]] = 0;
    for (ll i = 1; i < n; i++)
    {
        c[p[i]] = c[p[i - 1]];
        if (a[i].first != a[i - 1].first) c[p[i]]++;
    }
    ll k = 0;
    while ((1 << k) < n)
    {

        vector <pair <pair <ll, ll>, ll>> f(n);
        for (ll i = 0; i < n; i++)
        {
            f[i] = { {c[p[i]], c[(p[i] + (1 << k)) % n]}, p[i] };
        }
        sort(f.begin(), f.end());
        vector <ll> new_c(n);
        for (ll i = 0; i < n; i++) p[i] = f[i].second;
        new_c[p[0]] = 0;
        for (ll i = 1; i < n; i++)
        {
            new_c[p[i]] = new_c[p[i - 1]];
            if (!(c[p[i - 1]] == c[p[i]] && c[(p[i] + (1 << k)) % n] == c[(p[i - 1] + (1 << k)) % n]))
            {
                new_c[p[i]]++;
            }
        }
        k++;
        c = new_c;
    }
    return p;
}
vector <ll> find_lcp(string& s, vector <ll>& p)
{
    ll n = s.size();
    vector <ll> id(n), lcp(n);
    ll k = 0;
    for (ll i = 1; i <= n; i++) id[p[i]] = i;
    for (ll i = 0; i < n; i++)
    {
        while (id[i] != 1 && s[i + k] == s[p[id[i] - 1] + k]) k++;
        lcp[id[i] - 1] = k;
        if (k > 0) k--;
    }
    return lcp;
}
ll timer = 0;
void dfs(ll v, ll prev, vector <ll>& h, vector <ll>& tin, vector <ll>& tout, vector <vector <ll>>& up, vector <vector <pair <ll, ll>>>& g)
{
    tin[v] = timer++;
    up[0][v] = prev;
    for (ll i = 1; i < up.size(); i++)
    {
        up[i][v] = up[i - 1][up[i - 1][v]];
    }
    for (auto [i, id] : g[v])
    {
        if (i != prev)
        {
            h[i] = h[v] + 1;
            dfs(i, v, h, tin, tout, up, g);
        }
    }
    tout[v] = timer++;
}
bool upper(ll a, ll b, vector <ll>& tin, vector <ll>& tout)
{
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}
ll lca(ll a, ll b, vector <ll>& tin, vector <ll>& tout, vector <vector <ll>>& up)
{
    if (upper(a, b, tin, tout)) return a;
    if (upper(b, a, tin, tout)) return b;
    for (ll i = up.size() - 1; i >= 0; i--)
    {
        if (!upper(up[i][a], b, tin, tout))
        {
            a = up[i][a];
        }
    }
    return up[0][a];
}
ll nvp(vector <ll>& a)
{
    vector <ll> dp(a.size(), 1e18);
    for (ll i = 0; i < a.size(); i++)
    {
        dp[lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin()] = a[i];
    }
    ll ans = 0;
    for (ll i = 0; i < dp.size(); i++)
    {
        if (dp[i] != 1e18) ans++;
    }
    return ans;
}
ll grandi(vector <ll>& a)
{
    ll n = a.size();
    vector <bool> k(n + 1);
    for (auto i : a)
    {
        if (i <= n) k[i] = true;
    }
    for (ll i = 0; i <= n; i++)
    {
        if (!k[i]) return i;
    }
}
ll find(ll v, vector <ll>& p)
{
    if (p[v] == v) return v;
    return p[v] = find(p[v], p);
}
void union_s(ll a, ll b, vector <ll>& p, vector <ll>& sz)
{
    a = find(a, p);
    b = find(b, p);
    if (a != b)
    {
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //#define _DEBUG_
#ifdef _DEBUG_
    ifstream cin("input.txt");
    ofstream cout("output.txt");
#endif
    string alf = "abcdefghijklmnopqrstuvwxyz";
    random_device rd;
    mt19937 gen(rd());

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector <ll> a(n);
        for (ll i = 0; i < n; i++) cin >> a[i];
        ll ans = 0;
        for (ll i = 0; i < n - i - 1; i++)
        {
            ans = gcd(ans, abs(a[i] - a[n - i - 1]));
        }
        cout << ans << "\n";
    }

    return 0;
}
/*



*/