#include<bits/stdc++.h>



template<typename _Ty> void __(_Ty &x) {

	bool neg = false;

	unsigned c = getchar();

	for (; (c ^ 48) > 9; c = getchar()) if (c == '-') neg = true;

	for (x = 0; (c ^ 48) < 10; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);

	if (neg) x = -x;

}

template<typename _Ty> _Ty& read(_Ty &x) { __(x); return x; }

template<typename _Ty, typename ..._Tr> void read(_Ty &x, _Tr&... r) { __(x); read(r...); }



using s64 = long long;

using namespace std;



const int maxn = 105, mod = 998244353;



int a[maxn][maxn], n;

s64 dp[maxn][maxn];



bool valid(int x, int y) { // x > y

	for (int i = 0; i <= x; ++i) {

		if (a[i][x] == 1 && y >= i) return false;

		if (a[i][x] == 2 && y < i) return false;

	}

	return true;

}



int main() {



	read(n);

	for (int i = 1; i <= n; ++i) 

		for (int j = i; j <= n; ++j)

			read(a[i][j]);

			

	if (a[1][1] != 2) dp[1][0] = 2;

	

	for (int i = 1; i < n; ++i) {

		for (int j = 0; j < i; ++j) {

			(dp[i + 1][j] += valid(i + 1, j) * dp[i][j]) %= mod;

			(dp[i + 1][i] += valid(i + 1, i) * dp[i][j]) %= mod;

		}

	}

	

	s64 ans = 0;

	for (int i = 0; i < n; ++i) ans = (ans + dp[n][i]) % mod;

	

	cout << ans << endl;

	

	return 0;



}