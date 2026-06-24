#pragma GCC optimize("O3")

#pragma GCC optimize("unroll-loops")

#include<iostream>

#include<string>

#include<cstdio>

#include<vector>

#include<cmath>

#include<algorithm>

#include<functional>

#include<iomanip>

#include<queue>

#include<ciso646>

#include<random>

#include<map>

#include<set>

#include<bitset>

#include<stack>

#include<unordered_map>

#include<unordered_set>

#include<utility>

#include<cassert>

#include<complex>

#include<numeric>

#include<array>

#include<chrono>

using namespace std;



//#define int long long

typedef long long ll;



typedef unsigned long long ul;

typedef unsigned int ui;

constexpr ll mod = 998244353;

//constexpr ll mod = 1000000007;

const ll INF = mod * mod;

typedef pair<int, int>P;



#define rep(i,n) for(int i=0;i<n;i++)

#define per(i,n) for(int i=n-1;i>=0;i--)

#define Rep(i,sta,n) for(int i=sta;i<n;i++)

#define rep1(i,n) for(int i=1;i<=n;i++)

#define per1(i,n) for(int i=n;i>=1;i--)

#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)

#define all(v) (v).begin(),(v).end()

typedef pair<ll, ll> LP;



template<typename T>

void chmin(T& a, T b) {

	a = min(a, b);

}

template<typename T>

void chmax(T& a, T b) {

	a = max(a, b);

}

template<typename T>

void cinarray(vector<T>& v) {

	rep(i, v.size())cin >> v[i];

}

template<typename T>

void coutarray(vector<T>& v) {

	rep(i, v.size()) {

		if (i > 0)cout << " "; cout << v[i];

	}

	cout << "\n";

}

ll mod_pow(ll x, ll n, ll m = mod) {

	if (n < 0) {

		ll res = mod_pow(x, -n, m);

		return mod_pow(res, m - 2, m);

	}

	if (abs(x) >= m)x %= m;

	if (x < 0)x += m;

	//if (x == 0)return 0;

	ll res = 1;

	while (n) {

		if (n & 1)res = res * x % m;

		x = x * x % m; n >>= 1;

	}

	return res;

}

//mod should be <2^31

struct modint {

	int n;

	modint() :n(0) { ; }

	modint(ll m) {

		if (m < 0 || mod <= m) {

			m %= mod; if (m < 0)m += mod;

		}

		n = m;

	}

	operator int() { return n; }

};

bool operator==(modint a, modint b) { return a.n == b.n; }

bool operator<(modint a, modint b) { return a.n < b.n; }

modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= (int)mod; return a; }

modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += (int)mod; return a; }

modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }

modint operator+(modint a, modint b) { return a += b; }

modint operator-(modint a, modint b) { return a -= b; }

modint operator*(modint a, modint b) { return a *= b; }

modint operator^(modint a, ll n) {

	if (n == 0)return modint(1);

	modint res = (a * a) ^ (n / 2);

	if (n % 2)res = res * a;

	return res;

}



ll inv(ll a, ll p) {

	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);

}

modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

modint operator/=(modint& a, modint b) { a = a / b; return a; }

const int max_n = 1 << 20;

modint fact[max_n], factinv[max_n];

void init_f() {

	fact[0] = modint(1);

	for (int i = 0; i < max_n - 1; i++) {

		fact[i + 1] = fact[i] * modint(i + 1);

	}

	factinv[max_n - 1] = modint(1) / fact[max_n - 1];

	for (int i = max_n - 2; i >= 0; i--) {

		factinv[i] = factinv[i + 1] * modint(i + 1);

	}

}

modint comb(int a, int b) {

	if (a < 0 || b < 0 || a < b)return 0;

	return fact[a] * factinv[b] * factinv[a - b];

}

modint combP(int a, int b) {

	if (a < 0 || b < 0 || a < b)return 0;

	return fact[a] * factinv[a - b];

}



ll gcd(ll a, ll b) {

	a = abs(a); b = abs(b);

	if (a < b)swap(a, b);

	while (b) {

		ll r = a % b; a = b; b = r;

	}

	return a;

}

using ld = long double;

//typedef long double ld;

typedef pair<ld, ld> LDP;

