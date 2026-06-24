#include <bits/stdc++.h>

using namespace std;



#define endl '\n'

#define YES cout << "YES" << endl

#define NO cout << "NO" << endl

#define all(_) _.begin(), _.end()

#define sz(_) (int)_.size()

#define fs first

#define se second

#define Odd(_x) ((_x) & 1)

typedef long long ll;

typedef pair<int, int> pii;

const int N = 100000;

const int inf = 1e9 + 10;

const ll mod = 1e9 + 7;



void solve() {

    int n, m;

    map<int, int> cnt;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {

        int x; cin >> x;

        cnt[x]++;

    }



    set<array<int, 2>> p;

    for (int i = 0; i < m; i++){

        int u, v; cin >> u >> v;

        p.insert({u, v});

    }



    vector<vector<int>> occ(n + 1);

    for (auto &[ft, se] : cnt) {

        occ[se].push_back(ft);

    }

    for (auto &v : occ) {

        reverse(v.begin(), v.end());

    }



    ll ans = 0;

    for (int i = 1; i < n; i++) {

        for (int x : occ[i]) {

            for (int j = 1; j <= i; j++) {

                for (int y : occ[j]) {

                    if (x != y && !p.contains({x, y}) && !p.contains({y, x})) {

                        ans = max(ans, 1ll * (i + j) * (x + y));

                        break;

                    }

                }

            }

        }

    }

    cout << ans << endl;

}

#define MULTI_INPUT



int main() {

#ifndef ONLINE_JUDGE

    freopen(R"(D:\source files\source file2\input.txt)", "r", stdin);

    freopen(R"(D:\source files\source file2\output.txt)", "w", stdout);

#endif

    std::ios::sync_with_stdio(false);

    cin.tie(0);

#ifdef MULTI_INPUT

    int T;

    cin >> T;

    while (T--) {

        solve();

    }

#else

    solve();

#endif

    return 0;

}