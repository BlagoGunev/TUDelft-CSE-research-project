#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    long long arr_n[50], arr_m[50];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr_n[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &arr_m[i]);
    }

    long long ans[50];
    for (int i = 0; i < n; i++) {
        ans[i] = arr_n[i] * arr_m[0];
        for (int j = 1; j < m; j++) {
            if (arr_n[i] * arr_m[j] > ans[i]) {
                ans[i] = arr_n[i] * arr_m[j];
            }
        }
    }
    sort(ans, ans + n);
    printf("%lld", ans[n - 2]);
}