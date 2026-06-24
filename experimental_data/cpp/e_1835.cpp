#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll n, m, t;
ll b[3100];
ll f[3100][3100][3];
ll g[3100];
ll inv[10100];
bool vis[3100];

int main() {
	t = -1;
	inv[0] = inv[1] = 1;
	for (ll i = 2; i <= 10000; i++) {
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	}
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		if (vis[x]) {
			continue;
		}
		vis[x] = 1;
		b[++t] = i - 1;
	}
	b[++t] = n;
	for (ll i = t - 1; i >= 0; i--) {
		for (ll j = m - i; j >= 0; j--) {
			if (i + j + 1 <= m) {
				f[i][j][2] = ((f[i + 1][j][1] + b[i + 1] - b[i]) + (m - i - j - 1) * (f[i][j + 1][2] + 2) % mod) * inv[m - i - j] % mod;
			}
			f[i][j][1] = (m - i - j) * f[i][j][2] % mod;
			if (j >= 1) {
				f[i][j][1] = (f[i][j][1] + j * (f[i + 1][j - 1][1] + b[i + 1] - b[i]) % mod) % mod;
			}
			f[i][j][1] = f[i][j][1] * inv[m - i] % mod;
			f[i][j][0] = ((m - i - j) * (f[i][j + 1][0] + 2) % mod + (m - i - j) * inv[m - i - 1] % mod * f[i][j][2] % mod) % mod;
			if (j >= 1) {
				f[i][j][0] = (f[i][j][0] + (j - 1) * inv[m - i - 1] % mod * (f[i + 1][j - 1][1] + b[i + 1] - b[i]) % mod) % mod;
			}
			f[i][j][0] = f[i][j][0] * inv[m - i - j + 1] % mod;
		}
		g[i] = ((g[i + 1] + b[i + 1] - b[i]) + f[i][0][1] + min(i, 1ll) + 1 + (m - i - 1) * (f[i][1][0] + 2) % mod) * inv[m - i + 1] % mod;
	}
	printf("%lld\n", g[0]);
	return 0;
}