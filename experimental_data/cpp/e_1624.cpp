#include <bits/stdc++.h>
#define int long long
#define ll pair<long long, long long>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int tests = 1;
    cin >> tests;
    while (tests--) {
        int n, m;
        string s;
        cin >> n >> m;
        vector<string> matrix(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> matrix[i];
        }
        cin >> s;

        if (m == 1) {
            cout << "-1\n";
            continue;
        }
        vector<vector<vector<ll>>> cnt3(10, vector<vector<ll>>(10, vector<ll>(10, {-1, -1})));
        vector<vector<ll>> cnt2(10, vector<ll>(10, {-1, -1}));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j + 1 < m) {
                    cnt2[matrix[i][j] - '0'][matrix[i][j + 1] - '0'] = {i, j};
                }
                if (j + 2 < m) {
                    cnt3[matrix[i][j] - '0'][matrix[i][j + 1] - '0'][matrix[i][j + 2] - '0'] = {i, j};
                }
            }
        }
        vector<pair<int, ll>> src(m);
        vector<bool> poss(m);
        if (cnt2[s[0] - '0'][s[1] - '0'].first == -1) {
            cout << "-1\n";
            continue;
        }
        poss[1] = true;
        ll aux = cnt2[s[0] - '0'][s[1] - '0'];
        src[1] = {aux.first, {aux.second, aux.second + 1}};

        if (m >= 3 and cnt3[s[0] - '0'][s[1] - '0'][s[2] - '0'].first != -1) {
            aux = cnt3[s[0] - '0'][s[1] - '0'][s[2] - '0'];
            src[2] = {aux.first, {aux.second, aux.second + 2}};
            poss[2] = true;
        }

        for (int i = 3; i < m; ++i) {
            if (poss[i - 3]) {
                aux = cnt3[s[i - 2] - '0'][s[i - 1] - '0'][s[i] - '0'];
                if (aux.first != -1) {
                    src[i] = {aux.first, {aux.second, aux.second + 2}};
                    poss[i] = true;
                }
            }
            if (poss[i - 2]) {
                aux = cnt2[s[i - 1] - '0'][s[i] - '0'];
                if (aux.first != -1) {
                    src[i] = {aux.first, {aux.second, aux.second + 1}};
                    poss[i] = true;
                }
            }
        }

        if (!poss[m - 1]) {
            cout << "-1\n";
            continue;
        }
        vector<pair<int, ll>> ans;
        int st = m - 1;
        while (st > 0) {
            ans.push_back(src[st]);
            if (src[st].second.first + 1 == src[st].second.second) {
                st -= 2;
            } else {
                st -= 3;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (auto itr : ans) {
            cout << itr.second.first + 1 << ' ' << itr.second.second + 1 << ' ' << itr.first << '\n';
        }
    }
    return 0;
}