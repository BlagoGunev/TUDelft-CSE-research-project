/***************************************************************************
                                AUTHOR: SPARSH SINHA
            **************************************************************************/


#include <bits/stdc++.h>
using namespace std;
#define si(N) scanf("%d",&N);
#define sll(N) scanf("%lld",&N);
#define ss(s) scanf("%s",s);
#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i = a; i<=b;i++)
#define fori(i,n) for(int i = 0 ; i < n; i++)
#define umapii unordered_map<int,int>
#define umapll unordered_map<ll,ll>
#define mapll map<ll,ll>
#define mapii map<int,int>
#define debug(x)       cerr<< #x <<" : "<<x<<endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int i = 0; i<N;i++) cerr<<A[i]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int i=0;i<N;i++){cerr<<"[";for(int j=0;j<M;++j) cerr<<A[i][j]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[0].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
#define debugs(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin(); itr!=m.end();itr++) cerr<<*itr<<" "; cerr<<"]\n";
#define debugm(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin();itr!=m.end(); itr++) cerr<<"("<<itr->first<<","<<itr->second<<") ";cerr<<"]\n";
const int INF = 1e9 + 7;

int main(){
      int n , m;
      cin >> n >> m;
      vector < vector < int > > adj(8 , vector < int > (8 , 0));
      vector < int > degree(8 , 0);
      for(int i = 0; i < m; i++){
           int a , b;
           cin >> a >> b;
           adj[a][b] = 1; adj[b][a] = 1;
           degree[a]++; degree[b]++;
      }
      debugv(degree);
      if(n <= 6) cout << m << "\n";
      else{
          // here n is 7
          int ans = INT_MIN;
          for(int i = 1; i <= n; i++){
                // ith vertex is unassigned
                int placed = m - degree[i];
                for(int j = 1; j <= n ; j++){
                   // i is matched to j
                   int satisfy = 0;
                   for(int b = 1; b <= n; b++){
                       if(adj[i][b] == 1 && adj[j][b] == 0) satisfy++; 
                   }
                   ans = max(ans , placed + satisfy);
                }
          }
          cout << ans << endl;
      }
}