#include <cstdio>

using namespace std;



int cnt[4];



int main() {

    int n;

    scanf("%d", &n);

    long long ans = (long long)n * (n - 1) * (n - 2) / 6;

    int x, y;

    while (n--) {

        scanf("%d %d", &x, &y);

        cnt[(x & 2) | ((y >> 1) & 1)]++;

    }

    for (int p = 0; p < 4; p++)

        for (int q = p + 1; q < 4; q++)

            for (int r = q + 1; r < 4; r++) ans -= (long long)cnt[p] * cnt[q] * cnt[r];

    printf("%lld\n", ans);

    return 0;

}