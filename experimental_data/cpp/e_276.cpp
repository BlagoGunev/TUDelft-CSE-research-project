#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define lowbit(x) ((x) & (-(x)))

using namespace std;

class tree
{
public:
    vector<int> s;
    void modify(int p, int v)
    {
        if(!p) return;
        for(; p < s.size(); p += lowbit(p))
            s[p] += v;
    }
    int query(int p)
    {
        int ret = 0;
        for(; p; p -= lowbit(p))
            ret += s[p];
        return ret;
    }
};

tree seg[110000], all;
int mapping[110000], belong[110000], tot, rootsum = 0, size[110000];
queue<int> q;
bool vis[110000];

class Graph
{
public:
    int head[110000], Next[110000 * 2], No[110000 * 2], tot;
    Graph()
    {
        tot = 1, memset(head, 0, sizeof head);
    }
    void add(int x, int y)
    {
        Next[tot] = head[x];
        head[x] = tot;
        No[tot++] = y;
    }
}G;

void bfs()
{
    q.push(1);
    mapping[1] = 0;
    vis[1] = true;
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        vis[cur] = true;
        for(int i = G.head[cur]; i; i = G.Next[i])
        {
            int y = G.No[i];
            if(vis[y]) continue;
            q.push(y);
            mapping[y] = mapping[cur] + 1;
            if(cur == 1) belong[y] = y;
            else belong[y] = belong[cur];
            size[belong[y]]++;
        }
    }
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n - 1; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        G.add(x, y), G.add(y, x);
    }
    all.s.resize(4 * n);
    bfs();
    for(int i = 2; i <= n; ++i)
    {
        if(belong[i] == i)
            seg[belong[i]].s.resize(size[belong[i]] * 8);
    }
    for(int i = 0; i < q; ++i)
    {
        int ty, v;
        scanf("%d%d", &ty, &v);
        if(!ty)
        {
            int x, d;
            scanf("%d%d", &x, &d);
            if(d < mapping[v])
            {
                seg[belong[v]].modify(mapping[v] - d, x);
                seg[belong[v]].modify(min(mapping[v] + d + 1, size[belong[v]] + 1), -x);
            }
            else
            {
                rootsum += x;
                seg[belong[v]].modify(min(mapping[v] + d + 1, size[belong[v]] + 1), -x);
                all.modify(1, x);
                all.modify(d - mapping[v] + 1, -x);
                if(d - mapping[v] < mapping[v] + d)
                {
                    seg[belong[v]].modify(d - mapping[v] + 1, x);
                }
            }
        }
        else
        {
            if(v == 1)
            {
                printf("%d\n", rootsum);
            }
            else
            {
                printf("%d\n", seg[belong[v]].query(mapping[v]) + all.query(mapping[v]));
            }
        }
    }
    return 0;
}