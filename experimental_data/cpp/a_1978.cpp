#ifdef DEBUG
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <chrono>
#include <random>
#include <complex>
#include <numeric>
#include <assert.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, long long>;
using pli = pair<long long, int>;
using pll = pair<long long, long long>;
template <typename T>
using uset = unordered_set<T>;
template <typename T1, typename T2>
using umap = unordered_map<T1, T2>;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mx = *max_element(a.begin(), a.end() - 1);
    cout << mx + a[n - 1] << '\n';
}

signed main() {
#ifdef DEBUG
    freopen("01.dat", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
#ifdef DEBUG
        cout << "Testcase#\n";
#endif
        solve();
    }
    return 0;
}