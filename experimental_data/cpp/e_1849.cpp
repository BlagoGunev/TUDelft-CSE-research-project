#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = std::int_fast64_t;
using std::cout;
using std::cerr;
using std::endl;
using std::cin;

#if defined(DONLINE_JUDGE)
	#define NDEBUG
#elif defined(ONLINE_JUDGE)
	#define NDEBUG
#endif

template<typename T> std::vector<T> make_v(size_t a){return std::vector<T>(a);}
template<typename T, typename... Ts> auto make_v(size_t a, Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

// https://github.com/yosupo06/library-checker-problems/blob/master/datastructure/staticrmq/sol/correct.cpp
namespace lc {
	using namespace std;
	using uint = unsigned int;
	using ll = long long;
	using ull = unsigned long long;
	constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
	template <class T> using V = vector<T>;
	template <class T> using VV = V<V<T>>;

	// bit op
	int popcnt(uint x) { return __builtin_popcount(x); }
	int popcnt(ull x) { return __builtin_popcountll(x); }
	int bsr(uint x) { return 31 - __builtin_clz(x); }
	int bsr(ull x) { return 63 - __builtin_clzll(x); }
	int bsf(uint x) { return __builtin_ctz(x); }
	int bsf(ull x) { return __builtin_ctzll(x); }

	template <class D, class OP> struct SparseTable {
		D e;
		OP op;
		VV<D> data;
		SparseTable(V<D> v = V<D>(), D _e = D(), OP _op = OP()) : e(_e), op(_op) {
			int n = int(v.size());
			if (n == 0) return;
			int lg = bsr(uint(n)) + 1;
			data = VV<D>(lg);
			data[0] = v;
			int l = 1;
			for (int s = 1; s < lg; s++) {
				data[s] = V<D>(n);
				for (int i = 0; i < n - l; i++) {
					data[s][i] = op(data[s - 1][i], data[s - 1][i + l]);
				}
				l <<= 1;
			}
		}
		D query(int l, int r) const {
			assert(l <= r);
			if (l == r) return e;
			int u = bsr(uint(r - l));
			return op(data[u][l], data[u][r - (1 << u)]);
		}
	};
	template <class D, class OP>
	SparseTable<D, OP> get_sparse_table(V<D> v, D e, OP op) {
		return SparseTable<D, OP>(v, e, op);
	}
}

int main() {
	int n; scanf("%d", &n);
	std::vector<int> a(n); for (auto& v: a) scanf("%d", &v), --v;

	std::vector<int> ord(n);
	for (int i = 0; i < n; ++i) ord[a[i]] = i;

	auto sparse_table = lc::get_sparse_table(a, 1 << 30, [&](int a, int b){ return std::min(a, b); });

	i64 ans = 0;
	std::set<int> bounds;
	for (int ii = n - 1; ii >= 0; --ii) {
		const int idx = ord[ii];

		int l, r; {
			auto it = bounds.lower_bound(idx);
			r = (it != bounds.end() ? *it - 1 : n - 1);
			l = (it != bounds.begin() ? *std::prev(it) + 1 : 0);
		}

		// printf("# %d [%d %d]\n", ii + 1, l + 1, r + 1);

		const int llen = idx - l + 1;
		const int rlen = r - idx + 1;
		if (llen < rlen) {
			for (int i = idx; i >= l; --i) {
				int ok = idx, ng = r + 1;
				while (std::abs(ok - ng) > 1) {
					int mid = (ok + ng) >> 1;

					int min = sparse_table.query(i, mid + 1);
					int midx = ord[min];

					// printf("L %d %d %d\n", i + 1, mid + 1, min + 1, midx + 1);

					if (midx < idx) ok = mid;
					else ng = mid;
				}

				int min = sparse_table.query(i, ok + 1);
				int midx = ord[min];
				if (midx < idx) ans += ok - idx + 1;

				// printf("! %d %d\n", ok + 1, ans);
			}
		} else {
			for (int i = idx; i <= r; ++i) {
				int ng = idx + 1, ok = l;
				while (std::abs(ok - ng) > 1) {
					int mid = (ok + ng) >> 1;

					int min = sparse_table.query(mid, i + 1);
					int midx = ord[min];

					// printf("R %d %d %d\n", mid + 1, i + 1, min + 1, midx + 1);

					if (midx < idx) ok = mid;
					else ng = mid;
				}

				int min = sparse_table.query(ok, i + 1);
				int midx = ord[min];
				if (midx < idx) ans += ok - l + 1;

				// printf("! %d %d\n", ok + 1, ans);
			}
		}
		// printf("! # %lld\n", ans);

		bounds.insert(idx);
	}

	printf("%lld\n", ans);
	return 0;
}