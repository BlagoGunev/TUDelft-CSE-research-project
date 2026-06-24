#include "bits/stdc++.h"



using namespace std;



const int N = 400;

int n, m, ans = 0;

char a[N][N];

int dp[N][N][2];

int dp2[N][N][2];



int main() {

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> a[i][j];

        }

    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (i > 0 && a[i - 1][j] == '.') {

                dp[i][j][0] = dp[i - 1][j][0] + 1;

            }

        }

    }

    for (int i = n - 1; i >= 0; i--) {

        for (int j = 0; j < m; j++) {

            if (i + 1 < n && a[i + 1][j] == '.') {

                dp[i][j][1] = dp[i + 1][j][1] + 1;

            }

        }

    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (i) {

                int pos = i - 1 - dp[i][j][0];

                if (pos >= 0 && a[pos][j] == 'm') {

                    dp2[i][j][0] = dp[i][j][0] + 1 + dp[pos][j][0];

                } else {

                    dp2[i][j][0] = dp[i][j][0];

                }

            }

        }

    }

    for (int i = n - 1; i >= 0; i--) {

        for (int j = 0; j < m; j++) {

            if (i + 1 < n) {

                int pos = i + 1 + dp[i][j][1];

                if (pos < n && a[pos][j] == 'm') {

                    dp2[i][j][1] = dp[i][j][1] + 1 + dp[pos][j][1];

                } else {

                    dp2[i][j][1] = dp[i][j][1];

                }

            }

        }

    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            int cnt = 0;

            for (int j2 = j; j2 < m; j2++) {

                if (a[i][j2] == '#') {

                    break;

                }

                if (a[i][j2] == 'm') {

                    cnt++;

                }

                if (cnt >= 2) {

                    break;

                }

                if (j2 - j + 1 <= 2) {

                    continue;

                }

                int l = min(dp[i][j][0], dp[i][j2][0]);

                int r = min(dp[i][j][1], dp[i][j2][1]);

                if (l > 0 && r > 0) {

                    ans = max(ans, 2 * l + 2 * r + j2 - j + 1);

                }

                if (cnt == 0) {

                    {

                        int l = min(dp2[i][j][0], dp[i][j2][0]);

                        int r = min(dp[i][j][1], dp[i][j2][1]);

                        if (l > 0 && r > 0) {

                            ans = max(ans, 2 * l + 2 * r + j2 - j + 1);

                        }

                    }

                    {

                        int l = min(dp[i][j][0], dp2[i][j2][0]);

                        int r = min(dp[i][j][1], dp[i][j2][1]);

                        if (l > 0 && r > 0) {

                            ans = max(ans, 2 * l + 2 * r + j2 - j + 1);

                        }

                    }

                    {

                        int l = min(dp[i][j][0], dp[i][j2][0]);

                        int r = min(dp2[i][j][1], dp[i][j2][1]);

                        if (l > 0 && r > 0) {

                            ans = max(ans, 2 * l + 2 * r + j2 - j + 1);

                        }

                    }

                    {

                        int l = min(dp[i][j][0], dp[i][j2][0]);

                        int r = min(dp[i][j][1], dp2[i][j2][1]);

                        if (l > 0 && r > 0) {

                            ans = max(ans, 2 * l + 2 * r + j2 - j + 1);

                        }

                    }

                }

            }

        }

    }

    cout << ans << '\n';

}