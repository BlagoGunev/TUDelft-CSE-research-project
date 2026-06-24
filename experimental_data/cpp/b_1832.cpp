#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        long long int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum+= a[i];
        }
        sort(a, a+n);
        int i = 0, j = n-1;
        long long int lps[n];
        lps[0] = a[0];
        long long int rps[n];
        rps[n-1] = a[n-1];
        for(int i = 1; i < n; i++) {
            lps[i] = lps[i-1] + a[i];
        }
        for(int i = n-2; i >= 0; i--) {
            rps[i] = rps[i+1] + a[i];
        }
        long long int mini = 9223372036854775807;
        long long int temp = 0;
        for(int i = 0; i <= k; i++) {
            if(i == k) {
                temp = lps[2*i-1];
            }
            else if(i == 0) {
                temp = rps[n-k];
            }
            else {
                temp = lps[2*i-1]+rps[n-(k-i)];
            }
            mini = min(mini, temp);
        }
        cout << sum - mini << endl;
    }
    return 0;
}