const ld eps = 1e-10;

const ld pi = acosl(-1.0);

template<typename T>

void addv(vector<T>& v, int loc, T val) {

	if (loc >= v.size())v.resize(loc + 1, 0);

	v[loc] += val;

}

/*const int mn = 2000005;

bool isp[mn];

vector<int> ps;

void init() {

	fill(isp + 2, isp + mn, true);

	for (int i = 2; i < mn; i++) {

		if (!isp[i])continue;

		ps.push_back(i);

		for (int j = 2 * i; j < mn; j += i) {

			isp[j] = false;

		}

	}

}*/



//[,val)

template<typename T>

auto prev_itr(set<T>& st, T val) {

	auto res = st.lower_bound(val);

	if (res == st.begin())return st.end();

	res--; return res;

}



//[val,)

template<typename T>

auto next_itr(set<T>& st, T val) {

	auto res = st.lower_bound(val);

	return res;

}

using mP = pair<modint, modint>;

mP operator+(mP a, mP b) {

	return { a.first + b.first,a.second + b.second };

}

mP operator+=(mP& a, mP b) {

	a = a + b; return a;

}

mP operator-(mP a, mP b) {

	return { a.first - b.first,a.second - b.second };

}

mP operator-=(mP& a, mP b) {

	a = a - b; return a;

}

LP operator+(LP a, LP b) {

	return { a.first + b.first,a.second + b.second };

}

LP operator+=(LP& a, LP b) {

	a = a + b; return a;

}

LP operator-(LP a, LP b) {

	return { a.first - b.first,a.second - b.second };

}

LP operator-=(LP& a, LP b) {

	a = a - b; return a;

}



mt19937 mt(time(0));



const string drul = "DRUL";

string senw = "SENW";

//DRUL,or SENW

int dx[4] = { 1,0,-1,0 };

int dy[4] = { 0,1,0,-1 };

//-----------------------------------------

modint t2[40005];

modint f[40005];

modint rf[40005];

vector<modint> F(40005);

vector<modint> rF(40005);

//modint F[40005];

//modint rF[40005];

void init() {

	f[0] = 1;

	f[1] = 2;

	t2[0] = 1;

	t2[1] = 2;

	for (int i = 2; i < 40005; i++) {

		f[i] = f[i - 2] + f[i - 1];

		t2[i] = t2[i - 1] + t2[i - 1];

	}

	rep(i, 40005) {

		rf[i] = (modint)1 / f[i];

	}

	for (int i = 0; i < 40004; i++) {

		F[i] = f[i + 1] / t2[i + 1];

		rF[i] = (modint)1 / F[i];

	}

}

vector<P> ps;

vector<P> ns;





