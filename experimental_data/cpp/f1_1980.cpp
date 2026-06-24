#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll, ll>> a(k);
    for (int i = 0; i < k; ++i) cin >> a[i].first >> a[i].second;
    map<ll, vector<pair<int, int>>> col;
    for (int i = 0; i < k; ++i) col[a[i].second].push_back({ a[i].first, i });
    col[m + 1].push_back({ n, -1 });
    vector<int> res(k);
    ll ans = 0, cc = 1, cr = 0;
    for (auto& e : col)
    {
        auto m = *max_element(e.second.begin(), e.second.end());
        if (m.first > cr)
        {
            ans += (n - cr) * (e.first - cc);
            cr = m.first, cc = e.first;
            if (m.second != -1) res[m.second] = 1;
        }
    }
    cout << ans << '\n';
    for (auto e : res) cout << e << ' ';
    cout << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}