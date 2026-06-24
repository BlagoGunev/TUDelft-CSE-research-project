#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define dbl double
#define mod 1000000007

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    
    int ans = 0;
    for(auto &[f, s] : mp) {
        ans += s / 2;
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt = 1; 
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}