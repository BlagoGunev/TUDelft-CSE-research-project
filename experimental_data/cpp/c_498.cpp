#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<LL> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) { 
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;    
    excess[e.from] -= amt;
    Enqueue(e.to);
  }
  
  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++) 
      if (G[v][i].cap - G[v][i].flow > 0)
  dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) 
  Gap(dist[v]); 
      else
  Relabel(v);
    }
  }

  LL GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }
    
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }
    
    LL totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};
int facs(int a, int b)
{
  int res=0;
  while(a%b==0)
  {
    res++;
    a/=b;
  }
  return res;
}
bool isprime(int x)
{
  if(x<2)return false;
  for(int i=2;i*i<=x;++i)
  {
    if(x%i==0)return false;
  }
  return true;
}
struct ed{
  int u, v;
};
int main()
{
  int n,m,i,j,d,ans;
  ans=0;
  set<int> p;
  cin>>n>>m;
  vector<int> a(n);
  vector<ed> b(m);
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  for(i=0;i<m;++i)
  {
    cin>>b[i].u>>b[i].v;
    d = gcd(a[b[i].u-1], a[b[i].v-1]);
    for(j=1;j*j<=d;++j)
    {
        if(d%j==0)
        {
          if(isprime(j))p.insert(j);
          if(isprime(d/j))p.insert(d/j);
        }
    }
  }
  set<int>::iterator it;
  for (it = p.begin(); it != p.end(); it++)
  {
    int x = *it;
    PushRelabel g(2*n+2);
    for(j=0;j<m;++j)
    {
      if(b[j].u%2==1)
        g.AddEdge(2*b[j].u+1, 2*b[j].v, facs(gcd(a[b[j].u-1], a[b[j].v-1]), x));
      else
        g.AddEdge(2*b[j].v+1, 2*b[j].u, facs(gcd(a[b[j].u-1], a[b[j].v-1]), x));
    }
    for(j=1; j<=n; j+=2)
    {
      g.AddEdge(0, 2*j, 1000);
      g.AddEdge(2*j, 2*j+1, facs(a[j-1], x));
    }
    for(j=2; j<=n; j+=2)
    {
      g.AddEdge(2*j+1, 1, 1000);
      g.AddEdge(2*j, 2*j+1, facs(a[j-1], x));
    }
    ans+=g.GetMaxFlow(0, 1);
  }
  cout<<ans<<endl;
  return 0;
}