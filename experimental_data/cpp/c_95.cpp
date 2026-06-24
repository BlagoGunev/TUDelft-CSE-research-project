#include <stdio.h>
#include <string.h>

typedef long long LL;

#define MAXN 1100
#define MAXM 1300000
#define INF 1000000000000000LL

struct Edge {
    int v, e;
    Edge *link;
}edge[MAXM], *adj[MAXN];

int totE;
LL dis[MAXN];
bool inQ[MAXN];
int q[MAXN];
int limit[MAXN], cost[MAXN];
LL mp[MAXN][MAXN];

void addEdge(int u, int v, int e) {
    Edge *p = &edge[totE++];
    p->v = v; p->e = e; p->link = adj[u]; adj[u] = p;
}


int main() {
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &x, &y);
    for(int i = 0; i < m; ++i) {
        int u, v, e;
        scanf("%d%d%d", &u, &v, &e);
        addEdge(u, v, e);
        addEdge(v, u, e);
    }
    for(int i = 1; i <= n; ++i) scanf("%d%d", &limit[i], &cost[i]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) mp[i][j] = INF;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) dis[j] = INF;
        memset(inQ, false, sizeof(inQ));
        dis[i] = 0;
        int l = 0, r = 0;
        q[r++] = i;
        inQ[i] = true;
        while(l != r) {
            int u = q[l++];
            inQ[u] = false;
            if(l == MAXN) l = 0;
            Edge *p = adj[u];
            while(p) {
                if(dis[u] + p->e < dis[p->v]) {
                    dis[p->v] = dis[u] + p->e;
                    if(!inQ[p->v]) {
                        inQ[p->v] = true;
                        q[r++] = p->v;
                        if(r == MAXN) r = 0;
                    }
                }
                p = p->link;
            }
        }
        for(int j = 1; j <= n; ++j)
            if(j != i && dis[j] <= limit[i]) mp[i][j] = cost[i];
    }
    totE = 0;
    memset(adj, NULL, sizeof(adj));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(mp[i][j] != INF) addEdge(i, j, mp[i][j]);

    for(int i = 1; i <= n; ++i) dis[i] = INF;
    memset(inQ, false, sizeof(inQ));
    dis[x] = 0;
    int l = 0, r = 0;
    q[r++] = x;
    while(l != r) {
        int u = q[l++];
        inQ[u] = false;
        if(l == MAXN) l = 0;
        Edge *p = adj[u];
        while(p) {
            if(dis[u] + p->e < dis[p->v]) {
                dis[p->v] = dis[u] + p->e;
                if(!inQ[p->v]) {
                    inQ[p->v] = true;
                    q[r++] = p->v;
                    if(r == MAXN) r = 0;
                }
            }
            p = p->link;
        }
    }
    if(dis[y] == INF) puts("-1");
    else printf("%I64d\n", dis[y]);
    return 0;
}