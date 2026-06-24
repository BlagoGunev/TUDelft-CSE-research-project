#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, nmax = -1, ans = 0; cin >> n;
        vector<int>a(n), b(n);
        for (int &x : a)
            cin >> x, nmax = max(nmax, x);
        int lst = a[n - 1];
        for (int i = n - 1; i > -1; --i) {
            if (a[i] > lst) {
                ++ans;
                lst = a[i];
                if (lst == nmax) 
                    break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}