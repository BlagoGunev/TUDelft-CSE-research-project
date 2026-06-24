#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#define mod 998244353
#define maxn 2000005
#define maxm 2000005
#define int long long

using namespace std;

int a, b, c, d, fac[maxn], ifac[maxn], inv[maxn];

int C(int x, int y) {
	return fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int g(int x, int y) {
	return C(x + y - 1, y - 1);
}

void work() {
	cin >> a >> b >> c >> d;
	if(abs(a - b) > 1) {
		cout << "0\n";
		return ;
	}
	else {
		if(a == b) {
			if(a == 0) {
				if(c > 0 && d > 0) cout << "0\n";
				else cout << "1\n";
				return ;
			}
			cout << (g(c, a) * g(d, a + 1) % mod + g(d, a) * g(c, a + 1) % mod) % mod;
		}
		else {
			int p = max(a, b);
			cout << g(c, p) * g(d, p) % mod; 
		}
	}
	cout << '\n';
}

signed main() {
	inv[1] = fac[0] = ifac[0] = fac[1] = ifac[1] = 1;
	for(int i = 2; i <= 2000000; i++) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		fac[i] = i * fac[i - 1] % mod;
		ifac[i] = ifac[i - 1] * inv[i] % mod;
	}
	ios::sync_with_stdio(false); cin.tie(0);
	int _; cin >> _; while(_--) work();
}