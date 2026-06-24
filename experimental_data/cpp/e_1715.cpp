#include <iostream>

#include <vector>

#include <queue>

#include <algorithm>



using namespace std;



#define int long long



const int inf = 1e18;

const int inf1 = 1e15;



struct CHT {

    struct Point {

        int x, y;

        Point() {}

        Point(int _x, int _y): x(_x), y(_y) {}

        // 计算k 这里p节点的位置 大于当前的节点 

        double intersect(Point p) {

            double dy = p.y - y;

            double dx = x - p.x;

            return dy / dx;

        }

        // 计算 dis_old[v] + v*v - 2*uv, 

        // 这里k=u x = dis_old[v] + v*v, y = -2*v

        long long operator () (long long k) {

            return k * x + y;

        }

    };



    vector<double> K;

    vector<Point> points;



    void init(Point p) {

        K.push_back(-inf);

        points.push_back(p);

    }



    void addLine(Point p) {

        // 存在 K[yz] <= k[xy]的情况 z = p, y = points[sz-1], x = points[sz-2]

        // 此时丢弃中间节点y 

        while (points.size() >= 2 && p.intersect(points[points.size() - 1]) <= K.back()) {

            K.pop_back();

            points.pop_back();

        }

        if (!points.empty()) {

            K.push_back(p.intersect(points.back()));

        }

        points.push_back(p);

    }



    long long query(long long qk) {

        // 从递增的K序列中，找到最后一个 <= qk 的k[xp]对应的 p节点 

        int id = upper_bound(K.begin(), K.end(), qk) - K.begin();

        --id;

        return points[id](qk);

    }

};

// dijkstra求最短路径 

void dijkstra(vector<vector<pair<int, int>>> &g, vector<int> &dist) {

    const int n = g.size();

    vector<bool> used(n, false);

    priority_queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i) {

        q.push({ -dist[i], i });

    }

    while (!q.empty()) {

        int v = q.top().second;

        q.pop();

        if (used[v]) {

            continue;

        }

        used[v] = true;



        for (auto p : g[v]) {

            int u = p.first;

            int w = p.second;

            if (dist[u] > dist[v] + w) {

                dist[u] = dist[v] + w;

                q.push({ -dist[u], u });

            }

        }

    }

}



int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> g(n);

    for (int i = 0; i < m; ++i) {

        int u, v, w;

        cin >> u >> v >> w;

        --u; --v;

        g[u].push_back({ v, w });

        g[v].push_back({ u, w });

    }

    vector<int> dist(n, inf1);

    dist[0] = 0;

    dijkstra(g, dist);// 计算不做航班的dist 

    for (int i = 0; i < k; ++i) {

        // 计算坐了 i+1次 航班的dist 

        CHT cht;

        cht.init(CHT::Point(0, 0));

        for (int i = 1; i < n; ++i) {

            cht.addLine(CHT::Point(-i * 2, dist[i] + i * i));

        }

        for (int i = 0; i < n; ++i) {

            dist[i] = cht.query(i) + i * i;

        }

        // 用新的dist计算最短路径 

        dijkstra(g, dist);

    }

    for (int i : dist) {

        cout << i << ' ';

    }

}