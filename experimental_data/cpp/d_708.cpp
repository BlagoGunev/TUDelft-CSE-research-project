#include <bits/stdc++.h>



using namespace std;

#define int long long

#define all(a) (a).begin(), (a).end()

#define ms(a,v) memset(a, v, sizeof(a))

#define sz(v) ((int)(v).size())

#define mp make_pair

#define pb push_back

#define prev biiiiirl_sai_de_casa_comi_pra_caralho

#define next trapezio_descendente

#define index eh_ele_que_nos_vai_buscar

#define left aqui_eh_37_anos_porra

#define R32 ({i32 x; scanf("%d", &x); x;})

#define RL ({long long x; scanf("%lld", &x); x;})

#define RC ({char x; scanf(" %c", &x); x;})

#define RI RL

#define ff first

#define ss second

typedef pair<int, int> ii;

typedef vector<int> vi;

typedef vector<vi> vvi;

typedef vector<ii> vii;

typedef long long ll;



struct Edge {

  int next, cost, flow;

};



const int oo = 1e17;

struct Mincost{



  int s, t;

  int n;

  vector<vector<int>> adj;

  vector<Edge> e;

  vector<int> p, in_queue, pe, dist;



  Mincost(int n) : n(n), adj(n), p(n), in_queue(n), pe(n), dist(n){

    s = n-1;

    t = s-1;

  }



  void add_edge(int u, int v, int flow, int cost) {

    adj[u].push_back(e.size());

    e.push_back({v, cost, flow});

    adj[v].push_back(e.size());

    e.push_back({u, -cost, 0});

  }



  bool augment() {

    for (int i = 0; i < n; i++) p[i] = -1, dist[i] = oo;

    queue<int> q;

    q.push(s);

    in_queue[s] = 1;

    dist[s] = 0;

    while (!q.empty()) {

      int u = q.front();

      q.pop();

      in_queue[u] = 0;

      for (int k : adj[u]) {

        Edge& ed = e[k];

        if (ed.flow > 0 && dist[u]+ed.cost < dist[ed.next]) {

          dist[ed.next] = dist[u]+ed.cost;

          p[ed.next] = u;

          pe[ed.next] = k;

          if (!in_queue[ed.next]) {

            in_queue[ed.next] = 1;

            q.push(ed.next);

          }

        }

      }

    }



    p[s] = -1;

    return p[t] != -1;

  }

  pair<int, int> mincost() {

    int maxflow = 0, mincost = 0;

    while (augment()) {

      int cf = oo;

      for (int v = t; p[v] != -1; v = p[v]) { cf = min(cf, e[pe[v]].flow); }

      maxflow += cf;

      for (int v = t; p[v] != -1; v = p[v]) {

        e[pe[v]].flow -= cf;

        e[pe[v] ^ 1].flow += cf;

        mincost += cf * e[pe[v]].cost;

      }

    }

    return {maxflow, mincost};

  }

};



int deg[105];



int32_t main(){

  int n = RI;

  int m = RI;

  Mincost fl(n+2);



  int ans = 0;



  for(int i = 0; i < m; i++){

    int u = RI-1;

    int v = RI-1;

    int c = RI;

    int f = RI;

    deg[u] -= f, deg[v] += f;



    if(f > c){

      ans += f-c;

      fl.add_edge(u, v, oo, 2);

      fl.add_edge(v, u, f-c, 0);

      fl.add_edge(v, u, c, 1);

    }else{

      fl.add_edge(u, v, oo, 2);

      fl.add_edge(u, v, c-f, 1);

      fl.add_edge(v, u, f, 1);

    }

  }



  for(int i = 0; i < n; i++){

    if(deg[i] < 0)

      fl.add_edge(i, fl.t, -deg[i], 0);

    else fl.add_edge(fl.s, i, deg[i], 0);

  }



  fl.add_edge(n-1, 0, oo, 0);

  cout << ans + fl.mincost().ss << endl;

}