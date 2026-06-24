#include <bits/stdc++.h>

using std::ios_base;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::fixed;

using std::vector;
using std::string;
using std::stack;
using std::queue;
using std::deque;
using std::map;
using std::set;
using std::unordered_map;
using std::unordered_set;

using std::tuple;
using std::make_tuple;
using std::pair;
using std::make_pair;

using std::sort;
using std::reverse;
using std::nth_element;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

const int MAXN = 55;
const int INF = 1e9;
const int MOD = 1e9+7;
const int64_t L_INF = 4e18;

int k, n;
int64_t a[MAXN];
bool dp[MAXN][MAXN];

bool check(int64_t mask) {
    for (int i = 0; i <= k; i++)
        memset(dp[i], false, sizeof dp[i]);
    dp[0][0] = true;

    for (int i = 1; i <= k; i++) {
        for (int j = i; j <= n; j++) {
            int64_t sum = 0;
            for (int l = j; l >= i; l--) {
                sum += a[l - 1];
                if ((sum & mask) == mask && dp[i - 1][l - 1]) {
                    dp[i][j] = true;
                }
            }
        }
    }
    return dp[k][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int64_t ans = 0;
    for (int b = 60; b >= 0; b--) {
        if (check(ans | (1ll << b))) {
            ans |= 1ll << b;
        }
    }

    cout << ans << '\n';

    #ifdef LOCAL
        cerr << "\n== " << 1.0 * clock() / CLOCKS_PER_SEC << " sec.\n";
    #endif
    return 0;
}