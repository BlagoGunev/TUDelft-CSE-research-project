#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5, B = 400;

struct atom {
    int l, r, id;
    bool operator < (const atom A) const {
        if (l / B != A.l / B) return l < A.l;
        return r < A.r;
    }
} qq[N];

int a[N], id[N], ans[N], cnt[2005];
int T, n, q, k, sq, len;

inline int getid(int x) {
    if (x <= sq) return x;
    return len - k / x + 1;
}

inline void add(int x) {
    ++cnt[id[x]];
}

inline void del(int x) {
    --cnt[id[x]];
}

int main() {
    read(T);
    while (T--) {
        read(n); read(q); read(k); sq = sqrt(k + 0.5);
        len = 0;
        for (int l = 1, r; l <= k; l = r + 1, ++len) r = k / (k / l);
        for (int i = 1; i <= n; i++) read(a[i]), id[i] = getid(a[i]);
        for (int i = 1; i <= q; i++) read(qq[i].l), read(qq[i].r), qq[i].id = i;
        sort(qq + 1, qq + q + 1);
        for (int i = 1; i <= len; i++) cnt[i] = 0;
        for (int i = 1, l = 1, r = 0; i <= q; i++) {
            while (l > qq[i].l) add(--l);
            while (r < qq[i].r) add(++r);
            while (l < qq[i].l) del(l++);
            while (r > qq[i].r) del(r--);
            int mx = 0, sl = cnt[1], sr = cnt[len], qr = len;
            for (int j = 2; j <= len; j++) {
                if (!cnt[j]) continue;
                while (j + qr - 1 >= len + 2 && qr - 1 >= j) {
                    --qr;
                    sr += cnt[qr];
                }
                if (j != qr) mx = max(mx, sr - sl);
                else {
                    mx = max(mx, sr - sl - 1);
                    break;
                }
                sl += cnt[j];
            }
            ans[qq[i].id] = (mx + 1) / 2;
        }
        for (int i = 1; i <= q; i++) print(ans[i], i == q ? '\n' : ' ');
    }
    return 0;
}