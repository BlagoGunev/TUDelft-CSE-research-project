#include <iostream>

#include <vector>

#include <algorithm>

#include <set>

#include <map>

#include <unordered_set>

#include <unordered_map>

#include <functional>

#include <string>

#include <cmath>

#include <iomanip>

#include <queue>

#include <stack>

#include <deque>

#include <bitset>

#include <iterator>

#include <ctime>

#include <random>



using namespace std;



typedef long long ll;

typedef long double ld;



#define forab(i,a,b) for(int(i)=(a);(i)<(b);++(i))

#define forba(i,b,a) for(int(i)=(b)-1;(i)>=(a);--(i))

#define forn(i,n) forab((i),0,(n))

#define forni(i,n) forba((i),(n),0)

#define forall(x,a) for(auto(x):(a))

#define sqr(x) ((x)*(x))

#define vii vector<int>

#define vll vector<ll>

#define vcc vector<char>

#define pii pair<int,int>

#define pll pair<ll,ll>

#define vpii vector<pii>

#define vpll vector<pll>

#define sii set<int>

#define sll set<ll>

#define spii set<pii>

#define spll set<pll>

#define msii multiset<int>

#define msll multiset<ll>

#define mii map<int,int>

#define mll map<ll,ll>

#define vvii vector<vector<int>>

#define mp make_pair

#define all(a) (a).begin(),(a).end()

#define rall(a) (a).rbegin(),a.rend()

#define pb push_back

#define eb emplace_back



const ld EPS = 1e-7;

const ld PI = acos(-1);

const ll INF = 1e9;

const ll MOD = 1e9 + 7;



mt19937 rnd(time(0));

mt19937_64 rndll(time(0));



void solve() {

	int n;

	cin >> n;

	

	vvii g(n);

	

	forn(i,n-1) {

		int u,v;

		cin >> u >> v;

		u--, v--;

		g[u].pb(v), g[v].pb(u);

	}

	

	vcc used(n), par(n);

	vii p(n);

	

	bool cor = true;

	

	function<void(int)> dfs = [&](int v) {

		used[v]++;

		

		int cnt0 = 0, cnt1 = 0;

		forall(to,g[v]) {

			if (!used[to]) {

				p[to] = v;

				dfs(to);

				if (par[to]) cnt1++;

				else cnt0++;

			}

		}

		if (v) {

			par[v] = int(cnt0>=cnt1);

			if (par[v]) cnt1++;

			else cnt0++;

		}

		if (cnt1 < cnt0 || cnt1 > cnt0 + 1)

			cor = false;

	};

	

	dfs(0);

	

	if (!cor) {

		cout << "NO\n";

		return;

	}

	cout << "YES\n";

	

	function<void(int)> ans = [&](int v) {

		vii pars0, pars1;

		forall(to,g[v]) {

			if (to != p[v])

				if (par[to]) pars1.pb(to);

				else pars0.pb(to);

			else

				if (par[v]) pars1.pb(v);

				else pars0.pb(v);

		}

		int cp = g[v].size() % 2;

		forn(i,g[v].size()) {

			int to;

			if (cp) to = pars1.back();

			else to = pars0.back();

			if (to == v) cout << v + 1 << ' ' << p[v] + 1 << '\n';

			else ans(to);

			if (cp) pars1.pop_back();

			else pars0.pop_back();

			cp++;

			cp %= 2;

		}

	};

	

	ans(0);

}



int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	

	int T = 1;

	cin >> T;

	

	while (T--)

		solve();

	

	return 0;

}