void solve() {

	int h, w, k; cin >> h >> w >> k;

	auto isin = [&](int i, int j) {

		return 0 <= i && i < h && 0 <= j && j < w;

	};

	vector<P> vs(k);

	rep(i, k) {

		int x, y; cin >> x >> y; x--; y--;

		vs[i] = { x,y };

	}

	if (k == 2) {

		int xmi = min(vs[0].first, vs[1].first);

		int xma = max(vs[0].first, vs[1].first);

		int ymi = min(vs[0].second, vs[1].second);

		int yma = max(vs[0].second, vs[1].second);

		if (xmi > h - 1 - xma) {

			rep(j, 2)vs[j].first = h - 1 - vs[j].first;

		}

		if (ymi > w - 1 - yma) {

			rep(j, 2)vs[j].second = w - 1 - vs[j].second;

		}

	}

	auto calc = [&](int lenx, int leny)->modint {

		vector<P> pps = ps;

		vector<P> nns = ns;

		if (k == 0)return 0;

		else if (k == 1) {

			int cx = vs[0].first, cy = vs[0].second;

			rep(i, lenx)rep(j, leny) {

				int x = cx - i, y = cy - j;

				if (!isin(x, y)) {

					return 0;

				}

				pps.push_back({ x,y });

			}

			sort(all(pps));

			pps.erase(unique(all(pps)), pps.end());

			sort(all(nns));

			nns.erase(unique(all(nns)), nns.end());

			vector<vector<bool>> exi(h, vector<bool>(w));

			for (auto p : pps) {

				exi[p.first][p.second] = true;

			}

			for (auto p : nns) {

				if (exi[p.first][p.second]) {

					return 0;

				}

				exi[p.first][p.second] = true;

			}

			modint res = 1;

			rep(i, h)rep(j, w)if (!exi[i][j]) {

				res *= 2;

			}

			return res;

		}

		else {

			int cx0 = vs[0].first, cy0 = vs[0].second;

			int cx1 = vs[1].first, cy1 = vs[1].second;

			vector<vector<int>> G(h * w);

			rep(i, lenx)rep(j, leny) {

				int x0 = cx0 - i;

				int y0 = cy0 - j;

				int x1 = cx1 - i;

				int y1 = cy1 - j;

				if (!isin(x0, y0) && !isin(x1, y1)) {

					return 0;

				}

				else if (!isin(x0, y0)) {

					pps.push_back({ x1,y1 });

				}

				else if (!isin(x1, y1)) {

					pps.push_back({ x0,y0 });

				}

				else {

					int id0 = x0 * w + y0;

					int id1 = x1 * w + y1;

					G[id0].push_back(id1);

					G[id1].push_back(id0);

				}

			}

			vector<vector<bool>> exi(h, vector<bool>(w));

			sort(all(nns));

			nns.erase(unique(all(nns)), nns.end());

			for (auto p : nns) {

				int id = p.first * w + p.second;

				exi[id / w][id % w] = true;

				for (int to : G[id]) {

					pps.push_back({ to / w,to % w });

				}

			}

			sort(all(pps));

			pps.erase(unique(all(pps)), pps.end());

			for (auto p : pps) {

				int x = p.first, y = p.second;

				if (exi[x][y])return 0;

				exi[x][y] = true;

			}

			vector<bool> used(h * w);

			modint res = 1;

			rep(i, h * w) {

				if (used[i])continue;

				int cnt = 0;

				queue<int> q;

				q.push(i); used[i] = true;

				while (!q.empty()) {

					int id = q.front(); q.pop();

					if (!exi[id / w][id % w]) {

						cnt++;

					}

					for (int to : G[id]) {

						if (!used[to]) {

							used[to] = true;

							q.push(to);

						}

					}

				}

				res *= f[cnt];

			}

			return res;

		}

	};

	modint ans = mod_pow(2, h * w);

	ans -= mod_pow(2, (h - 1) * w);

	ans -= mod_pow(2, h * (w - 1));

	ans += mod_pow(2, (h - 1) * (w - 1));

	if (k == 0) {

		//

	}

	else if (k == 1) {

		struct ste {

			int i, j; int cnt; bool valid; bool isn, isp;

		};

		int cx = vs[0].first;

		int cy = vs[0].second;

		vector<vector<bool>> isp(h, vector<bool>(w));

		auto isn = isp;

		vector<ste> mem;

		bool valid = true;

		int cnt = h * w;

		auto upd = [&](int i, int j, bool b) {

			mem.push_back({ i,j,cnt,valid,isn[i][j],isp[i][j] });

			if (b) {

				if (isn[i][j])valid = false;

				if (!isp[i][j]) {

					cnt--; isp[i][j] = true;

				}

			}

			else {

				if (isp[i][j])valid = false;

				if (!isn[i][j]) {

					cnt--; isn[i][j] = true;

				}

			}

		};

		auto und = [&](int num) {

			rep(_, num) {

				ste s = mem.back(); mem.pop_back();

				cnt = s.cnt;

				valid = s.valid;

				isn[s.i][s.j] = s.isn;

				isp[s.i][s.j] = s.isp;

			}

		};

		for (int rx = h - 1; rx >= 0; rx--) {

			int ord = mem.size();

			und(ord);

			for (int x = rx + 1; x < h; x++) {

				rep(y, w) {

					upd(x, y, false);

				}

			}

			for (int ry = w - 1; ry >= 0; ry--) {

				int lenx = h - rx, leny = w - ry;

				if (ry + 1 < w) {

					for (int x = 0; x <= rx; x++) {

						upd(x, ry + 1, false);

					}

				}

				int lx = cx - lenx + 1;

				int ly = cy - leny + 1;

				bool islas = false;

				for (int x = lx; x <= cx; x++) {

					int y = ly;

					if (!isin(x, y))islas = true;

					else {

						upd(x, y, true);

					}

				}

				if (islas)break;

				rep(i, (1 << 4)) {

					int coef = 1;

					int m = mem.size();

					if (i & (1 << 0)) {

						rep(y, w)upd(0, y, false);

						coef *= -1;

					}

					if (i & (1 << 1)) {

						rep(y, w)upd(rx, y, false);

						coef *= -1;

					}

					if (i & (1 << 2)) {

						rep(x, h)upd(x, 0, false);

						coef *= -1;

					}

					if (i & (1 << 3)) {

						rep(x, h)upd(x, ry, false);

						coef *= -1;

					}

					modint val = 0;

					if (valid) {

						val = (modint)coef * t2[cnt];

					}

					ans -= val;

					int dif = mem.size() - m;

					und(dif);

				}

			}

		}

	}

	else {

		struct ste {

			int i, j; int cnt; modint pro; bool valid; bool isn, isp; int len;

		};

		int dx = vs[1].first - vs[0].first;

		int dy = vs[1].second - vs[0].second;

		int sz = h * w;

		vector<vector<int>> G(sz);

		rep(i, h)rep(j, w) {

			int id = i * w + j;

			int ni = i + dx, nj = j + dy;

			if (isin(ni, nj)) {

				int to = ni * w + nj;

				G[id].push_back(to);

				G[to].push_back(id);

			}

		}

		vector<int> trans(sz, -1);

		int tmp = 0;

		vector<int> clen;

		rep(i, sz) {

			if (trans[i] >= 0)continue;

			queue<int> q;

			q.push(i); trans[i] = tmp;

			int cnt = 0;

			while (!q.empty()) {

				cnt++;

				int id = q.front(); q.pop();

				for (int to : G[id])if (trans[to] < 0) {

					q.push(to);

					trans[to] = tmp;

				}

			}

			tmp++;

			clen.push_back(0);

		}

		vector<vector<bool>> isp(h, vector<bool>(w));

		auto isn = isp;

		vector<ste> mem;

		bool valid = true;

		modint pro = 1;

		int lenx, leny;

		auto ss = [&](int x, int y) {

			int res = 0;

			rep(j, 2) {

				int dx = vs[j].first - x;

				int dy = vs[j].second - y;

				if (0 <= dx && dx < lenx && 0 <= dy && dy < leny) {

					res |= (1 << j);

				}

			}

			return res;

		};

		auto cann = [&](int x0, int y0, int x1, int y1) {

			int s0 = ss(x0, y0);

			int s1 = ss(x1, y1);

			if ((s0 & 1) && (s1 & 2))return true;

			if ((s1 & 1) && (s0) & 2)return true;

			return false;

		};

		int cnt = h * w;

		function<void(int, int, bool)> upd = [&](int i, int j, bool b) {

			int loc = trans[i * w + j];

			mem.push_back({ i,j,cnt,pro,valid,isn[i][j],isp[i][j],clen[loc] });

			if (b) {

				if (isn[i][j])valid = false;

				else if (!isp[i][j]) {

					pro *= rF[clen[loc]];

					for (int to : G[i * w + j]) {

						int tx = to / w, ty = to % w;

						if (cann(i, j, tx, ty) && !isp[tx][ty] && !isn[tx][ty])clen[loc]--;

					}

					pro *= F[clen[loc]];

					isp[i][j] = true;

					cnt--;

				}

			}

			else {

				if (isp[i][j])valid = false;

				else if (!isn[i][j]) {

					pro *= rF[clen[loc]];

					for (int to : G[i * w + j]) {

						int tx = to / w, ty = to % w;

						if (cann(i, j, tx, ty) && !isp[tx][ty] && !isn[tx][ty])clen[loc]--;

					}

					pro *= F[clen[loc]];

					isn[i][j] = true;

					for (int to : G[i * w + j]) {

						if (cann(i, j, to / w, to % w))upd(to / w, to % w, true);

					}

					cnt--;

				}

			}

		};

		auto und = [&](int num) {

			rep(_, num) {

				ste s = mem.back(); mem.pop_back();

				cnt = s.cnt;

				pro = s.pro;

				valid = s.valid;

				isn[s.i][s.j] = s.isn;

				isp[s.i][s.j] = s.isp;

				clen[trans[s.i * w + s.j]] = s.len;

			}

		};

		for (int rx = h - 1; rx >= 0; rx--) {

			//if (rx == 1)continue;

			int ord = mem.size();

			und(ord);

			assert(cnt == h * w);

			pro = 1;

			fill(all(clen), 0);

			lenx = h - rx, leny = 0;

			for (int x = rx + 1; x < h; x++) {

				for (int y = 0; y < w; y++) {

					upd(x, y, false);

				}

			}

			for (int ry = w - 1; ry >= 0; ry--) {

				modint csum = 0;

				lenx = h - rx, leny = w - ry;

				bool islas = false;

				per(i, lenx){

					int j = leny - 1;

					int x0 = vs[0].first - i;

					int y0 = vs[0].second - j;

					int x1 = vs[1].first - i;

					int y1 = vs[1].second - j;

					if (!isin(x0, y0) && !isin(x1, y1)) {

						//islas = true;

					}

					else if (!isin(x0, y0)) {

						//upd(x1, y1, true);

					}

					else if (!isin(x1, y1)) {

						//upd(x0, y0, true);

					}

					else {

						if (!isn[x0][y0] && !isp[x0][y0] && !isn[x1][y1] && !isp[x1][y1]) {

							int loc = trans[x0 * w + y0];

							pro *= rF[clen[loc]];

							clen[loc]++;

							pro *= F[clen[loc]];

						}

						if (isn[x0][y0])upd(x1, y1, true);

						if (isn[x1][y1])upd(x0, y0, true);

					}

				}

				per(i, lenx){

					int j = leny - 1;

					int x0 = vs[0].first - i;

					int y0 = vs[0].second - j;

					int x1 = vs[1].first - i;

					int y1 = vs[1].second - j;

					if (!isin(x0, y0) && !isin(x1, y1)) {

						islas = true;

					}

					else if (!isin(x0, y0)) {

						upd(x1, y1, true);

					}

					else if (!isin(x1, y1)) {

						upd(x0, y0, true);

					}

					else {

						/*if (!isn[x0][y0] && !isp[x0][y0] && !isn[x1][y1] && !isp[x1][y1]) {

							int id = trans[x0 * w + y0];

							pro *= rF[clen[id]];

							clen[id]++;

							pro *= F[clen[id]];

						}

						if (isn[x0][y0])upd(x1, y1, true);

						if (isn[x1][y1])upd(x0, y0, true);*/

					}

				}

				if (islas)break;

				if(!valid)break;

				if (ry + 1 < w) {

					for (int x = 0; x <= rx; x++) {

						upd(x, ry + 1, false);

					}

				}

				rep(i, (1 << 4)) {

					int coef = 1;

					int m = mem.size();

					if (i & (1 << 0)) {

						rep(y, w)upd(0, y, false);

						coef *= -1;

					}

					if (i & (1 << 1)) {

						rep(y, w)upd(rx, y, false);

						coef *= -1;

					}

					if (i & (1 << 2)) {

						rep(x, h)upd(x, 0, false);

						coef *= -1;

					}

					if (i & (1 << 3)) {

						rep(x, h)upd(x, ry, false);

						coef *= -1;

					}

					modint val = 0;

					if (valid) {

						val = (modint)coef * pro;

						val *= t2[cnt];

					}

					//int cc = 0;

					//rep(i, clen.size())if (clen[i] > 0)cc += clen[i] + 1;

					//cout << cnt << " " << cc << "\n";

					//cout << rx << " " << ry << " " << t2[cnt]*pro <<" "<<valid<< " " << i << "\n";

					csum += val;

					int dif = mem.size() - m;

					und(dif);

				}

				ans -= csum;

				//cout << rx << " " << ry << " " << csum << "\n";

			}



		}

	}



	cout << ans << "\n";

}





signed main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

	//cout << fixed << setprecision(10);

	//init_f();

	init();

	//expr();

	//while(true)

	int t; cin >> t; rep(i, t)

		solve();

	return 0;

}