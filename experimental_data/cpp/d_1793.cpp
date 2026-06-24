/**
 * author: smas
 */

#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int MAX = 2 * 1e5 + 2;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1), q(n + 1);
    vector<int> invP(MAX);
    vector<int> invQ(MAX);

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        invP[p[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> q[i];
        invQ[q[i]] = i;
    }

    i64 ans = 1;

    int maxL = n;
    int minR = 1;

    for (int mex = 2; mex <= n; ++mex) {
        maxL = min(maxL, invP[mex - 1]);
        minR = max(minR, invP[mex - 1]);

        maxL = min(maxL, invQ[mex - 1]);
        minR = max(minR, invQ[mex - 1]);

        int minL = 1;
        int maxR = n;

        if (invP[mex] < maxL) {
            minL = invP[mex] + 1;
        } else {
            maxR = invP[mex] - 1;
        }

        if (invQ[mex] < maxL) {
            minL = max(minL, invQ[mex] + 1);
        } else {
            maxR = min(maxR, invQ[mex] - 1);
        }

        if (maxL <= n && minL > 0 && maxR <= n && minR > 0 && maxL >= minL && maxR >= minR) {
            ans += 1LL * (maxL - minL + 1) * (maxR - minR + 1);
        }
    }

    int lenL = min(invP[1], invQ[1]) - 1;
    int lenR = min(n - invP[1], n - invQ[1]);
    int lenM = abs(invP[1] - invQ[1]) - 1;

    ans += 1LL * (lenL + 1) * lenL / 2;
    ans += 1LL * (lenR + 1) * lenR / 2;
    ans += 1LL * (lenM + 1) * lenM / 2;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}