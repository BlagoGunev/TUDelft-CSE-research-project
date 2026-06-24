#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MD = 1000000009;

const int MAXN = 500100;
const int MAXK = 524288;

struct mt
{
    int a[2][2];
    void init(int aa, int bb, int cc, int dd) {
        a[0][0] = aa, a[0][1] = bb, a[1][0] = cc, a[1][1] = dd;
    }
};

mt
mult(const mt &a, const mt &b)
{
    mt res;
    res.init((1ll * a.a[0][0] * b.a[0][0] + 1ll * a.a[0][1] * b.a[1][0]) % MD,
            (1ll * a.a[0][0] * b.a[0][1] + 1ll * a.a[0][1] * b.a[1][1]) % MD,
            (1ll * a.a[1][0] * b.a[0][0] + 1ll * a.a[1][1] * b.a[1][0]) % MD,
            (1ll * a.a[1][0] * b.a[0][1] + 1ll * a.a[1][1] * b.a[1][1]) % MD);
    return res;
}

mt sm[MAXN];
int sum_cov[2 * MAXK];
int sum_beg[2 * MAXK][2];
int end_cnt[2 * MAXK];
int part_sum[MAXN];
int n, m;
int fib[MAXN];

void
precalc()
{
    sm[0].init(1, 0, 0, 1);
    sm[1].init(1, 1, 1, 0);
    for (int i = 2; i < MAXN; ++i) {
        sm[i] = mult(sm[i - 1], sm[1]);
    }
    fib[1] = fib[2] = 1;
    for (int i = 3; i < MAXN; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MD;
    }
}

void
add(int l, int r)
{
    for (int cur_v = 1, cur_f = 1, cur_t = n + 1; cur_f <= l && cur_t >= r; ) {
        sum_cov[cur_v] = (sum_cov[cur_v] + fib[r - l + 2]) % MD;
        sum_cov[cur_v] = (sum_cov[cur_v] + MD - 1) % MD;
        if (cur_f == cur_t - 1) {
            break;
        }
        int mid = (cur_f + cur_t) / 2;
        if (r <= mid) {
            cur_t = mid;
            cur_v *= 2;
        } else if (l >= mid) {
            cur_f = mid;
            cur_v = cur_v * 2 + 1;
        } else {
            break;
        }
    }
    for (int cur_v = 1, cur_f = 1, cur_t = n + 1; ; ) {
        if (cur_t < r) {
            int v = cur_v;
            sum_beg[v][0] = (sum_beg[v][0] + fib[cur_t - l + 2]) % MD;
            sum_beg[v][1] = (sum_beg[v][1] + fib[cur_t - l + 1]) % MD; 
            end_cnt[v] = (end_cnt[v] + 1) % MD;
        }
        if (cur_f == cur_t - 1) {
            break;
        }
        int mid = (cur_f + cur_t) / 2;
        if (l >= mid) {
            cur_v = cur_v * 2 + 1;
            cur_f = mid;
        } else {
            cur_t = mid;
            cur_v *= 2;
        }
    }
    for (int cur_v = 1, cur_f = 1, cur_t = n + 1; ; ) {
        if (cur_f > l) {
            int v = cur_v;
            sum_cov[v] = (sum_cov[v] + fib[r - l + 2]) % MD;
            sum_cov[v] = (sum_cov[v] + MD - 1) % MD;
            sum_beg[v][0] = (sum_beg[v][0] + MD - fib[cur_t - l + 2]) % MD;
            sum_beg[v][1] = (sum_beg[v][1] + MD - fib[cur_t - l + 1]) % MD;
            end_cnt[v] = (end_cnt[v] + MD - 1) % MD;
        }
        if (cur_f == cur_t - 1) {
            break;
        }
        int mid = (cur_f + cur_t) / 2;
        if (r <= mid) {
            cur_v *= 2;
            cur_t = mid;
        } else {
            cur_v = cur_v * 2 + 1;
            cur_f = mid;
        }
    }
}

int
getSum(int r)
{
    int a = 0, b = 0, c = 0;
    int res = 0;
    int cur_v, cur_f, cur_t;
    for (cur_v = 1, cur_f = 1, cur_t = n + 1; ; ) {
        if (cur_f == cur_t - 1) {
            break;
        }
        int mid = (cur_f + cur_t) / 2;
        if (r > mid) {
            res = (res + sum_cov[cur_v * 2]) % MD;
            const mt &mult_m = sm[mid - cur_f];
            int ta = (1ll * mult_m.a[0][0] * a + 1ll * mult_m.a[0][1] * b) % MD;
            int tb = (1ll * mult_m.a[1][0] * a + 1ll * mult_m.a[1][1] * b) % MD;
            a = (ta + sum_beg[cur_v * 2][0]) % MD;
            b = (tb + sum_beg[cur_v * 2][1]) % MD;
            c = (c + end_cnt[cur_v * 2]) % MD;
            cur_v = cur_v * 2 + 1;
            cur_f = mid;
        } else {
            cur_v *= 2;
            cur_t = mid;
        }
    }
    { // cur_f == cur_t - 1
        res = (res + sum_cov[cur_v]) % MD;
        const mt &mult_m = sm[cur_t - cur_f];
        int ta = (1ll * mult_m.a[0][0] * a + 1ll * mult_m.a[0][1] * b) % MD;
        int tb = (1ll * mult_m.a[1][0] * a + 1ll * mult_m.a[1][1] * b) % MD;
        a = (ta + sum_beg[cur_v][0]) % MD;
        b = (tb + sum_beg[cur_v][1]) % MD;
        c = (c + end_cnt[cur_v]) % MD;
    } 
    res = (res + a) % MD;
    res = (res + MD - c) % MD;
    return res;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    precalc();
    part_sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        cin >> cur;
        part_sum[i] = (part_sum[i - 1] + cur) % MD;
    }
    for (int i = 0; i < m; ++i) {
        int tp, l, r;
        cin >> tp >> l >> r;
        if (tp == 1) {
            add(l, r + 1);
        } else {
            int tmp = getSum(r + 1);
            if (l != 1) {
                tmp = (tmp + MD - getSum(l)) % MD;
            }
            tmp = (tmp + part_sum[r]) % MD;
            tmp = (tmp + MD - part_sum[l - 1]) % MD;
            cout << tmp << '\n';
        }
    }
    return 0;
}