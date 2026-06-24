#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    long long int n, m;

    scanf("%lld%lld", &n, &m);
    if (n <= m) {
        printf("%lld\n", n);
    } else {
        long double delta = n - m;
        long double min = (sqrtl(8.0L * delta + 1.0L) - 1.0L) / 2.0L;
        long long int ans = ceil(min);
        printf("%lld\n", ans + m);
    }

    return 0;
}