#include <algorithm>
#include <iostream>
using namespace std;

#define N 200001
using ll = long long;

int f(int x) {
    int result = 1;
    while (result < x) {
        result <<= 1;
    }
    return result - x;
}

int sum[N];

void solve() {
    int n;
    cin >> n;
    fill_n(sum, n + 1, 0);
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        sum[x]++;
    }
    for (int i = 2; i <= n; i++) {
        sum[i] += sum[i - 1];
    }
    int result = 1e9;
    for (int i = 0, x, y;; i++) {
        x = upper_bound(sum, sum + n + 1, 1 << i) - sum - 1;
        for (int j = 0;; j++) {
            y = upper_bound(sum + x, sum + n + 1, (1 << j) + sum[x]) - sum - 1;
            result =
                min(result, ((1 << i) - sum[x]) +
                                ((1 << j) - (sum[y] - sum[x])) + f(n - sum[y]));
            if ((1 << i) + (1 << j) > n) {
                break;
            }
        }
        if (1 << i > n) {
            break;
        }
    }
    cout << result << '\n';
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}