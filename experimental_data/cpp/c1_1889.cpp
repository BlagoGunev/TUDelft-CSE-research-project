#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int maxn = 2e5 + 5;

ll a[maxn];
set<int> add[maxn];
set<int> sub[maxn];
set<int> result[maxn];
ll ans[maxn];
void solve() {
    int n,m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        ans[i] = 0;
        add[i].clear();
        sub[i].clear();
    }
    vector<int> cnt(m + 1); // cnt[i]: 第m天如果不下雨会有多少城市dry
    map<pii, int> mp; // mp[(i,j)]: 如果(i,j) 不下雨会有多少城市dry
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add[u].insert(i), sub[v + 1].insert(i);
    }
    set<int> s;
    for (int i = 1; i <= n; i++) {
        for (auto x: add[i]) s.insert(x);
        for (auto x: sub[i]) s.erase(x);
        if (s.size() == 0) ans[i] = 1;
        if (s.size() == 1) cnt[*s.begin()]++;
        if (s.size() == 2) {
            int x1 = (*s.begin());
            int x2 = (*prev(s.end()));
//            cout << i << " " << x1 << " " << x2 << endl;
            mp[{x1, x2}]++;
        }
    }
    int mx = 0;
    for (auto [day,times]: mp) {
        mx = max(mx, times + cnt[day.first] + cnt[day.second]);
    }

    sort(cnt.begin(), cnt.end(), greater<int>());
    mx = max(mx, cnt[0] + cnt[1]);

    for (int i = 1; i <= n; i++) if (ans[i]) mx++;
    cout << mx << endl;


}
int main() {
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}