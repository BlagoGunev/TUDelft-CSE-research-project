#include <bits/stdc++.h>

#define M 1010



using namespace std;



typedef long long ll;



ll S[M][M], SS[M][M], S1[M][M], S2[M][M], S3[M][M], S4[M][M], Ans[M][M], AA[M][M], n, m, k;



int main()

{

	scanf("%lld%lld%lld", &n, &m, &k);

	for(int i = 1; i <= n; i++)

		for(int j = 1; j <= m; j++) scanf("%lld", &S[i][j]), Ans[i][j] = k * S[i][j];

	k--;

	if(k) for(int T = 0; T < 4; T++) {

		for(int i = 1; i <= n; i++) {

			S4[i][m + 1] = 0;

			for(int j = 1; j <= m; j++) {

				S1[i][j] = S1[i - 1][j] + S1[i][j - 1] - S1[i - 1][j - 1] + S[i][j];

				S2[i][j] = S2[i - 1][j] + S1[i][j];

				if(i > k) S2[i][j] -= S1[i - k][j];

				S3[i][j] = S3[i][j - 1] + S1[i][j];

				if(j > k) S3[i][j] -= S1[i][j - k];

				S4[i][j] = S4[i - 1][j + 1] + S1[i][j];

				if(i > k && j <= m - k) S4[i][j] -= S1[i - k][j + k];

			}

		}

		for(int i = k; i <= n - k + 1; i++)

			for(int j = k; j <= m - k + 1; j++)

				Ans[i][j] += S4[i + k][j] - S2[i + k][j - 1] - S3[i][j + k - 1] + S1[i][j - 1] * (k + 1);

		for(int i = 1; i <= n; i++)

			for(int j = 1; j <= m; j++)

				SS[m - j + 1][i] = S[i][j], AA[m - j + 1][i] = Ans[i][j];

		swap(n, m);

		for(int i = 1; i <= n; i++)

			for(int j = 1; j <= m; j++)

				S[i][j] = SS[i][j], Ans[i][j] = AA[i][j];

	}

	k++;

	ll ans = -1, x, y;

	for(int i = k; i <= n - k + 1; i++)

		for(int j = k; j <= m - k + 1; j++)

			if(Ans[i][j] > ans) ans = Ans[i][j], x = i, y = j;

	printf("%lld %lld\n", x, y);

	return 0;

}