#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

ll n;
ll a[200010];
ll cnt[50];

void run_case() {
    scanf("%lld", &n);
    ll tot = 0;
    for (ll i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
        tot += a[i];
    }
    if (tot % n != 0) {
        printf("No\n");
        return;
    }
    ll avg = tot / n;
    memset(cnt, 0, sizeof(cnt));
    for (ll i=1; i<=n; i++) {
        ll diff = a[i] - avg;
        if (diff == 0) continue;
        bool flag = false;
        for (ll j=0; j<=30; j++) {
            for (ll k=0; k<=30; k++) {
                if ((1<<j) - (1<<k) == diff) {
                    cnt[j] ++;
                    cnt[k] --;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) {
            printf("No\n");
            return;
        }
    }
    for (ll i=0; i<=30; i++) {
        if (cnt[i] != 0) {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc --) {
        run_case();
    }

    return 0;
}