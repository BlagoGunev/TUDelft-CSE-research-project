#include <bits/stdc++.h>



using namespace std;



#define ff first

#define ss second

#define vt vector

#define pb push_back

#define ppb pop_back

#define all(a) a.begin(), a.end()

#define tostr(x) to_string(x)

#define tonum(s) atoi(s.c_str())

#define ent "\n"

#define sp ' '



using ll  = long long;

using db  = double;

using ldb = long double;

using pll = pair <ll, ll>;

using pii = pair <int, int>;



const ll  INF = 8e18;

const int inf = 8e9 + 7;

const int MOD = 1e9 + 7;

const int M   = 1e3 + 7;

const int N   = 2e5 + 7;



/*-------------------------main-------------------------*/



vt <int> g[N];

int dep[N], tin[N], tout[N], up[N][21], timer;



void dfs(int v, int p = 1, int d = 0){

    dep[v] = d;

    tin[v] = ++timer;

    up[v][0] = p;

    for (int j = 1; j <= 20; j++) up[v][j] = up[up[v][j - 1]][j - 1];

    for (auto to : g[v]){

        if (to != p) dfs(to, v, d + 1);

    }

    tout[v] = ++timer;

}



bool par(int a, int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }



int lca(int a, int b){

    if (par(a, b)) return a;

    if (par(b, a)) return b;

    for (int j = 20; j >= 0; j--) if (!par(up[a][j], b)) a = up[a][j];

    return up[a][0];

}



void solve(){

    #define test

    int n;

    cin >> n;

    for (int i = 1; i < n; i++){

        int u, v;

        cin >> u >> v;

        g[u].pb(v);

        g[v].pb(u);

    }

    dfs(1);

    int q;

    cin >> q;

    while (q--){

        int k;

        cin >> k;

        vt <pii> v;

        for (int i = 1; i <= k; i++){

            int x;

            cin >> x;

            v.pb({dep[x], x});

        }

        sort(all(v));

        int x = v[k - 1].ss, y = 0;

        for (int i = k - 2; i >= 0; i--){

            if (!par(v[i].ss, x)){

                y = v[i].ss;

                break;

            }

        }

        if (k == 1 || y == 0){

            cout << "YES" << ent;

            continue;

        }

        int l = lca(x, y);

        bool ok = 1;

        for (int i = 0; i < k; i++){

            int c = v[i].ss;

            if (c == l || ((par(c, x) || par(c, y)) && !par(c, l))) continue;

            ok = 0;

        }

        cout << (ok ? "YES" : "NO") << ent;

    }

}



signed main() {

	//freopen("lca.in", "r", stdin);

	//freopen("lca.out", "w", stdout);

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	cout.tie(0);

	int testy;

	#ifdef tests

		cin >> testy;

	#endif

	#ifdef test

		testy = 1;

	#endif

	while (testy--) {

		solve();

	}

	return 0;

}