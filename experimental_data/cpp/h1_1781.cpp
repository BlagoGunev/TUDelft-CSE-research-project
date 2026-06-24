#include <bits/stdc++.h>



#define itn int

#define all(x) (x).begin(), (x).end()

#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())



using namespace std;



inline int nxt() {

	int x;

	scanf("%d", &x);

	return x;

}



template <uint32_t base>

struct Montgomery {

	using i32 = int32_t;

	using u32 = uint32_t;

	using u64 = uint64_t;



	static constexpr u32 mod() {

		return base;

	}



	static constexpr u32 np = []() {

		u32 x = base;

		for (int i = 0; i < 4; ++i) {

			x *= 2u - base * x;

		}

		return -x;

	}();

	static constexpr u32 r2 = -(u64)(base) % base;



	static_assert(base < (1u << 30));

	static_assert(base * np + 1 == 0);



	static u32 reduce(u64 x) {

		return (x + (u64)((u32)x * np) * base) >> 32;

	}



	u32 x;

	Montgomery(): x(0) {}

	constexpr Montgomery(long long y): x(y ? reduce((u64)(y % base + base) * r2) : 0) {}



	Montgomery& operator +=(const Montgomery& ot) {

		if ((i32)(x += ot.x - 2 * base) < 0) {

			x += 2 * base;

		}

		return *this;

	}



	Montgomery& operator -=(const Montgomery& ot) {

		if ((i32)(x -= ot.x) < 0) {

			x += 2 * base;

		}

		return *this;

	}



	Montgomery& operator *=(const Montgomery& ot) {

		x = reduce((u64)x * ot.x);

		return *this;

	}



	Montgomery& operator /=(const Montgomery& ot) {

		return *this *= ot.inverse();

	}



	friend Montgomery operator +(Montgomery a, const Montgomery& b) {

		a += b;

		return a;

	}



	friend Montgomery operator -(Montgomery a, const Montgomery& b) {

		a -= b;

		return a;

	}



	friend Montgomery operator *(Montgomery a, const Montgomery& b) {

		a *= b;

		return a;

	}



	friend Montgomery operator /(Montgomery a, const Montgomery& b) {

		a /= b;

		return a;

	}



	Montgomery operator -() const {

		return Montgomery() - *this;

	}



	u32 get() const {

		u32 res = reduce(x);

		return res < base ? res : res - base;

	}



	u32 operator ()() const {

		return get();

	}



	Montgomery inverse() const {

		return pow(base - 2);

	}



	Montgomery inv() const {

		return inverse();

	}



	Montgomery pow(int64_t p) const {

		if (p < 0) {

			return pow(-p).inverse();

		}

		Montgomery res = 1;

		Montgomery a = *this;

		while (p) {

			if (p & 1) {

				res *= a;

			}

			p >>= 1;

			a *= a;

		}

		return res;

	}



	friend istream& operator >>(istream& istr, Montgomery& m) {

		long long x;

		istr >> x;

		m = Montgomery(x);

		return istr;

	}



	friend ostream& operator <<(ostream& ostr, const Montgomery& m) {

		return ostr << m.get();

	}



	bool operator ==(const Montgomery& ot) const {

		return (x >= base ? x - base : x) == (ot.x >= base ? ot.x - base : ot.x);

	}



	bool operator !=(const Montgomery& ot) const {

		return (x >= base ? x - base : x) != (ot.x >= base ? ot.x - base : ot.x);

	}



	explicit operator int64_t() const {

		return x;

	}



	explicit operator bool() const {

		return x;

	}

};



constexpr int mod = 998'244'353;

using Mint = Montgomery<mod>;



const int N = 228;

Mint dp[N][2][2];



