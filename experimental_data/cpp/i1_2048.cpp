#include <bits/stdc++.h>

#ifdef LOCAL
#define debug(x) cerr << (#x) << ": " << x << endl
#else
#define debug(x)
#endif

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

mt19937 rnd(0);

const int BIG = 1e9, LG = 30;
const ll INF = 1e18;
const ld eps = 1e-10, PI = acos(-1);

int n;
str s;
vi ans;

bool dfs(int l, int r, int cnt, int& x, bool& flag) {
    if (l > r) {
        x = 0;
        flag = true;
        return true;
    }

    if (l == r) {
        ans[l] = cnt;
        x = 1;
        flag = true;
        return true;
    }

    if (s[l] == 'L' && s[r] == 'R') {
        ans[l] = ans[r] = cnt;
        bool ok = dfs(l + 1, r - 1, cnt + 1, x, flag);
        x++;
        return ok;
    }

    if (s[l] == 'L' && s[r] == 'L') {
        ans[l] = cnt;
        bool ok = dfs(l + 1, r - 1, cnt + 1, x, flag);
        ans[r] = cnt + x + 1;
        x += 2;
        return ok & flag;
    }

    if (s[l] == 'R' && s[r] == 'R') {
        ans[r] = cnt;
        bool ok = dfs(l + 1, r - 1, cnt + 1, x, flag);
        ans[l] = cnt + x + 1;
        x += 2;
        return ok & flag;
    }

    if (s[l] == 'R' && s[r] == 'L') {
        fill(ans.begin() + l, ans.begin() + r + 1, cnt + 1);
        x = 1;
        flag = false;
        return true;
    }

    return false;
}

void solve() {
    cin >> n >> s;
    ans.resize(n);
    int x;
    bool flag;
    if (dfs(0, n - 1, 0, x, flag)) {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}