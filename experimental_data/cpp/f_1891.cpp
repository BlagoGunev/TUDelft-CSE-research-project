#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

int beg[sz], fin[sz], kt;
vector <int> g[sz];
vector <pair <int, int>> add[sz];

void dfs(int u) {
   beg[u] = ++kt;
   for(int v : g[u]) dfs(v);
   fin[u] = kt;
}

struct segtree {
   int n, h;
   ll tree[sz<<1], ex[sz];

   inline void renew(int nn) {
      n = nn, h = 32 - __builtin_clz(n);
      for(int i=0; i<n; i++) tree[n+i] = tree[i] = ex[i] = 0;
   }

   inline void calc(int p, int d) {
      tree[p] = tree[p<<1] + tree[p<<1|1];
      ex[p] ? tree[p] += ex[p] * d : 1;
   }

   inline void apply(int p, ll v, int d) {
      tree[p] += v * d;
      if(p < n) ex[p] += v;
   }

   void pull(int p) {
      int d = 1;
      while(p > 1) {
         p >>= 1, d <<= 1;
         calc(p, d);
      }
   }

   void push(int p) {
      for(int s=h, d=1<<(h-1); s; s--, d>>=1) {
         int i = p >> s;
         if(ex[i]) {
            apply(i<<1, ex[i], d);
            apply(i<<1|1, ex[i], d);
            ex[i] = 0;
         }
      }
   }

   void update(int l, int r, ll v) {
      if(l > r) return;
      l += n, r += n + 1;
      int l0 = l, r0 = r, d = 1;
      while(l < r) {
         if(l & 1) apply(l++, v, d);
         if(r & 1) apply(--r, v, d);
         l >>= 1, r >>= 1, d <<= 1;
      }
      pull(l0), pull(r0 - 1);
   }

   ll query(int l, int r) {
      if(l > r) return 0;
      l += n, r += n + 1;
      push(l), push(r - 1);
      ll res = 0;
      while(l < r) {
         if(l & 1) res += tree[l++];
         if(r & 1) res += tree[--r];
         l >>= 1, r >>= 1;
      }
      return res;
   }
} sgt;

void solve() {
   int q, n = 1;
   scanf("%d", &q);
   for(int i=0; i<q; i++) {
      int t, v;
      scanf("%d %d", &t, &v);
      if(t == 1) {
         g[v].push_back(++n);
      }
      else {
         int x;
         scanf("%d", &x);
         add[n].emplace_back(v, x);
      }
   }
   kt = -1;
   dfs(1);
   sgt.renew(n);

   for(int i=1; i<=n; i++) {
      ll cut = sgt.query(beg[i], beg[i]);
      sgt.update(beg[i], beg[i], -cut);

      for(auto &[v, x] : add[i]) {
         int l = beg[v], r = fin[v];
         sgt.update(l, r, x);
      }
   }

   for(int i=1; i<=n; i++) add[i].clear(), g[i].clear();

   for(int i=1; i<=n; i++) 
      printf("%lld ", sgt.query(beg[i], beg[i]));
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}