#ifdef LOCAL
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <cmath>
#include <deque>
#include <random>
#include <bitset>
#include <map>
#include <cassert>
#include <complex>
#include <cmath>
#include <time.h>
#else
#include "bits/stdc++.h"
#endif

using namespace std;
using cd = complex<double>;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll int64_t
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second

#define int ll
#define double ld
#define endl '\n'

const int inf = 1e9;
const ll INF = 1e18;

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    map<int, int> values;
    values[0] = 1;

    for (int i = 1; i <= n; ++i) {
        map<int, int> new_values;
        for (auto e : values) {
            new_values[abs(e.x + arr[i])] = (new_values[abs(e.x + arr[i])] + e.y) % mod;
            new_values[e.x + arr[i]] = (new_values[e.x + arr[i]] + e.y) % mod;
        }
        if (new_values.size() == 1)
            values = new_values;
        else {
            values = {*new_values.begin(), *new_values.rbegin()};
        }
    }

    cout << values.rbegin()->y << endl;
}

signed main() {
#ifndef LOCAL
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
#endif


    cout.precision(16);
    cout << fixed;

    int t = 1;
     cin >> t;
    while (t--) {
        solve();
    }
}