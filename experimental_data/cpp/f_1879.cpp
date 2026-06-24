#ifdef LOCAL
#define _GLIBCXX_DEBUG
#else
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define mp make_pair
#define pbc push_back
#define all(v) begin(v),end(v)
#define vin(v) for (auto &el : v) cin >> el

mt19937 rnd(179);
template<typename T1, typename T2>
inline void chkmin(T1 &x, const T2 &y) {
    if (y < x) {
        x = y;
    }
}
template<typename T1, typename T2>
inline void chkmax(T1 &x, const T2 &y) {
    if (y > x) {
        x = y;
    }
}
const ll INF = 1e15;

struct Part {
    pair <ll, int> first{-INF, -1};
    pair <ll, int> second{-INF, -1};
};

Part merge(const Part& a, const Part& b) {
    Part ans;

    ans.first = max(a.first, b.first);
    ans.second = max(a.second, b.second);
    if (a.first != ans.first) ans.second = max(ans.second, a.first);
    if (b.first != ans.first) ans.second = max(ans.second, b.first);
    return ans;
}

struct Sparse {
    vector <vector <Part>> st;
    vector <Part> a;
    int k = 0;

    Sparse(int n, vector <Part>& a) : a(a) {
        while ((1 << k) < n) k++;
        st.resize(k, a);

        for (int i = 0; i < k; ++i) {
            int cur_len = (1 << (k - i - 1));
            for (int j = cur_len; j < n; j += 2 * cur_len) {
                for (int x = j + 1; x < j + cur_len && x < n; ++x) {
                    st[i][x] = merge(st[i][x - 1], st[i][x]);
                }

                for (int x = j - 2; x >= j - cur_len; --x) {
                    st[i][x] = merge(st[i][x + 1], st[i][x]);
                }
            }
        }
    }

    Part get_ans(int l, int r) {
        if (l == r) return a[l];

        int x = (l ^ r);
        int b = 31 - __builtin_clz(x);

        return merge(st[k - 1 - b][l], st[k - 1 - b][r]);
    }
};

const int MAXN = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector <Part> flex(MAXN);
    vector <int> h(n), a(n);

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        flex[a[i]] = merge(flex[a[i]], {{h[i], i}, {-INF, -1}});
    }

    Sparse t(MAXN, flex);
    vector <ll> ans(n);

    for (int x = 1; x < MAXN; ++x) {
        Part cha;

        for (int cnt_h = 0; x * cnt_h + 1 < MAXN; ++cnt_h) {
            if (cnt_h == 198) {
                int xd = 0;
            }
            int l = cnt_h * x + 1;
            int r = min(MAXN - 1, l + x - 1);

            Part bob = t.get_ans(l, r);
            if (bob.first.first > 0) {
                ll cnt_moves = 1ll * bob.first.first * (cnt_h + 1);
                cha = merge(cha, {{cnt_moves, bob.first.second}, {-INF, -1}});
            }
            if (bob.second.first > 0) {
                ll cnt_moves = 1ll * bob.second.first * (cnt_h + 1);
                cha = merge(cha, {{cnt_moves, bob.second.second}, {-INF, -1}});
            }
        }

        ll cnt2 = 0;
        if (cha.second.second >= 0) cnt2 = cha.second.first;
        ans[cha.first.second] = max(ans[cha.first.second], cha.first.first - cnt2);
    }

    for (auto i : ans) cout << i << " ";
    cout << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}