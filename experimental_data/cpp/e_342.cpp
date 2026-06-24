#include <bits/stdc++.h>

using namespace std;



const int MXN = 2e5 + 9, LG = 17, INF = 1e9 + 7;



int N,Q;

vector <int> g[MXN],cg[MXN];

int subTree[MXN],Removed[MXN];

int dep[MXN],par[MXN][LG], P[MXN], ans[MXN];

int timer = 0, tin[MXN], tout[MXN];

int Closest[MXN];



inline void dfs(int node,int from){

	tin[node] = ++timer;

	par[node][0] = from;

	dep[node] = dep[from] + 1;

	for(int i = 1;i < LG;++i)

		par[node][i] = par[par[node][i - 1]][i - 1];

	for(int i = 0;i < (int)g[node].size();++i){

		int next = g[node][i];

		if(next != from) dfs(next,node);

	}

	tout[node] = ++timer;

}



inline bool isAnc(int u,int v){

	return (tin[u] <= tin[v] && tout[u] >= tout[v]);

}



inline int LCA(int u,int v){

	if(isAnc(u,v)) return u;

	if(isAnc(v,u)) return v;

	for(int lev = LG - 1;lev >= 0;--lev)

		if((par[u][lev] > 0) && (!isAnc(par[u][lev],v)))

			u = par[u][lev];

	return par[u][0];

}



inline int dist(int u,int v){

    if(u == 0 || v == 0) return INF;

	return dep[u] + dep[v] - 2 * dep[LCA(u,v)];

}



inline int go(int u,int p){

    if(Removed[u]) return 0;

    int ret = 1;

	for(int i = 0;i < (int)g[u].size();++i){

        int to = g[u][i];

        if(to != p) ret += go(to,u);

    }

    return subTree[u] = ret;

}



inline int getCentroid(int u,int p,int nodes){

    if(Removed[u]) return 0;

    for(int i = 0;i < (int)g[u].size();++i){

        int to = g[u][i];

        if(Removed[to] || (to == p)) continue;

        if(subTree[to] > (nodes/2)) return getCentroid(to,u,nodes);

    }

    return u;

}



inline void Decompose(int u,int p){

    int centroid = getCentroid(u,0,go(u,0));

    P[centroid] = p; cg[p].push_back(centroid);

    Removed[centroid] = true;

    for(int i = 0;i < (int)g[centroid].size();++i){

        int to = g[centroid][i];

        if(Removed[to]) continue;

        Decompose(to,centroid);

    }

}



inline void Update(int u){

    int cur = u;

    while(cur != 0){

        if(dist(Closest[cur],cur) > dist(cur,u))

            Closest[cur] = u;

        cur = P[cur];

    }

}



inline int Query(int u){

    int ret = INF, cur = u;

    while(cur != 0){

        ret = min(ret,dist(u,cur) + dist(cur,Closest[cur]));

        cur = P[cur];

    }

    return ret;

}



int main(){

    scanf("%d %d",&N,&Q);

    for(int i = 1;i < N;++i){

        int u,v; scanf("%d %d",&u,&v);

        g[u].push_back(v); g[v].push_back(u);

    }

    dfs(1,0); Decompose(1,0); Update(1);

    while(Q--){

        int type, X; scanf("%d %d",&type,&X);

        if(type == 1) Update(X);

        else printf("%d\n",Query(X));

    }

    return 0;

}