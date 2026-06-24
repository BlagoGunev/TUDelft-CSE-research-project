#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 5e5+5;

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int surplus = INT_MAX;
        vector<int> want;
        for (int i = 0; i < n; i++) {
            if (a[i] >= b[i]) surplus=min(surplus, a[i]-b[i]);
            else want.push_back(b[i]-a[i]);
        }

        if (want.size() == 0) cout << "YES\n";
        else if (want.size() > 1) cout << "NO\n";
        else {
            if (want[0] <= surplus) cout << "YES\n";
            else cout << "NO\n";
        }

    }

    return 0;
}