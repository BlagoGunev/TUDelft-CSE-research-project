#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long max1 = INT_MIN, max2 = INT_MIN;
        long long min1 = INT_MAX, min2 = INT_MAX;
         long long prod1;
              long long prod2,ans;
        if(n==2){
           cout<< a[0]*a[1]<<endl;
        }else{
        for (int i = 0; i < n; i++) {
            if (a[i] > max1) {
                max2 = max1;
                max1 = a[i];
            } else if (a[i] > max2) {
                max2 = a[i];
            }
            
            if (a[i] < min1 && a[i] < 0) {
                min2 = min1;
                min1 = a[i];
            } else if (a[i] < min2 && a[i] < 0) {
                min2 = a[i];
            }
        }
        if(max1>0&&max2>0){
         prod1 = max1 * max2;
        }
        else {prod1=0;}
        if(min1<0&&min2<0){
          prod2 = min1 * min2;
        }
        else {prod2=0;}
        ans = max(prod1, prod2);
        cout << ans << endl;
    }
    }
    return 0;
}