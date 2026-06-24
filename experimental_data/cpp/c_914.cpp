#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e3+5, MOD = 1e9+7;

ll K, fact[MAXN], ifact[MAXN];
string str;

ll pkt(ll a, ll b) {
 ll ret = 1;
 ll base = a;
 while (b) {
  if (b&1) ret = ret*base%MOD;
  base = base*base%MOD;
  b >>= 1;
 }
 return ret;
}

ll hitung(ll x) {
 ll cnt = 0;
 while (x != 1) {
  x = __builtin_popcount(x);
  cnt++;
 }
 return cnt;
}

int main() {
 ios::sync_with_stdio(0); cin.tie(0);
 
 fact[0] = 1;
 ifact[0] = 1;
 for (int i = 1; i < MAXN; i++) {
  fact[i] = fact[i-1]*i%MOD;
  ifact[i] = pkt(fact[i], MOD-2);
 }
 
 cin >> str;
 cin >> K;
 if (K == 0) return cout << "1\n", 0;
 
 ll ans = 0;
 for (int i = 1; i <= 1000; i++) {
  if (hitung(i) != K-1) continue;
  ll cnt = 0;
  for (int j = 0; j < (int)str.length(); j++) {
   if (str[j] == '1') {
    ll tempat = str.length()-j-1;
    if (i-cnt > tempat) {
     cnt++;
     continue;
    }
    if (cnt > i) break;
    ll now = fact[tempat]*ifact[i-cnt]%MOD*ifact[tempat-(i-cnt)]%MOD;
    ans = (ans+now)%MOD;
    cnt++;
   }
  }
  if (cnt == i) ans = (ans+1)%MOD;
 }
 if (K == 1) ans--;
 cout << ans << "\n";
 
 return 0;
}