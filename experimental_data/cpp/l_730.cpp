#include <bits/stdc++.h>

//#include <fcntl.h>



using std::max; using std::swap; using std::abs; using std::priority_queue; using std::queue; using std::bitset; using std::make_tuple; 

using std::istream; using std::ostream; using std::fixed; using std::greater; using std::tuple; using std::tie; using std::make_pair;

using std::cout; using std::cerr; using std::endl; using std::lower_bound; using std::upper_bound; using std::deque; using std::min; 

using std::map; using std::string; using std::fill; using std::copy; using std::sort; using std::unique; using std::unordered_set; 

using std::multiset; using std::nth_element; using std::min_element; using std::max_element; using std::vector; using std::set; 

using std::unordered_map; using std::pair; using std::next_permutation; using std::reverse; using std::rotate; using std::cin; 

using std::iota; using std::function; using std::shuffle; using std::iter_swap; using std::ofstream; using std::ifstream;



typedef long long ll;

typedef long double ld;

typedef unsigned int uint;

typedef unsigned long long ull;



int const INF = 100 + (int) 1e9;

ll const INFL = 100 + (ll) 1e18;

ld const PI = 3.141592653589793238462643L;

const int MOD = 1000000007;

std::mt19937 mt19937(960172);



ll rnd(ll x, ll y) { static auto gen = std::bind(std::uniform_int_distribution<ll>(), mt19937); return gen() % (y - x + 1) + x; }

bool is_prime(ll x) { if (x <= 1) return 0; for (ll y = 2; y * y <= x; ++y) if (x % y == 0) return 0; return 1; }

ll sqr(int a) { return (ll) a * a; } ld sqr(ld a) { return a * a; } ll sqr(ll a) { return a * a; }

ll gcd(ll a, ll b) { while (b > 0) { ll t = a % b; a = b; b = t; } return a; }



const int N = 1 << 19;



void add(int& a, int b) {

	if ((a += b) >= MOD)

		a -= MOD;

}

int sum(int a, int b) {

	if ((a += b) >= MOD)

		a -= MOD;

	return a;

}



int prod(int a, int b) {

	return (ll) a * b % MOD;

}



class SegTreeMin

{

	int t[N*2-1];

public:

	void init(int n, int * a)

	{

		for (int i = 0; i < n; ++i)

			t[N-1+i] = a[i];

		for (int i = N - 2; i >= 0; --i)

			t[i] = min(t[i*2+1], t[i*2+2]);

	}

	int getMin(int l, int r, int c = 0, int cl = 0, int cr = N - 1)

	{

		if (l > cr || cl > r)

			return INF;

		if (l <= cl && cr <= r)

			return t[c];

		return min(getMin(l, r, c*2+1, cl, (cl+cr)/2), getMin(l, r, c*2+2, (cl+cr)/2+1, cr));

	}

} balanceST;



struct Adr

{

	int l, r, v;

};

struct Mlr

{

	int l, r, v;

};

struct Level

{

	vector < Adr > adrs;

	vector < int > adrsum;



	vector < Mlr > mlrs;

	vector < int > mlrprd, mlr0;

} lv[N];

int lvc = 0;



int n;

string s;

int balance[N];

int brpair[N];

int pval[N];



int go(int cl, int cr, int d)

{

	//int bcl = cl;

	lvc = max(lvc, d + 1);

	int cans = 0;

	while (cl < cr)

	{

		Adr cv = {cl, 0, 1};

		while (true)

		{

			if (cl >= cr || s[cl] == '+')

				break;

			if (s[cl] == '*')

				++cl;

			if (s[cl] == '(')

			{

				pval[cl] = go(cl + 1, brpair[cl], d + 1);

				cv.v = prod(cv.v, pval[cl]);

				lv[d].mlrs.push_back({cl, brpair[cl]+1, pval[cl]});

				cl = brpair[cl] + 1;

			} else {

				int x = 0;

				int ccl = cl;

				while (ccl < cr && '0' <= s[ccl] && s[ccl] <= '9')

					x = ((ll)x*10 + (s[ccl++] - '0')) % MOD;

				pval[cl] = x;

				lv[d].mlrs.push_back({cl, ccl, x});

				cv.v = prod(cv.v, pval[cl]);

				cl = ccl;				

			}

		}

		cv.r = cl;

		lv[d].adrs.push_back(cv);

		add(cans, cv.v);

		++cl;

	}

	//cerr << "  % " << s.substr(bcl, cr-bcl) << "=" << cans << "\n";

	return cans;

}



vector < int > allND;

int p10[N];

int s10[N];



int inv(ll a)

{

	ll r = 1, b = MOD-2;

	while (b)

	{

		if (b & 1)

			(r *= a) %= MOD;

		b >>= 1;

		(a *= a) %= MOD;

	}

	return r;

}



int getProd(int d, int s1, int s2)

{

	if (lv[d].mlr0[s2] != lv[d].mlr0[s1])

		return 0;

	//for (auto x : lv[d].mlrs)

		//cerr << x.v << " ";

	//cerr << "   #\n";

	return prod(lv[d].mlrprd[s2], inv(lv[d].mlrprd[s1]));

}



int eval2(int ql, int qr)

{

	if (s[ql] == '(')

		return pval[ql];

	return sum(s10[qr], MOD - prod(s10[ql], p10[qr-ql]));

}



int eval1(int ql, int qr, int d)

