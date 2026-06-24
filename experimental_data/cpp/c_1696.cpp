#include <bits/stdc++.h>

using namespace std;



int n, m, k; 



vector<pair<int, long long>> cal(vector<int> a, int m) {

    vector<pair<int, long long>> b;

    for (int x : a) {

        int y = 1;

        while (x % m == 0) {

            x /= m;

            y *= m;

        }

        if (!b.empty() && x == b.back().first) {

            b.back().second += y;

        } else {

            b.emplace_back(make_pair(x, y));

        }

    }

    return b;

}



void solve() {

    cin >> n >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    auto pa = cal(a, m);

    cin >> k;

    vector<int> b(k);

    for (int i = 0; i < k; i++) cin >> b[i];

    auto pb = cal(b, m);

    cout << (pa == pb ? "YES" : "NO") << '\n';

}





int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int tt;

    cin >> tt;

    // should be o(n + k) or o((n + k)log(n + k))

    while (tt--) solve();

}