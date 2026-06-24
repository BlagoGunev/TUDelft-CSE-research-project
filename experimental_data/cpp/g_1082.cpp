#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL INF = 1e18;
const LL maxn = 1e5+10;
struct Dinic {
    static const LL maxn = 1e5 + 10;
    static const LL maxm = 4e5 + 10;

    struct Edge {
        LL u, v, next, flow, cap;
    } edge[maxm*2];

    LL head[maxn], level[maxn], cur[maxn], eg;

    void AddEdge(LL u, LL v, LL cap) {
        edge[eg] = {u, v, head[u], 0, cap}, head[u] = eg++;
        swap(u, v);
        edge[eg] = {u, v, head[u], 0, 0}, head[u] = eg++;
    }

    void init() {
        eg = 0;
        memset(head, -1, sizeof head);
    }
    bool makeLevel(LL s, LL t, LL n) {
        for(LL i = 0; i < n; i++) level[i] = 0, cur[i] = head[i];
        queue<LL> q; q.push(s);
        level[s] = 1;
        while(!q.empty()) {
            LL u = q.front();
            q.pop();
            for(LL i = head[u]; ~i; i = edge[i].next) {
                Edge &e = edge[i];
                if(e.flow < e.cap && level[e.v] == 0) {
                    level[e.v] = level[u] + 1;
                    if(e.v == t) return 1;
                    q.push(e.v);
                }
            }
        }
        return 0;
    }
    LL findpath(LL s, LL t, LL limit = 1e18) {
        if(s == t || limit == 0) return limit;
        for(LL i = cur[s]; ~i; i = edge[i].next) {
            cur[edge[i].u] = i;
            Edge &e = edge[i], &rev = edge[i^1];
            if(e.flow < e.cap && level[e.v] == level[s] + 1) {
                LL flow = findpath(e.v, t, min(limit, e.cap - e.flow));
                if(flow > 0) {
                    e.flow += flow;
                    rev.flow -= flow;
                    return flow;
                }
            }
        }
        return 0;
    }
    LL operator()(LL s, LL t, LL n) {
        LL ans = 0;
        while(makeLevel(s, t, n)) {
            LL flow;
            while((flow = findpath(s, t)) > 0) ans += flow;
        }
        return ans;
    }
} dinic;

LL n, m;
LL vv[maxn];

int main() {
    scanf("%lld%lld", &n, &m);
    LL S = 0, T = n + m + 1;
    for (LL i = 1; i <= n; i++){
        scanf("%lld", &vv[i]);
    }
    dinic.init();
    LL sum = 0;
    for (LL i = 1; i <= m; i++){
        LL u, v, w;

        scanf("%lld%lld%lld", &u, &v, &w);
        sum += w;
        dinic.AddEdge(S, n+i, w);
        dinic.AddEdge(n+i, u, INF);
        dinic.AddEdge(n+i, v, INF);
    }
    for (LL i = 1; i <= n; i++) {
        dinic.AddEdge(i, T, vv[i]);;
    }
    cout <<sum - dinic(S, T, T + 1);
    return 0;
}