{

	int s1 = lower_bound(lv[d].mlrs.begin(), lv[d].mlrs.end(), Mlr({ql,0,0}), [](const Mlr&a, const Mlr&b){return a.l<b.l;}) - lv[d].mlrs.begin();

	int s2 = upper_bound(lv[d].mlrs.begin(), lv[d].mlrs.end(), Mlr({0,qr,0}), [](const Mlr&a, const Mlr&b){return a.r<b.r;}) - lv[d].mlrs.begin() - 1;

	//cerr << "in eval " << ql << ' ' << qr << " : " << s1 <<  ' ' << s2 << endl;

	int ans = 1;

	if (s1 - 1 == s2 + 1)

	{

		////cerr << "FOOO" << endl;

		return eval2(ql, qr);

	}

	else {

		if (s2 >= s1) {

			//cerr << "here1" << endl;

			ans = getProd(d, s1, s2+1);

			//cerr << ans << "\n";

		}

		if (s1 > 0 && ql < lv[d].mlrs[s1-1].r) {

			//cerr << "here2" << endl;

			ans = prod(ans, eval2(ql, lv[d].mlrs[s1-1].r));

		}

		if (s2 + 1 < (int)lv[d].mlrs.size() && qr > lv[d].mlrs[s2+1].l) {

			//cerr << "here3" << endl;

			ans = prod(ans, eval2(lv[d].mlrs[s2+1].l, qr));

		}

	}

	return ans;

}



void solve()

{

	p10[0] = 1;

	for (int i = 1; i < N; ++i)

		p10[i] = prod(p10[i-1], 10);

	cin >> s;

	n = (int)s.size();

	vector < int > st;

	for (int i = 0; i < n; ++i)

	{

		if (s[i] == '(')

			st.push_back(i);

		else if (s[i] == ')')

		{

			brpair[i] = st.back();

			brpair[st.back()] = i;

			st.pop_back();

		}

		balance[i + 1] = (int)st.size();

	}

	balanceST.init(n + 1, balance);

	

	s10[0] = 0;

	for (int i = 0; i < n; ++i)

	{

		int cc = ('0' <= s[i] && s[i] <= '9' ? s[i] - '0' : 0);

		s10[i+1] = (10LL*s10[i]+cc) % MOD;

	}

	

	go(0, n, 0);

	for (int i = 0; i < lvc; ++i)

	{

		lv[i].adrsum.push_back(0);

		for (auto a : lv[i].adrs)

			lv[i].adrsum.push_back((lv[i].adrsum.back() + a.v) % MOD);

		lv[i].mlrprd.push_back(1);

		lv[i].mlr0.push_back(0);

		for (auto a : lv[i].mlrs)

		{

			if (a.v != 0)

				lv[i].mlrprd.push_back(prod(lv[i].mlrprd.back(), a.v));

			lv[i].mlr0.push_back(lv[i].mlr0.back() + (a.v == 0 ? 1 : 0));

		}

	}

	

	allND.push_back(-1);

	for (int i = 0; i < n; ++i)

		if (s[i] > '9' || s[i] < '0')

			allND.push_back(i);

	allND.push_back(n);

	

	int qq;

	cin >> qq;

	while (qq--)

	{

		int ql, qr;

		scanf("%d%d", &ql, &qr);

		--ql;

		if (balance[ql] != balance[qr] || balanceST.getMin(ql, qr) != balance[ql] || s[ql] == '+' || s[ql] == '*' || s[qr-1] == '+' || s[qr-1] == '*')

		{

			cout << "-1\n";

			continue;

		}

		int d = balance[ql];

		int s1 = lower_bound(lv[d].adrs.begin(), lv[d].adrs.end(), Adr({ql,0,0}), [](const Adr&a, const Adr&b){return a.l<b.l;}) - lv[d].adrs.begin();

		int s2 = upper_bound(lv[d].adrs.begin(), lv[d].adrs.end(), Adr({0,qr,0}), [](const Adr&a, const Adr&b){return a.r<b.r;}) - lv[d].adrs.begin() - 1;

		////cerr << s1 << " " << s2 << " ?\n";

		int ans = 0;

		if (s1 - 1 == s2 + 1)

			ans = eval1(ql, qr, d);

		else {

			if (s2 >= s1)

				ans = sum(lv[d].adrsum[s2+1], MOD-lv[d].adrsum[s1]);

			////cerr << ans << "?\n";

			if (s1 > 0 && ql < lv[d].adrs[s1-1].r)

				add(ans, eval1(ql, lv[d].adrs[s1-1].r, d));

			////cerr << ans << "?\n";

			if (s2 + 1 < (int)lv[d].adrs.size() && qr > lv[d].adrs[s2+1].l)

				add(ans, eval1(lv[d].adrs[s2+1].l, qr, d));

			////cerr << ans << "?\n";

		}

		cout << ans << "\n";

	}

	/*

	//cerr << s << "\n";

	for (int i = 0; i < n; ++i)

		//cerr << i << " " << pval[i] << "\n";

	//cerr << "\n";

	for (int i = 0; i < lvc; ++i)

	{

		//cerr << i << ": ";

		for (auto a : lv[i].adrs)

			//cerr << s.substr(a.l, a.r-a.l) << "=" << a.v << " ";

		//cerr << "\n";

	}*/

}







int main() {

    

    //freopen("", "r", stdin);

    //freopen("", "w", stdout);

    

    cout.precision(15);

    cout << fixed;

    //cerr.precision(6);

    //cerr << fixed;

    

    int tcn = 1;

    for (int tn = 1; tn <= tcn; ++tn)

        solve();

    

#ifdef LOCAL

    cerr << "time: " << (ll) clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;

#endif

}