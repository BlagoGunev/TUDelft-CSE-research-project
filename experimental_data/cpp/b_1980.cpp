#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, f, k;
        cin >> n >> f >> k;
        vector<int> a(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        int fav_value = a[f - 1];
        vector<int> tt = a;
        sort(a.rbegin(), a.rend());

        int cnt = count(tt.begin(), tt.end(), fav_value);
        int ct = 0;

        for (int i = 0; i < k; ++i) {
            if (a[i] == fav_value) {
                ct++;
            }
        }

        if (ct == cnt) {
            cout << "YES" << endl;
        } else if (ct == 0) {
            cout << "NO" << endl;
        } else {
            cout << "MAYBE" << endl;
        }
    }

    return 0;
}