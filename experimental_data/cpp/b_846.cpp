#include <bits/stdc++.h>
#include<bits/stdc++.h>

using namespace std;

long long int t[51];

int main()
{
    long long int n, K, M, i, j, k, l, ct, tp, fg, mx;
    scanf("%lld %lld %lld", &n, &K, &M);
    for (i = 0; i < K; i++) {
        scanf("%lld", &t[i]);
    }
    mx = 0;
    sort(t, t + K);
    for (i = 0; i <= n; i++) {
        ct = 0;
        fg = 0;
        tp = M;
        for (j = 0; j < i; j++) {
            for (k = 0; k < K; k++) {
                tp -= t[k];
                if (tp < 0) {
                    fg = 1;
                    break;
                }
                ct++;
                if (k == K - 1) {
                    ct++;
                }
            }
            if (fg) {
                break;
            }
        }
        if (ct > mx) {
            mx = ct;
        }
        if (fg) {
            break;
        }
        fg = 0;
        for (j = 0; j < K; j++) {
            for (k = i; k < n; k++) {
                tp -= t[j];
                if (tp < 0) {
                    fg = 1;
                    break;
                }
                ct++;
                if (j == K - 1) {
                    ct++;
                }
            }
            if (fg) {
                break;
            }
        }
        if (ct > mx) {
            mx = ct;
        }
    }
    printf("%lld", mx);
    return 0;
}