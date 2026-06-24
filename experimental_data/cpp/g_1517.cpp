#include <vector>
#include <queue>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

namespace solve
{
    const int inf = 1e9;
    const double eps = 1e-8;
    typedef long long ll;

    const int maxn = 1010;

    template <typename T>
    struct Dinic
    {
        static const int maxn = 2010;
        struct edge
        {
            int x, y;
            T cap, flow;
            T now_flow() { return cap - flow; }
        };

        vector<edge> edges;
        vector<int> e[maxn];

        int mx;

        inline int add(int x, int y, T cap)
        {
            // cerr << "?" << x << " " << y << " " << cap << endl;
            edges.push_back({x, y, cap, 0});
            edges.push_back({y, x, 0, 0});
            int m = edges.size();
            e[x].push_back(m - 2), e[y].push_back(m - 1);
            mx = max({mx, x, y});
            return m - 2;
        }

        int cur[maxn], vis[maxn], s, t, dis[maxn];

        bool bfs()
        {
            fill(vis, vis + mx + 1, 0);
            dis[s] = 0, vis[s] = 1;
            queue<int> q;
            q.push(s);
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for (int i : e[x])
                {
                    auto &k = edges[i];
                    if (!vis[k.y] && k.cap - k.flow > 0)
                    {
                        dis[k.y] = dis[x] + 1;
                        vis[k.y] = 1, q.push(k.y);
                    }
                }
            }
            return vis[t];
        }

        T dfs(int x, T lim)
        {
            if (x == t || lim == 0)
                return lim;
            T res = 0, f;
            for (int &i = cur[x]; i < (int)e[x].size(); i++)
            {
                auto &k = edges[e[x][i]];
                if (dis[x] + 1 != dis[k.y] || (f = dfs(k.y, min(lim, k.cap - k.flow))) == 0)
                    continue;
                res += f, lim -= f, k.flow += f, edges[e[x][i] ^ 1].flow -= f;
                if (lim == 0)
                    break;
            }
            return res;
        }

        T dinic(int s_, int t_)
        {
            s = s_, t = t_;
            T res = 0;
            while (bfs())
                fill(cur, cur + mx + 1, 0), res += dfs(s, inf);
            return res;
        }

        void clear()
        {
            mx = 0;
            for (int i = 0; i <= mx; i++)
                e[i].clear();
            edges.clear();
        }

        Dinic() { clear(); }
    };

    int n;

    Dinic<ll> G;
    ll sum;

    int x[maxn], y[maxn], w[maxn];

    inline int get(int x) { return (x % 2 + 2) % 2; }

    void main()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i] >> w[i], sum += w[i];
        int S = n * 2 + 1, T = S + 1;
        for (int i = 1; i <= n; i++)
            G.add(i, i + n, w[i]);
        for (int i = 1; i <= n; i++)
            if (get(x[i]) == 1 && get(y[i]) == 1)
            {
                G.add(S, i, inf);
                for (int j = 1; j <= n; j++)
                    if (i != j)
                        if (get(x[j]) == 0 && get(y[j]) == 1 && abs(x[j] - x[i]) == 1 && y[i] == y[j])
                            G.add(i + n, j, inf);
            }
        for (int i = 1; i <= n; i++)
            if (get(x[i]) == 0 && get(y[i]) == 1)
                for (int j = 1; j <= n; j++)
                    if (i != j)
                        if (get(x[j]) == 0 && get(y[j]) == 0 && abs(y[i] - y[j]) == 1 && x[i] == x[j])
                            G.add(i + n, j, inf);
        for (int i = 1; i <= n; i++)
            if (get(x[i]) == 0 && get(y[i]) == 0)
                for (int j = 1; j <= n; j++)
                    if (i != j)
                        if (get(x[j]) == 1 && get(y[j]) == 0 && abs(x[i] - x[j]) == 1 && y[i] == y[j])
                            G.add(i + n, j, inf);
        for (int i = 1; i <= n; i++)
            if (get(x[i]) == 1 && get(y[i]) == 0)
                G.add(i + n, T, inf);    
        cout << sum - G.dinic(S, T) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve::main();
}