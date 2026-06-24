#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <random>
#include <chrono>
#include <ctime>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <iomanip>
#include <map>
#include <cassert>
#include <functional>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using str = string;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using ld = long double;
const ld PI = acos(-1);

#define all(c) ((c).begin()), ((c).end())
#define ff first
#define ss second
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
#define debug(x) cerr<<#x<<": "<<x<<endl;
#define mp make_pair
#define forn(i, n) for (ll i = 0; i < n; ++i)
#define sz(a) (ll)a.size()

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


bool cmp(pll &a, pll &b) {
    if (a.ff == b.ff) return a.ss > b.ss;
    return a.ff > b.ff;
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
//mt19937 rnd(31313121);
str Y = "YES\n";
str N = "NO\n";
const ll INF = 1e16 + 10;
const ll Maxn = 1e6 + 10;
ll dp[2][Maxn];


void solve() {
    ll n;
    cin >> n;
    ll r1, r2, r3, d;
    cin >> r1 >> r2 >> r3 >> d;
    forn (i, 2) {
        fill(dp[i], dp[i] + Maxn, INF);
    }
    vll a(n);
    forn (i, n) cin >> a[i];
    dp[0][0] = -d;
    dp[1][0] = -d - r1;
    forn (i, n) {
        dp[0][i + 1] = min(dp[0][i + 1], dp[0][i] + d + r1 * a[i] + r3);
        dp[0][i + 1] = min(dp[0][i + 1], dp[1][i] + d + r1 * a[i] + r3 + d + r1 + d);
        dp[0][i + 1] = min(dp[0][i + 1], dp[1][i] + d + min(r2, r1 * (a[i] + 1)) + d + r1 + d + r1);
        dp[1][i + 1] = min(dp[1][i + 1], dp[0][i] + d + min(r1 * (a[i] + 1ll), r2));
        dp[1][i + 1] = min(dp[1][i + 1], dp[1][i] + d + min(r1 * (a[i] + 1ll), r2) + d + r1 + d);
        if (i == n - 1) {
            dp[0][i + 1] = min(dp[0][i + 1], dp[1][i] + d + r1 * a[i] + r3 + d + r1);
        }
    }
    cout << dp[0][n] << '\n';
    return;
}


int main() {
    fast;
    ll t;
    t = 1;
    forn (i, t) {
        solve();
    }
    return 0;
}