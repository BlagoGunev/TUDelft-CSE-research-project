#include <cstdio>

#include <algorithm>



static const auto AMAX = 1000;

static const auto BMAX = 1000;

static const auto CMAX = 10;



static int A, B, C;

static char a[AMAX + 1];

static char b[BMAX + 1];

static int LCP[AMAX + 1][BMAX + 1];

static int DP[AMAX + 1][BMAX + 1][1 + CMAX];



static inline void MAZ(int &a, int b) {

	if(a < b) a = b;

}



int main() {

	scanf("%d%d%d%s%s", &A, &B, &C, a, b);

	for(auto i = A; i >= 0; i--) {

		for(auto j = B; j >= 0; j--) {

			LCP[i][j] = (i != A && j != B && a[i] == b[j] ? 1 + LCP[i + 1][j + 1] : 0);

		}

	}

	for(auto i = A - 1; i >= 0; i--) {

		for(auto j = B - 1; j >= 0; j--) {

			auto lcp = LCP[i][j];

			for(auto k = 1; k <= C; k++) {

				auto dp = std::max(DP[i + 1][j][k], DP[i][j + 1][k]);

				if(lcp != 0) MAZ(dp, lcp + DP[i + lcp][j + lcp][k - 1]);

				DP[i][j][k] = dp;

			}

		}

	}

	printf("%d\n", DP[0][0][C]);

	return 0;

}