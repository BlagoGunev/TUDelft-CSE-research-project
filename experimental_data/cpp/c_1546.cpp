#include <bits/stdc++.h>

#define fi first

#define se second

using namespace std;

using i64 = long long;

using ld = long double;

using pii = pair<int, int>;

template<typename T> bool chkmin(T &a, T b) { return (b < a) ? a = b, true : false; }

template<typename T> bool chkmax(T &a, T b) { return (b > a) ? a = b, true : false; }

constexpr int inf = ~0U >> 1;

constexpr int mod = 1000000007;

constexpr int N = 200010;



void solve() {

    int n;

    cin >> n;

    vector<int> odd, even;

    for (int i = 0; i < n; ++i) {

        int x;

        cin >> x;

        if (i & 1) odd.push_back(x);

        else even.push_back(x);

    }

    sort(odd.begin(), odd.end());

    sort(even.begin(), even.end());

    vector<int> a(n);

    int l = 0, r = 0;

    for (int i = 0; i < n; ++i) {

        if (i & 1) a[i] = odd[l++];

        else a[i] = even[r++];

    }

    cout << (is_sorted(a.begin(), a.end()) ? "YES\n" : "NO\n");

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int t;

    cin >> t;

    while (t--) {

        solve();

    }

    return 0;

}