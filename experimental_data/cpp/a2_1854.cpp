#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

int a[22];

void solve() {
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    
    int pl = 0, mn = 0, ma = 1;
    for(int i=1;i<=n;i++) {
        if(a[i] > 0) pl++;
        if(a[i] < 0) mn++;
        
        if(abs(a[i]) > abs(a[ma])) ma = i;
    }
    
    if(a[ma] == 0) {
        cout << "0\n";
        return;
    }
    
    if(a[ma] > 0) {
        if(mn <= 12) {
            cout << n-1+mn << "\n";
            for(int i=1;i<=n;i++) {
                if(a[i] < 0) cout << i << " " << ma << "\n";
            }
            for(int i=2;i<=n;i++) cout << i << " " << i-1 << "\n";
        } else {
            int j = 0;
            for(int i=1;i<=n;i++) {
                if(a[i] < 0) {
                    j = i;
                    break;
                }
            }
            cout << n+pl+4 << "\n";
            for(int i=1;i<=5;i++) cout << j << " " << j << "\n";
            for(int i=1;i<=n;i++) {
                if(a[i] > 0) cout << i << " " << j << "\n";
            }
            for(int i=n-1;i>=1;i--) cout << i << " " << i+1 << "\n";
        }
    } else {
        if(pl <= 12) {
            cout << n-1+pl << "\n";
            for(int i=1;i<=n;i++) {
                if(a[i] > 0) cout << i << " " << ma << "\n";
            }
            for(int i=n-1;i>=1;i--) cout << i << " " << i+1 << "\n";
        } else {
            int j = 0;
            for(int i=1;i<=n;i++) {
                if(a[i] > 0) {
                    j = i;
                    break;
                }
            }
            cout << n+mn+4 << "\n";
            for(int i=1;i<=5;i++) cout << j << " " << j << "\n";
            for(int i=1;i<=n;i++) {
                if(a[i] < 0) cout << i << " " << j << "\n";
            }
            for(int i=2;i<=n;i++) cout << i << " " << i-1 << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}