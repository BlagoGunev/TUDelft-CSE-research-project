//
// Created by BigBag at 18.07.24. 17:28:30
//

#include <bits/stdc++.h>

using namespace std;

#ifdef BigBag

#include "BigBag/debug.h"

#else
#define DEBUG while (0)
#define LOG(...)
#endif

const int max_n = 2000222, inf = 1000111222;

int t, n, k, ones[max_n];
string s, a[max_n];
vector<int> dp[max_n];

int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        fill(ones, ones + k, 0);
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            reverse(a[i].begin(), a[i].end());
            for (int j = 0; j < k; ++j) {
                ones[j] += a[i][j] - '0';
            }
        }
        for (int i = 0; i <= k; ++i) {
            dp[i].resize(n + 1);
            fill(dp[i].begin(), dp[i].end(), -1);
        }
        dp[0][0] = 1;
        for (int i = 0; i < k; ++i) {
            for (int add = 0; add <= n; ++add) {
                if (dp[i][add] == -1) {
                    continue;
                }
//                LOG(i, add);
                for (int b = 0; b < 2; ++b, ones[i] = n - ones[i]) {
//                    LOG(b, add, ones[i], (add + ones[i]) % 2, s[i] - '0');
                    if ((add + ones[i]) % 2 == s[i] - '0') {
                        dp[i + 1][(add + ones[i]) / 2] = add;
                    }
                }
            }
        }
        if (dp[k][0] == -1) {
            cout << "-1\n";
            continue;
        }
        string ans;
        int add = 0;
        for (int i = k; i; ) {
            int padd = dp[i][add];
            --i;
            for (int b = 0; b < 2; ++b, ones[i] = n - ones[i]) {
                if ((padd + ones[i]) % 2 == s[i] - '0' && (padd + ones[i]) / 2 == add) {
                    ans += b + '0';
                    break;
                }
            }
            add = padd;
        }
        cout << ans << "\n";
//        DEBUG {
//            for (int i = 0; i < n; ++i) {
//                for (int j = 0; j < k; ++j) {
//                    if (ans[j] == '0') {
//                        cout << char(a[i][j]);
//                    } else {
//                        cout << char(a[i][j] ^ 1);
//                    }
//                }
//                cout << endl;
//            }
//            cout << endl;
//        };
    }
    exit(0);
}