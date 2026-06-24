#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define app push_back
#define int long long

#ifdef LOCAL
#define debug(...) [](auto...a) { ((cout << a << ' '), ...) << endl; }(#__VA_ARGS__, ":", __VA_ARGS__)
#define debugv(v) do { cout << #v << ": "; for (auto x : v) cout << x << ' '; cout << endl; } while(0)
#else
#define debug(...)
#define debugv(v)
#endif

using namespace std;

void solve();

int32_t main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int sum = accumulate(all(a), 0LL);
    while (a.size() > 1) {
        reverse(all(a));
        vector<int> b(a.size() - 1);
        for (int i = 0; i + 1 < a.size(); ++i) b[i] = a[i + 1] - a[i];
        sum = max(abs(accumulate(all(b), 0LL)), sum);
        a = b;
    }
    cout << sum << '\n';
}