#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5, mz = 1e5+5;

ll ans;
int csub[sz], mp[sz], ara[sz], sdp[1 << 10];
vector <int> g[sz];
bitset <sz> bigset;
bitset <mz> smallset;

int main() {
   int n;
   cin >> n;
   for(int i=2; i<=n; i++) {
      int p;
      scanf("%d", &p);
      g[p].push_back(i);
   }

   int k = 0;
   vector <int> a(n);
   queue <int> q; q.push(1);
   while(!q.empty()) {
      int u = q.front(); q.pop();
      for(int v : g[u]) q.push(v);
      a[k++] = u;
   }
   reverse(a.begin(), a.end());

   for(int u : a) {
      int m = 0, mx = 0;
      for(int v : g[u]) csub[u] += csub[v], ara[m++] = csub[v], mx = max(mx, csub[v]);

      ll here = 0;

      if(mx * 2 >= csub[u]) here = (ll) mx * (csub[u] - mx);
      else if(m <= 10) {
         for(int msk = 1; msk < 1 << m; msk++) {
            int b = 31 - __builtin_clz(msk);
            sdp[msk] = sdp[msk ^ 1 << b] + ara[b];
            here = max(here, (ll) sdp[msk] * (csub[u] - sdp[msk]));
         }
      }
      else if(csub[u] < mz) {
         smallset[0] = 1;
         for(int v : g[u]) mp[csub[v]]++;
         for(int x = 1; x <= csub[u]; x++) {
            int &c = mp[x];
            if(!c) continue;
            if(c > 2) {
               if(c & 1) mp[x << 1] += c >> 1, c = 1;
               else mp[x << 1] += (c - 2) >> 1, c = 2;
            }
            while(c) c--, smallset |= smallset << x;
         }
         for(int i = 0; i < mz; i = smallset._Find_next(i)) {
            smallset[i] = 0;
            here = max(here, (ll) i * (csub[u] - i));
            if(i == csub[u]) break;
         }
      }
      else {
         bigset[0] = 1;
         for(int v : g[u]) mp[csub[v]]++;
         for(int x = 1; x <= csub[u]; x++) {
            int &c = mp[x];
            if(!c) continue;
            if(c > 2) {
               if(c & 1) mp[x << 1] += c >> 1, c = 1;
               else mp[x << 1] += (c - 2) >> 1, c = 2;
            }
            while(c) c--, bigset |= bigset << x;
         }
         for(int i = 0; i < sz; i = bigset._Find_next(i)) {
            bigset[i] = 0;
            here = max(here, (ll) i * (csub[u] - i));
            if(i == csub[u]) break;
         }
      }
      ans += here;
      csub[u]++;
   }
   cout << ans;
}