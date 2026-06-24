#include <cstdio>
using namespace std;

int dp[1010][110], pw[1010];

int main() {
    int n, K, m;
    scanf("%d%d%d", &n, &K, &m);
    pw[0] = 1;
    for (int i = 1; i <= 1000; i ++) {
        pw[i] = (long long)pw[i - 1] * 10 % K;
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i ++) {
        int down = (i == n - 1 ? 1 : 0);
        for (int j = down; j < 10; j ++) {
            int st = (i == 0 ? 0 : 1);
            for (int k = st; k <= K; k ++) {
                int to = (k + pw[i] * j) % K;
                if (to == 0 && j == 0) {
                    to = K;
                }
                dp[i + 1][to] += dp[i][k];
                if (dp[i + 1][to] >= m) {
                    dp[i + 1][to] -= m;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int pre = 1;
        for (int j = n; j > i; j --) {
            if (j == n) {
                pre = (long long)pre * 9 % m;
            } else {
                pre = (long long)pre * 10 % m;
            }
        }
        ans += (long long)pre * dp[i][0] % m;
        if (ans >= m) {
            ans -= m;
        }
    }
    printf("%d\n", ans % m);
    return 0;
}