#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
typedef long long ll;

using namespace __gnu_pbds;

template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define all(x) x.begin(),x.end()
#define pb push_back
#ifdef LOCAL
#define deb(x) cout << #x << " = " << (x) << endl
#define debn(x, n) { cout << #x << "(" << n << ") = " << \
        "{"; int _f_ = 1; for(int _i_ = 0;_i_<n;_i_++) {if (!_f_) cout << "|"; cout << x[_i_]; _f_= 0;} cout << "}" << endl;}
#define deba(x) { cout << #x << " (size: " << (int)x.size() << ") = " << \
        "{"; int _f_ = 1; for (auto o : x) {if (!_f_) cout << "|"; cout << o; _f_ = 0;} cout << "}" << endl;}
#else
#define deb(x) ;
#define debn(x, n) ;
#define deba(x) ;
#endif

template<class T>
istream &operator>>(istream &in, vector<T> &a) {
    for (auto &x: a) in >> x;
    return in;
}

template<class T>
ostream &operator<<(ostream &out, const vector<T> &a) {
    for (auto &x: a) out << x << ' ';
    return out;
}

template<class T>
istream &operator>>(istream &in, pair<T, T> &a) {
    in >> a.first >> a.second;
    return in;
}

template<class T>
ostream &operator<<(ostream &out, const pair<T, T> &a) {
    out << "(" << a.first << "," << a.second << ")";
    return out;
}

const double PI = atan(1) * 4;
constexpr double eps = 0.00000001;
constexpr ll mod = 1e9 + 7;
constexpr ll N = 1e5 + 10;

vector<vector<int>> g;
vector<pair<int, int>> e;
int was[N];
int mask[N];
vector<int> st;
vector<int> path;

void dfs(int x, int end) {
    was[x] = 1;
    if (x == end) {
        path = st;
    }
    for (auto i: g[x]) {
        int y = x ^ e[i].first ^ e[i].second;
        if (was[y]) continue;
        st.pb(i);
        dfs(y, end);
        st.pop_back();
    }
}

vector<int> to;
int dp[(1 << 20) + 10];

int getans(int mask) {
    int &ans = dp[mask];
    if (ans != -1) return ans;
    ans = 1e9;
    for (auto x: to) {
        if (x & mask) {
            int sl = mask & (~x);
            ans = min(ans, 1 + getans(sl));
        }
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n;
    g.clear();
    e.clear();
    to.clear();
    e.resize(n - 1);
    g.resize(n);
    for (int i = 0; i < n; i++) mask[i] = 0;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[i] = {x, y};
        g[x].pb(i);
        g[y].pb(i);
    }
    cin >> k;
    st.reserve(n - 1);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        st.clear();
        for (int j = 0; j < n; j++) {
            was[j] = 0;
        }
        dfs(x, y);
        for (auto x: path) {
            mask[x] |= (1 << i);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (mask[i] != 0 && count(all(to), mask[i]) == 0) {
            to.pb(mask[i]);
        }
    }
    sort(all(to));
    for (int i = 0; i < (1 << k); i++) {
        dp[i] = -1;
    }
    dp[0] = 0;
    int ans = getans((1 << k) - 1);
    cout<<ans<<'\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cout.precision(12);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}