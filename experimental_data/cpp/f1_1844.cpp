#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define maxn 200010
#define maxm 200010
#define eps 1e-8
#define M1 (ll)998244353
#define M (ll)1000000007
#define inf 1e18
#define pi acos(-1)
#define Ls(x) (x << 1)
#define Rs(x) (x << 1 | 1)
#define lowbit(x) (x & -x)
#define highbit(x) (1 << (31 - __builtin_clz(x)))
#define bitcnt(x) (__builtin_popcount(x))

ll a[maxn], c, n;
int l[maxn], r[maxn];
void init() {
    for (int i = 1; i <= n; ++i) {
        l[i] = i - 1, r[i] = i + 1;
    }
    l[0] = 0, r[0] = 1;
    l[n + 1] = n, r[n + 1] = n + 1;
}
void Print() {
    for (int i = r[0]; i != n + 1; i = r[i]) cout << a[i] << " ";
    cout << "\n";
}
// y 插入到位置 x，循环位移(y 放到 x 前面)
void Move(int x, int y) {
    if (x == y) return;
    r[l[y]] = r[y], l[r[y]] = l[y];
    l[y] = l[x], r[y] = x;
    r[l[y]] = y, l[x] = y;
}

using P = pair<ll, int>;  // val = a[pos], pos
multiset<P> ms;
void Swap(int L, int R) {
    if (L >= R) return;
    ms.clear();
    for (int i = r[L - 1]; i != R + 1; i = r[i]) {
        ms.insert({a[i], i});
    }
    // 注意顺序：判断 j 原位置是否合法
    for (int i = r[L - 1]; i != R + 1; i = r[i]) {
        // a[l[i]] - a[j] <= c && a[l[j]] - a[r[j]] <= c
        while (ms.lower_bound({a[l[i]] - c, 0}) != ms.end()) {
            int j = ms.lower_bound({a[l[i]] - c, 0})->second;
            ms.erase(ms.find({a[j], j}));
            if (a[l[j]] - a[r[j]] > c) continue;
            Move(i, j), i = j;
            break;
        }
    }
}
void sol() {
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (c >= 0) {
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    c = -c;
    sort(a + 1, a + 1 + n, greater<ll>());
    init();
    a[0] = inf, a[n + 1] = -inf;
    int lst = 1;
    for (int i = 0; i <= n; ++i) {
        if (a[i] - a[i + 1] > c) {
            Swap(lst + 1, i - 1);
            lst = i + 1;
        }
    }
    Print();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll T = 1;
    cin >> T;
    while (T--) {
        sol();
    }
    return 0;
}