//#pragma optimize("O3")
//#pragma optimize("unroll-loops")
//#pragma traget("avx,avx2,tune=native")
 
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <cstdint>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <map>
#include <queue>
#include <ctime>
#include <stack>
#include <set>
#include <list>
#include <random>
#include <deque>
#include <functional>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <complex>
#include <numeric>
#include <cassert>
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <thread>
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
#define el '\n'
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define point pair <ll, ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
 
using namespace std;
mt19937 rnd(time(0));
 
const ll INF = 2e18 + 10;
const ll inf = 2e9 + 10;
const ll N = 1e6 + 10;
const ll mod = 998244353;
const ll LOG = 18;

vector <ll> gr[N];
ll cnt[N], up[N], split[N];
void dfs(ll v, ll pr) {
    for (ll to : gr[v])
        if (to != pr)
            dfs(to, v);

    ll deg = gr[v].size(), mx = 0, sum = 0;
    for (ll to : gr[v]) {
        if (to == pr)
            continue;

        while (up[to] < deg - 1 && split[to])
            cnt[to]++, up[to] += 2, split[to]--;
        while (up[to] < deg - 1)
            cnt[to]++, up[to]++;
        cnt[v] += cnt[to];
        up[to] -= deg - 1;
        split[v] += split[to];

        mx = max(mx, up[to]);
        sum += up[to];
    }
    if (v == 1) cnt[v] -= deg * (deg - 1) / 2;
    else cnt[v] -= (deg - 1) * (deg - 2) / 2;

    if (mx * 2 <= sum) {
        split[v] += sum / 2;
        cnt[v] -= sum / 2;
        up[v] = sum % 2 + deg - 1;
    } else {
        ll can = split[v];
        for (ll to : gr[v]) {
            if (to == pr)
                continue;
            if (up[to] == mx) {
                can -= split[to];
                break;
            }
        }

        split[v] += sum - mx;
        cnt[v] -= sum - mx;
        sum = mx * 2 - sum;

        ll add = min(can, sum / 2);
        sum -= add * 2;
        split[v] += add;
        cnt[v] -= add;
        up[v] = sum + deg - 1;
    }
    return;
}

void solve() {
    ll n;
    cin >> n;

    for (ll i = 1; i <= n; i++) {
        gr[i].clear();
        cnt[i] = up[i] = split[i] = 0;
    }

    for (ll i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;

        gr[u].pb(v);
        gr[v].pb(u);
    }

    dfs(1, -1);
    cout << cnt[1] << el;
    return;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int tests = 1;
    cin >> tests;
 
    while (tests--) 
        solve();
    return 0;
}
/*
*/