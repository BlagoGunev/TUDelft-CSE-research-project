///mAAria...
#include<bits/stdc++.h>

using namespace std;
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")*/
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fs first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define inf 100000000000000000

int n,m,k,vis[200005],dist[200005];
vector<pair<int, pair<int,int>>> e;
vector<pair<int,int>> adj[200005];
set<int> s;
vector<int> vec;

void djikstra(int v){

   for(auto i:s){dist[i]=inf;vis[i]=0;}
   dist[v]=0;
   int sc = v;
   priority_queue<pair<int,int>> q;
   q.push({0,v});
   while(!q.empty()){
      v = q.top().sc;q.pop();
      if(vis[v])continue;
      vis[v]=1;
      if( sc<v && dist[v]>0)vec.pb(dist[v]);
      for(auto t:adj[v]){
         if(dist[t.fs]>=dist[v]+t.sc){
            dist[t.fs] = dist[v]+t.sc;
            q.push({-dist[t.fs],t.fs});
         }
      }
   }

}

signed main(){
    IOS;

    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
      int x,y,w;
      cin >> x >> y >> w;
      e.pb({w,{x,y}});
    }
    sort(all(e));

    for(int i = 0;i<min(k,m);i++){

      pair<int,pair<int,int>>  t = e[i];

      int x = t.sc.fs;
      int y = t.sc.sc;
      int w = t.fs;

      adj[x].pb({y,w});
      adj[y].pb({x,w});

      s.insert(x);
      s.insert(y);


    }

    for(auto t:s){
      djikstra(t);
    }

    sort(all(vec));

    cout << vec[k-1] << endl;


return 0;}