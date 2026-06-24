#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 200005, mod = 998244353;
ll modpow(ll a, int b){
	ll res = 1;
	for(; b; b >>= 1){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}
int b[maxn];
int main(){
	int n, m, K;
	scanf("%d%d%d", &n, &m, &K);
	for(int i = 1; i <= m; i++) scanf("%d", b + i);
	n -= b[m] * 2;
	for(int i = m; i >= 1; i--) b[i] -= b[i - 1];
	ll res = 1;
	for(int i = 1; i <= m; i++){
		ll t = modpow(K, b[i]);
		res = t * (t + 1) / 2 % mod * res % mod;
	}
	printf("%lld\n", res * modpow(K, n) % mod);
	return 0;
}