#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::ios_base;
using std::fixed;
using std::endl;

using std::pair;
using std::make_pair;
using std::swap;

using std::string;
using std::vector;
using std::map;
using std::set;

using std::sort;
using std::reverse;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sqr(x) ((x) * (x))

const int MAXN = 55;
const int INF = 1e9;
const int MOD = 1e9+7;
const long long L_INF = 4e18;
const long double EPS = 1e-10;

int n, l;
string s[MAXN], t;
int dp[MAXN * MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    srand(566);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    cin >> t;
    l = t.size();

    for (int i = 0; i <= l; i++)
        dp[i] = INF;
    dp[0] = 0;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            int _l = i, _r = 0;
            while (_r < s[j].size() && _l < l) {
                if (s[j][_r] == t[_l])
                    _l++;
                _r++;
            }
            dp[_l] = std::min(dp[_l], dp[i] + 1);
        }
    }

    if (dp[l] >= INF / 2)
        dp[l] = -1;
    cout << dp[l];

#ifdef LOCAL
    cerr << "\n== " << 1.0 * clock() / CLOCKS_PER_SEC << " sec.\n";
#endif
    return 0;
}