#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)

#define pb push_back
#define mp make_pair
#define st first
#define nd second

const int MOD = 1000000007;

int _find[111111];
int actual_node(int v) {
  if (_find[v] != v) _find[v] = actual_node(_find[v]);
  return _find[v];
}

vector<int> adj[111111];

int N;
int depth[111111];
int parent[111111];

LL size[111111];
LL subtree_size[111111];

LL decr = 0;
LL mults[111111];

int go(int v, int p = -1) {
  if (p != -1) {
    depth[v] = depth[p] + 1;
    parent[v] = p;
  }

  subtree_size[v] = 1;
  for (int u: adj[v]) if (u != p) {
    int si_rec = go(u, v);
    subtree_size[v] += si_rec;
    mults[v] += si_rec * (LL)(si_rec - 1);
    decr += si_rec * (LL)(si_rec - 1);
  }

  if (p != -1) {
    mults[v] += (N-subtree_size[v])*(LL)(N-subtree_size[v]-1);
    decr += (N-subtree_size[v])*(LL)(N-subtree_size[v]-1);
  }

  return subtree_size[v];
}

int merge(int u, int v) { // u is parent of v
  decr -= subtree_size[v] * size[u] * (subtree_size[v] - 1);
  // cout << "!!" << decr << endl;
  mults[u] -= subtree_size[v] * (subtree_size[v] - 1);

  decr -= (N-subtree_size[v]) * size[v] * (N-subtree_size[v]-1);
  // cout << "!!" << decr << endl;
  mults[v] -= (N-subtree_size[v]) * (N-subtree_size[v]-1);

  decr += size[v] * mults[u];
  decr += size[u] * mults[v];
  mults[u] += mults[v];
  size[u] += size[v];
  _find[v] = u;

  return u;
}

int main() {
  // ios_base::sync_with_stdio(0);

  scanf("%d", &N);
  REP(i,N-1) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  REP(i,N) _find[i] = i;
  REP(i,N) size[i] = 1;

  go(0,-1);

  LL all = N*(LL)(N-1)*(N-2);

  cout << all - decr << endl;
  int Q;
  scanf("%d", &Q);
  REP(i,Q) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;

    // REP(k,N) if (actual_node(k) == k) {
    //   cout << k << " " << mults[k] << " " << size[k] << " " << subtree_size[k] << endl;
    // }

    // cout << "QUERY " << u << " " <<  v << endl;

    u = actual_node(u);
    v = actual_node(v);

    if (u == v) {
      cout << all - decr << endl;
      continue;
    }

    while (u != v) {
      // printf("!!%d %d\n", u, v);
      if (depth[u] < depth[v]) swap(u,v);
      u = merge(actual_node(parent[u]), u);
    }

    cout << all - decr << endl;
  }
}