#include <bits/stdc++.h>

using namespace std;



#define MOD 1000000007

#define INF 0x3f3f3f3f

#define f first

#define s second

#define rep(i,a,b) for (int i=a; i<b; ++i)

#define setpr(x) cout<<setprecision(x)<<fixed

#define sz(v) int(v.size())

#define all(v) v.begin(),v.end()

#define int ll



typedef long long ll;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;



void solve(){

  int n,m;

  cin>>n>>m;

  

  vector<string> a(n),b(m);

  rep(i,0,n) cin>>a[i];

  rep(i,0,m) cin>>b[i];

  

  int q;

  cin>>q;

  

  while (q--){

    int d;

    cin>>d;

    

    d--;

    cout<<a[d%n]+b[d%m]<<"\n";

  }

}



#undef int

int main(int argc, const char * argv[]) {

  ios_base::sync_with_stdio(false);

  cin.tie(NULL);

  

  int t=1;

//  cin>>t;

  for (int i=0;i<t;i++){

    solve();

  }

  

  return 0;

}