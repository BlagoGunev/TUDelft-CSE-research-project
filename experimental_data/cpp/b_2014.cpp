#include <bits/stdc++.h>
using namespace std;

signed main(){
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        int ans;
        
        if (n < k) {
            ans = n * (n + 1) / 2;
        } else {
            ans = (n * (n + 1) / 2) - ((n - k) * (n - k + 1) / 2);
        }

        if (ans % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}