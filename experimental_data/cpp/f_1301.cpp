#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <random>



using namespace std;

using namespace __gnu_pbds;



typedef long long ll;

typedef unsigned long long ull;

typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define AboTaha_on_da_code ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define X first

#define Y second



const int dx[8]={0, 0, 1, -1, 1, -1, -1, 1}, dy[8]={1, -1, 0, 0, 1, -1, 1, -1};

const int M = 1e9+7, M2 = 998244353;

const double EPS = 1e-9;



void burn(int tc)

{

    int n, m, k; cin >> n >> m >> k;

    vector <vector <int>> grid(n, vector <int> (m));

    vector <vector <pair<int, int>>> col(k);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> grid[i][j], grid[i][j]--;

            col[grid[i][j]].emplace_back(i, j);

        }

    }

    vector <vector <vector <int>>> dist(k, vector <vector <int>> (n, vector <int> (m, -1)));

    for (int c = 0; c < k; c++) {

        queue <pair<int, int>> q;

        for (auto [x, y] : col[c]) {

            q.push({x, y});

            dist[c][x][y] = 0;

        }

        vector <bool> vis(k, false);

        vis[c] = true;

        while(!q.empty()) {

            auto [x, y] = q.front();

            q.pop();

            if (!vis[grid[x][y]]) {

                vis[grid[x][y]] = true;

                for (auto[nx, ny]: col[grid[x][y]]) {

                    if (!~dist[c][nx][ny]) {

                        dist[c][nx][ny] = dist[c][x][y] + 1;

                        q.push({nx, ny});

                    }

                }

            }

            for (int i = 0; i < 4; i++) {

                int nx = x+dx[i], ny = y+dy[i];

                if (~nx && ~ny && nx < n && ny < m && !~dist[c][nx][ny]) {

                    dist[c][nx][ny] = dist[c][x][y]+1;

                    q.push({nx, ny});

                }

            }

        }

    }

    int q; cin >> q;

    while(q--) {

        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        x1--, y1--, x2--, y2--;

        int dis = abs(x1-x2)+abs(y1-y2);

        for (int i = 0; i < k; i++) {

            dis = min(dis, 1+dist[i][x1][y1]+dist[i][x2][y2]);

        }

        cout << dis << '\n';

    }

}



int main()

{

    AboTaha_on_da_code



//    freopen("Ain.txt", "r", stdin);

//    freopen("Aout.txt", "w", stdout);



    int T = 1; // cin >> T;



    for (int i = 1; i <= T; i++) {

//        cout << "Case #" << i << ": ";

        burn(i);

//        cout << '\n';

    }

    return 0;

}