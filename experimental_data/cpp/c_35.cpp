#include <cstdio>
#include <cstring>
#include <iostream>

bool g[2005][2005];

int dx[4] = {1, 0, -1,0};
int dy[4] = {0, 1, 0,-1};
struct p
{
    int x, y;
    int step;
}queue[2000 * 2000 + 5];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int n,m;
    scanf("%d %d", &n , &m);
    int k;
    scanf("%d", &k);
    int head = 0, tail = 0;
    for (int i = 0; i < k; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][v] = true;
        queue[tail].x = u;
        queue[tail].y = v;
        queue[tail++].step = 0;
    }
//printf("!!");
    while(head != tail)
    {
        for (int l = 0; l < 4; ++l)
        {
            int xx = queue[head].x + dx[l];
            int yy = queue[head].y + dy[l];
            if (xx > 0 && yy > 0 && xx <= n && yy <= m && !g[xx][yy])
            {
                g[xx][yy] = true;
                queue[tail].x = xx;
                queue[tail].y = yy;
                queue[tail++].step = queue[head].step + 1;
            }
        }
        head++;
    }
    printf("%d %d\n", queue[tail-1].x, queue[tail-1].y);
    return 0;
}