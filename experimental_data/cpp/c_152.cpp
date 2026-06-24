#include <bits/stdc++.h>



using namespace std;



typedef long long ll;



const int N = 105;

const ll mod = (ll)1e9 + 7;



int n, m;

ll dp[N];

char c[N][N];

set < char > s;



int main() {



	cin >> n >> m;



	for (int i = 1; i <= n; i++)

		for (int j = 1; j <= m; j++)

			cin >> c[i][j];



	dp[0] = 1;



	for (int j = 1; j <= m; j++) {

		for (int i = 1; i <= n; i++) {

			s.insert(c[i][j]);

		}

		dp[j] = dp[j - 1] * (ll)s.size() % mod;

		s.clear();

	}



	cout << dp[m];



	return 0;

}