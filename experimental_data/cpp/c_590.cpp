#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <algorithm>
using namespace std;

#define X first
#define Y second

typedef long long LL;

int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char d[1024][1024];
int dist[3][1024][1024];
int g[3][3];
queue <pair<int, int> > q1, q2, q3;

int main() {
    scanf("%d%d\n", &n, &m);
    memset(d, '#', sizeof(d));
    for (int i = 1; i <= n; ++i) {
        scanf("%s", d[i] + 1);
        d[i][m + 1] = '#';
    }
    memset(dist, 63, sizeof(dist));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (d[i][j] == '1') {
                dist[0][i][j] = 0;
                q1.push(make_pair(i, j));
            }
            if (d[i][j] == '2') {
                dist[1][i][j] = 0;
                q2.push(make_pair(i, j));
            }
            if (d[i][j] == '3') {
                dist[2][i][j] = 0;
                q3.push(make_pair(i, j));
            }
        }
    while (!q1.empty()) {
        pair <int, int> now = q1.front();
        q1.pop();
        pair <int, int> nst;
        for (int di = 0; di < 4; ++di) {
            nst = now;
            nst.X += dx[di];
            nst.Y += dy[di];
            if (d[nst.X][nst.Y] != '#' && dist[0][nst.X][nst.Y] > 1000000000) {
                dist[0][nst.X][nst.Y] = dist[0][now.X][now.Y] + 1;
                q1.push(nst);
            }
        }
    }
    while (!q2.empty()) {
        pair <int, int> now = q2.front();
        q2.pop();
        pair <int, int> nst;
        for (int di = 0; di < 4; ++di) {
            nst = now;
            nst.X += dx[di];
            nst.Y += dy[di];
            if (d[nst.X][nst.Y] != '#' && dist[1][nst.X][nst.Y] > 1000000000) {
                dist[1][nst.X][nst.Y] = dist[1][now.X][now.Y] + 1;
                q2.push(nst);
            }
        }
    }
    while (!q3.empty()) {
        pair <int, int> now = q3.front();
        q3.pop();
        pair <int, int> nst;
        for (int di = 0; di < 4; ++di) {
            nst = now;
            nst.X += dx[di];
            nst.Y += dy[di];
            if (d[nst.X][nst.Y] != '#' && dist[2][nst.X][nst.Y] > 1000000000) {
                dist[2][nst.X][nst.Y] = dist[2][now.X][now.Y] + 1;
                q3.push(nst);
            }
        }
    }
    memset(g, 63, sizeof(g));
    LL ans = 1000000000;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (d[i][j] == '1') {
                g[0][1] = g[1][0] = min(g[0][1], dist[1][i][j] - 1);
                g[0][2] = g[2][0] = min(g[0][2], dist[2][i][j] - 1);
            } else if(d[i][j] == '2') {
                g[1][0] = g[0][1] = min(g[1][0], dist[0][i][j] - 1);
                g[1][2] = g[2][1] = min(g[1][2], dist[2][i][j] - 1);
            } else if(d[i][j] == '3') {
                g[2][1] = g[1][2] = min(g[2][1], dist[1][i][j] - 1);
                g[2][0] = g[0][2] = min(g[0][2], dist[0][i][j] - 1);
            } else if(d[i][j] == '.') {
                ans = min(ans, (LL)dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2ll);
            } 
        }
    ans = min(ans, (LL)g[0][1] + g[0][2]);
    ans = min(ans, (LL)g[1][0] + g[1][2]);
    ans = min(ans, (LL)g[2][0] + g[1][2]);
    if (ans >= 1000000000ll)
        ans = -1;
    printf("%d\n", (int)ans);
    return 0;
}