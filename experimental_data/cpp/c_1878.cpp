#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k, x , c = 0, sum = 0;
        cin >> n >> k >> x;
        ll minSum = k * (k + 1) / 2;
        ll maxSum = k*(2*n - k + 1) / 2;
        if (minSum > x || maxSum < x) {
            cout << "NO" << endl;
        }else {
            cout << "YES" << endl;
        }
    }
}