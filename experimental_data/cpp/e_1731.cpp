#include<bits/stdc++.h>

using namespace std;

using ll = long long;

using ld = long double;



#pragma GCC target("avx2")

#pragma GCC optimize("O3")

#pragma GCC optimize("unroll-loops")



//only for atcoder

//#include<atcoder/all>

//using namespace atcoder;



#define rep(i,l,r) for(ll i=(l); i<(r); i++)

#define rrep(i,l,r) for(ll i=(r)-1; i>=(l); i--)

#define ALL(c) (c).begin(), (c).end()

#define RALL(c) (c).rbegin(), (c).rend()

#define SORT(c) sort(ALL(c))

#define RSORT(c) sort(RALL(c))

#define MINV(c) *min_element(ALL(c))

#define MAXV(c) *max_element(ALL(c))



using VI = vector<int>;

using VVI = vector<VI>;

using VL = vector<ll>;

using VVL = vector<VL>;

using VS = vector<string>;

using VVS = vector<VS>;

using VB = vector<bool>;

using VVB = vector<VB>;

using VC = vector<char>;

using VVC = vector<VC>;

using VD = vector<ld>;

using VVD = vector<VD>;

using P = pair<ll,ll>;

using VP = vector<P>;

using VVP = vector<vector<P>>;

const ll LINF = 2e18;

const int INF = 2e9;

const int MOD = 1e9+7;



//公約数がiのものが何個あるか？

//dp[i] := 和がiになるために必要な個数



void solve(){

  ll N, M;

  cin >> N >> M;

  VL cnt(N+1);

  rrep(i,1,N+1){

    ll g = N/i;

    g = g*(g-1)/2;

    rep(j,2,N+1){

      if(i*j > N){

        break;

      }

      g -= cnt[i*j];

    }

    cnt[i] = g;

  }

  

  /*rep(i,0,N+1){

    cout << cnt[i] << " ";

  }*/

  

  int p = N;

  ll ans = 0;

  while(M > 0){

    if(p == 1){

      break;

    }

    if(cnt[p] < p-1){

      p--;

      continue;

    }

    if(M < p-1){

      p--;

      continue;

    }

    ll X = min(M/(p-1), cnt[p]/(p-1));

    M -= X*(p-1);

    ans += p*X;

    cnt[p] -= X*(p-1);

  }

  if(M > 0){

    cout << -1 << endl;

    return;

  }

  cout << ans << endl;

}



int main(){

  ios::sync_with_stdio(false);

  cin.tie(nullptr);

  int T;

  cin >> T;

  //T = 1;

  for(int i=0; i<T; i++){

    solve();

  }

}