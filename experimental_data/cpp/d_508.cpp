#include <bits/stdc++.h>
using namespace std;

struct DisjointSets
{
    vector<int> representatives;

    DisjointSets(const int N) : representatives(N)
    {
        iota(begin(representatives), end(representatives), 0);
    }

    int find(const int a)
    {
        if (representatives[a] != a)
            representatives[a] = find(representatives[a]);
        return representatives[a];
    }

    void merge(const int a, const int b) { representatives[find(a)] = find(b); }
};

struct Graph
{
    int N;
    struct Edge { int source, target; };
    vector<Edge> edges;
    vector<vector<int>> adjacency_list;
    vector<int> out_degrees, in_degrees;

    Graph(const int N) : N(N), adjacency_list(N), out_degrees(N), in_degrees(N) {}

    void add_edge(const int a, const int b)
    {
        edges.push_back({a, b});
        adjacency_list[a].push_back(b);
        out_degrees[a]++;
        in_degrees[b]++;
    }

    bool has_eulerian_path() const
    {
        auto components = DisjointSets(N);
        for (const auto e : edges)
            components.merge(e.source, e.target);

        auto non_isolated_vertices = vector<int>();
        for (auto v = 0; v < N; v++) if (in_degrees[v] > 0 || out_degrees[v] > 0)
            non_isolated_vertices.push_back(v);

        auto is_weakly_connected = true;
        for (const auto v : non_isolated_vertices)
            is_weakly_connected &= components.find(v) == components.find(non_isolated_vertices[0]);

        if (!is_weakly_connected) return false;

        auto starts = 0, finishes = 0, balanced_count = 0;
        for (auto v = 0; v < N; v++)
        {
            if (in_degrees[v] == out_degrees[v]) balanced_count++;
            if (out_degrees[v] == in_degrees[v]+1) starts++;
            if (in_degrees[v] == out_degrees[v]+1) finishes++;
        }

        return balanced_count == N || (starts == 1 && finishes == 1 && balanced_count == N-2);
    }

    vector<int> eulerian_path() const
    {

        auto start = 0;
        for (auto v = 0; v < N; v++)
            if (in_degrees[v] > 0 || out_degrees[v] > 0)
                start = v;
        for (auto v = 0; v < N; v++)
            if (out_degrees[v] == in_degrees[v]+1)
                start = v;

        auto path = deque<int>();
        auto next = vector<int>(N);
        const function<void(int)> dfs = [&](const int v)
        {
            while (next[v] < out_degrees[v])
                dfs(adjacency_list[v][next[v]++]);
            path.push_front(v);
        };
        dfs(start);

        return vector<int>(begin(path), end(path));
    }
};

int main()
{
    ios::sync_with_stdio(false);

    int n; cin >> n;

    auto graph = Graph(256*256);

    for (auto i = 0; i < n; i++)
    {
        string s; cin >> s;
        graph.add_edge(s[0]*256 + s[1], s[1]*256 + s[2]);
    }

    if (graph.has_eulerian_path())
    {
        cout << "YES" << endl;

        const auto path = graph.eulerian_path();
        auto result = string(1, char(path[0] / 256));
        for (const auto v : path)
            result += char(v % 256);
        cout << result << endl;
    }
    else cout << "NO" << endl;
}