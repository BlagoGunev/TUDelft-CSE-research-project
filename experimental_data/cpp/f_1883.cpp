#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        vector<ll> vec(n);
        map<ll, ll> m;
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
            m[vec[i]]++;
        }

        set<ll> s;
        vector<ll> dp(n);

        for (int i = n - 1; i > -1; i--) {
            s.insert(vec[i]);
            dp[i] = s.size();
        }

        ll res = 0;

        s.clear();
        for (int i = 0; i < n - 1; i++) {
            if (s.count(vec[i])) continue;
            s.insert(vec[i]);
            res += dp[i + 1];
        }

        for (auto it = m.begin(); it != m.end(); it++) {
            if (it -> second == 1) res++;
        }

        cout << res << endl;
    }


    return 0;
}