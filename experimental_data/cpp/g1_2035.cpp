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

const int md = 998244353;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 3005;

struct atom {
    int x, k;
    atom (int a = 0, int b = 0) : x(a), k(b) {}
    bool operator < (const atom A) const { return x < A.x; }
};

atom a[N];
int dp[N], mx[N], pw[N], inv[N];
int T, n, m;

int cnt;
int query1(int l, int r, int x, int vx) {
    if (l == r) return 1;
    int mid = (l + r) >> 1;
    if (mid >= x) {
        int tmp = query1(l, mid, x, vx);
        if (x != mid) {
            tmp = mul(tmp, n - vx + 1);
            ++cnt;
        }
        return tmp;
    }
    return query1(mid + 1, r, x, vx);
}

int query2(int l, int r, int x, int vx) {
    if (l == r) return 1;
    int mid = (l + r) >> 1;
    if (mid >= x) return query2(l, mid, x, vx);
    ++cnt;
    return mul(query2(mid + 1, r, x, vx), vx - 1);
}

int query(int l, int r, int x, int y, int vx, int vy) {
    if (l == r) return 1;
    int mid = (l + r) >> 1;
    if (y <= mid) return query(l, mid, x, y, vx, vy);
    if (x >= mid + 1) return query(mid + 1, r, x, y, vx, vy);
    cnt = 0;
    int tmp = mul(query1(l, mid, x, vx), query2(mid + 1, r, y, vy));
    // fprintf(stderr, "l = %d, mid = %d, r = %d, x = %d, y = %d, cnt = %d, tmp = %d\n", l, mid, r, x, y, cnt, tmp);
    if (x != mid) {
        tmp = mul(tmp, vy - vx);
        ++cnt;
    }
    tmp = mul(tmp, pw[y - x - 1 - cnt]);
    return tmp;
}

int calcl(int i) {
    cnt = 0;
    int tmp = query2(1, n, a[i].x, a[i].k);
    tmp = mul(tmp, pw[a[i].x - 1 - cnt]);
    // fprintf(stderr, "l : i = %d, tmp = %d\n", i, tmp);
    return tmp;
}

int calcr(int i) {
    cnt = 0;
    int tmp = query1(1, n, a[i].x, a[i].k);
    tmp = mul(tmp, pw[n - a[i].x - cnt]);
    // fprintf(stderr, "r : i = %d, tmp = %d\n", i, tmp);
    return tmp;
}

int calc(int i, int j) {
    int ans = query(1, n, a[i].x, a[j].x, a[i].k, a[j].k);
    // fprintf(stderr, "calc : i = %d, j = %d, ans = %d\n", i, j, ans);
    return ans;
}

int main() {
    for (int i = 1; i < N; i++) inv[i] = fpow(i, md - 2);
    read(T);
    while (T--) {
        read(n); read(m);
        pw[0] = 1;
        for (int i = 1; i <= n; i++) pw[i] = mul(pw[i - 1], n);
        for (int i = 1; i <= m; i++) {
            read(a[i].x); read(a[i].k);
        }
        sort(a + 1, a + m + 1);
        for (int i = 1; i <= m; i++) {
            dp[i] = calcl(i); mx[i] = 1;
            if (a[i].k == 1 && a[i].x != 1) mx[i] = -1e9;
            for (int j = 1; j < i; j++) {
                if (a[j].k < a[i].k) {
                    int res = mul(dp[j], calc(j, i));
                    if (mx[j] + 1 > mx[i]) {
                        mx[i] = mx[j] + 1;
                        dp[i] = res;
                    } else if (mx[j] + 1 == mx[i]) {
                        dp[i] = add(dp[i], res);
                    }
                }
            }
        }
        int ans = 0, maxn = 0;
        for (int i = 1; i <= m; i++) {
            int res = mul(dp[i], calcr(i));
            if (mx[i] > maxn) {
                maxn = mx[i];
                ans = res;
            } else if (mx[i] == maxn) {
                ans = add(ans, res);
            }
        }
        if (maxn == 0) ans = pw[n];
        printf("%d %d\n", m - maxn, ans);
    }
    return 0;
}