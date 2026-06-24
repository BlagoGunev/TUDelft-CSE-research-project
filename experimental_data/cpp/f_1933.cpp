#include <iostream>
#include <deque>
#include <vector>

#define pii pair<int, int>

using namespace std;

const int INF = 0x3f3f3f3f;

int T;

int n;
int m;

int a[1010][1010];
int dis[1010][1010];

vector<pii> NxtPoint(pii p) {
    vector<pii> res;
    auto& [x, y] = p;
    if (a[(x + 1) % n][y] == 0 && a[(x + 2) % n][y] == 0) {
        res.push_back({ (x + 2) % n, y });
    }
    if (y < m - 1 && a[(x + 1) % n][y + 1] == 0) {
        res.push_back({ (x + 1) % n, y + 1 });
    }
    return res;
}

void Bfs() {
    deque<pii> que = { {0, 0} };
    pii solo;
    int curDis;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dis[i][j] = INF;
        }
    }
    dis[0][0] = 0;
    while (que.size()) {
        solo = que.front();
        que.pop_front();
        curDis = dis[solo.first][solo.second] + 1;
        for (auto& [x, y] : NxtPoint(solo)) {
            if (dis[x][y] == INF) {
                dis[x][y] = curDis;
                que.push_back({ x, y });
            }
        }
    }
}

int DisRes(int x, int d) {
    int p = (n - 1 + d) % n;
    return d + min((x - p + n) % n, (p - x + n) % n);
}

void Solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    Bfs();
    int res = INF;
    for (int i = 0; i < n; i++) {
        res = min(res, DisRes(i, dis[i][m - 1]));
    }
    if (res == INF) {
        cout << "-1\n";
        return;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;while (T--) {
        Solve();
    }
    return 0;
}