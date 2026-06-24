/**
 * Created by megurine on 2023/02/14 10:03:27.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

template<typename T>
void chmax(T &a, T b) { if (b > a) a = b; }

template<typename T>
void chmin(T &a, T b) { if (b < a) a = b; }

template<typename T>
class fenwick {
private:
    vector<T> fenw;
    int n;
public:
    explicit fenwick(int _n) : n(_n), fenw(_n) {
        assert(_n >= 0);
    }

    void modify(int x, T v) {
        for (int i = x; i < n; i |= i + 1)
            fenw[i] += v;
    }

    T get(int x) {
        T v{};
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            v += fenw[i];
        return v;
    }

    /**
     * 找到满足条件的最小索引
     */
    template<typename Fn>
    int partition(Fn fn) {
        int k = __lg(n | 1), j = -1;
        T tot{};
        for (int i = 1 << k; i; i >>= 1) {
            if (j + i < n && !fn(j + i, tot + fenw[j + i])) {
                tot += fenw[j += i];
            }
        }
        return j + 1;
    }
};

void elysia() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<PII>> arr(4);
    vector<int> trr(n), srt(n), rk(n);
    for (int i = 0; i < n; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        arr[a << 1 | b].emplace_back(t, i);
        trr[i] = t;
    }
    if (arr[1].size() + arr[3].size() < k || arr[2].size() + arr[3].size() < k || k * 2 > m + arr[3].size()) {
        cout << -1 << endl;
        return;
    }
    iota(itr(srt), 0);
    sort(itr(srt), [&](int i, int j) -> bool {
        return trr[i] < trr[j];
    });
    for (int i = 0; i < n; ++i) rk[srt[i]] = i;

    for (auto &it: arr) sort(itr(it));
    fenwick<int> fcc(n), fvv(n);
    for (int i = 0; i < n; ++i) {
        fcc.modify(rk[i], 1);
        fvv.modify(rk[i], trr[i]);
    }
    int cc = min(k, int(arr[3].size())); // 最多选择 1 1 的数量
    int ans = 2e9 + 1, xx = -1;
    for (int x = cc, tot = 0; x >= 0; --x) {
        if (arr[1].size() + x < k || arr[2].size() + x < k || k * 2 - x > m) {
            break;
        }
        if (x == cc) {
            for (int i = 0; i < cc; ++i) {
                int j = arr[3][i].second;
                fcc.modify(rk[j], -1);
                fvv.modify(rk[j], -trr[j]);
                tot += trr[j];
            }
            for (int i = 0; i < k - cc; ++i) {
                int j1 = arr[1][i].second, j2 = arr[2][i].second;
                fcc.modify(rk[j1], -1);
                fvv.modify(rk[j1], -trr[j1]);
                fcc.modify(rk[j2], -1);
                fvv.modify(rk[j2], -trr[j2]);
                tot += trr[j1] + trr[j2];
            }
        } else {
            int j1 = arr[1][k - x - 1].second, j2 = arr[2][k - x - 1].second, j3 = arr[3][x].second;
            fcc.modify(rk[j1], -1);
            fvv.modify(rk[j1], -trr[j1]);
            fcc.modify(rk[j2], -1);
            fvv.modify(rk[j2], -trr[j2]);
            fcc.modify(rk[j3], 1);
            fvv.modify(rk[j3], trr[j3]);
            tot += trr[j1] + trr[j2] - trr[j3];
        }

        int c0 = fcc.partition([&](int i, int v) -> bool {
            return v > m - k * 2 + x;
        });
        int cur = tot + fvv.get(c0 - 1);
        if (cur < ans) {
            ans = cur, xx = x;
        }
    }
    vector<int> idx;
    for (int i = 0; i < xx; ++i) {
        int j = arr[3][i].second;
        rk[j] = -1, idx.emplace_back(j + 1);
    }
    for (int i = 0; i < k - xx; ++i) {
        int j1 = arr[1][i].second, j2 = arr[2][i].second;
        rk[j1] = rk[j2] = -1;
        idx.emplace_back(j1 + 1), idx.emplace_back(j2 + 1);
    }
    vector<PII> rem;
    for (int i = 0; i < n; ++i)
        if (rk[i] >= 0)
            rem.emplace_back(trr[i], i);
    sort(itr(rem));
    for (int i = 0; i < m - k * 2 + xx; ++i) {
        idx.emplace_back(rem[i].second + 1);
    }
    cout << ans << endl;
    sort(itr(idx));
    for (auto &x: idx) cout << x << ' ';
    cout << endl;

}

int main() {
#ifdef MEGURINE
#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
    fr("../input.txt");
    fw("../output.txt");
    clock_t start = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    cout << fixed << setprecision(12);
    while (T--) {
        elysia();
    }
    cout.flush();
#ifdef MEGURINE
    clock_t end = clock();
    cout << "\n\nRunning Time : " << (double) (end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
    return 0;
}