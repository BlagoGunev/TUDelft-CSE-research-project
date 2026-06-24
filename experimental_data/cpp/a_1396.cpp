#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <cctype>
#include <cstring>
#include <list>
#include <assert.h>

using namespace std;
using ll = long long;
using ld = long double;

ll inf = 99999999999;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    if (n == 1) {
        cout << 1 << ' ' << 1 << '\n';
        cout << 0 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        cout << 0 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        cout << -a[0] << '\n';
        return 0;
    }
    ll mod = a[n - 1] % n;
    cout << 1 << ' ' << n - 1 << '\n';
    for (ll i = 0; i < n - 1; ++i) {
        cout << (n - 1) * (a[i] % n) << ' ';
        a[i] += (n - 1) * (a[i] % n);
    }
    cout << '\n';
    cout << n << ' ' << n << '\n';
    cout << -a[n - 1] << '\n';
    a[n - 1] = 0;
    cout << 1 << ' ' << n << '\n';
    for (ll i = 0; i < n; ++i) {
        cout << -a[i] << ' ';
    }
    return 0;
}