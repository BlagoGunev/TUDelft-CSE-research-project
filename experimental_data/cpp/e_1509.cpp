#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

typedef pair<int, int> PII;



void solve() {

    int n;

    ll k;

    cin >> n >> k;

    k--;

    if (n <= 60 and k >> (n - 1)) {

        cout << -1 << '\n';

        return;

    }

    vector<int> bk;

    while (k) {

        bk.push_back(k % 2);

        k /= 2;

    }

    vector<int> ans(n + 1);

    iota(ans.begin(), ans.end(), 0);

    reverse(ans.begin(), ans.end());

    int N = bk.size();

    int l = 0;

    for (int i = 1; i <= N; i++) {

        if (bk[i - 1] == 0) {

            int r = i - 1;

            reverse(ans.begin() + l, ans.begin() + r + 1);

            l = i;

        }

    }

    reverse(ans.begin() + l, ans.begin() + N + 1);

    reverse(ans.begin(), ans.end());

    for (int i = 1; i <= n; i++) {

        cout << ans[i] << " \n"[i == n];

    }

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);



    int T = 1;

    cin >> T;

    while (T--) {

        solve();

    }

    return 0;

}