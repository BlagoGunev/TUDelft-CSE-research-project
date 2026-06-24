#include <iostream>
#include <cstdio>
using namespace std;
const int N = 400010;
int n, ans;
int a[N], b[N];
int cnt0, cnt1;
int t0[N], t1[N];
int w(int bit) {
    return (1 << bit);
}
void radix_sort(int bit) {
    int t = w(bit);
    cnt0 = cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] & t) t1[++cnt1] = a[i];
        else t0[++cnt0] = a[i];
    }
    for (int i = 1; i <= cnt0; i++)
        a[i] = t0[i];
    for (int i = 1; i <= cnt1; i++)
        a[i + cnt0] = t1[i];
    t = (t << 1) - 1;
    for (int i = 1; i <= n; i++)
        b[i] = a[i] & t;
    return;
}
int count(int l, int r) {
    int pl = n, pr = n, tot = 0;
    for (int i = 1; i <= n; i++) {
        while(pl >= 1 && b[i] + b[pl] >= l) pl--;
        while(pr >= 1 && b[i] + b[pr] > r) pr--;
        if (pr <= i) break;
        tot ^= ((pr - max(pl, i)) & 1);
    }
    return tot;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int bit = 0; bit <= 24; bit++) {
        radix_sort(bit);
        int flag = count(w(bit), w(bit + 1) - 1) ^ count(w(bit) * 3, w(bit + 2));
        if (flag) ans += w(bit);
    }
    printf("%d\n", ans);
    return 0;
}