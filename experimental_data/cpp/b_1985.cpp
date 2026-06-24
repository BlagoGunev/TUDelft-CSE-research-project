#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
const int N = 2e5+5, M = 1e9+7;

void solve() {
    int n;
    cin >> n;
    int mx = 0, ans = n;
    for (int i = 2; i <= n; i++) {
        int sm = 0;
        for (int j = i; j <= n; j += i)sm += j;
        if (sm > mx) {
            mx = sm;
            ans = i;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
}