#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <algorithm>
#include <array>
#include <set>
#include <deque>
#include <cmath>
#include <map>
#include <bitset>
#include <list>
#include <fstream>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
//#define int long long

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

const int INF = 1e9 + 7;
const ld EPS = 1e-9;

void solve() {
    int n, k;
    cin >> n >> k;
    k %= (n + 1);
    vector<int> a(n + 1);
    vector<bool> was(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        was[a[i]] = true;
    }
    for (int i = 0; i <= n; i++) {
        if (!was[i]) a[n] = i;
    }
    for (int i = -k + n + 1; i < -k + n + 1 + n; i++)
        cout << a[i % (n + 1)] << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}