#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n, s;
        cin >> n >> s;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        
        long long left = 0, right = 1, mx = -1, ll, rr, sum = 0;
        for (; right <= n; right++) {
            sum += arr[right];
            if (s + sum < 0) {
                while(left < right - 1 && s + sum < 0) {
                    left++;
                    sum -= arr[left];
                }
                while(s + sum < 0 && right <= n) {
                    left++;
                    right++;
                    sum += arr[right];
                    sum -= arr[left];
                }
            }

            if (sum + s >= 0 && right - left > mx && right <= n) {
                mx = right - left;
                ll = left + 1;
                rr = right;
            }
        }
        if (mx == -1) {
            cout << -1 << '\n';
        }
        else {
            cout << ll << ' ' << rr << '\n';
        }
    }
    return 0;
}