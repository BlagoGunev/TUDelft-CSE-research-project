#include<bits/stdc++.h>

#define debug(x) cerr << #x << " = " << x << '\n';

#define debug_(x) cerr << #x << " = " << x << ' ';



using namespace std;



typedef long long ll;



const ll P = (ll)1e9 + 7;



ll qpow(ll a, ll n) {

	ll res = 1;

	while(n) {

		if(n & 1) res = res * a % P;

		a = a * a % P;

		n >>= 1;

	}

	return res;

}



ll inv(ll x) {

	return qpow(x, P - 2);

}



int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	

	int n;

	cin >> n;

	auto dis = vector(n, vector<int>(n, numeric_limits<int>::max() >> 1)); 

	for(int i = 0; i < n - 1; i++) {

		int u, v;

		cin >> u >> v;

		u--, v--;

		dis[u][v] = dis[v][u] = 1;

	}

	

	auto f = vector(n, vector<int>(n, 0));

	for(int i = 0; i < n; i++) {

		for(int j = (i == 0); j < n; j++) {

			if(i == 0) f[i][j] = 1;

			else if(j == 0) f[i][j] = 0;

			else f[i][j] = (f[i - 1][j] + f[i][j - 1]) * inv(2) % P;

		}

	}

	for(int i = 0; i < n; i++) dis[i][i] = 0;

	for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

	ll res = 0;

	for(int rt = 0; rt < n; rt++) {

		for(int i = 0; i < n; i++) {

			for(int j = i + 1; j < n; j++) {

				int common = (dis[rt][i] + dis[rt][j] - dis[i][j]) / 2;

				int l1 = dis[rt][i] - common;

				int l2 = dis[rt][j] - common;

				(res += f[l2][l1]) %= P;

			}

		}

	}

	(res *= inv(n)) %= P;

	cout << res << '\n';

	

	return 0;

}