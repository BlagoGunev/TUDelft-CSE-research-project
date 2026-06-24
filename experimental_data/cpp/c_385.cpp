#include <stdio.h>

int lp[10000001];
int primes[10000001];
int cnt = 0;

int f[10000001];

int main()
{
    //freopen("input", "r", stdin);

    for (int i = 2; i <= 10000000; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes[cnt++] = i;
        }
        for (int j = 0; j < cnt && primes[j] <= lp[i] && i * primes[j] <= 10000000; j++) {
            lp[i * primes[j]] = primes[j];
        }
    }

    int n;
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d",  &x);
        while (x > 1) {
            int t = lp[x];
            f[t]++;
            while (x%t == 0) {
                x /= t;
            }
        }
    }

    for (int i = 3; i <= 10000000; i++) {
        f[i] += f[i-1];
    }

    int m;
    scanf("%d", &m);

    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (l > 10000000) {
            printf("0\n");
        }
        else {
            if (r > 10000000)
                r = 10000000;
            printf("%d\n", f[r] - f[l-1]);
        }
    }
}