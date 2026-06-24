#include<bits/stdc++.h>
using namespace std;
int n, demons[1005], updatedDemons[1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> demons[i];
    }
    
    while (!demons[n]) {
        n--;
    }
    
    int ans = 1e9, mnp = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            updatedDemons[j] = max(0, demons[j] - (j >= i));
        }
        
        int sum = -i;
        for (int j = 1; j <= n; j++) {
            sum += 3 * updatedDemons[j] + 2 * max(updatedDemons[j] - updatedDemons[j - 1], 0);
        }
        
        if (sum < ans) {
            ans = sum;
            mnp = i;
        }
    }
    
    for (int j = mnp; j <= n; j++) {
        demons[j] = max(demons[j] - 1, 0);
    }
    
    for (int i = 1; i <= n; i++) {
        while (demons[i]) {
            cout << "ARA";
            int j = i;
            while (demons[j + 1]) {
                j++;
                cout << "RA";
            }
            for (int k = j; k >= i; k--) {
                cout << "L";
                demons[k] = max(demons[k] - 1, 0);
            }
            cout << "A";
        }
        cout << "AR";
    }
    
    cout << "A";
    
    for (int j = n; j >= mnp; j--) {
        cout << "L";
    }
    
    cout << "A";
    
    return 0;
}