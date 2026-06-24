#include <vector>

#include <algorithm>

#include <iostream>

#include <array>



using ll = long long;



ll quickPow(ll base, ll fact, ll mod) {

	ll ans = 1;

	while (fact) {

		if (fact & 1) ans = ans * base % mod;

		base = base * base % mod;

		fact >>= 1;

	}

	return ans;

}



const int mod = 1e9 + 7;

std::vector<int> power(1e6 + 10);



struct hash_node {

	static constexpr int base = 31;

	static constexpr int mod1 = 1e9 + 9;

	static constexpr int mod2 = 1e9 + 7;

	ll h1;



	bool operator ==(const hash_node& rhs) const {

		return h1 == rhs.h1;

	}



	hash_node() : h1(0) {}



	hash_node(const int& c) {

		h1 = c % mod1;

//		h2 = c % mod2;

	}



	hash_node operator <<(int idx) const {

		hash_node ans;

//		ans.h1 = h1 * quickPow(base, idx, mod1) % mod1;

		ans.h1 = h1 * power[idx] % mod1;

//		ans.h2 = h2 * quickPow(base, idx, mod2) % mod2;

		return ans;

	}



	hash_node& operator <<=(int idx) {

		h1 = h1 * power[idx] % mod1;

//		h1 = h1 * quickPow(base, idx, mod1) % mod1;

//		h2 = h2 * quickPow(base, idx, mod2) % mod2;

		return *this;

	}



	hash_node operator +(const hash_node& rhs) const {

		hash_node ans;

		ans.h1 = (h1 + rhs.h1) % mod1;

//		ans.h2 = (h2 + rhs.h2) % mod2;

		return ans;

	}



	hash_node operator -(const hash_node& rhs) const {

		hash_node ans;

		ans.h1 = (mod1 + h1 - rhs.h1) % mod1;

//		ans.h2 = (mod2 + h2 - rhs.h2) % mod2;

		return ans;

	}



	friend std::ostream& operator <<(std::ostream& os, const hash_node& rhs) {

		os << rhs.h1;

		return os;

	}

};



struct hash {





	std::vector<hash_node> h;

	std::string s;

	int n;



	hash() {}



	hash(const std::string& copy) : s(copy), n(int(copy.size())) {

		h.resize(n);

		h[0] = 0;

		n--;

		for (int i = 1; i <= n; ++i) {

			h[i] = (h[i - 1] << 1) + hash_node(s[i] - 'a' + 1);

		}

	}



	hash_node getHash(int del, int pos) {

		if (pos < del)return h[pos];

		//123...del...pos

		return (h[del - 1] << (pos - del + 1)) + (h[pos + 1] - (h[del] << (pos + 1 - del)));

	}

};



int main() {

	std::ios::sync_with_stdio(false);

	std::cin.tie(nullptr);

	std::cout.tie(nullptr);



	power[0] = 1;

	for (int i = 1; i <= 1e6 + 5; ++i) {

		power[i] = 1ll * power[i - 1] * 31 % (1000000009);

	}



	int n;

	std::cin >> n;

	std::vector<hash> H(n);

	std::vector<std::string> S(n);

	for (int i = 0; i < n; ++i) {

		std::cin >> S[i];

		S[i] = '*' + S[i];

		H[i] = hash(S[i]);

	}





	std::vector<std::vector<std::array<int, 2>>> v(n);

	for (int i = 0; i < n; ++i) {

		v[i].resize(S[i].length() + 1);

		std::vector<char> nxt(S[i].length());

		nxt[S[i].length() - 1] = 0;

		for (int j = S[i].length() - 2; j; --j) {

			if (S[i][j] == S[i][j + 1]) nxt[j] = nxt[j + 1];

			else nxt[j] = S[i][j + 1];

		}

		int l = 1, r = S[i].length();

		for (int j = 1; j < S[i].length(); ++j) {

			if (S[i][j] < nxt[j])v[i][r--] = std::array<int, 2>{j, i == 0};

			else v[i][l++] = std::array<int, 2>{j, i == 0};;

		}

		v[i][l] = std::array<int, 2>{int(S[i].length()), i == 0};

	}



	std::function<bool(int, int, int, int)> cmp = [&](int x, int dx, int y, int dy) -> bool {

		int l = 1;

		int r = std::min(S[x].length() - (dx < S[x].length()) - 1, S[y].length() - (dy < S[y].length()) - 1);

//		std::cerr << x << ' ' << dx << ' ' << y << ' ' << dy << "!!" << l << ' ' << r << '\n';

		int pos = 0;

		while (l <= r) {

			int m = (l + r) >> 1;

//			std::cerr << m << ' ' << x << ' ' << dx << ' ' << y << ' ' << dy << ' ' << H[x].getHash(dx, m) << ' ' << H[y].getHash(dy, m) << '\n';

			if (H[x].getHash(dx, m) == H[y].getHash(dy, m)) {

				l = m + 1;

			} else {

				pos = m;

				r = m - 1;

			}

		}

		bool res = false;

		if (pos == 0) {

			if (S[x].length() - (dx < S[x].length()) == S[y].length() - (dy < S[y].length())) res = x < y;

			else res = S[x].length() - (dx < S[x].length()) < S[y].length() - (dy < S[y].length());

		} else {

			res = S[x][pos + (pos >= dx)] < S[y][pos + (pos >= dy)];

		}

//		std::cerr << "@@" << res << '\n';

		return res;

	};



	for (int i = 0; i < n - 1; ++i) {

		int p = 1;

		int sum = 0;

		for (int jj = 1; jj < v[i + 1].size(); ++jj) {

			auto& j = v[i + 1][jj];

			while (p < v[i].size() && cmp(i, v[i][p][0], i + 1, j[0])) {

				sum = (sum + v[i][p++][1]) % mod;

			}

			j[1] = sum;

		}

	}

	for (int i = 0; i < n; ++i) {

//		for (int j = 1; j <= S[i].length(); ++j)std::cerr << v[i][j][0] << ' ' << v[i][j][1] << "&&&";

//		std::cerr << '\n';

	}



	ll ans = 0;

////	for (int i = 0; i < S[n - 1].length(); ++i)std::cerr << v[n - 1][i][1] << '!';

	for (auto i: v[n - 1]) {

		ans = (ans + i[1]) % mod;

	}

	std::cout << ans << '\n';

	return 0;

}