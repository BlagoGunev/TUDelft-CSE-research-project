#include <cstdio>
#include <vector>
#include <queue>

#define N 1000005

using namespace std;

int n,k,d[N],f[N],p[N],h[N];
vector <int> a[N];

void dfs(int u)
{
    if ((int)a[u].size() == 0)
    {
        d[u] = f[u] = 1;
        p[u] = h[u];
        return;
    }
    int tmp = 0;
    p[u] = n;
    for (int i = 0; i < (int)a[u].size(); i++)
    {
        int v = a[u][i];
        h[v] = h[u] + 1;
        dfs(v);
        if (p[v] - h[u] <= k)
        {
            p[u] = min(p[u],p[v]);
            d[u] += d[v];
        }
    }
    for (int i = 0 ; i < (int)a[u].size(); i++)
    {
        int v = a[u][i];
        if (p[v] - h[u] <= k) f[u] = max(f[u],d[u] - d[v] + f[v]); else f[u] = max(f[u],d[u] + f[v]);
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 2; i <= n; i++)
    {
        int x;
        scanf("%d",&x);
        a[x].push_back(i);
    }
    dfs(1);
    printf("%d",max(d[1],f[1]));
    return 0;
}