#include <bits/stdc++.h>



#if (_WIN32 || __WIN32__)

#  define LLD "%I64d"

#else

#  define LLD "%lld"

#endif



using std::istream; using std::ostream; using std::fixed; using std::greater;

using std::tuple; using std::tie; using std::make_pair; using std::multiset;

using std::nth_element; using std::min_element; using std::max_element;

using std::vector; using std::set; using std::map; using std::string;

using std::fill; using std::copy; using std::sort; using std::unique;

using std::unordered_set; using std::unordered_map; using std::pair;

using std::next_permutation; using std::reverse; using std::rotate;

using std::cin; using std::cout; using std::cerr; using std::endl;

using std::lower_bound; using std::upper_bound; using std::deque;

using std::min; using std::max; using std::swap; using std::abs;

using std::priority_queue; using std::queue; using std::bitset;



typedef long long ll;

typedef long double ld;



int const INF = (int) 1e9;

ll const INFL = (ll) 1e18;

ld const PI = 3.1415926535897932384626433832795028;





int const N = 100100;





vector<pair<int, int>> g[N];





ll dfs(int v, int anc) {

	ll ret = 0;

	

	for (auto e : g[v]) {

		int to = e.first;

		

		if (to == anc) {

			continue;

		}

		

		ret = max(ret, e.second + dfs(to, v));

	}

	

	return ret;

}





void solve() {

	

	int n;

	scanf("%d", &n);

	

	ll sum = 0;

	

	for (int i = 0; i < n - 1; ++i) {

		int a, b, w;

		scanf("%d%d%d", &a, &b, &w);

		--a, --b;

		g[a].emplace_back(b, w);

		g[b].emplace_back(a, w);

		sum += w;

	}

	

	sum *= 2;

	sum -= dfs(0, -1);

	

	printf(LLD "\n", sum);

	

}







int main() {



	cout.precision(15);

	cout << fixed;

	cerr.precision(6);

	cerr << fixed;

	

	srand(1510);



	solve();



#ifdef LOCAL

	cerr << "time: " << clock() << " ms" << endl;

#endif

}