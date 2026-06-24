#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tests; cin >> tests;
    while (tests--) {
        int n; cin >> n;
        vector<string> grid(n);
        for (string &row : grid) cin >> row;
        
        int moves = 0;

        vector<int> lefts(n), rights(n);
        for (int row = 0; row < n; ++row) {
            vector<int> sum(n);
            sum[0] = lefts[0] - rights[0];
            for (int i = 1; i < n; ++i) sum[i] = sum[i-1] + lefts[i] - rights[i-1];

            for (int i = 0; i < n; ++i) {
                int v = (grid[row][i] - '0' + sum[i]) % 2;
                if (v) ++moves, ++lefts[i], ++rights[i];
            }

            vector<int> lefts2(n), rights2(n);
            for (int i = 0; i < n; ++i) {
                lefts2[max(i-1, 0)] += lefts[i];
                rights2[min(i+1, n-1)] += rights[i];
            }
            
            lefts = lefts2, rights = rights2;
        }
        cout << moves << '\n';
    }
    return 0;
}