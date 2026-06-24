#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

#define rep(i,a,b) for(ll i=(a); i<(b); ++i)
#define repc(i,a,b,c) for(ll i=(a); i<(b); i+=c)
#define repn(i,a,b) for(ll i=(a); i>(b); --i)
#define trav(a,x) for(auto& a: x)
#define travm(a,x) for(const auto& [a, v]: x)
#define all(x) begin(x),end(x)
#define sz(x) (int)size(x)
#define tmod(a) ((a%MOD)+MOD)%MOD
#define tmod2(a) ((a%MOD2)+MOD2)%MOD2
#define tmodc(a,b) ((a%b)+b)%b
#define madd(a,b) (tmod(a)+tmod(b))%MOD
#define madd2(a,b) (tmod2(a)+tmod2(b))%MOD2
#define maddc(a,b,c) (tmodc(a,c)+tmodc(b,c))%c
#define pb push_back
#define mp make_pair
#define cauto const auto
using ll = long long;
int iINF = numeric_limits<int>::max();
int MOD = 1e9+7;
int MOD2 = 1e9+22;
#define int ll
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vd = vector<double>;
using vll = vector<ll>;
using vpii = vector<pii>;

ll lINF = numeric_limits<ll>::max();
ll negINF = lINF+1;
double EPS = .00001;
cauto maxn = 200001;

void solve()
{
  int n;
  cin >> n;
  vi p(n);
  rep(i,1,n+1)
  {
    string s;
    cin >> s;
    int ind = 0;
    rep(j,1,i) if(s[j-1]=='1') ind++;
    rep(j,i+1,n+1) if(s[j-1]=='0') ind++;
    p[ind] = i;
  }
  rep(i,0,n) cout << p[i] << " ";
  cout << "\n";
}
void pre()
{
  
}
int32_t main() 
{
  ios::sync_with_stdio(false);
  pre();
  int t=1; cin >> t;
  while(t--) solve();
}
/*
When flooring double that has been divided, add .00000000001
Careful mixing subtracting and mod!
*/