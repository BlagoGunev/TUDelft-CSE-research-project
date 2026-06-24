#include <bits/stdc++.h>

/*#include <ext/pb_ds/detail/standard_policies.hpp>

#include <ext/pb_ds/tree_policy.hpp>

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

*/

//#pragma GCC optimize("Ofast")

//#pragma GCC optimize("unroll-loops")

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native") //bad

//#pragma GCC target("avx,avx2")

#define ll long long

#define ull unsigned ll

#define ff first

#define ss second

#define int ll

#define all(v) v.begin(), v.end()

#define rall(v) v.rbegin(), v.rend()

#define pb push_back

#define pii pair <int, int>

#define pdd pair <double, double>

#define _size(a) (int)a.size()

using namespace std;

mt19937 rnd(time(nullptr));

const ll inf = 1e15;

//constexpr ll mod = 998244353;

constexpr ll mod = 1e9+7;

const int N = 3e5+10, B = 350;

inline int sqr(int a){ return a * a; }

inline int pw2(int x){ return (1ll << x); }



vector < vector <int> > g(N);

vector <int> p(N), a(N), sz(N), cnt(N);



void dfs(int v){

	sz[v] = a[v];

	if (g[v].size() == 0 && v != 1) cnt[v] = 1;

	

	for (auto to : g[v]){

		if (to == p[v]) continue;

		dfs(to);

		sz[v] += sz[to];

		cnt[v] += cnt[to];

	}

}



void solve(){

	int n;

	cin >> n;

	for (int i = 2; i <= n; ++i){

		cin >> p[i];

		g[p[i]].pb(i);

	}

	for (int i = 1; i <= n; ++i) cin >> a[i];

	

	dfs(1);

	int ans = 0;

	for (int i = 1; i <= n; ++i) ans = max(ans, (sz[i] + cnt[i] - 1) / cnt[i]);

	cout << ans;

}



signed main(){

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tt = 1;

	//cin >> tt;

    while (tt--){

        solve();

        cout << '\n';

    }

}