#include <bits/stdc++.h>

using namespace std;
int n, t[200005];
void solve() {
    cin >> n;
    for (int i=1; i<n; i++) cin >> t[i];
    for (int i=1; i<=n; i++) {
        if (i==1) cout << t[1] << " ";
        else if (i==n) cout << t[n-1] << " ";
        else cout << min(t[i], t[i-1]) << " ";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}