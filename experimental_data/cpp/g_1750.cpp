#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



const int maxn = 2e3 + 10;

int n, mod;

int c[maxn][maxn];

int f[maxn][maxn];

int a[maxn];

int u[maxn];

int fac[maxn];

ll ans[maxn];



int main(){

	cin >> n >> mod;

	for( int i = 1 ; i <= n ; ++ i ){

		u[i] = 1;

	}

	u[0] = u[n+1] = 0;

	for( int i = 0 ; i <= n ; ++ i ){

		for( int j = 0 ; j <= n ; ++ j ){

			c[i][j] = f[i][j] = 0;

		}

	}

	for( int i = 0 ; i <= n ; ++ i ){

		c[i][0] = c[i][i] = 1;

		for( int j = 1 ; j < i ; ++ j ){

			c[i][j] = ( c[i-1][j-1] + c[i-1][j] ) % mod;

		}

	}



	fac[0] = 1;

	for( int i = 1 ; i <= n ; ++ i ){

		fac[i] = (ll) fac[i-1] * i % mod;

	}

	f[0][0] = 1;

	for( int i = 1 ; i <= n ; ++ i ){

		f[i][0] = fac[i];

		for( int j = 1 ; j <= n ; ++ j ){

			f[i][j] = ( f[i][j-1] - f[i-1][j-1] + mod ) % mod;

		}

	}



	for( int i = 0 ; i <= n + 2 ; ++ i ){

		ans[i] = 0;

	}

	for( int i = 1 ; i <= n ; ++ i ){

		cin >> a[i];

	}



	int cnt = 0;

	a[0] = -100;

	for( int i = 1 ; i <= n ; ++ i ){

		int cut0 = 0;

		int cut1 = 0;

		int fix  = 0;

		for( int j = 1 ; j < a[i] ; ++ j ){

			if( u[j] == 1 && u[j-1] == 0 ){

				++ cut0;

			}

			if( u[j] == 1 && u[j-1] == 1 ){

				++ cut1;

			}

			if( u[j] == 1 && j == a[i-1] + 1 ){

				++ fix;

			}

		}

		cut0 -= fix;

		int link = 0;

		for( int j = 1 ; j <= n ; ++ j ){

			if( u[j] == 1 && u[j-1] == 1 ){

				++ link;

			}

		}

		for( int uslink = 0 ; uslink <= link ; ++ uslink ){

			ans [ cnt+n-i-uslink + 1 - 1 ] += (ll) c[link][uslink] * f[n-i-uslink][link-uslink] % mod * fix % mod;

		}

		for( int uslink = 0 ; uslink <= link ; ++ uslink ){

			ans [ cnt+n-i-uslink + 1 ] += (ll) c[link][uslink] * f[n-i-uslink][link-uslink] % mod * cut0 % mod;

		}

		-- link;

		for( int uslink = 0 ; uslink <= link ; ++ uslink ){

			ans [ cnt+n-i-uslink + 1 ] += (ll) c[link][uslink] * f[n-i-uslink][link-uslink] % mod * cut1 % mod;

		}

		u[a[i]] = 0;

		if( i == 1 || a[i] != a[i-1] + 1 ){

			++ cnt;

		}

	}



	for( int i = 1 ; i <= n ; ++ i ){

		cout << ans[i] % mod << ' ';

	}

	cout << '\n';

}