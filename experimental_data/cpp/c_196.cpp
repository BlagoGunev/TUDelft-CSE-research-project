#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> my[1600];

int xx = 0, yy = 0;

struct ww
{
    int x, y, id;
    bool operator < (const ww &o) const
    {
        if (x - xx >= 0 && o.x - xx <= 0) {
            return true;
        }
        if (x - xx <= 0 && o.x - xx >= 0) {
            return false;
        }
        return (y - yy) * (long long)(o.x - xx) < (o.y - yy) * (long long)(x - xx);
        //return atan2(y - yy, x - xx) < atan2(o.y - yy, o.x - xx);
    }
} z[1600];

bool u[1600] = { 0 };
int a[1600] = { 0 };
int our[1600] = { 0 };

int dfs(int x)
{
    u[x] = true;
    a[x] = 1;
    int s = my[x].size(), i = 0, y = 0;
    for (i = 0; i < s; i ++) {
        y = my[x][i];
        if (!u[y]) {
            a[x] += dfs(y);
        }
    }
    return a[x];
}



void tt(int x, int p, int q)
{
    u[x] = true;

    int s = my[x].size(), i = 0, y = 0, t = p, now = 0;
    
    for (i = p + 1; i <= q; i ++) {
        if (z[i].y < z[t].y || z[i].y == z[t].y && z[i].x < z[t].x) {
            t = i;
        }
    }
    if (t != p) {
        swap(z[t], z[p]);
    }
    
    our[z[p].id] = x;
    
    xx = z[p].x;
    yy = z[p].y;
    
    //if (p < q) {
        sort(z + p + 1, z + q + 1);
    //}
    now = p + 1;
    for (i = 0; i < s; i ++) {
        y = my[x][i];
        if (!u[y]) {
            tt(y, now, now + a[y] - 1);
            now += a[y];
        }
    }
}

int main()
{
    int i = 0, n = 0, p = 0, q = 0;
    while (scanf("%d", &n) == 1) {
        for (i = 1; i <= n; i ++) {
            my[i].clear();
        }
        for (i = 1; i <= n - 1; i ++) {
            scanf("%d%d", &p, &q);
            my[p].push_back(q);
            my[q].push_back(p);
        }
        for (i = 1; i <= n; i ++) {
            scanf("%d%d", &z[i].x, &z[i].y);
            z[i].id = i;
        }
        memset(u, 0, sizeof(u));
        dfs(1);
        memset(u, 0, sizeof(u));
        tt(1, 1, n);
        for (i = 1; i <= n; i ++) {
            printf("%d", our[i]);
            if (i < n) {
                printf(" ");
            }
            else {
                printf("\n");
            }
        }
    }
    return 0;
}