#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  int t ;
  cin >> t ;
  vector <int> adj[1003],adj2[1003] ;
  int dist[1003][1003] ;
  bool cn1[1003][1003],cn2[1003][1003] ;
  while (t --){
    int n,s1,s2,i,j ;
    cin >> n >> s1 >> s2 ;
    for (i = 1 ; i <= n ; i ++) adj[i].clear(),adj2[i].clear() ;
    for (i = 1 ; i <= n ; i ++){
      for (j = 1 ; j <= n ; j ++) dist[i][j]=INT_MAX,cn1[i][j]=0,cn2[i][j]=0 ;
    }
    int m1,m2 ;
    cin >> m1 ;
    while (m1--){
      cin >> i >> j ;
      adj[i].push_back(j) ;
      adj[j].push_back(i) ;
      cn1[i][j]=cn1[j][i]=1 ;
    }
    cin >> m2 ;
    while (m2--){
      cin >> i >> j ;
      adj2[i].push_back(j) ;
      adj2[j].push_back(i) ;
      cn2[i][j]=cn2[j][i]=1 ;
    }
    priority_queue <tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q ;
    q.push({0,s1,s2}) ;
    while (!q.empty()){
      auto [dd,a,b]=q.top() ;
      q.pop() ;
      if (dd>=dist[a][b]) continue ;
      dist[a][b]=dd ;
      // cout << a << " " << b << " " << dd << endl ;
      for (auto aa : adj[a]){
        for (auto bb : adj2[b]){
          if (dist[aa][bb]>dd+abs(aa-bb)){
            q.push({dd+abs(aa-bb),aa,bb}) ;
          }
        }
      }
    }
    int mn=INT_MAX ;
    for (i = 1 ; i <= n ; i ++){
      for (j = 1 ; j <= n ; j ++){
        if (cn1[i][j]&&cn2[i][j]){
          // cout << i << j << dist[i][i] << dist[j][j] << endl ;
          mn=min(mn,min(dist[i][i],dist[j][j])) ;
        }
      }
    }
    if (mn==INT_MAX) cout << -1 << endl ;
    else cout << mn << endl ;
  }
  return 0 ;
}