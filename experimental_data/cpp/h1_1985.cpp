#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for (string &i : g)
        cin >> i;

    vector<int> sx(n), sy(m);

    vector<vector<bool>> vis(n, vector<bool> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.' || vis[i][j])
                continue;

            queue<array<int, 2>> q;
            q.push({i, j});
            vis[i][j] = 1;

            set<int> s, t;
            int cnt = 0;

            while (q.size()) {
                auto [r, c] = q.front();
                q.pop();

                cnt++;
                s.insert(r);
                t.insert(c);

                for (int d = 0; d < 4; d++) {
                    int nr = r + dx[d], nc = c + dy[d];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        if (g[nr][nc] == '#' && !vis[nr][nc]) {
                            vis[nr][nc] = 1;
                            q.push({nr, nc});
                        }
                        else if (g[nr][nc] == '.') {
                            s.insert(nr);
                            t.insert(nc);
                        }
                    }
                }
            }

            for (int x : s)
                sx[x] += cnt;
            for (int y : t)
                sy[y] += cnt;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.')
                sx[i]++, sy[j]++;
        }
    }

    cout << max(*max_element(all(sx)), *max_element(all(sy))) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    
    while (t--)
        solve();

    return 0;
}