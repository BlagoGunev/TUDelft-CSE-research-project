#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "debugger/debug.h"
#else
#define debug(...) 8
#endif

#define int long long
#define double long double
 
void testcase() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;

    const int A = 1 << m;
    vector<vector<int>> bestAfterOps(m + 1, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++)  {
        const int x = a[i];
        vector<int> val(A, x);
        bestAfterOps[0][i] = x;
        for (int mask = 1; mask < A; mask++) {
            const int msb = __lg(mask);
            const int setBits = __builtin_popcountll(mask);
            val[mask] = val[mask ^ (1 << msb)] & b[msb];
            bestAfterOps[setBits][i] = min(bestAfterOps[setBits][i], val[mask]);
        }
    }

    priority_queue<array<int, 3>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({bestAfterOps[0][i] - bestAfterOps[1][i], 1, i});
    }

    int ans = accumulate(a.begin(), a.end(), 0LL);
    while (k--) {
        auto [toDec, opsDone, index] = pq.top();
        pq.pop();
        ans -= toDec;
        if (opsDone != m) {
            pq.push({bestAfterOps[opsDone][index] - bestAfterOps[opsDone + 1][index], opsDone + 1, index});
        }
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(10);
    int tt = 1;
    cin >> tt;
    while (tt--) testcase();
}