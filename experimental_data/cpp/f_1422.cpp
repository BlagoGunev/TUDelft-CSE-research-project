#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define inf 0x7FFFFFFF

#define llinf 0x7FFFFFFFFFFFFFFF

#define ff first

#define ss second

#define FOR(i, a, b) for(int i = a; i < b; i++)

#define ROF(i, a, b) for(int i = a - 1; i >= b; i--)



#ifdef _MSC_VER

#define __builtin_popcount(x) __popcnt(x)

#endif



const int mx = 2e5 + 5;

const int mod = 1e9 + 7;



/**

 * Description: point update and rectangle sum with offline 2D BIT.

	* For each of the points to be updated, $x\in (0,SZ)$ and $y\neq 0$.

 * Time: O(N\log^2 N)

 * Memory: O(N\log N)

 * Source: Benjamin Qi

 * Verification:

	* https://dmoj.ca/problem/occ19g4

	* http://www.usaco.org/index.php?page=viewproblem2&cpid=722 (753 ms)

	* http://www.usaco.org/index.php?page=viewproblem2&cpid=601 (679 ms)

 */



template<class T, int SZ> struct OffBIT2D {

	bool mode = 0; // mode = 1 -> initialized

	vector<pair<int,int>> todo; // locations of updates to process

	int cnt[SZ], st[SZ];

	vector<int> val; vector<T> bit; // store all BITs in single vector

	void init() {

		assert(!mode); mode = 1;

		int lst[SZ]; FOR(i,0, SZ) lst[i] = cnt[i] = 0;

		sort(todo.begin(), todo.end(), [](const pair<int,int>& a, const pair<int,int>& b) {

			return a.ss < b.ss; });

		for (auto& t : todo) for (int x = t.ff; x < SZ; x += x & -x)

			if (lst[x] != t.ss) lst[x] = t.ss, cnt[x] ++;

		int sum = 0; FOR(i,0, SZ) lst[i] = 0, st[i] = (sum += cnt[i]);

		val.resize(sum); bit.resize(sum, 1); reverse(todo.begin(), todo.end());

		for(auto &t : todo) for (int x = t.ff; x < SZ; x += x & -x)

			if (lst[x] != t.ss) lst[x] = t.ss, val[--st[x]] = t.ss;

	}

	int rank(int y, int l, int r) {

		return upper_bound(begin(val) + l, begin(val) + r, y) - begin(val) - l;

	}

	void UPD(int x, int y, T t) {

		for (y = rank(y, st[x], st[x] + cnt[x]); y <= cnt[x]; y += y & -y)

			bit[st[x] + y - 1] = (ll) bit[st[x] + y - 1] * t % mod;

	}

	void upd(int x, int y, T t) {

		if (!mode) todo.push_back({ x,y });

		else for (; x < SZ; x += x & -x) UPD(x, y, t);

	}

	int QUERY(int x, int y) {

		T res = 1;

		for (y = rank(y, st[x], st[x] + cnt[x]); y; y -= y & -y) res = (ll) res * bit[st[x] + y - 1] % mod;

		return res;

	}

	T query(int x, int y) {

		assert(mode);

		T res = 1; for (; x; x -= x & -x) res = (ll) res * QUERY(x, y) % mod;

		return res;

	}

};



int mpow(int a, int b = mod - 2) {

	int res = 1;

	while (b) {

		if (b & 1)

			res = (ll)res * a % mod;

		a = (ll) a * a % mod;

		b >>= 1;

	}

	return res;

}



int main() {

	cin.tie(0)->sync_with_stdio(0);

	int f[mx], inv[mx], pm[mx], ipm[mx]; //prefix mult, inverse

	bool m[mx]{};

	FOR (i, 2, mx) { //sieve

		if (m[i]) continue;

		f[i] = -1;

		for (int k = i + i; k < mx; k += i) {

			m[k] = 1; f[k] = i;

		}

	}

	FOR (i, 2, mx) { //precompute inverses for faster?

		if (f[i] == -1) {

			inv[i] = mpow(i);

		}

	}



	int n; cin >> n;

	int a[mx];

	FOR(i, 0, n) {

		cin >> a[i];

		pm[i] = i ? (ll) pm[i-1] * a[i] % mod : a[i];

	}

	FOR(i, 0, n) {

		ipm[i] = mpow(pm[i]);

	}



	int prev[mx];

	memset(prev, -1, sizeof(int)* mx);



	vector<vector<int>> q;



	OffBIT2D<int, mx> bit;



	FOR(i, 0, n) {

		int cf = -1;

		int cn = -1;

		int c = a[i];

		while (c > 1) {

			int t = f[c] == -1 ? c : f[c];

			if (t == cf) cn *= t;

			else cn = t;

			if (prev[cn] != -1) {

				q.push_back({ prev[cn], i, inv[t]});

				bit.upd(mx-prev[cn]-1, i, 0);

			}

			prev[cn] = i;

			cf = t;

			c /= t;

		}

	}

	bit.init();

	for (auto& x : q) {

		bit.upd(mx-x[0]-1, x[1], x[2]);

	}



	int k; cin >> k;

	int l = 0, r = 0;

	while (k--) {

		int x, y; cin >> x >> y; l += x; r += y;

		l %= n; r %= n; if (l > r) swap(l, r);

		int res = pm[r];

		if (l) res = (ll)res * ipm[l - 1] % mod;

		res = (ll)res * bit.query(mx-l-1, r) % mod;

		cout << res << endl;

		l = r = res;

	}

}