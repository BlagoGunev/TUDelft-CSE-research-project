#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for(int i=(a); i<(n); ++i)
#define per(i, a, n) for(int i=(a); i>(n); --i)
#define pb emplace_back
#define mp make_pair
#define clr(a, b) memset(a, b, sizeof(a))
#define all(x) (x).begin(),(x).end()
#define lowbit(x) (x & -x)
#define fi first
#define se second
#define lson o<<1
#define rson o<<1|1
#define gmid l[o]+r[o]>>1
 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll, ll>;
using ui = unsigned int;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr double EPS = 1e-8;
const double PI = acos(-1.0);

constexpr int N = 3010;

int T, n, k;
char s[N];
int dp[N][N], dp1[N][N], tmp[N], ans[N];
int dp2[N];

void upd(int &x, int y){
  if(x < y) x = y;
}

void solve(char x, char y){
  rep(i, 0, k + 1){
    dp[0][i] = 0;
    tmp[i] = 0;
  }
  rep(i, 1, n + 1){
    if(s[i] == x){
      rep(j, 0, k + 1)  ++tmp[j];
    } else {
      per(j, k, 0)  tmp[j] = tmp[j-1] + 1;
      tmp[0] = 0;
    }
    rep(j, 0, k + 1){
      dp[i][j] = max(dp[i-1][j], tmp[j]);
    }
  }
  rep(i, 0, k + 1){
    dp1[n+1][i] = 0;
    tmp[i] = 0;
  }
  per(i, n, 0){
    if(s[i] == y){
      rep(j, 0, k + 1)  ++tmp[j];
    } else {
      per(j, k, 0)  tmp[j] = tmp[j-1] + 1;
      tmp[0] = 0;
    }
    rep(j, 0, k + 1){
      dp1[i][j] = max(dp1[i+1][j], tmp[j]);
    }
  }

  rep(i, 0, n + 1){
    dp2[i] = -1;
  }

  upd(dp2[dp[n][k]], 0);
  upd(dp2[0], dp1[1][k]);

  rep(i, 1, n){
    rep(j, 0, k + 1){
      upd(dp2[dp[i][j]], dp1[i+1][k-j]);
    }
  }

  if(x == '0'){
    rep(i, 1, n + 1){
      rep(j, 0, n + 1){
        if(dp2[j] == -1)  continue;
        ans[i] = max(ans[i], j * i + dp2[j]);
      }
    }
  } else {
    rep(i, 1, n + 1){
      rep(j, 0, n + 1){
        if(dp2[j] == -1)  continue;
        ans[i] = max(ans[i], j + dp2[j] * i);
      }
    }
  }
}

void _main(){
  cin >> T;
  while(T--){
    cin >> n >> k;
    cin >> (s + 1);
    rep(i, 1, n + 1){
      ans[i] = 0;
    }
    solve('0', '1');
    solve('1', '0');
    rep(i, 1, n + 1){
      cout << ans[i] << " \n"[i == n];
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}