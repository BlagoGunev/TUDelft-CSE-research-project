#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = (ll)1e9 + 7;
template<class t, class u>
ostream& operator<<(ostream& os, const pair<t, u> &p){
	return os << "(" << p.first << ", " << p.second << ")";
}
template<class t>
ostream& operator<<(ostream& os,const vector<t> &v){
	os << "{";
  for (auto e : v)
    os << e << " ";
	return os << "}";
}
ll pow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1)  res = res * x % mod;
    n >>= 1;
    x = x * x % mod;
  }
  return res;
}
int main() {
  ll x, n;
  scanf("%lld%lld", &x, &n);
  vector<ll> prime;
  ll tmp = x;
  for (ll i = 2; i * i <= x; ++i) {
    int num = 0;
    while (tmp % i == 0) {
      ++num;
      tmp /= i;
    }
    if (num) {
      prime.push_back(i);
    }
  }
  if (tmp > 1)  prime.push_back(tmp);
  // cout << prime << endl;
  ll ans = 1;
  for (ll p : prime) {
    ll tmp = n, sum = 0;
    while (tmp) {
      sum += tmp / p;
      tmp /= p;
    }
    ans = ans * pow(p, sum) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}