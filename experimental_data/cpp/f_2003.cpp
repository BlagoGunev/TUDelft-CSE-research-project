#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define all(x) x.begin(), x.end()
const int mod = 998244353, N = 505;

auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

template <typename T>
struct BIT {
    // single point add, prefix query sum
    vector <T> val;
    int n, offset;
    BIT () = default;
    BIT (int _n, int _offset = 3) : n(_n + _offset * 2), offset(_offset) {
        val.assign(n, -1 << 30);
    }
    void add(int p, T v) {
        for (p += offset; p < n; p += p & (-p)) {
            val[p] = max(val[p], v);
        }
    }
    T query(int p) {
        T ans = -1 << 30;
        for (p += offset; p > 0; p -= p & (-p)) {
            ans = max(ans, val[p]);
        }
        return ans;
    }
    T query(int l, int r) {
        // query [l, r)
        return query(r - 1) - query(l - 1);
    }
    int kth (int k) {
        // 1-index, return kth smallest number
        // 1 <= k && k <= current size
        int ans = 0;
        for (int i = 1 << __lg(n); i > 0; i >>= 1) {
            if (ans + i < n && val[ans + i] < k) {
                k -= val[ans += i];
            }
        }
        return ans - offset + 1;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i], --a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i], --b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    int ans = -1;
    for (int _ = 0; _ < 100; ++_) {
        vector <int> w(n);
        for (int i = 0; i < n; ++i) {
            w[i] = rng() % m;
        }
        vector bit(1 << m, BIT <int>(n));
        bit[0].add(0, 0);
        for (int i = 0; i < n; ++i) {
            for (int msk = 0; msk < 1 << m; ++msk) if (msk >> w[b[i]] & 1) {
                int val = bit[msk ^ (1 << w[b[i]])].query(a[i]) + c[i];
                bit[msk].add(a[i], val);
            }
        }
        ans = max(ans, bit.back().query(n - 1));
    }
    cout << ans << '\n';
}