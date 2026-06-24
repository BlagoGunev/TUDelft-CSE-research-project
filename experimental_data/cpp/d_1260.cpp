#include <bits/stdc++.h>
#define R register
#define mp make_pair
#define ll long long
#define pii pair<int, int>
using namespace std;
const int N = 210000;

int m, n, k, t, a[N], lt[N], rt[N], d[N], sum[N];

template <class T>
inline void read(T &x) {
    x = 0;
    char ch = getchar(), w = 0;
    while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
    while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x = w ? -x : x;
    return;
}

inline bool check(int mid) {
    memset(sum, 0, sizeof (sum));
    int tot = n + 1;
    for (R int i = 1; i <= k; ++i)
        if (d[i] > mid) ++sum[lt[i]], --sum[rt[i] + 1];
    for (R int i = 1; i <= n + 1; ++i)
        sum[i] += sum[i - 1], tot += !!sum[i] * 2;
    return tot <= t;
}

int main() {
    read(m), read(n), read(k), read(t);
    for (R int i = 1; i <= m; ++i) read(a[i]);
    sort(a + 1, a + 1 + m), reverse(a + 1, a + 1 + m);
    for (R int i = 1; i <= k; ++i)
        read(lt[i]), read(rt[i]), read(d[i]);
    int l = 0, r = m, mid;
    while (l != r) mid = (l + r + 1) >> 1, check(a[mid]) ? l = mid : r = mid - 1;
    cout << l << endl;
    return 0;
}