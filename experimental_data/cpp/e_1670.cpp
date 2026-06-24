// BEGIN BOILERPLATE CODE



#include <bits/stdc++.h>

using namespace std;



#ifdef KAMIRULEZ

	const bool kami_loc = true;

	const long long kami_seed = 69420;

#else

	const bool kami_loc = false;

	const long long kami_seed = chrono::steady_clock::now().time_since_epoch().count();

#endif



const string kami_fi = "kamirulez.inp";

const string kami_fo = "kamirulez.out";

mt19937_64 kami_gen(kami_seed);



long long rand_range(long long rmin, long long rmax) {

	uniform_int_distribution<long long> rdist(rmin, rmax);

	return rdist(kami_gen);

}



void file_io(string fi, string fo) {

	if (fi != "" && (!kami_loc || fi == kami_fi)) {

		freopen(fi.c_str(), "r", stdin);

	}

	if (fo != "" && (!kami_loc || fo == kami_fo)) {

		freopen(fo.c_str(), "w", stdout);

	}

}



void set_up() {

	if (kami_loc) {

		file_io(kami_fi, kami_fo);

	}

	ios_base::sync_with_stdio(0);

	cin.tie(0);

}



void just_do_it();



void just_exec_it() {

	if (kami_loc) {

		auto pstart = chrono::steady_clock::now();

		just_do_it();

		auto pend = chrono::steady_clock::now();

		long long ptime = chrono::duration_cast<chrono::milliseconds>(pend - pstart).count();

		string bar(50, '=');

		cout << '\n' << bar << '\n';

		cout << "Time: " << ptime << " ms" << '\n';

	}

	else {

		just_do_it();

	}

}



int main() {

	set_up();

	just_exec_it();

	return 0;

}



// END BOILERPLATE CODE



// BEGIN MAIN CODE



const int ms = 1.5e5 + 20;

vector<pair<int, int>> adj[ms];

int e[ms][2];

int res[ms][2];

int pt;

int n;



void dfs(int u, int pr, bool f) {

	for (auto x: adj[u]) {

		int v = x.first;

		int k = x.second;

		if (v != pr) {

			pt++;

			if (!f) {

				res[k][1] = n + pt;

				res[v][0] = pt;

			}

			else {

				res[k][1] = pt;

				res[v][0] = n + pt;

			}

			dfs(v, u, !f);

		}

	}

}



void query() {

	cin >> n;

	n = (1 << n);

	for (int i = 1; i <= n; i++) {

		adj[i].clear();

	}

	for (int i = 0; i < n - 1; i++) {

		int u, v;

		cin >> u >> v;

		e[i][0] = u;

		e[i][1] = v;

		adj[u].push_back({v, i});

		adj[v].push_back({u, i});

	}

	res[1][0] = n;

	pt = 0;

	dfs(1, -1, 0);

	cout << 1 << '\n';

	for (int i = 1; i <= n; i++) {

		cout << res[i][0] << " ";

	}

	cout << '\n';

	for (int i = 0; i < n - 1; i++) {

		cout << res[i][1] << " ";

	}

	cout << '\n';

}



void just_do_it() {

	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {

		query();

	}

}



// END MAIN CODE