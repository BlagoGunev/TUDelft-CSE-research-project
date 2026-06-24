#include<bits/stdc++.h>



const int N = 3e5 + 5, M = 30 * N;

int trie[M][2], dp[M][2];



int main()

{

	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);



	int T; std::cin >> T;

	while (T--)

	{

		int n; std::cin >> n;

		int ans = 0, cnt = 1;

		for (int i = 0; i < n; ++i)

		{

			int x; std::cin >> x;

			int v = (x ^ i), MID = 0, u = 1;

			for (int p = 29; ~p; --p)

			{

				int k = ((v >> p) & 1);

				MID = std::max(MID, dp[trie[u][!k]][!((x >> p) & 1)]);

				u = trie[u][k];

			}

			MID++; ans = std::max(ans, MID); u = 1;

			for (int p = 29; ~p; --p)

			{

				int k = ((v >> p) & 1);

				if (!trie[u][k])trie[u][k] = ++cnt;

				u = trie[u][k]; k = ((i >> p) & 1);

				dp[u][k] = std::max(dp[u][k], MID);

			}

		}

		std::cout << ans << "\n";



		for (int i = 1; i <= cnt; ++i)dp[i][0] = dp[i][1] = trie[i][0] = trie[i][1] = 0;

	}



	return 0;

}