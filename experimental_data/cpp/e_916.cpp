#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

int n, q, dfs_clock, a[MAXN];
int dfn[MAXN], low[MAXN], top[MAXN];
int fa[MAXN], deep[MAXN], size[MAXN], son[MAXN];

vector<int> G[MAXN];

namespace BIT {
  ll c0[MAXN], c1[MAXN];
  void add(ll *c, int x, ll k) {
    for(; x <= n; x += x & -x) c[x] += k;
  }
  ll sum(ll *c, int x) { 
    ll r = 0; 
    for(; x; x -= x & -x) r += c[x];
    return r;
  }
  void add(int l, int r, ll k) {
    add(c0, l, k); add(c0, r + 1, -k);
    add(c1, l, (l - 1) * k); add(c1, r + 1, -r * k);
  }
  ll sum(int l, int r) {
    return sum(c0, r) * r - sum(c1, r) - sum(c0, l - 1) * (l - 1) + sum(c1, l - 1);
  }
}

void dfs1(int cur, int father, int dep)  {
  fa[cur] = father;
  deep[cur] = dep;
  size[cur] = 1;
  son[cur] = 0;
  for(int i = 0; i < G[cur].size(); i++) {
    int nx = G[cur][i];
    if(nx != father) {
      dfs1(nx, cur, dep + 1);
      size[cur] += size[nx];
      if(size[nx] > size[son[cur]]) {
        son[cur] = nx;
      }
    }
  }
}

void dfs2(int cur, int tp) {
  top[cur] = tp;
  dfn[cur] = ++dfs_clock;
  if(son[cur]) dfs2(son[cur], tp);
  for(int i = 0; i < G[cur].size(); i++) {
    int nx = G[cur][i];
    if(nx != fa[cur] && nx != son[cur]) {
      dfs2(nx, nx);
    }
  }
  low[cur] = dfs_clock;
}

int lca(int u, int v) {
  int t1 = top[u], t2 = top[v];
  while(t1 != t2) {
    if(deep[t1] < deep[t2]) {
      swap(t1, t2); swap(u, v);
    }
    u = fa[t1], t1 = top[u];
  }
  return deep[u] < deep[v] ? u : v;
}

bool contain(int u, int v) { // u in v's subtree
  return dfn[u] >= dfn[v] && dfn[u] <= low[v];
}

bool cmp(int x, int y) {
  return low[x] < low[y];
}

int lca(int u, int v, int root) {
  int z1 = lca(root, u);
  int z2 = lca(root, v);
  if(z1 == z2) return lca(u, v);
  return deep[z1] > deep[z2] ? z1 : z2;
}

void add(int cur, ll x, int root) {
  if(root == cur) BIT::add(1, n, x);
  else if(contain(root, cur)) {
    BIT::add(1, n, x);
    int sta = lower_bound(G[cur].begin(), G[cur].end(), root, cmp) - G[cur].begin();
    for(int i = sta; i < G[cur].size(); i++) {
      int nx = G[cur][i];
      if(nx != fa[cur] && contain(root, nx)) {
        BIT::add(dfn[nx], low[nx], -x); break;
      }
    }
  } else {
    BIT::add(dfn[cur], low[cur], x);
  }
}

ll query(int cur, int root) {
  if(root == cur) return BIT::sum(1, n);
  else if(contain(root, cur)) {
    ll res = BIT::sum(1, n);
    int sta = lower_bound(G[cur].begin(), G[cur].end(), root, cmp) - G[cur].begin();
    for(int i = sta; i < G[cur].size(); i++) {
      int nx = G[cur][i];
      if(nx != fa[cur] && contain(root, nx)) {
        res -= BIT::sum(dfn[nx], low[nx]); break;
      }
    }
    return res;
  } else {
    return BIT::sum(dfn[cur], low[cur]);
  }
}

int main() {
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int root = 1;
  dfs1(1, 0, 1); dfs2(1, 1);
  for(int i = 1; i <= n; i++) {
    sort(G[i].begin(), G[i].end(), cmp);
  }
  for(int i = 1; i <= n; i++) {
    BIT::add(dfn[i], dfn[i], a[i]);
  }
  while(q--) {
    int opt;
    scanf("%d", &opt);
    if(opt == 1) {
      int v;
      scanf("%d", &v);
      root = v;
    } else if(opt == 2) {
      int u, v, x, z;
      scanf("%d %d %d", &u, &v, &x);
      z = lca(u, v, root);
      add(z, x, root);
    } else {
      int v;
      scanf("%d", &v);
      printf("%lld\n", query(v, root));
    }
  }
  return 0;
}