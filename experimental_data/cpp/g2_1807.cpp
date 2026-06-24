#pragma GCC optimization("Ofast")
#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
/**
 *  @author Mahmouud Ali
 **/
#define all(v) v.begin(), v.end()
#define fs first
#define sc second
#define no return cout << "NO\n", void()
#define yes return cout << "YES\n", void()
typedef long long ll;
typedef long double ld;
const ll inf = 1e9;
const int mod = 1e9 + 7;
const char nl = '\n';
using namespace std;

void Traveler() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

inline void test_case() {
    ll n;
    cin >> n;
    ll c[n];
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    sort(c, c + n);
    if (c[0] != 1) no;
    for (int i = 1; i < n; ++i)
        c[i] += c[i - 1];
    for (int i = 1; i < n; ++i)
        if (c[i] - c[i - 1] > c[i - 1]) no;
    yes;
}

signed main() {
    Traveler();
    int tc = 1;
    cin >> tc;
    while (tc--) test_case();
}