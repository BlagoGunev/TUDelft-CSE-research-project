#include <bits/stdc++.h>
using namespace std;

const int maxn = 200200;
const int maxm = maxn << 2;
int a[maxn], n, ret;
int head[maxn], to[maxm], edge[maxm], ecnt;
int pcnt, prime[maxn],dis[maxn];
bool isprime[maxn];

void adde(int x, int y){
  edge[++ecnt] = y, to[ecnt] = head[x], head[x] = ecnt;
  edge[++ecnt] = x, to[ecnt] = head[y], head[y] = ecnt;
}

void dfs(int u, int p, int x) {
  dis[u] = 0;
  for(int i = head[u]; ~i; i=to[i]) {
    int &v = edge[i];
    if(v == p) continue;
    if(a[v] % x == 0) {
      while(a[v] % x == 0) a[v] /= x;
      dfs(v, u, x);
      ret = max(ret, dis[u]+dis[v]+1);
      dis[u] = max(dis[u], dis[v]);
    }
  }
  dis[u]++;
}

signed main() {
  // freopen("in", "r", stdin);
  pcnt = 0;
  memset(head, -1, sizeof head);
  for(int i = 2; i < maxn; i++){
    if(!isprime[i]) {
      isprime[i] = 1;
      prime[++pcnt] = i;
    }
    for(int j = 1; j <= pcnt && prime[j] * i <= maxn; j++) {
      isprime[prime[j]*i] = 1;
      if(i % prime[j] == 0) break;
    }
  }
  scanf("%d", &n);
  ret = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if(a[i] > 1) ret = 1;
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d",&u,&v);
    adde(u,v);
  }
  for(int i = 1; i <= n; i++) {
    int x = a[i];
    for(int j = 1; j <= pcnt && prime[j] * prime[j] <= a[i]; j++) {
      if(x % prime[j] == 0) {
        while(x % prime[j] == 0) x /= prime[j];
        dfs(i, 0, prime[j]);
      }
    }
    if(x > 1) dfs(i, 0, x);
    a[i] = 1;
  }
  printf("%d\n", ret);
  return 0;
}