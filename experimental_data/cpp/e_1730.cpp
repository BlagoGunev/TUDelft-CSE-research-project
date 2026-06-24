// LUOGU_RID: 99331490
#include <bits/stdc++.h>
#define SZ(x) (int) x.size() - 1
#define all(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof x)
#define F(i, x, y) for (int i = (x); i <= (y); i++)
#define DF(i, x, y) for (int i = (x); i >= (y); i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); }
template <typename T> void read(T &x) {
    x = 0; int f = 1; char c = getchar();
    for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
    for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
    x *= f;
}
const int N = 5e5 + 10, M = 1e6 + 10;
int n, a[N], lg[N], q[N], l[N], r[N], tl[N], tr[N], lst[M], cnt[M];
ll ans;
vector <int> d[M];
vector <int> tube[M];
void zhk() {
    ans = 0;
    read(n);
    F(i, 1, 1e6) {
        cnt[i] = 0;
        lst[i] = -1; tube[i].clear();
    }
    F(i, 1, n) read(a[i]), tube[a[i]].push_back(i);
    F(i, 2, n) lg[i] = lg[i >> 1] + 1;
    int t = 0;
    F(i, 1, n) {
        while (t && a[q[t]] < a[i]) r[q[t--]] = i - 1;
        l[i] = q[t] + 1; r[i] = n;
        q[++t] = i;
    }
    t = 0;
    F(i, 1, n) {
        while (t && a[q[t]] > a[i]) tr[q[t--]] = i - 1;
        tr[i] = n;
        q[++t] = i;
    }
    t = 0;
    DF(i, n, 1) {
        while (t && a[q[t]] > a[i]) tl[q[t--]] = i + 1;
        tl[i] = 1;
        q[++t] = i;
    }
    // F(i, 1, n) cout << tl[i] << " " << tr[i] << endl;
    // F(i, 1, 1e6) lst[i] = -1;
    // DF(i, n, 1) {
    //     lst[a[i]] = i;
    //     for (int j: d[a[i]]) {
    //         if (lst[j] == -1 || tl[lst[j]] > i || lst[j] > r[i]) R[i].push_back(-1);
    //         else R[i].push_back(lst[j]);
    //     }
    // }
    // F(i, 1, n) {
    //     lst[a[i]] = i;
    //     for (int j: d[a[i]]) {
    //         if (lst[j] == -1 || tr[lst[j]] < i || lst[j] < l[i]) L[i].push_back(-1);
    //         else L[i].push_back(lst[j]);
    //     }
    // }
    F(i, 1, n) {
        lst[a[i]] = i;
        int s = 0;
        for (int j: d[a[i]]) {
            int t = lst[j], tt = -1;
            if (t == -1 || tr[t] < i || t < l[i]) t = -1;
            while (cnt[j] < tube[j].size() && tube[j][cnt[j]] < i) cnt[j]++;
            if (cnt[j] < tube[j].size()) {
                int x = tube[j][cnt[j]];
                if (x <= r[i] && tl[x] <= i) tt = x;
            }
                // cout << i << " " << l[i] << " " << r[i] << " " << d[a[i]][s] << " " << t << " " << tt << endl;
            if (t != -1 || tt != -1) {
                if (t == -1) ans += (ll) (min(r[i], tr[tt]) - tt + 1) * (i - max(l[i], tl[tt]) + 1);
                else if (tt == -1) ans += (ll) (t - max(l[i], tl[t]) + 1) * (min(r[i], tr[t]) - i + 1);
                    else ans += (ll) (t - max(l[i], tl[t]) + 1) * (min(r[i], tr[tt]) - i + 1)
                    + (ll) (i - max(l[i], tl[t]) + 1) * (min(r[i], tr[tt]) - tt + 1)
                    - (ll) (t - max(l[i], tl[t]) + 1) * (min(r[i], tr[tt]) - tt + 1);
                // cout << i << " " << d[a[i]][s] << " " << ans - lastans << " " << L[i][s] << " " << R[i][s] << endl;
                // cout << (ll) (L[i][s] - max(l[i], tl[L[i][s]]) + 1) * (min(r[i], tr[R[i][s]]) - i + 1)
                //     << " " << (ll) (i - max(l[i], tl[L[i][s]]) + 1) * (min(r[i], tr[R[i][s]]) - R[i][s] + 1)
                //     << " " << (ll) (L[i][s] - max(l[i], tl[L[i][s]]) + 1) * (min(r[i], tr[R[i][s]]) - R[i][s] + 1) << endl;
            } s++;
        }
    } cout << ans << endl;
}
signed main() {
    F(i, 1, 1e6)
        for (int j = i; j <= 1e6; j += i)
            d[j].push_back(i);
    // int mx = 0;
    // F(i, 1, 1e6) chkmax(mx, (int) d[i].size());
    // cout << mx;
    int _ = 1;
    cin >> _;
    while (_--) zhk();
    return 0;
}