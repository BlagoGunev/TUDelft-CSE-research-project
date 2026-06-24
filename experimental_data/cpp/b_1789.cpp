#include <bits/stdc++.h>
using namespace std;
#define int int64_t
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int h=0;
    for(int r=0;r<n/2;r++) {
        if(s[r]!=s[n-r-1]) {
            if(r==0) {
                h++;
            }
            else {
                int k=r-1;
                if(s[k]==s[n-k-1]) {
                    h++;
                }
            }
        }
    }
    if(h>1) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
    cout << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin >> t;
    while(t--) {
        solve();
    }
}