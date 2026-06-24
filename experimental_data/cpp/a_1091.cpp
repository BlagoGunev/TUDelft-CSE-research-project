#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3];
    for (auto& x : a) cin >> x;

    int ans = -1;
    for (int i = 0; i < 3; i++) {
        int tmp = a[i];
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;

            int t = a[i] + (j - i);
            if (a[j] < t && (tmp = -1)) break;
            tmp += t;
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}