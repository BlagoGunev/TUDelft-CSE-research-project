#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,sse,sse4")
#if __has_include(<tr2/dynamic_bitset>)
#include <tr2/dynamic_bitset>
#endif
using namespace std;

using ll = long long;
using ldbl = long double;
//using lll = __int128_t;
template<typename T> using two = pair<T, T>;
#define all(X...) (X).begin(), (X).end()
#define all_r(X...) (X).rbegin(), (X).rend()
using _ntests_t = unsigned;
#define ntests _ntests_t _nt; cin >> _nt; [[maybe_unused]] NEXT_TEST: while (_nt --)
#define next_test goto NEXT_TEST
#define line "\n"
constexpr int mod  [[maybe_unused]] = 998244353;
constexpr int mod1 [[maybe_unused]] = 1000000007;
template<class T, class Cmp> using pq_cmp = priority_queue<T, vector<T>, Cmp>;
template<typename T> T sq(T x) { return x * x; }
template<typename T> T id(T x) { return x; }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ntests {
		int n, m;
		cin >> n >> m;
		int c = 1;
		int x = n;
		int l = max(0, n - m);
		int r = n + m;
		for (int i = 0; i <= 30; i ++) {
			if (r - l >= c || (r & c) || (l & c)) x |= c;
			c <<= 1;
		}
		cout << x << endl;
	}
}