void solve() {

	int n = nxt(), m = nxt(), k = nxt();

	vector<pair<int, int>> forb(k);

	for (auto& [x, y] : forb) {

		x = nxt() - 1, y = nxt() - 1;

	}



	const int sz = n * m;

	vector<Mint> p2(sz + 1, 1);

	vector<Mint> n2(sz + 1, 1);

	for (int i = 1; i <= sz; ++i) {

		p2[i] = p2[i - 1] * 2;

	}

	n2[sz] = p2[sz].inv();

	for (int i = sz - 1; i >= 0; --i) {

		n2[i] = n2[i + 1] * 2;

	}



	auto cw = [&](int a, int b) -> Mint {

		if (a < 0 || b < 0) {

			return 1;

		} else {

			return p2[a * b];

		}

	};



	Mint ans = 0;

	for (int a = 1; a <= n; ++a) {

		for (int b = 1; b <= m; ++b) {

			Mint cnt = 0;

			for (int l : {0, 1}) {

				for (int r : {0, 1}) {

					for (int u : {0, 1}) {

						for (int d : {0, 1}) {

							cnt += cw(a - l - r, b - u - d) * ((l + r + u + d) % 2 ? -1 : 1);

						}

					}

				}

			}

			ans += cnt;

		}

	}



	if (k == 0) {

		cout << ans << "\n";

		return;

	}

	

	if (k == 1) {

		auto [x, y] = forb[0];

		for (int a = 1; a <= n; ++a) {

			for (int b = 1; b <= m; ++b) {

				int l = x - (n - a);

				int r = x;

				int u = y - (m - b);

				int d = y;

				if (l < 0 || r >= a || u < 0 || d >= b) {

					continue;

				}

				Mint cnt = 0;

				for (int ll : {0, 1}) {

					for (int rr : {0, 1}) {

						for (int uu : {0, 1}) {

							for (int dd : {0, 1}) {

								if (ll && l == 0) {

									continue;

								}

								if (rr && r == a - 1) {

									continue;

								}

								if (uu && u == 0) {

									continue;

								}

								if (dd && d == b - 1) {

									continue;

								}

								cnt += cw(a - ll - rr, b - uu - dd) * ((ll + rr + uu + dd) % 2 ? -1 : 1);

							}

						}

					}

				}

				ans -= cnt * n2[(r - l + 1) * (d - u + 1)];

			}

		}

		cout << ans << "\n";

		return;

	}

	

	if (forb[0].first > forb[1].first) {

		forb[0].first = n - 1 - forb[0].first;

		forb[1].first = n - 1 - forb[1].first;

	}

	if (forb[0].second > forb[1].second) {

		forb[0].second = m - 1 - forb[0].second;

		forb[1].second = m - 1 - forb[1].second;

	}

	// if (forb[0].second == forb[1].second) {

	// 	swap(forb[0].first, forb[0].second);

	// 	swap(forb[1].first, forb[1].second);

	// 	swap(n, m);

	// }

	// cerr << forb[0].first << " " << forb[0].second << " " << forb[1].first << " " << forb[1].second << " " << n << " " << m << "\n";

	auto [x, y] = forb[0];

	int vx = forb[1].first - forb[0].first;

	int vy = forb[1].second - forb[0].second;



	vector<vector<int>> touched(n, vector<int>(m, 0));

	vector<vector<char>> islit(n, vector<char>(m, 0));

	int timer = 0;



	dp[1][0][1] = dp[1][1][0] = 0;

	dp[1][0][0] = 1;

	dp[1][1][1] = 1;

	for (int c = 2; c <= max(n, m); ++c) {

		for (int i : {0, 1}) {

			for (int j : {0, 1}) {

				dp[c][i][j] = 0;

			}

		}

		for (int i : {0, 1}) {

			for (int j : {0, 1}) {

				if (!i && !j) {

					continue;

				}

				for (int k : {0, 1}) {

					dp[c][k][i] += dp[c - 1][k][j];

				}

			}

		}

	}

	for (int c = 1; c <= max(n, m); ++c) {

		dp[c][0][0] += dp[c][0][1] + dp[c][1][0] + dp[c][1][1];

		dp[c][0][1] += dp[c][1][1];

		dp[c][1][0] += dp[c][1][1];

	}

	// cerr << dp[2][0][0] << " " << dp[2][0][1] << " " << dp[2][1][0] << " " << dp[2][1][1] << " --\n";



	auto is_inside = [&](int i, int j, int a, int b) {

		return clamp(i, 0, a - 1) == i && clamp(j, 0, b - 1) == j;

	};



	for (int a = 1; a <= n; ++a) {

		for (int b = 1; b <= m; ++b) {

			int l = x - (n - a);

			int r = x;

			int u = y - (m - b);

			int d = y;



			bool ok = true;

			for (int i = l; i <= r; ++i) {

				for (int j = u; j <= d; ++j) {

					if (!is_inside(i, j, a, b) && !is_inside(i + vx, j + vy, a, b)) {

						ok = false;

						break;

					}

				}

			}

			if (!ok) {

				continue;

			}



			// cerr << a << " " << b << ": " << l << " " << r << " " << u << " " << d << "\n";



			for (int ll : {0, 1}) {

				for (int rr : {0, 1}) {

					for (int uu : {0, 1}) {

						for (int dd : {0, 1}) {

							int sign = (ll + rr + uu + dd) % 2 ? -1 : 1;

							++timer;

							Mint cnt = 1;

							for (int i = l; i <= r; ++i) {

								for (int j = u; j <= d; ++j) {

									if (is_inside(i, j, a, b) && touched[i][j] == timer) {

										continue;

									}



									auto si = i, sj = j;

									auto fi = i, fj = j;

									int cn = 1;

									while (fi <= r && fj <= d) {

										++cn;

										if (is_inside(fi, fj, a, b)) {

											touched[fi][fj] = timer;

										}

										fi += vx;

										fj += vy;

									}

									if (is_inside(fi, fj, a, b)) {

										touched[fi][fj] = timer;

									}

									int left_unlit = 0, right_unlit = 0;

									for (int ii = si, jj = sj, c = 0; c < 2; ++c, ii += vx, jj += vy) {

										if (ii < ll || ii + rr >= a || jj < uu || jj + dd >= b) {

											++left_unlit;

										} else {

											break;

										}

									}

									if (left_unlit > 1) {

										cnt = 0;

										break;

									}

									for (int ii = fi, jj = fj, c = 0; c < 2; ++c, ii -= vx, jj -= vy) {

										if (ii < ll || ii + rr >= a || jj < uu || jj + dd >= b) {

											++right_unlit;

										} else {

											break;

										}

									}

									if (right_unlit > 1) {

										cnt = 0;

										break;

									}

									// cerr << a << " " << b << " " << ll << rr << uu << dd << "; " << si << " " << sj << ": " << cn << " " << left_unlit << " " << right_unlit << ", " << dp[cn - left_unlit - right_unlit][left_unlit][right_unlit] << "\n";

									cnt *= dp[cn - left_unlit - right_unlit][left_unlit][right_unlit];

								}

							}

							if (cnt == 0) {

								continue;

							}

							for (int i = 0; i < a; ++i) {

								for (int j = 0; j < b; ++j) {

									if (touched[i][j] == timer) {

										continue;

									}

									// cerr << a << " " << b << " " << ll << " " << rr << " " << uu << " " << dd << ": " << i << " " << j << "\n";

									if (i >= ll && i + rr < a && j >= uu && j + dd < b) {

										cnt *= 2;

									}

								}

							}

							// if (!(ll + rr + uu + dd)) {

								// cerr << a << " " << b << ": " << ll << " " << rr << " " << uu << " " << dd << " -- " << cnt << "\n";

							// }



							ans -= cnt * sign;

						}

					}

				}

			}

		}

	}



	cout << ans << "\n";

}



int main() {

	int t = nxt();

	while (t--) {

		solve();

	}



	return 0;

}