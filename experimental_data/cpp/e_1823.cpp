#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define FOR(i, to) for (int i = 0; i < (to); ++i)
typedef vector<vector<int> > vvi; 
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pair<int, int> > vpi;
typedef pair<ll,ll> pll;
#define Nmax 200100
int N, L, R, C, sg[Nmax];
int x,y,w, viz[Nmax];
vi g[Nmax];

void dfs(int x) {
  ++C;
  viz[x] = 1;
  for(auto y: g[x]) if(!viz[y]) dfs(y);
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin>>N>>L>>R;

  rep(i, L, min(N+1, L+R)) {
    sg[i] = sg[i-L] + 1; 
  }

  /*for(int i=0;i<=N;++i) {
    cout<<i<<" "<<sg[i]<<endl;
  }*/

  FOR(i, N) {
    cin>>x>>y;
    g[x].pb(y);
    g[y].pb(x);
  }

  int ret = 0;
  rep(i,1,N+1) {
    if(!viz[i]) {
      C = 0;
      dfs(i);
      ret ^= sg[C];
    }
  }
  if(ret) cout<<"Alice\n";
  else cout<<"Bob\n";
  return 0;
}