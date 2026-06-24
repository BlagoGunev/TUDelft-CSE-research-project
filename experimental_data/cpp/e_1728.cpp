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



long double rand_real(long double rmin, long double rmax) {

	uniform_real_distribution<long double> rdist(rmin, rmax);

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



long long floor(long long x, long long y) {

	return (x / y) - ((x ^ y) < 0 && (x % y));

}



long long ceil(long long x, long long y) {

	return (x / y) + ((x ^ y) > 0 && (x % y));

}



const int ms = 3e5 + 20;

long long ta[ms];

long long tb[ms];

long long d[ms];

long long s;

long long lim;

long long n;



pair<long long, pair<long long, long long>> egcd(long long a, long long b, long long s1 = 1, long long s2 = 0, long long t1 = 0, long long t2 = 1) {

	if (b == 0) {

		return {a, {s1, t1}};

	}

	long long q = a / b;

	return egcd(b, a - b * q, s2, s1 - s2 * q, t2, t1 - t2 * q);

}



void query() {

	long long a, b;

	cin >> a >> b;

	auto p = egcd(a, b);

	long long g = p.first;

	long long x = p.second.first;

	long long y = p.second.second;

	if (n % g != 0) {

		cout << -1 << '\n';

		return;

	}

	x *= n / g;

	y *= n / g;

	long long lt = ceil(-x, b / g);

	long long rt = floor(y, a / g);

	long long lx = max(lt, ceil(lim - x * a + 1, a * b / g));

	long long rx = min(rt, floor(lim - x * a, a * b / g));

	if (lt > rt) {

		cout << -1 << '\n';

		return;

	}

	long long r1 = -1;

	long long r2 = -1;

	if (lt <= rx) {

		r1 = s + d[(x + rx * (b / g)) * a];

	}

	if (lx <= rt) {

		r2 = s + d[(x + lx * (b / g)) * a];

	}

	cout << max(r1, r2) << '\n';

}



void just_do_it() {

	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> ta[i];

		cin >> tb[i];

		s += tb[i];

		d[i] = ta[i] - tb[i];

	}

	sort(d + 1, d + n + 1, greater<>());

	lim = -1;

	for (int i = 1; i <= n; i++) {

		if (d[i] < 0 && lim == -1) {

			lim = i - 1;

		}

		d[i] += d[i - 1];

	}

	if (lim == -1) {

		lim = n;

	}

	int q;

	cin >> q;

	for (int i = 0; i < q; i++) {

		query();

	}

}



// END MAIN CODE