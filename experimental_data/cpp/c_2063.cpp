#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
const int mod = 998244353, N = 1000001;

void solve() {
    int n;
    cin >> n;
    vector <vector <int>> adj(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    int ans = 0;
    multiset <int> S;
    for (int i = 0; i < n; ++i) {
        S.insert(adj[i].size());
    }
    for (int i = 0; i < n; ++i) {
        S.extract(adj[i].size());
        for (int j : adj[i]) {
            ans = max(ans, (int)adj[i].size() + (int)adj[j].size() - 2);
            S.extract(adj[j].size());
        }
        if (!S.empty()) {
            ans = max(ans, (int)adj[i].size() + *prev(S.end()) - 1);
        }
        S.insert(adj[i].size());
        for (int j : adj[i]) {
            S.insert(adj[j].size());
        }
    }
    cout << ans << '\n';
}

int main () {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}