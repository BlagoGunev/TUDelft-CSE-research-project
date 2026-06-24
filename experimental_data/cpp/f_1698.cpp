/*+Rainybunny+*/

#include <bits/stdc++.h>

#define rep(i, l, r) for (int i = l, rep##i = r; i <= rep##i; ++i)
#define per(i, r, l) for (int i = r, per##i = l; i >= per##i; --i)

typedef std::pair<int, int> PII;
#define fi first
#define se second

const int MAXN = 500;
int n, a[MAXN + 5], b[MAXN + 5];
std::vector<PII> ans;

inline bool solve() {
#define rever(l, r) \
    void((ans.emplace_back(l, r), std::reverse(a + (l), a + (r) + 1)))

    rep (i, 2, n - 1) if (a[i] != b[i]) {
        int x = a[i - 1], u = a[i], v = b[i];
        rep (j, i + 1, n - 1) if (a[j] == v && a[j + 1] == x) {
            rever(i - 1, j + 1); break;
        }
        if (a[i] == b[i]) continue;
        
        int p = 0;
        rep (j, i, n - 1) if (a[j] == x && a[j + 1] == v) { p = j; break; }
        if (!p) return false;
        
        rep (s, i, p) {
            rep (t, p + 1, n) if (a[s] == a[t]) {
                rever(s, t), rever(i - 1, s + t - p);
                goto DONE;
            }
        }
        DONE: ;
    }
    return true;
#undef rever
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n), ans.clear();
        rep (i, 1, n) scanf("%d", &a[i]);
        rep (i, 1, n) scanf("%d", &b[i]);
        if (a[1] != b[1] || a[n] != b[n] || !solve()) puts("NO");
        else {
            printf("YES\n%zd\n", ans.size());
            for (PII& p: ans) printf("%d %d\n", p.fi, p.se);
        }
    }
    return 0;
}