#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int zero = 0, i = 0;
    long long ans = 0;
    while (a[i] == 0) {
        zero++;
        i++;
    }
    while (i < n) {
        int k = 1; i++;
        while (i < n && a[i - 1] == a[i]) {
            k++;
            i++;
        }
        ans += min(k, zero);
        while (i < n && a[i] == 0) {
            zero++;
            i++;
        }
    }
    cout << ans;
}