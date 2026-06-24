#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long

deque<int> q;
const int maxn = 200100;
int n, m, k, u, v, w, tot;
ll dist[maxn];
int inq[maxn], from[maxn];
int e, to[maxn * 5], ne[maxn * 5], he[maxn], we[maxn * 5], is[maxn * 5];

void link(int u, int v, int w) { to[++e] = v, ne[e] = he[u], he[u] = e, we[e] = w; }

void spfa(){
  memset(dist, 127, sizeof(dist));
  q.push_front(1), dist[1] = 0, inq[1] = 1;
  while(!q.empty()){
    int t = q.front(); q.pop_front(); 
    for(int j = he[t]; j; j = ne[j])
      if (dist[t] + we[j] < dist[to[j]]){
        dist[to[j]] = dist[t] + we[j];
        from[to[j]] = j;
        if (!inq[to[j]]){
          inq[to[j]] = 1;
          if (!q.empty() && dist[to[j]] < dist[q.front()]) q.push_front(to[j]);
          else q.push_back(to[j]);
        }
      }else if (dist[t] + we[j] == dist[to[j]] && is[from[to[j]]]) from[to[j]] = j;
    inq[t] = 0;
  }
  for(int i = 2; i <= n; i++) if (is[from[i]]) tot++;
}

int main(){
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i <= m; i++){
    scanf("%d%d%d", &u, &v, &w);
    link(u, v, w), link(v, u, w);
  }
  for(int i = 1; i <= k; i++){
    scanf("%d%d", &v, &w);
    link(1, v, w), is[e] = 1; 
  }
  spfa();
  printf("%d\n", k - tot);
  return 0;
}