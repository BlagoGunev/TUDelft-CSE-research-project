#include <bits/stdc++.h>
#define LL long long
#define mes(s, x) memset(s, x, sizeof(s))
#define Maxn 500005
#define mod 998244353
using namespace std;
inline LL read(){char c;c = getchar();while(!(('0' <= c && c <= '9') || c == '-')) c = getchar();bool flag = 0;if(c == '-'){flag = 1;c = getchar();}LL tot = 0;while('0' <= c && c <= '9'){tot = 10 * tot + c - '0';c = getchar();}return flag ? -tot : tot;}
LL e[Maxn], frac[Maxn], _frac[Maxn];
LL C(int i, int j){
	if(i < 0 && i > j) return 0;
	return frac[j] * _frac[i] % mod * _frac[j - i] % mod;
}
LL Pow(int i, int x){
	if(i == 0) return 1;
	LL t = Pow(i >> 1, x);
	t = t * t % mod;
	if(i & 1) t = t * x % mod;
	return t;
}
LL f(int i){
	if(i == 1) return 1;
	return Pow(i - 2, i);
}
int main(){
	int n = read();
	if(n % 2){
		printf("0");
		return 0;
	}
	LL ans = 0;
	e[1] = 1;
	for(int i = 2; i <= n; i++) e[i] = (mod - (mod / i) * e[mod % i] % mod) % mod;
	frac[0] = _frac[0] = 1;
	for(int i = 1; i <= n; i++){
		frac[i] = i * frac[i - 1] % mod;
		_frac[i] = e[i] * _frac[i - 1] % mod;
	}
	for(int i = 0; i < n - 1; i++){
		if(i % 2) ans = (ans + C(i, n - 2) * f(i + 1) % mod * f(n - i - 1) % mod * (i + 1) % mod * (n - i - 1) % mod) % mod;
		else ans = (ans - C(i, n - 2) * f(i + 1) % mod * f(n - i - 1) % mod * (i + 1) % mod * (n - i - 1) % mod + mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}