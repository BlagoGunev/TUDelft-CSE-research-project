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



const int ms = 5e5 + 20;

int e[300020][2];

int qs[500020][2];

bool f[300020];

int g[300020];

int par[200020][2];

int de[200020];

int fa[200020];

int a[200020];

int pt[200020][2];

int pp[200020];

int tr[800020];

deque<int> ch[200020];

int tz = 1;



int root(int u) {

	if (par[u][0] == 0) {

		return u;

	}

	return root(par[u][0]);

}



int update(int u, int v, int pp) {

	int ru = root(u);

	int rv = root(v);

	if (ru == rv) {

		return -1;

	}

	if (de[ru] > de[rv]) {

		swap(ru, rv);

	}

	par[ru][0] = rv;

	par[ru][1] = pp;

	ch[rv].push_front(ru);

	if (de[ru] == de[rv]) {

		de[rv]++;

	}

	return rv;

}



void dfs(int u) {

	pt[u][0] = tz++;

	for (auto v: ch[u]) {

		dfs(v);

	}

	pt[u][1] = tz - 1;

}



void build(int cc, int lt, int rt) {

	if (lt == rt) {

		tr[cc] = a[lt];

		return;

	}

	int mt = (lt + rt) / 2;

	build(cc * 2, lt, mt);

	build(cc * 2 + 1, mt + 1, rt);

	tr[cc] = max(tr[cc * 2], tr[cc * 2 + 1]);

}



void update(int cc, int lt, int rt, int px) {

	if (lt == rt) {

		a[px] = 0;

		tr[cc] = 0;

		return;

	}

	int mt = (lt + rt) / 2;

	if (px <= mt) {

		update(cc * 2, lt, mt, px);

	}

	else {

		update(cc * 2 + 1, mt + 1, rt, px);

	}

	tr[cc] = max(tr[cc * 2], tr[cc * 2 + 1]);

}



int get(int cc, int lt, int rt, int ql, int qr) {

	if (lt == ql && rt == qr) {

		return tr[cc];

	}

	int mt = (lt + rt) / 2;

	if (qr <= mt) {

		return get(cc * 2, lt, mt, ql, qr);

	}

	else if (ql >= mt + 1) {

		return get(cc * 2 + 1, mt + 1, rt, ql, qr);

	}

	else {

		return max(get(cc * 2, lt, mt, ql, mt), get(cc * 2 + 1, mt + 1, rt, mt + 1, qr));

	}

}



void just_do_it() {

	int n, m, q;

	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++) {

		cin >> fa[i];

		pp[fa[i]] = i;

	}

	for (int i = 1; i <= m; i++) {

		cin >> e[i][0] >> e[i][1];

	}

	deque<int> p;

	for (int i = 0; i < q; i++) {

		cin >> qs[i][0] >> qs[i][1];

		if (qs[i][0] == 2) {

			f[qs[i][1]] = true;

			p.push_front(qs[i][1]);

		}

	}

	for (int i = 1; i <= m; i++) {

		if (!f[i]) {

			p.push_front(i);

		}

	}

	for (auto x: p) {

		g[x] = update(e[x][0], e[x][1], x);

	}

	for (int i = 1; i <= n; i++) {

		if (par[i][0] == 0) {

			dfs(i);

		}

	}

	for (int i = 1; i <= n; i++) {

		a[pt[i][0]] = fa[i];

	}

	for (int i = 1; i <= m; i++) {

		f[i] = false;

	}

	build(1, 1, n);

	for (int i = 0; i < q; i++) {

		if (qs[i][0] == 2) {

			f[qs[i][1]] = true;

			if (g[qs[i][1]] != -1) {

				int u = g[qs[i][1]];

				ch[u].pop_front();

			}

		}

		else {

			int u = qs[i][1];

			while (par[u][0] != 0 && !f[par[u][1]]) {

				u = par[u][0];

			}

			int res = a[pt[u][0]];

			if (!ch[u].empty()) {

				int lt = pt[ch[u].front()][0];

				int rt = pt[ch[u].back()][1];

				res = max(res, get(1, 1, n, lt, rt));

			}

			cout << res << '\n';

			update(1, 1, n, pt[pp[res]][0]);

		}

	}

}



// END MAIN CODE