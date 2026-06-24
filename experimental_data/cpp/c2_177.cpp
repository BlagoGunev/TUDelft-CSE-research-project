#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 2000;

int edge[MAXN][MAXN];
int cnt[MAXN];
int dis[MAXN][MAXN];
int disCnt[MAXN];
int label[MAXN];
int n;
int num;

bool calc(const int &u, const int &l)
{
    num++;
    label[u] = l;
    bool flag = true;
    for (int i = 0; i < cnt[u]; i++)
    {
        if ((label[edge[u][i]] == -1) && (!calc(edge[u][i], l)))
        {
            flag = false;
        }
    }
    if (flag)
    {
        for (int i = 0; i < disCnt[u]; i++)
        {
            if (label[dis[u][i]] == l)
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

void init(void)
{
    int m;
    cin >> n >> m;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edge[u][cnt[u]++] = v;
        edge[v][cnt[v]++] = u;
    }
    cin >> m;
    memset(disCnt, 0, sizeof(disCnt));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        dis[u][disCnt[u]++] = v;
        dis[v][disCnt[v]++] = u;
    }
}

void solve(void)
{
    int ans = 0;
    memset(label, 0xff, sizeof(label));
    for (int i = 0; i < n; i++)
    {
        if (label[i] == -1)
        {
            num = 0;
            if (calc(i, i) && (num > ans))
            {
                ans = num;
            }
        }
    }
    cout << ans << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    init();
    solve();
    return 0;
}