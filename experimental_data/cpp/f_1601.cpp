#include<bits/stdc++.h>



using namespace std;



#define Reimu inline void // 灵梦赛高

#define Marisa inline int // 魔理沙赛高

#define Sanae inline bool // 早苗赛高



using LL = long long;

using ULL = unsigned long long;



using Pii = pair<int, int>;

using Tiii = tuple<int, int, int>;

#define fi first

#define se second



template<typename Ty, unsigned N>

using Arr = Ty[N];

template<typename Ty, unsigned N, unsigned M>

using Mat = Ty[N][M];



namespace FastIO {

	template<typename Ty>

	Reimu read(Ty &x) { // 默认读入整型 int, LL, Uint, ULL, ...

		x = 0;

		int f = 0, c = getchar();

		for (; !isdigit(c); c = getchar()) f |= c == '-';

		for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c & 15);

		if (f) x = -x;

	}



	template<>

	Reimu read(double &x) { // 读入浮点型 double

		x = 0;

		int f = 0, c = getchar();

		for (; !isdigit(c); c = getchar()) f |= c == '-';

		for (; isdigit(c); c = getchar()) x = x * 10 + (c & 15);

		if (c == '.') {

			double e = 1;

			for (c = getchar(); isdigit(c); c = getchar()) x += (c & 15) * (e *= .1);

		}

		if (f) x = -x;

	}



	template<>

	Reimu read(char &c) { // 读入字符 char

		do c = getchar(); while (!isgraph(c));

	}



	template<>

	Reimu read(string &s) { // 读入字符串 string

		s = "";

		char c = getchar();

		while (!isgraph(c)) c = getchar();

		for (; isgraph(c); c = getchar()) s += c;

	}



	template<typename Ty, typename...Args>

	Reimu read(Ty &x, Args &...args) { // 不定长传参

		read(x);

		read(args...);

	}



	// 以上快读

	template<typename Ty>

	Reimu print(const Ty &x) { // 默认输出整型 int, LL, Uint, ULL, ...

		if (x < 0) {

			putchar('-');

			print(-x);

			return;

		}

		if (x > 9) print(x / 10);

		putchar(x % 10 | 48);

	}



	template<>

	Reimu print(const char &c) { // 输出字符 char

		putchar(c);

	}



	template<>

	Reimu print(const string &s) { // 输出字符串 string

		for (auto &c: s) putchar(c);

	}



	template<typename Ty, typename...Args>

	Reimu print(const Ty &x, const Args &...args) { // 不定长传参

		print(x);

		print(args...);

	}

	// 以上快写

}

using namespace FastIO; // 使用快读快写



const int P1 = 998244353, P2 = 1e9 + 7, half = 1000000;

Marisa mod(LL x, int P) { return (x %= P) < 0 ? x + P : x; }



const int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};



int ans, tot1;

LL n, tot2;

Arr<LL, 10> s;

Arr<vector<int>, 10> vec;



Reimu init(int x, int v) {

	if (x > 6) return;

	vec[x].emplace_back(mod(tot1 - v, P1));

	s[x] += mod(tot1++ - v, P1);

	for (int i = 0; i < 10; ++i) init(x + 1, v * 10 + i);

}



Marisa check(LL x) { return x * half + half - 1 <= n && x * half * 10 > n; }

Reimu solve(int x, LL v) {

	if (v > n) return;

	if (check(v)) {

		for (int i = 0; i <= 6; ++i) {

			int t = mod(tot2 + 1 - v * pow10[i], P1), loc = lower_bound(vec[i].begin(), vec[i].end(), P1 - t) - vec[i].begin();

			ans = mod(ans + s[i] + 1LL * t * vec[i].size() - 1LL * P1 * (vec[i].size() - loc), P2);

		}

		tot2 += tot1;

	} else {

		ans = mod(ans + mod(++tot2 - v, P1), P2);

		for (int i = (!x); i < 10; ++i) solve(x + 1, v * 10 + i);

	}

}



signed main() {

	read(n);

	init(0, 0);

	for (int i = 0; i <= 6; ++i) sort(vec[i].begin(), vec[i].end());

	for (int i = 1; i < 10; ++i) solve(1, i);

	print(ans);

	return 0;

}