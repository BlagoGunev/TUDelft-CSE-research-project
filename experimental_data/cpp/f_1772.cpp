// Problem: F. Copy of a Copy of a Copy

// Contest: Codeforces - Codeforces Round #839 (Div. 3)

// URL: https://codeforces.com/problemset/problem/1772/F

// Memory Limit: 256 MB

// Time Limit: 2000 ms

// 

// Powered by CP Editor (https://cpeditor.org)



#include<bits/stdc++.h>

#define endl '\n'

#define Carol MyWife^=^

#define pb push_back

#define pp pop_back

#define debug1(x) cout << #x << " = " << (x) << '\n'

#define debug2(x) cout << #x << " = " << (x) << ' '

//#define x first

//#define y second

using namespace std;

typedef long long LL;

typedef pair<int, int> PII;

const int N = 35, M = 35, K = 110;

const int MOD = 998244353, INF = 0x3f3f3f3f;

LL n, m, k;

struct Node {

	int id, cnt;

	char g[N][M];

} ;

struct OPT {

	int type;

	int x, y;

} ;

Node G[K];

int dx[4] = {0, -1, 0, 1};

int dy[4] = {-1, 0, 1, 0};

bool cmp(Node a, Node b) {

	return a.cnt > b.cnt;

}

void solve() {

	cin >> n >> m >> k;

	k ++;

	for(int a = 1; a <= k; a ++) {

		G[a].id = a;

		G[a].cnt = 0;

		for(int i = 1; i <= n; i ++) {

			for(int j = 1; j <= m; j ++)

				cin >> G[a].g[i][j];

		}

		for(int i = 1; i <= n; i ++) {

			for(int j = 1; j <= m; j ++){

				if(i == 1 || i == n || j == 1 || j == m) continue;

				bool f = true;

				for(int id = 0; id < 4; id ++){

					f &= ((G[a].g[i][j]-'0') ^ (G[a].g[i+dx[id]][j+dy[id]] - '0'));

				}

				if(f) G[a].cnt ++;

			}

		}

	}

	sort(G + 1, G + 1 + k, cmp);

	cout << G[1].id << endl;

	vector<OPT> ans;

	for(int a = 2; a <= k; a ++) {

		if(G[a].cnt < G[a - 1].cnt) {

			for(int i = 1; i <= n; i ++) {

				for(int j = 1; j <= m; j ++)

					if(G[a].g[i][j] != G[a - 1].g[i][j]) {

						ans.push_back({1, i, j});

					}

			}

			ans.push_back({2, G[a].id, -1});

		} else {

			ans.push_back({2, G[a].id, -1});

		}

	}

	cout << ans.size() << endl;

	for(auto res : ans) {

		if(res.y == -1) cout << res.type << ' ' << res.x << endl;

		else cout << res.type << ' ' << res.x << ' ' << res.y << endl;

	}

}



int main() {

	ios::sync_with_stdio(false);

	cin.tie(nullptr), cout.tie(nullptr);

	int t = 1;

	//cin >> t;

	while(t --) solve();

	

	return 0;

}