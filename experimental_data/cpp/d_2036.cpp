#include <bits/stdc++.h>
#define ar array
//#define int long long

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

int dr[4] = { 0, 1, 0, -1};
int dc[4] = { 1, 0, -1, 0};

void solve() {
    int n, m; cin >> n >> m;

    char mat[n+1][m+1];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) cin >> mat[i][j];

    ll ans = 0;
    int T=1, B=n, L=1, R=m;
    bool vis[n+1][m+1];
    memset(vis, 0, sizeof(vis));

    while(true) {
        if((B - T + 1) * (R - L + 1) < 4) break;
        string s = "";

        int x = T, y = L, dir = 0;
        while(true) {
            if(vis[x][y]) break;
            vis[x][y] = 1;
            s += mat[x][y];
            int nx = x + dr[dir], ny = y + dc[dir];
            if(nx < T || nx > B || ny < L || ny > R) dir++;
            nx = x + dr[dir], ny = y + dc[dir];
            x = nx; y = ny;
        }

        s += s[0]; s += s[1]; s += s[2];
        for(int i=0; i+3<s.size(); i++) {
            if(s[i] == '1' && s[i+1] == '5' && s[i+2] == '4' && s[i+3] == '3') ans++;
        }
        T++, L++, R--, B--;
        // cout << s << '\n';
    }

    cout << ans << '\n';
}

signed main() {
    int t = 1; cin >> t;
    while(t--) solve();

    return 0;
}