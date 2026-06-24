//Pranet Verma
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int owner[MAXN];
const int LN = 20;
int pa[20][MAXN];
int dep[MAXN];
int sz[MAXN];
vector<int> g[MAXN];
void dfs(int u, int p = 0) {
	dep[u] = dep[p] + 1;
	sz[u] = 1; 
	for (auto v : g[u]) {
		if (v != p) {
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
}

int lca(int u,int v)
{
    if(dep[u]<dep[v])
        swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=LN-1;i>=0;--i)
        if(d&(1<<i))
            u=pa[i][u];
    if(u==v)
        return u;
    for(int i=LN-1;i>=0;--i)
        if(pa[i][u]!=pa[i][v])
            u=pa[i][u],
            v=pa[i][v];
    return pa[0][u];
}

int main() {
	int n, m;
	int k, q;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &k, &q);	 
	for (int i = 0; i < k; ++i) {
		int u, t;
		scanf("%d %d", &u, &t);
		assert (pa[0][u] == u or pa[0][u] == 0);
		if (owner[t] == 0) {
			if (pa[0][u] == 0) {
				pa[0][u] = u;
			}
		}
		else {
			pa[0][u] = owner[t];
		}
		owner[t] = u;
	}

	for (int i = 1; i <= n; ++i) {
		if (pa[0][i] == 0 or pa[0][i] == i) {
			pa[0][i] = i;
		}
		else {
			g[pa[0][i]].push_back(i);
		}
	} 
	for (int j = 1; j < 20; ++j) {
		for (int i = 1; i <= n; ++i) {
			pa[j][i] = pa[j - 1][pa[j - 1][i]];
		}	
	}
	for (int i = 1; i <= n; ++i) {
		if (pa[0][i] == i) {
			dfs(i);
		}
	}
	for (int i = 0; i < q; ++i) {
		int u, t;
		scanf("%d %d", &u, &t);
		if (owner[t] == 0) {
			printf("%d\n", 0);
		}
		else {
			if (pa[19][owner[t]] != pa[19][u]) {
				printf("%d\n", 0);
			}
			else {
				// if owner if my child, we have a problem;
				int v = owner[t];
				if (lca(u, v) == u) {
					printf("%d\n", sz[u]);
				}
				else {
					printf("%d\n", 0);
				}
			}
		}
	}
}