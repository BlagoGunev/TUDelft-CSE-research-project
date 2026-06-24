#include <bits/stdc++.h>



using i64 = long long;



void solve() {

    int n, m;

    std::cin >> n >> m;

    std::vector<std::vector<int>> A(n, std::vector<int>(m));

    std::vector<std::vector<int>> S(n, std::vector<int>(m));

    for (int i = 0; i < n; i++) {

        std::string s;

        std::cin >> s;

        for (int j = 0; j < m; j++) {

            S[i][j] = A[i][j] = s[j] == '1';

            if (i) {

                S[i][j] += S[i - 1][j];

            }

        }

    }



    int ans = 114514233;

    for (int i = 0; i < n; i++) {

        for (int j = i + 4; j < n; j++) {

            std::vector<int> a(m), b(m);

            for (int k = 0; k < m; k++) {

                a[k] = j - i - 1 - (S[j - 1][k] - S[i][k]);

                b[k] = (S[j - 1][k] - S[i][k]) + !A[i][k] + !A[j][k];

                if (k) {

                    b[k] += b[k - 1];

                }

            }

            int pre = 160000;

            for (int k = 3; k < m; k++) {

                pre = std::min(pre, a[k - 3] - b[k - 3]);

                ans = std::min(ans, pre + b[k - 1] + a[k]);

            }

        }

    }



    std::cout << ans << "\n";

}



int main() {

    std::ios::sync_with_stdio(false);

    std::cin.tie(nullptr);



    int t;

    std::cin >> t;



    while (t--) {

        solve();

    }



    return 0;

}