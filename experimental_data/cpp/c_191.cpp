#include <bits/stdc++.h>
#define fst first
#define snd second

using namespace std;

typedef pair<int, int> ii;

const int N = 100005, E = N + N, LOGN = 17;

int to[E], ant[E], adj[N], inde = 0;

inline void add_edge(int a, int b) {
  to[inde] = b; ant[inde] = adj[a]; adj[a] = inde++;
  to[inde] = a;ant[inde] = adj[b]; adj[b] = inde++;
}

int ancestral[N][LOGN], level[N], parent[N], n;
int counter[N];

void dfs(int u, int pai, int lvl) {
  parent[u] = pai;
  level[u] = lvl;
  for (int i = adj[u]; ~i; i = ant[i]) {
    int v = to[i];
    if (v == pai) continue;

    dfs(v, u, lvl + 1);
  }
}

void build_dp() {
  memset(ancestral, -1, sizeof ancestral);

  for (int i = 0; i < n; ++i) {
    ancestral[i][0] = parent[i];
  }

  for (int j = 1; j < LOGN; ++j) {
    for (int i = 0; i < n; ++i) {
      if (ancestral[i][j - 1] != -1) {
        ancestral[i][j] = ancestral[ancestral[i][j - 1]][j - 1];
      }
    }
  }
}

int get_lca(int p, int q) {
  if (level[p] < level[q]) {
    swap(p, q);
  }

  for (int i = LOGN - 1; i >= 0; --i) {
    if (level[p] - (1 << i) >= level[q]) {
      p = ancestral[p][i];
    }
  }

  if (p == q) {
    return p;
  }

  for (int i = LOGN - 1; i >= 0; --i) {
    if (ancestral[p][i] != -1 && ancestral[p][i] != ancestral[q][i]) {
      p = ancestral[p][i];
      q = ancestral[q][i];
    }
  }

  return ancestral[p][0];
}

ii edges[N];
int subtree_sum[N];

void calc_sums(int u, int pai = -1) {
  subtree_sum[u] = counter[u];
  for (int i = adj[u]; ~i; i = ant[i]) {
    int v = to[i];
    if (v == pai) continue;
    calc_sums(v, u);
    subtree_sum[u] += subtree_sum[v];
  }
}

int main() {
  memset(adj, -1, sizeof adj); inde = 0;
  
  scanf("%d", &n);

  for (int i = 1; i < n; ++i) {
    int a, b; scanf("%d %d", &a, &b); --a; --b;
    edges[i - 1] = ii(a, b);
    add_edge(a, b);
  }

  dfs(0, -1, 0);
  build_dp();

  int q; scanf("%d", &q);
  while (q --> 0) {
    int a, b; scanf("%d %d", &a, &b); --a; --b;
    int lca = get_lca(a, b);
    ++counter[a];
    ++counter[b];
    counter[lca] -= 2;
  }

  calc_sums(0);

  for (int i = 0; i < n - 1; ++i) {
    int x = edges[i].fst, y = edges[i].snd;
    if (level[edges[i].snd] > level[x]) {
      x = edges[i].snd;
    }
    if (i) printf(" ");
    printf("%d", subtree_sum[x]);
  }
  puts("");
  return 0;
}