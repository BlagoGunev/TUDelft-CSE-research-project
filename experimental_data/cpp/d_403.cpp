#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN (1004)

typedef long long ll;
typedef pair <int, int> PII;
typedef vector <int> VI;

const int moder = 1000000007;

int T;
int N, K;

ll F[MAXN];
int C[MAXN][MAXN];
int dp1[MAXN][MAXN];
int dp2[MAXN][MAXN];

ll Cnr(int n, int r)
{
	if(r < 0 || r > n)
		return 0;
	return C[n][r];
}

int main()
{
	int i, j;

	C[0][0] = 1;
	for(i = 1; i < MAXN; ++i)
	{
		C[i][0] = C[i][i] = 1;
		for(j = 1; j < i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % moder;
	}

	F[0] = 1;
	for(i = 1; i < MAXN; ++i)
		F[i] = (F[i - 1] * i) % moder;

	dp1[1][0] = 1;
	for(i = 2; i < MAXN; ++i) // k
	{
		for(j = 1; j < MAXN; ++j) // n
		{
			ll res = 0;
			int i1 = i - 1;
			int i2 = j - i1 - 1;
			while(i2 >= 0)
			{
				res += dp1[i - 1][i2];
				i2 -= i1;
			}

			dp1[i][j] = res % moder;
		}
	}

	for(i = 1; i < MAXN; ++i)
	{
		for(j = 0; j < MAXN; ++j)
		{
			ll res = 0;
			int i1 = i;
			int i2 = j;
			while(i2 >= 0)
			{
				res += dp1[i][i2];
				i2 -= i1;
			}

			dp2[i][j] = res % moder;
		}
	}

	scanf("%d", &T);
	while(--T >= 0)
	{
		scanf("%d %d", &N, &K);
		--N;

		ll sol = 0;
		int b = N - K * (K - 1) / 2;
		for(i = 0; i <= b; ++i)
		{
			sol += (dp2[K][N - i] * Cnr(K + i, K)) % moder;
		}

		sol %= moder;
		sol = (sol * F[K]) % moder;
		printf("%d\n", (int) sol);
	}

	return 0;
}