//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

#include <stdio.h>
#include <bits/stdc++.h>

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

using namespace std;

inline void setmin(int &x, int y) { if (y < x) x = y; }
inline void setmax(int &x, int y) { if (y > x) x = y; }
inline void setmin(ll &x, ll y) { if (y < x) x = y; }
inline void setmax(ll &x, ll y) { if (y > x) x = y; }

const int N = 200000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;

vector<int> g[N];
unordered_set<int> G[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    cout << fixed;
    //ll TL = 0.95 * CLOCKS_PER_SEC;
    //clock_t time = clock();
    ll n, m;
    cin >> n >> m;
    ull A, B, C;
    cin >> A >> B >> C;
    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ull ans = 0;
    rep(i, 0, n)
    {
        ll l = i, r = n - i - 1;
        ans += (A * i) * (r * (r - 1) / 2);
        ans += (B * i) * (l * r);
        ans += (C * i) * (l * (l - 1) / 2);
    }
    for (ll i = 0; i < n; i++)
        for (ll j : g[i])
        {
            if (j < i)
                continue;
            if (i > 0)
            {
                ans -= A * ((i - 1) * i / 2);
                ans -= (B * i + C * j) * i;
            }
            if (j - i - 1 > 0)
            {
                ans -= B * ((j - 1) * j / 2 - i * (i + 1) / 2);
                ans -= (A * i + C * j) * (j - i - 1);
            }
            if (n - j - 1 > 0)
            {
                ans -= C * ((n - 1) * n / 2 - j * (j + 1) / 2);
                ans -= (A * i + B * j) * (n - j - 1);
            }
        }
    for (ll i = 0; i < n; i++)
    {
        ll cnt1 = 0, sum1 = 0;
        ll cnt2 = 0, sum2 = 0;
        vector<ll> v1, v2;
        for (ll j : g[i])
            if (j < i)
            {
                cnt1++;
                sum1 += j;
                v1.push_back(j);
            }
            else
            {
                cnt2++;
                sum2 += j;
                v2.push_back(j);
            }
        ans += (B * i) * (cnt1 * cnt2) + (A * sum1) * cnt2 + (C * sum2) * cnt1;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        ans += (C * i) * (cnt1 * (cnt1 - 1) / 2);
        rep(j, 0, cnt1)
        {
            ans += (B * v1[j]) * j;
            ans += (A * v1[j]) * (cnt1 - j - 1);
        }
        ans += (A * i) * (cnt2 * (cnt2 - 1) / 2);
        rep(j, 0, cnt2)
        {
            ans += (C * v2[j]) * j;
            ans += (B * v2[j]) * (cnt2 - j - 1);
        }
    }
    rep(i, 0, n)
        for (int j : g[i])
            G[i].insert(j);
    vector<int> p(n);
    rep(i, 0, n)
        p[i] = i;
    sort(p.begin(), p.end(), [](int a, int b) { return sz(g[a]) > sz(g[b]); });
    vector<int> pos(n);
    rep(i, 0, n)
        pos[p[i]] = i;
    for (int i : p)
        for (int j : g[i])
        {
            if (pos[j] < pos[i])
                continue;
            for (int k : g[j])
            {
                if (pos[k] < pos[j])
                    continue;
                if (G[i].count(k))
                {
                    ll I = i, J = j, K = k;
                    if (I > J)
                        swap(I, J);
                    if (J > K)
                        swap(J, K);
                    if (I > J)
                        swap(I, J);
                    ans -= A * I + B * J + C * K;
                }
            }
        }
    cout << ans << "\n";
    return 0;
}