#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int n, i;
int w[N], h[N], pw[N], ph[N], sw[N], sh[N], sumw, sumh;
int readint() {
        int x = 0;
        char c;
        do {
                c = getchar();
        } while (c <= 32);
        while (c >= '0' && c <= '9') {
                x = (x << 3) + (x << 1) + c - 48;
                c = getchar();
        }
        return x;
}
int main() {
#ifndef ONLINE_JUDGE
        freopen("data.in", "r", stdin);
#endif
        n = readint();
        for (i = 1; i <= n; ++i) {
                w[i] = readint();
                h[i] = readint();
        }
        pw[0] = ph[0] = 0;
        for (i = 1; i <= n; ++i) {
                pw[i] = pw[i - 1] + w[i];
                ph[i] = max(ph[i - 1], h[i]);
        }
        sw[n + 1] = sh[n + 1] = 0;
        for (i = n; i >= 1; --i) {
                sw[i] = sw[i + 1] + w[i];
                sh[i] = max(sh[i + 1], h[i]);
        }
        for (i = 1; i <= n; ++i) {
                sumw = pw[i - 1] + sw[i + 1];
                sumh = max(ph[i - 1], sh[i + 1]);
                printf("%d ", sumw * sumh);
        }
        printf("\n");
        return 0;
}