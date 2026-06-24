#pragma GCC optimize("Ofast")

#pragma GCC optimize("unroll-loops")

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")

#include<bits/stdc++.h>

using std::cin;

using std::cout;

const int N = 100005;

struct db { int exp; unsigned value; };

const unsigned lim = 1u << 31;

void operator += (db & x, const db & y) {

	if(x.exp >= y.exp) {

		if(x.exp - y.exp < 31) {

			x.value += y.value >> (x.exp - y.exp);

			if(x.value >= lim) {

				x.value >>= 1;

				x.exp += 1;

			}

		}

	} else {

		if(y.exp - x.exp < 31) {

			x.value = (x.value >> (y.exp - x.exp)) + y.value;

			x.exp = y.exp;

			if(x.value >= lim) {

				x.value >>= 1;

				x.exp += 1;

			}

		} else {

			x = y;

		}

	}

}

int n;

db mem[N * 2], *dp = mem + N;

char c[N];

int main() {

	std::ios::sync_with_stdio(false), cin.tie(0);

	cin >> n;

	dp[1] = {0, 1};

	for(int i = 1;i < n;++i) cin >> c[i];

	for(int i = 1;i < n;++i) {

		char c = ::c[i];

		if(c == ::c[i + 1]) {

			if(c != '>') {

				db tmp = {0, 0};

				for(int j = 1;j <= i;++j) {

					dp[j] += tmp;

					tmp = dp[j];

					dp[j] += dp[j - 1];

				}

				dp -= 2;

			} else {

				db tmp = {0, 0};

				for(int j = i;j >= 1;--j) {

					dp[j] += tmp;

					tmp = dp[j];

					dp[j] += dp[j +  1];

				}

			}

			i += 1;

			continue;

		}

		if(c != '>') {

			for(int j = 1;j <= i;++j) {

				dp[j] += dp[j - 1];

			}

			-- dp;

		} else {

			for(int j = i;j >= 1;--j) {

				dp[j] += dp[j + 1];

			}

		}

	}

	db ans = {0, 0};

	for(int i = 1;i <= n;++i) {

		ans += dp[i];

	}

	printf("%.20lf\n", ans.exp + std::log2(ans.value));

}