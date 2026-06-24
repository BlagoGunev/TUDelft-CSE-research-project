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

const int MAXN = 5005;
const int INF = 1e9;
const int MOD = 1e9+7;
const int64_t L_INF = 4e18;

int n;
int dp[2][MAXN];
int max[MAXN];
int q;
unordered_map<int, vector<pair<int, int> > > query;
int ans[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dp[0][i];
        max[i] = dp[0][i];
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (r == l) {
            ans[i] = dp[0][l];
        } else {
            query[r - l].emplace_back(l, i);
        }
    }

    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            dp[len & 1][i] = dp[(len & 1) ^ 1][i] ^ dp[(len & 1) ^ 1][i + 1];
            max[i] = std::max(dp[len & 1][i], std::max(max[i], max[i + 1]));
        }
        if (query.find(len) != query.end()) {
            for (auto& x : query[len]) {
                ans[x.second] = max[x.first];
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }

    #ifdef LOCAL
        cerr << "\n== " << 1.0 * clock() / CLOCKS_PER_SEC << " sec.\n";
    #endif
    return 0;
}