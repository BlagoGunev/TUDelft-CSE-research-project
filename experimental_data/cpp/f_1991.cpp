// Problem: F. Triangle Formation
// Contest: Codeforces - Pinely Round 4 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1991/problem/F
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#include <chrono>
std::mt19937 eng(std::chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return std::uniform_int_distribution<int>(l, r)(eng); }

namespace FastIO {
	template <typename T> inline T read() { T x = 0, w = 0; char ch = getchar(); while (ch < '0' || ch > '9') w |= (ch == '-'), ch = getchar(); while ('0' <= ch && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar(); return w ? -x : x; }
	template <typename T> inline void write(T x) { if (!x) return; write<T>(x / 10), putchar((x % 10) ^ '0'); }
	template <typename T> inline void print(T x) { if (x > 0) write<T>(x); else if (x < 0) putchar('-'), write<T>(-x); else putchar('0'); }
	template <typename T> inline void print(T x, char en) { print<T>(x), putchar(en); }
	inline char rChar() { char ch = getchar(); while (!isalpha(ch)) ch = getchar(); return ch; }
}; using namespace FastIO;

const int V = 100;

#define MAXN 200001
int a[MAXN];
bool ok[MAXN][V + 1];
int main() {
	int N = read<int>(), Q = read<int>();
	for (int i = 1; i <= N; ++i) a[i] = read<int>();
	for (int i = 1; i <= N; ++i) {
		std::vector<int> vec; int cur = 0;
		for (int j = i, b = std::min(N, i + V - 1), n = 0; j <= b; ++j, ++n) {
			if (cur) { ok[i][j - i] = true; continue; }
			vec.push_back(a[j]);
			int k = n; while (k && vec[k] < vec[k - 1]) std::swap(vec[k], vec[k - 1]), --k;
			int mn_ok = n + 100, mx_ok = -100;
			for (int d = 2; d <= n; ++d) if (vec[d - 2] + vec[d - 1] > vec[d]) { mn_ok = d; break; }
			for (int d = n; d >= 2; --d) if (vec[d - 2] + vec[d - 1] > vec[d]) { mx_ok = d; break; }
			if (mx_ok - mn_ok >= 3) cur = 1;
			for (int p = 0, q = 5; q <= n; ++p, ++q) {
				if (vec[p] + vec[p + 1] > vec[q - 1] && vec[p + 2] + vec[p + 3] > vec[q]) { cur = 1; break; }
				if (vec[p] + vec[p + 2] > vec[q - 1] && vec[p + 1] + vec[p + 3] > vec[q]) { cur = 1; break; }
				if (vec[p] + vec[p + 3] > vec[q - 1] && vec[p + 1] + vec[p + 2] > vec[q]) { cur = 1; break; }
				if (vec[p + 1] + vec[p + 2] > vec[q - 1] && vec[p] + vec[p + 3] > vec[q]) { cur = 1; break; }
				if (vec[p] + vec[p + 1] > vec[q - 2] && vec[p + 2] + vec[q - 1] > vec[q]) { cur = 1; break; }
				if (vec[p] + vec[p + 2] > vec[q - 2] && vec[p + 1] + vec[q - 1] > vec[q]) { cur = 1; break; }
				if (vec[p + 1] + vec[p + 2] > vec[q - 2] && vec[p] + vec[q - 1] > vec[q]) { cur = 1; break; }
			} if (cur == 1) ok[i][j - i] = true;
		}
	} for (int i = 1, l, r; i <= Q; ++i) {
		l = read<int>(), r = read<int>();
		if (r - l >= V) { puts("YES"); continue; }
		puts(ok[l][r - l] ? "YES" : "NO");
	}
	return 0;
}

// a b c [d] e [f]