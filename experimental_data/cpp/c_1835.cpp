// ki bood ke goft Ghatinga?

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> ppiii;

// vectors and Sets:
#define vc vector
#define pb push_back
#define all(c) (c).begin(), (c).end()

// pairs
#define mp make_pair
#define fr first
#define sc second

// execution time check and Debug
#define StartEX clock_t startExeTime = clock();
#define EndEX clock_t endExeTime = clock();
#define ExTime cerr << "\nTotal Execution Time is: " << double(-double(startExeTime)+double(endExeTime)) / CLOCKS_PER_SEC;
#define debug(x) cerr << #x << " : " << x << '\n'
#define endl "\n"

// time optimization
#define Heh ios::sync_with_stdio(false);cin.tie(0);
#define Bah ios::sync_with_stdio(false);
#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

// useful functions
ll pw(ll a,ll b){
  ll ret = 1;
  ll mul = a;
  while(b > 0){
	if(b&1)
	  ret = (ret * mul);
	mul = (mul * mul);
	b >>= 1;
  }
  return ret;
}
ll pw(ll a,ll b,ll mod){
  ll ret = 1;
  ll mul = a;
  while(b > 0){
	if(b&1)
	  ret = (ret * mul) % mod;
	mul = (mul * mul) % mod;
	b >>= 1;
  }
  return ret;
}

ll to_int(string s){
  ll ret = 0;
  for(int i = 0 ; i < (int)s.size() ; i++) ret = 10 * ret + s[i] - '0';
  return ret;
}

bool deq(ld a , ld b){return (abs(a-b) < 0.000001);} // 10 ^ -6

int main()
{
  Heh;
  mt19937 mt(time(0));
  ll p[18];
  p[0] = 1;
  for(ll i = 1 ; i < 18 ; i++) p[i] = 10 * p[i-1];
  int tt;
  cin >> tt;
  while(tt--){
    int k;
    cin >> k;
    int n = 1 << (k + 1);
    ll a[n];
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    ll ps[n];
    ps[0] = a[0];
    for(int i = 1 ; i < n ; i++) ps[i] = ps[i-1] ^ a[i];
    map<ll,pii> vis;
    map<pii,int> viss;
    for(int i = 0 ; i < n ; i++){
      if(vis[a[i]].fr == 0)
	vis[a[i]] = {i+1,i+1} , viss[{i,i}] = 1;
    }
    for(int i = 1 ; i < n ; i++){
      if(vis[ps[i]].fr == 0)
	vis[ps[i]] = {1,i+1} , viss[{0,i}] = 1;
    }
    for(int _ = 0 ; _ < max(400 , n * 10) ; _++){
      int l = mt() % n , r = mt() % n;
      if(l > r) swap(l , r);
      if(viss[{l,r}]) continue;
      viss[{l,r}] = 1;
      ll x = ps[r];
      if(l) x ^= ps[l-1];
      if(vis[x].fr){
	l++ , r++;
	auto [a , b] = vis[x];
	if((a <= l and b >= r) or (l <= a and r >= b)) continue;
	if(a > l) swap(a , l) , swap(b , r);
	cout << a << " " << min(b , l-1) << " ";
	cout << max(l , b+1) << " " << r << endl;
	break;
      }
      vis[x] = {l+1,r+1};
    }
  }
}

// ki seda kard Patinga?