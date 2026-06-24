#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

typedef pair<int, int> PII;



int main() {

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    

    int l, r;

    cin >> l >> r;

    int k = 0;

    r -= (l - 1);

    while (1 << (k + 1) <= r) k++;

    vector<array<int, 3>> ans;

    for (int i = 0; i <= k; i++) {

        for (int j = i + 1; j <= k; j++) {

            ans.push_back({i, j, 1 << i});

        }

    }

    for (int i = 0; i <= k; i++) {

        ans.push_back({-1, i, 1});

    }

    int n = k + 2;

    if (r != 1 << k) {

        int cur = 0;

        ans.push_back({-1, k + 1, 1});

        for (int i = k; i >= 0; i--) {

            if ((r - 1) >> i & 1) {

                ans.push_back({i, k + 1, cur + 1});

                cur += (1 << i);

            }

        }

        n++;

    }

    cout << "YES\n";

    if (l != 1) {

        n++;

        ans.push_back({-2, -1, l - 1});

    } 

    cout << n << " " << ans.size() << '\n';

    for (auto [u, v, w] : ans) {

        u += 2 + (l != 1), v += 2 + (l != 1);

        cout << u << " " << v << " " << w << '\n';

    }

    return 0;

}