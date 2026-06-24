#include <bits/stdc++.h>
using namespace std;

int Q;
long long a[4];

int main() {
    scanf("%d", &Q);
    while (Q--) {
        scanf("%lld%lld%lld", &a[1], &a[2], &a[3]);
    sort(a + 1, a + 4);
    long long res = 0;
    res = a[2];
    a[3] -= a[2] - a[1];
    res += a[3]/2;
        printf("%lld\n", res);
    }
}