#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MaxN  = 100005;
const int MaxE  = MaxN * 2;
const int oo    = 0x3f3f3f3f;

struct Edge {
    int to, w;
    Edge* next;
} memo[MaxE], *cur, *g[MaxN];
bool vst[MaxN];
int q[MaxN], d[MaxN];
int n;

void init() {
    for (int i = 1; i <= n; i++) {
        g[i] = NULL;
        vst[i] = false;
    }
    cur = memo;
}

void add_edge(int u, int v, int w) {
    cur->to     = v;
    cur->w      = w;
    cur->next   = g[u];
    g[u]        = cur++;
}

void spfa(int s) {
    int f = 0, b = 0;
    int u, v;
    
    memset(d, 0x3f, sizeof(d));
    d[s]    = 0;
    q[b++]  = s;
    
    while (f ^ b) {
        u = q[f++];
        if (f == MaxN) f = 0;
        vst[u] = false;
        for (Edge* it =  g[u]; it; it = it->next) {
            v = it->to;
            if (d[v] - d[u] > it->w) {
                d[v] = d[u] + it->w;
                if (!vst[v]) {
                    vst[v]  = true;
                    q[b++]  = v;
                    if (b == MaxN) b = 0;
                }
            }
        }
    }
}

int main() {
    int m, u, v, w, start;
    
    while (scanf("%d%d%d", &n, &m, &start) == 3) {
        init();
        while (m--) {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
            add_edge(v, u, w);
        }
        scanf("%d", &w);
        spfa(start);
        int ret = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (d[i] == w) ret++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (d[i] < w) {
                for (Edge* it = g[i]; it; it = it->next) {
                    if (d[i] + it->w > w) {
                        if (d[i] + it->w - w + d[it->to] > w) {
                            ret++;
                        } else if (d[i] + it->w - w + d[it->to] == w) {
                            ret++;
                            cnt++;
                        }
                    }
                }
            }
        }
        printf("%d\n", ret - cnt / 2);
    }
    
    return 0;
}