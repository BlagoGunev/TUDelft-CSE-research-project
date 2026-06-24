#include <bits/stdc++.h>

#define debug_(x) cerr << #x << " = " << x << ' '

#define debug(x) cerr << #x << " = " << x << '\n'



using namespace std;



typedef long long ll;



const int N = (int)2e5;



const int INF = numeric_limits<int>::max();



int n, p[N + 1], f[N + 1][2];



int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	

	cin >> n;

	for(int i = 1; i <= n; i++) {

		cin >> p[i];

	}

	int last = n + 1;

	ll res = 0;

	for(int i = n; i >= 1; i--) {

		f[i][0] = INF;

		f[i][1] = -INF;

		for(int j = i + 1; j <= n; j++) {

			int g0 = -INF, g1 = INF;

			if(p[j] > p[j - 1]) g0 = max(g0, f[j - 1][0]);

			if(p[j] > f[j - 1][1]) g0 = max(g0, p[j - 1]);

			if(p[j] < p[j - 1]) g1 = min(g1, f[j - 1][1]);

			if(p[j] < f[j - 1][0]) g1 = min(g1, p[j - 1]);

			if(g0 == f[j][0] && g1 == f[j][1]) {

				break;

			}

			f[j][0] = g0, f[j][1] = g1;

			if(g0 == -INF && g1 == INF) {

				last = min(last, j);

			}

		}

		res += last - i;

	}

	cout << res << '\n';



	return 0;

}