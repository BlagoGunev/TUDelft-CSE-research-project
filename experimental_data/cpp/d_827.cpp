#include<bits/stdc++.h>
#define LIM 222222
#define fi first
#define se second
using namespace std;

typedef pair < int , int > ii;
int ans[LIM] , n , m;
vector < ii > adj[LIM];
vector < ii > E;
int x[LIM] , y[LIM] , c[LIM] , in_tree[LIM];

/*dsu*/
int pset[LIM];

int findset(int u){
    return (pset[u] == u ? u : pset[u] = findset(pset[u]));
}

void join(int u,int v){
    pset[findset(u)] = findset(v);
}

/*----*/

int par[LIM][20] , edge_Id[LIM] , h[LIM] , maxVal[LIM][20];

void spanning_tree(){
    scanf("%d %d",&n,&m);
    for(int i = 1 ; i <= m ; i++){
        scanf("%d %d %d",&x[i],&y[i],&c[i]);
        E.push_back(ii(c[i] , i));
    }
    for(int i = 1 ; i <= n ; i++)   pset[i] = i;
    sort(E.begin() , E.end());
    for(int i = 0 ; i < E.size() ; i++){
        int id = E[i].se;
        if(findset(x[id]) != findset(y[id])){
            join(x[id] , y[id]);
            adj[x[id]].push_back(ii(y[id] , id));
            adj[y[id]].push_back(ii(x[id] , id));
            in_tree[id] = true;
        }
    }
}

ii lca(int u,int v){
    ii ret = ii(0 , 0);
    if(h[v] > h[u]) swap(u , v);
    for(int log = 18 ; log >= 0 ; log--)   if(h[par[u][log]] >= h[v]){
        ret.se = max(ret.se , maxVal[u][log]);
        u = par[u][log];
    }
    for(int log = 18 ; log >= 0 ; log--)
        if(par[u][log] != par[v][log]){
            ret.se = max(ret.se , maxVal[u][log]);
            ret.se = max(ret.se , maxVal[v][log]);
            u = par[u][log];
            v = par[v][log];
        }
    while(u != v){
        ret.se = max(ret.se , maxVal[u][0]);
        ret.se = max(ret.se , maxVal[v][0]);
        u = par[u][0];
        v = par[v][0];
    }
    ret.fi = u;
    return ret;
}

void dfs(int u,int pre){
    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i].fi , id = adj[u][i].se;
        if(v == pre)    continue;
        h[v] = h[u] + 1;
        par[v][0] = u;
        maxVal[v][0] = c[id];
        edge_Id[v] = id;
        for(int log = 1 ; log <= 18 ; log++){
            par[v][log] = par[par[v][log - 1]][log - 1];
            maxVal[v][log] = max(maxVal[v][log - 1],maxVal[par[v][log - 1]][log - 1]);
        }
        dfs(v , u);
    }
}

void go(int u,int w,int c){
    while(true){
        u = findset(u);
        if(h[u] <= h[w])    break;
        ans[edge_Id[u]] = c - 1;
        pset[u] = par[u][0];
    }
}

void solve(){
    memset(ans , -1 , sizeof ans);
    h[1] = 1;
    dfs(1 , -1);
    for(int i = 1 ; i <= n ; i++)   pset[i] = i;
    for(int i = 0 ; i < E.size() ; i++){
        int id = E[i].se;
        if(!in_tree[id]){
            ii ret = lca(x[id] , y[id]);
            ans[id] = ret.se - 1;
            int w = ret.fi;
            go(x[id] , w , c[id]);
            go(y[id] , w , c[id]);

        }
    }
    for(int i = 1 ; i <= m ; i++)   printf("%d ",ans[i]);
}

int main(){
  //  freopen("test.inp","r",stdin);
    spanning_tree();
    solve();
}