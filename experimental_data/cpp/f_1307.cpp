#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define MAXN 400005

template <typename T> inline void read (T &t){t = 0;char c = getchar();int f = 1;while (c < '0' || c > '9'){if (c == '-') f = -f;c = getchar();}while (c >= '0' && c <= '9'){t = (t << 3) + (t << 1) + c - '0';c = getchar();} t *= f;}
template <typename T,typename ... Args> inline void read (T &t,Args&... args){read (t);read (args...);}
template <typename T> inline void write (T x){if (x < 0){x = -x;putchar ('-');}if (x > 9) write (x / 10);putchar (x % 10 + '0');}
template <typename T> inline void chkmax (T &a,T b){a = max (a,b);}
template <typename T> inline void chkmin (T &a,T b){a = min (a,b);}

int n,K,R;
vector <int> g[MAXN];

int fa[MAXN],dep[MAXN],dis[MAXN],par[MAXN][21];
void dfs1 (int u,int pat){
    par[u][0] = pat,dep[u] = dep[pat] + 1;
    for (Int i = 1;i <= 20;++ i) par[u][i] = par[par[u][i - 1]][i - 1];
    for (Int v : g[u]) if (v != pat) dfs1 (v,u);
}

int getlca (int u,int v){
    if (dep[u] < dep[v]) swap (u,v);
    for (Int i = 20,dis = dep[u] - dep[v];~i;-- i) if (dis >> i & 1) u = par[u][i];
    if (u == v) return u;
    else{
        for (Int i = 20;~i;-- i) if (par[u][i] ^ par[v][i]) u = par[u][i],v = par[v][i];
        return par[u][0];
    }
}

int findSet (int x){return fa[x] == x ? x : fa[x] = findSet (fa[x]);}
int getdist (int u,int v){
    return dep[u] + dep[v] - dep[getlca (u,v)] * 2;
}
int getclimb (int u,int t){
    for (Int i = 20;~i;-- i) if (t >> i & 1) u = par[u][i];
    return u;
}

signed main(){
    read (n,K,R);int now = n;
    for (Int x = 1;x <= 2 * n;++ x) fa[x] = x;
    for (Int i = 2,u,v;i <= n;++ i)
        read (u,v),++ now,g[u].push_back (now),g[v].push_back (now),g[now].push_back (u),g[now].push_back (v);
    queue <int> q;memset (dis,-1,sizeof (dis));
 	for (Int i = 1,x;i <= R;++ i) read (x),q.push (x),dis[x] = 0;
    while (!q.empty()){
        int u = q.front();q.pop ();
        if (dis[u] == K) break;
        for (Int v : g[u]){
            fa[findSet (v)] = findSet (u);
            if (dis[v] == -1) dis[v] = dis[u] + 1,q.push (v);
        }
    }
    dfs1 (1,0);
    int Q;read (Q);
    while (Q --> 0){
        int u,v;read (u,v);int len = getdist (u,v);
        if (len <= 2 * K){puts ("YES");continue;}
        int lca = getlca (u,v);
        int tu = (dep[u] - dep[lca] >= K) ? getclimb (u,K) : getclimb (v,len - K),
            tv = (dep[v] - dep[lca] >= K) ? getclimb (v,K) : getclimb (u,len - K);
        if (findSet (tu) == findSet (tv)) puts ("YES");
        else puts ("NO");
    }
    return 0;
}