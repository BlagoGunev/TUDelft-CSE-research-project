#include <cmath>

#include <vector>

#include <cstdio>

#include <cstring>

#include <iostream>

#include <algorithm>

using namespace std;

#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

#define endl '\n'

#define x first

#define y second

#define pb push_back

typedef long long LL;



const int N = 200005, mod = 1e9 + 7;

LL n, m, h;

vector<pair<LL, LL>> g[N];

LL vis[N], f[N], is_good;



LL qpow(LL a, LL b) {

	LL ret = 1;

	while (b) {

		if (b & 1) ret = ret * a % mod;

		a = a * a % mod;

		b >>= 1;

	}

	return ret;

}



void dfs(int x,int val) {

    vis[x] = 1; f[x] = val;

    for(auto pa : g[x]) {

        LL y = pa.x, dis = pa.y;

        if (f[y] == -1) {

            int s=((-val - dis)%h + h)%h;

            dfs(y,s);

        }

        else if(((val + f[y] + dis)%h + h)%h) is_good=0;

    }

}



inline void solve() {

	cin >> n >> m >> h;

	for (int i = 1; i <= n + m; i++) vis[i] = 0, g[i].clear(), f[i] = -1;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= m; j++) {

			LL x; cin >> x;

			if (x != -1) {

				g[i].pb({j + n, x});

				g[j + n].pb({i, x});

			}

		}

	}

	LL ans = 1, cnt = 0;

	for (int i = 1; i <= n + m; i++) {

		if (vis[i]) continue;

		vis[i] = 1;

		if (g[i].empty()) cnt++;

		else {

			f[i] = 0;

			is_good = 1;

			dfs(i, 0);

			if (is_good) cnt++;

			else ans = 0;

		}

	}

	if (ans == 0) cout << 0 << endl;

	else cout << qpow(h, cnt-1) << endl;

}



int main()

{

	fastio;

	// freopen("coding/test.in","r",stdin);

	// freopen("coding/test.out","w",stdout);

	int t = 1; 

	cin >> t;

	while (t--) {

		solve();

	}

	return 0;

}

/*



*/