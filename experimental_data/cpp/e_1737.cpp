#include <bits/stdc++.h>



using namespace std;



// 5 is a root of both mods



template <int MOD, int RT> struct Mint {

	static const int mod = MOD;

	static constexpr Mint rt() { return RT; } // primitive root for FFT



	static constexpr int md() { return MOD; } // primitive root for FFT



	int v; 

	explicit operator int() const { return v; } // explicit -> don't silently convert to int



	explicit operator bool() const { return v != 0; }

	Mint() { v = 0; }

	Mint(long long _v) { v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }

	friend bool operator==(const Mint& a, const Mint& b) { return a.v == b.v; }

	friend bool operator!=(const Mint& a, const Mint& b) { return !(a == b); }

	friend bool operator<(const Mint& a, const Mint& b) { return a.v < b.v; }

	friend bool operator>(const Mint& a, const Mint& b) { return a.v > b.v; }

	friend bool operator<=(const Mint& a, const Mint& b) { return a.v <= b.v; }

	friend bool operator>=(const Mint& a, const Mint& b) { return a.v >= b.v; }

	friend std::istream& operator >> (std::istream& in, Mint& a) { 

		long long x; std::cin >> x; a = Mint(x); return in; }

	friend std::ostream& operator << (std::ostream& os, const Mint& a) { return os << a.v; }

	Mint& operator+=(const Mint& m) { 

		if ((v += m.v) >= MOD) v -= MOD; 

		return *this; }

	Mint& operator-=(const Mint& m) { 

		if ((v -= m.v) < 0) v += MOD; 

		return *this; }

	Mint& operator*=(const Mint& m) { 

		v = (long long)v * m.v % MOD; return *this; }

	Mint& operator/=(const Mint& m) { return (*this) *= inv(m); }

	friend Mint pow(Mint a, long long p) {

		Mint ans = 1; assert(p >= 0);

		for (; p; p /= 2, a *= a) if (p & 1) ans *= a;

		return ans; 

	}

	friend Mint inv(const Mint& a) { assert(a.v != 0); return pow(a, MOD - 2); }

	Mint operator-() const { return Mint(-v); }

	Mint& operator++() { return *this += 1; }

	Mint& operator--() { return *this -= 1; }

	friend Mint operator+(Mint a, const Mint& b) { return a += b; }

	friend Mint operator-(Mint a, const Mint& b) { return a -= b; }

	friend Mint operator*(Mint a, const Mint& b) { return a *= b; }

	friend Mint operator/(Mint a, const Mint& b) { return a /= b; }

};



using mi = Mint<1000000007, 5>;



void solve_case(int tc = 0) {

	int n;

	cin >> n;

	int lim = n + 5;

	vector<mi> po(lim + 1);

	vector<mi> ipo(lim + 1);

	po[0] = ipo[0] = 1;

	mi i2 = 1 / mi(2);

	for (int i = 1; i <= lim; ++i) {

		po[i] = po[i - 1] * 2;

		ipo[i] = ipo[i - 1] * i2;

	}

	vector<mi> p(n);

	vector<mi> q(n);

	mi run = 0;

	int to = n - 1;

	for (int i = n - 1; i >= 0; --i) {

		if (i < n - 1) {

			while (to > 2 * i) {

				run -= ipo[to] * q[to];

				--to;

			}

			q[i] = run * po[i];

		} else {

			q[i] = 1;

		}

		p[i] = ipo[i / 2] * q[i];  

		run += ipo[i] * q[i];

	}

	p[0] = n == 1 ? 1 : 0;

	for (mi x : p) {

		cout << x << '\n';

	}

}



int main() {

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	int tt = 1;

	cin >> tt;

	for (int tc = 1; tc <= tt; ++tc) {

		solve_case(tc);

	}

	return 0;

}