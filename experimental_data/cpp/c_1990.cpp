#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int sum = 0;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        int b[n];
        map<int, int> mp;
        int mad = 0;
        for (int i = 0; i < n; i++) {
            mp[a[i]]++;
            if (mp[a[i]] > 1 && a[i] > mad) mad = a[i];
            b[i] = mad;
            sum += b[i];
        }

        mp.clear();
        mad = 0;
        for (int i = 0; i < n; i++) {
            mp[b[i]]++;
            if (mp[b[i]] > 1 && b[i] > mad) mad = b[i];
            b[i] = mad;
        }

        int cnt = 1;
        for (int i = n - 1; i >= 0; i--) {
            sum += b[i] * cnt;
            cnt++;
        }

        cout << sum << '\n';
    }

    return 0;
}