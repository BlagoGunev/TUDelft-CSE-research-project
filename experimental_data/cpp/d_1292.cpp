#include<bits/stdc++.h>

typedef long long ll;

typedef unsigned long long ull;

#define rep(i, a, b) for(int i = (a); i <= (b); i ++)

#define per(i, a, b) for(int i = (a); i >= (b); i --)

#define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)

using namespace std;



inline int read() {

	int x = 0, f = 1; char c = getchar();

	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();

	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();

	return x * f;

}



const int N = 5010;

int n, m, c[N], p[N], s[N], f[N][N];



int main() {

	n = read();

	rep(i, 1, n) {int x = read(); c[x] ++, m = max(m, x);}

	rep(i, 2, m) {

		rep(j, 2, i) f[i][j] = f[i - 1][j];

		int cur = i;

		for(int k = 2; k <= cur; k ++) while(cur % k == 0) cur /= k, f[i][k] ++;

	}

	

	ll sum = 0;

	

	p[0] = 1;

	rep(i, 1, m) {

		if(! c[i]) {p[i] = 1; continue;}

		rep(j, 1, i) if(f[i][j]) p[i] = j, sum += 1ll * f[i][j] * c[i];

	}

	

	ll ans = sum;

	

	while(true) {

		int pos = 1;

		rep(i, 1, m) s[i] = 0;

		rep(i, 0, m) s[p[i]] += c[i];

		rep(i, 1, m) if(s[i] > s[pos]) pos = i;

		if(pos == 1 || s[pos] == 1 || 2 * s[pos] <= n) break;

		

		ans = min(ans, sum -= s[pos] * 2 - n);

		rep(i, 0, m) {

			if(p[i] != pos || p[i] == 1) {p[i] = 1; continue;}

			-- f[i][p[i]];

			while(p[i] > 1 && ! f[i][p[i]]) p[i] --;

		}

	}

	

	printf("%lld\n", ans);

	

	return 0;

}