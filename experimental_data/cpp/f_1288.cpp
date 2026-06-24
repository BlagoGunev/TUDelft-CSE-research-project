// LUOGU_RID: 101592253
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define FR first
#define SE second
using namespace std;
inline int read() {
    int x = 0; bool op = 0;
    char c = getchar();
    while(!isdigit(c))op |= (c == '-'), c = getchar();
    while(isdigit(c))x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return op ? -x : x;
}
const int N = 1e6 + 10;
const int INF = 1e9;
int n1, n2, m, wr, wb, S, T, s, t;
char c1[N], c2[N];
int id[N][2];
int dis[N], vis[N], pre[N], inc[N], in[N], out[N];
int etot = 1;
int head[N], to[N], nxt[N], edge[N], flow[N];
void addedge(int u, int v, int f, int w) {
    to[++etot] = v; flow[etot] = f; edge[etot] = w;
    nxt[etot] = head[u]; head[u] = etot;
    return ;
}
void add(int u, int v, int f, int w) {
    addedge(u, v, f, w); addedge(v, u, 0, -w);
    return ;
}
bool spfa() {
    for(int i = 0; i <= T; i++)dis[i] = INF;
    dis[S] = 0; inc[S] = INF;
    queue<int> q; q.push(S);
    while(q.empty() == false) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int i = head[u]; i; i = nxt[i]) {
            int v = to[i], w = edge[i];
            if(flow[i] == 0)continue;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pre[v] = i; inc[v] = min(inc[u], flow[i]);
                if(vis[v] == false) {
                    vis[v] = true; q.push(v);
                }
            }
        }
    }
    return dis[T] < INF;
}
int ans, cnt;
void update() {
    ans += dis[T] * inc[T]; cnt += inc[T];
    for(int i = T; i != S; i = to[pre[i] ^ 1]) {
        // printf("path:%d\n", i);
        flow[pre[i]] -= inc[T];
        flow[pre[i] ^ 1] += inc[T];
    }
    return ;
}
int main() { 
    n1 = read(); n2 = read(); m = read(); wr = read(); wb = read();
    scanf("%s", c1 + 1); scanf("%s", c2 + 1);
    for(int i = 1; i <= m; i++) {
        int u = read(), v = read();
        add(u, v + n1, 1, wr); id[i][0] = etot;
        add(v + n1, u, 1, wb); id[i][1] = etot;
    }
    s = 0; t = n1 + n2 + 1; S = t + 1; T = t + 2;
    for(int i = 1; i <= n1; i++) {
        if(c1[i] == 'B')add(i, t, INF, 0), out[i]++, in[t]++;
        else if(c1[i] == 'R')add(s, i, INF, 0), in[i]++, out[s]++;
        else add(s, i, INF, 0), add(i, t, INF, 0);
    }
    for(int i = 1; i <= n2; i++) {
        if(c2[i] == 'B')add(s, i + n1, INF, 0), in[i + n1]++, out[s]++;
        else if(c2[i] == 'R')add(i + n1, t, INF, 0), out[i + n1]++, in[t]++;
        else add(s, i + n1, INF, 0), add(i + n1, t, INF, 0);
    }
    for(int i = 0; i <= n1 + n2 + 1; i++) {
        // printf("deg:%d %d %d\n", i, in[i], out[i]);
        if(in[i] > out[i])add(S, i, in[i] - out[i], 0);
        else if(in[i] < out[i])add(i, T, out[i] - in[i], 0);
    }
    add(t, s, INF, 0);
    while(spfa())update();
    // printf("ans:%d %d\n", cnt, ans);
    for(int i = head[S]; i; i = nxt[i])if(flow[i])return puts("-1"), 0;
    printf("%d\n", ans);
    for(int i = 1; i <= m; i++) {
        if(flow[id[i][0]])printf("R");
        else if(flow[id[i][1]])printf("B");
        else printf("U");
    }
    return 0;
}