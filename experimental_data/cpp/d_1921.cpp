#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5 + 5e2;

ll n, m, a[N], b[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) cin >> b[j];
    sort(a + 1, a + n + 1); sort(b + 1, b + m + 1);
    ll ans = 0;
    int la = 1, ra = n, lb = 1, rb = m;
    while (la <= ra) {
        if (abs(a[la] - b[rb]) >= abs(a[ra] - b[lb])) {
            ans += abs(a[la++] - b[rb--]);
        } else {
            ans += abs(a[ra--] - b[lb++]);
        }
    }
    cout << ans << endl;
}

int main() {
    int Case;
    cin >> Case;
    while (Case--) {
        solve();
    }
    return 0;
}