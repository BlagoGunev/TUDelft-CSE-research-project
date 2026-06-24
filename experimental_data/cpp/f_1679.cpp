#include <bits/stdc++.h>

using namespace std;



#define _				ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

#define all(x)			x.begin(), x.end()

#define pb				push_back

#define mp				make_pair

#define F				first

#define S				second

//#define mid				((L + R) >> 1ll)

#define lc				(id << 1ll)

#define rc				(lc | 1ll)

#define debug(x)		cerr << x << endl

#define int				long long



typedef long long ll;

typedef pair<int, int> pii;

const int maxn = 1e5 + 10;

const ll Inf = 1e17 + 10;

const int mod = 998244353;

const int LG = 23;

int n, m, ans;

int a[55][55];

int Mp[(1 << 10) + 10][20], dp[(1 << 10) + 10], pd[(1 << 10) + 10];



int add(int a, int b){

	int c = a + b;

	if(c < 0)

		c += mod;

	if(c >= mod)

		c -= mod;

	return c; 	

}



inline int mul(int a, int b){

	return 1ll * a * b % mod;	

}



inline int pwr(int a, int b){

	int res = 1;

	for( ; b ; b >>= 1ll , a = 1ll * a * a % mod)

		if(b & 1ll)

			res = 1ll * res * a % mod;

	return res;	

}



inline int Inv(int a){

	return pwr(a, mod - 2);	

} 





int32_t main(){_

	cin >> n >> m;

	for(int i = 1 ; i <= m ; i ++){

		int u, v;

		cin >> u >> v;

		a[v][u] = a[u][v] = 1;

	}

	

	for(int msk = 0 ; msk < (1 << 10) ; msk ++)

		for(int i = 0 ; i <= 9 ; i ++)

			for(int j = 0 ; j <= 9 ; j ++)

				if((j < i || msk & (1 << j)) && a[i][j])

					Mp[msk][i] |= (1 << j);

	

	

	dp[0] = 1; 

	for(int i = 1 ; i <= n ; i ++){

		memset(pd, 0, sizeof pd);		

		for(int msk = 0 ; msk < (1 << 10) ; msk ++)

			if(dp[msk])

				for(int j = 0 ; j <= 9 ; j ++){

					if(msk & (1 << j))

						continue;

					pd[Mp[msk][j]] = add(pd[Mp[msk][j]], dp[msk]);

				}

				

		for(int j = 0 ; j < (1 << 10) ; j ++)

			dp[j] = pd[j];

	}

	

	for(int i = 0 ; i < (1 << 10) ; i ++)

		ans = add(ans, dp[i]);

		

	cout << ans << '\n';

	return 0;

}