#include <bits/stdc++.h>

using namespace std;

using LL = long long;

constexpr int mod = 1000000007;

constexpr int N = 2e5 + 7;

inline LL qsm(LL a, LL b, LL p) {

    LL res = 1;

    while(b) {

        if(b & 1) res = res * a % p;

        b >>= 1;

        a = a * a % p;

    }

    return res;

}

LL s[N];

inline void solve() {

    int n; cin >> n;

    vector<vector<int>> pos(n + 1);

    for (int i = 1; i <= n; i ++) {

        cin >> s[i];

        pos[s[i]].push_back(i);

    }

    vector<int> ans;

    for (int i = 1; i <= n;) {

        int j = i + 1;

        int x = 0;

        while(true) {

            auto it = lower_bound(pos[x].begin(), pos[x].end(), i);

            if(it == pos[x].end()) {

                break;

            }

            j = max(j, *it + 1);

            x ++;

        }

        i = j;

        ans.push_back(x);

    }

    int len = ans.size();

    cout << len << '\n';

    for (int i = 0; i < len; i ++) {

        cout << ans[i] << " \n"[i == len - 1];

    }

}

signed main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    int T;

    for (cin >> T; T; T --) solve();

    return 0;

}