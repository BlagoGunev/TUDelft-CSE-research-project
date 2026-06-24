#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for (int i = n - 2; i >= 0; i--) {
            a[i] = max(a[i], a[i + 1] + 1);
        }
        
        cout << a[0] << endl;
    }
}