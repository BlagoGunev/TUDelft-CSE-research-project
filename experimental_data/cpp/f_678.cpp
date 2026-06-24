#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Line
{
    int m, b;
    ll evaluate(int x) { return static_cast<ll>(m)*x + b; }
};

struct UpperHull
{
    vector<Line> active;

    void insert(Line l)
    {
        while (active.size() >= 2 && supersedes(active.end()[-2], active.back(), l))
            active.pop_back();
        active.push_back(l);
    }

    bool supersedes(Line l1, Line l2, Line l3)
    {
        return static_cast<ll>(l1.b-l3.b) * (l2.m-l1.m) <= static_cast<ll>(l1.b-l2.b) * (l3.m-l1.m);
    }

    ll query(int x)
    {
        if (active.empty()) return numeric_limits<ll>::min();
        while (active.size() >= 2 && active.back().evaluate(x) <= active.end()[-2].evaluate(x))
            active.pop_back();
        return active.back().evaluate(x);
    }
};

struct SegmentTree
{
    int n;
    vector<UpperHull> data;

    SegmentTree(int n) : n(n), data(vector<UpperHull>(2*n)) {}

    void insert(int a, int b, Line l)
    {
        for (auto i = a+n, j = b+n+1; i < j; i /= 2, j /= 2)
        {
            if (i % 2) data[i++].insert(l);
            if (j % 2) data[--j].insert(l);
        }
    }

    ll query(int a, int x)
    {
        auto result = numeric_limits<ll>::min();
        for (auto i = a+n; i >= 1; i /= 2)
            result = max(result, data[i].query(x));
        return result;
    }
};

struct Event { int start, end; Line line; };
struct Query { int id, x; };

vector<ll> solve(int n, vector<Event> events, vector<Query> queries)
{
    auto tree = SegmentTree(n);
    sort(begin(events), end(events), [](Event a, Event b) { return a.line.m < b.line.m; });
    for (auto event : events)
        tree.insert(event.start, event.end, event.line);

    auto answers = vector<ll>(queries.size());
    sort(begin(queries), end(queries), [](Query a, Query b) { return a.x > b.x; });
    for (auto query : queries)
        answers[query.id] = tree.query(query.id, query.x);
    return answers;
}

int main()
{
    int n; scanf("%d", &n);

    auto events = vector<Event>();
    auto queries = vector<Query>();
    auto ids = vector<int>(n);
    auto nqueries = int{0};
    for (auto time = 0; time < n; time++)
    {
        int type; scanf("%d", &type);
        if (type == 1)
        {
            int m, b; scanf("%d %d", &m, &b);
            ids[time] = static_cast<int>(events.size());
            events.push_back({nqueries, -2, {m, b}});
        }
        else if (type == 2)
        {
            int start_time; scanf("%d", &start_time);
            start_time--;
            events[ids[start_time]].end = nqueries-1;
        }
        else if (type == 3)
        {
            int x; scanf("%d", &x);
            queries.push_back({nqueries++, x});
        }
        else throw invalid_argument("Invalid operation type: " + to_string(type));
    }
    for (auto& event : events) if (event.end == -2)
        event.end = nqueries-1;

    auto answers = solve(nqueries, events, queries);
    for (auto x : answers)
    {
        if (x == numeric_limits<ll>::min()) puts("EMPTY SET");
        else printf("%lld\n", x);
    }
}