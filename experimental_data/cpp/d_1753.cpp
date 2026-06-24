#include<bits/stdc++.h>

#define ll long long

#define ld long double

#define fi first

#define se second

#define pii pair<int, int>

#define pll pair<long long, long long>

using namespace std;



const ll MAX = 1e18;

//vector<pii> smjer1 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

//vector<pii> smjer2 = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    int n, m;

    ll p, q;

    cin >> n >> m >> p >> q;



    vector<vector<char>> mat(n, vector<char> (m));

    vector<vector<ll>> dist(n, vector<ll> (m));

    priority_queue<pair<ll, pii>> pq;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> mat[i][j];

            if (mat[i][j] == '.') pq.push({0, {i, j}});

            else dist[i][j] = MAX;

        }

    }



    while(!pq.empty()) {

        ll d = -pq.top().fi;

        int x = pq.top().se.fi;

        int y = pq.top().se.se;

        pq.pop();

        if (d > dist[x][y]) continue;

        if (y >= 2 && mat[x][y - 2] == 'L' && d + q < dist[x][y - 2]) {

            dist[x][y - 2] = d + q;

            pq.push({-dist[x][y - 2], {x, y - 2}});

        }



        if (y < m - 2 && mat[x][y + 2] == 'R' && d + q < dist[x][y + 2]) {

            dist[x][y + 2] = d + q;

            pq.push({-dist[x][y + 2], {x, y + 2}});

        }



        if (x >= 2 && mat[x - 2][y] == 'U' && d + q < dist[x - 2][y]) {

            dist[x - 2][y] = d + q;

            pq.push({-dist[x - 2][y], {x - 2, y}});

        }



        if (x < n - 2 && mat[x + 2][y] == 'D' && d + q < dist[x + 2][y]) {

            dist[x + 2][y] = d + q;

            pq.push({-dist[x + 2][y], {x + 2, y}});

        }



        if (x >= 1 && y >= 1 && (mat[x - 1][y - 1] == 'L' || mat[x - 1][y - 1] == 'U') && d + p < dist[x - 1][y - 1]) {

            dist[x - 1][y - 1] = d + p;

            pq.push({-dist[x - 1][y - 1], {x - 1, y - 1}});

        }



        if (x >= 1 && y < m - 1 && (mat[x - 1][y + 1] == 'R' || mat[x - 1][y + 1] == 'U') && d + p < dist[x - 1][y + 1]) {

            dist[x - 1][y + 1] = d + p;

            pq.push({-dist[x - 1][y + 1], {x - 1, y + 1}});

        }



        if (x < n - 1 && y >= 1 && (mat[x + 1][y - 1] == 'L' || mat[x + 1][y - 1] == 'D') && d + p < dist[x + 1][y - 1]) {

            dist[x + 1][y - 1] = d + p;

            pq.push({-dist[x + 1][y - 1], {x + 1, y - 1}});

        }



        if (x < n - 1 && y < m - 1 && (mat[x + 1][y + 1] == 'R' || mat[x + 1][y + 1] == 'D') && d + p < dist[x + 1][y + 1]) {

            dist[x + 1][y + 1] = d + p;

            pq.push({-dist[x + 1][y + 1], {x + 1, y + 1}});

        }



//        for (int i = 0; i < 4; i++) {

//            int x2 = x + smjer1[i].fi;

//            int y2 = y + smjer1[i].se;

//            int x3 = x + 2 * smjer1[i].fi;

//            int y3 = y + 2 * smjer1[i].se;

//            if (x3 >= n || x3 < 0 || y3 >= m || y3 < 0) continue;

//            if (mat[x2][y2] == '#' || mat[x3][y3] == '#') continue;

//            if (d + q >= dist[x3][y3]) continue;

//            dist[x3][y3] = d + q;

//            pq.push({-dist[x3][y3], {x3, y3}});

//        }

//

//        for (int i = 0; i < 4; i++) {

//            int x2 = x + smjer2[i].fi;

//            int y2 = y;

//            int x3 = x;

//            int y3 = y + smjer2[i].se;

//            int x4 = x + smjer2[i].fi;

//            int y4 = y + smjer2[i].se;

//            if (x4 >= n || x4 < 0 || y4 >= m || y4 < 0) continue;

//            if (mat[x2][y2] == '#' && mat[x3][y3] == '#') continue;

//            if (mat[x4][y4] == '#') continue;

//            if (d + p >= dist[x4][y4]) continue;

//            dist[x4][y4] = d + p;

//            pq.push({-dist[x4][y4], {x4, y4}});

//        }

    }



    ll sol = MAX;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

//            cout << dist[i][j] << " ";

            if (i < n - 1) sol = min(sol, dist[i][j] + dist[i + 1][j]);

            if (j < m - 1) sol = min(sol, dist[i][j] + dist[i][j + 1]);

        }

//        cout << endl;

    }



    if (sol == MAX) sol = -1;

    cout << sol << "\n";

    return 0;

}