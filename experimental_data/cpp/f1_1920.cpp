#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define endl '\n'
#define debug(x) cout << __FUNCTION__ << ": " << #x " = " << (x) << endl
using ll = long long;

const int maxn = 3e5 + 10;
const int maxm = 2e6 + 10;
const ll INF = 3e18;
const int mod = 998244353;
int n, m, k;

void kkkyyyhhh() {
    int q;
    cin >> n >> m >> q;
    vector<vector<char>> g(n + 2, vector<char> (m + 2, 2e9));
    vector<vector<int>> mn(n + 1, vector<int> (m + 1, 2e9));
    auto lup = mn, ldown = mn, rup = mn, rdown = mn;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> g[i][j];
    }

    auto deal = [&](vector<vector<int>>& v) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (g[i][j] == 'v') v[i][j] = 0;
                else {
                    v[i][j] = min(v[i - 1][j], v[i][j - 1]) + 1;
                }
            }
        }
    };
    
    deal(lup);
    for (int i = 1; i <= n; i++) {
        reverse(g[i].begin(), g[i].end());
    }
    deal(rup);
    reverse(g.begin(), g.end());
    deal(rdown);
    for (int i = 1; i <= n; i++) {
        reverse(g[i].begin(), g[i].end());
    }
    deal(ldown);
    reverse(g.begin(), g.end());

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mn[i][j] = min({lup[i][j], rup[i][m - j + 1], rdown[n - i + 1][m - j + 1], ldown[n - i + 1][j]});
           // cout << i << " " << j << " " << mn[i][j] << endl;
        }
    }


    int x, y;
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    int ddx[] = {-1, 0, 1, 0, -1, -1, 1, 1}, ddy[] = {0, 1, 0, -1, -1, 1, -1, 1};
    auto check = [&](int mid) {
        vector<vector<int>> can(n + 2, vector<int> (m + 2));
        auto vis = can;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (mn[i][j] >= mid) can[i][j] = 1;
            }
        }
        if (!can[x][y]) return false;
        queue<pair<int, int>> q;
        q.push({x, y});
        can[x][y] = 2;
        while (q.size()) {
            auto nowx = q.front().first, nowy = q.front().second;
          //  if (x == 7 && y == 7 && mid == 1) cout << nowx << " " << nowy << endl;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = nowx + dx[k], ny = nowy + dy[k];
                if (nx <= 0 || nx > n || ny <= 0 || ny > m || !can[nx][ny] || can[nx][ny] == 2 || g[nx][ny] == '#') continue;
                can[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
        queue<pair<int, int>> othq;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (g[i][j] == '#') {
                    othq.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        while (othq.size()) {
            auto nowx = othq.front().first, nowy = othq.front().second;
            othq.pop();
            if (!nowx || nowx == n + 1 || !nowy || nowy == m + 1) return false;
            for (int k = 0; k < 8; k++) {
                int nx = nowx + ddx[k], ny = nowy + ddy[k];
                if (can[nx][ny] == 2 || vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                othq.push({nx, ny});
            }
        }
        return true;
    };

    while (q--) {
        cin >> x >> y;
        int l = 0, r = n + m;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        cout << r << endl;
    }
}       

signed main() {
    IOS;
    int w_ = 1;
  //  cin >> w_;
    while (w_--) kkkyyyhhh();
    return 0;
}