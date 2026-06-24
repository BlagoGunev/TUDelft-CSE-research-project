#include <bits/stdc++.h>

#define X first

#define Y second



using namespace std;



//#define endl '\n'

typedef long long LL;



const int MX = 200005;



int n, x, sz[MX], p[MX];

vector <int> con[MX];



bool check(){

	for(int i = 0; i < n; i++) if(p[i] != i) return 0;

	return 1;

}



int vis[MX];



int main() {

#ifndef ONLINE_JUDGE

    freopen("in.txt", "r", stdin);

#endif

    ios::sync_with_stdio(0);

    cin.tie(0); cout.tie(0);



	int Tc;

	for(cin >> Tc; Tc--;) {

		cin >> n >> x;

		x--;

		for(int i = 0; i < n; i++) con[i].clear(), vis[i] = 0;

		int u, v;

		for(int i = 0; i < n - 1; i++) {

			cin >> u >> v;

			u--, v--;

			con[u].push_back(v);

			con[v].push_back(u);

		}

		int pos = -1;

		for(int i = 0; i < n; i++) {

			sz[i] = con[i].size();

			if (sz[i] == n - 1) pos = i;

		}

		

		for(int i = 0; i < n; i++) cin >> p[i], p[i]--;

		

		int cnt = 0;

		for(int i = 0; i < n; i++) {

			if(vis[p[i]]) continue;

			u = p[i], v = p[u];

			vis[u] = 1;

			while(!vis[v]) {

				vis[v] = 1;

				v = p[v];

				cnt++;

			}

		}

		

//		cout << cnt << endl;

		

		if(check() || (pos == -1) || (cnt == 1 && (x == p[x]))) {

			cout << "Alice" << endl;

			continue;

		}

		if(p[pos] != pos && (x == pos || x == p[pos])) {

			cout << "Bob" << endl;

			continue;

		}

		if(cnt % 2 == 0) {

			if(x == pos) cout << "Bob" << endl;

			else cout << "Alice" << endl;

		}

		else {

			if(x == pos) cout << "Alice" << endl;

			else cout << "Bob" << endl;

		}

		

	}

    return 0;

}