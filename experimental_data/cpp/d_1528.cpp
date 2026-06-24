#include<bits/stdc++.h>



using namespace std;



typedef long long ll;



inline void min(ll& a ,ll b) {if(a > b) a = b;}



int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

	cout.tie(0);

	

	int n, m;

	cin >> n >> m;

	auto cost = vector(n, vector<ll>(n, (ll)1e15));

	for(int i = 0; i < m; i++) {

		int a, b;

		ll c;

		cin >> a >> b >> c;

		for(int j = 0; j < n; j++) {

			ll d = (n + j - b) % n;

			min(cost[a][j], d + c);

		}

	}

	

	auto res = vector(n, vector<int>(n, -1));

	auto dij = [&](int s, vector<int>& dis) {

		vector<int> vis(n, 0);

		dis[s] = 0;

		for(int it = 0; it < n; it++) {

			int u = -1;

			for(int i = 0; i < n; i++) {

				if(dis[i] == -1 || vis[i]) continue;

				if(u == -1 || dis[i] < dis[u]) u = i;

			}

			vis[u] = 1;

			

			for(int v = 0; v < n; v++) {

				if(vis[v]) continue;

				if(dis[v] == -1 || dis[v] > dis[u] + cost[u][((v - dis[u]) % n + n) % n]) {

					dis[v] = dis[u] + cost[u][((v - dis[u]) % n + n) % n];

				}

			}

		}

	};

	

	for(int i = 0; i < n; i++) {

		dij(i, res[i]);

	}

	for(int i = 0; i < n; i++) {

		for(int j = 0; j < n; j++) {

			cout << res[i][j] << " \n"[j == n - 1];

		}

	}

	

	return 0;

}