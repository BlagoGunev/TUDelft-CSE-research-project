#define _USE_MATH_DEFINES

#define _EXT_CODECVT_SPECIALIZATIONS_H 1

#define _EXT_ENC_FILEBUF_H 1

#include <bits/stdc++.h>

#include <bits/extc++.h>

using namespace std;

/*

#include <atcoder/all>

using namespace atcoder;

*/

/*

#include <boost/multiprecision/cpp_int.hpp>

#include <boost/multiprecision/cpp_dec_float.hpp>

using bll = boost::multiprecision::cpp_int;

using bdouble = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<100>>;

using namespace boost::multiprecision;

*/

#if defined(LOCAL_TEST) || defined(LOCAL_DEV)

	#define BOOST_STACKTRACE_USE_ADDR2LINE

	#define BOOST_STACKTRACE_ADDR2LINE_LOCATION /usr/local/opt/binutils/bin/addr2line

	#define _GNU_SOURCE 1

	#include <boost/stacktrace.hpp>

#endif

#ifdef LOCAL_TEST

	namespace std {

		template <typename T> class dvector : public std::vector<T> {

		public:

			using std::vector<T>::vector;

			template <typename T_ = T, typename std::enable_if_t<std::is_same_v<T_, bool>, std::nullptr_t> = nullptr>

			std::vector<bool>::reference operator[](std::size_t n) {

				if (this->size() <= n) { std::cerr << boost::stacktrace::stacktrace() << '\n' << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")" << '\n'; } return this->at(n);

			}

			template <typename T_ = T, typename std::enable_if_t<std::is_same_v<T_, bool>, std::nullptr_t> = nullptr>

			const T_ operator[](std::size_t n) const {

				if (this->size() <= n) { std::cerr << boost::stacktrace::stacktrace() << '\n' << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")" << '\n'; } return this->at(n);

			}

			template <typename T_ = T, typename std::enable_if_t<!std::is_same_v<T_, bool>, std::nullptr_t> = nullptr>

			T_& operator[](std::size_t n) {

				if (this->size() <= n) { std::cerr << boost::stacktrace::stacktrace() << '\n' << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")" << '\n'; } return this->at(n);

			}

			template <typename T_ = T, typename std::enable_if_t<!std::is_same_v<T_, bool>, std::nullptr_t> = nullptr>

			const T_& operator[](std::size_t n) const {

				if (this->size() <= n) { std::cerr << boost::stacktrace::stacktrace() << '\n' << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")" << '\n'; } return this->at(n);

			}

		};

		template <typename T, typename Compare = std::less<T>, typename Allocator = std::allocator<T>> class dmultiset : public std::multiset<T,Compare,Allocator> {

		public:

			using std::multiset<T,Compare,Allocator>::multiset;

			const typename std::multiset<T,Compare,Allocator>::iterator erase(const typename std::multiset<T,Compare,Allocator>::iterator it) {

				return std::multiset<T,Compare,Allocator>::erase(it);

			}

			std::size_t erase([[maybe_unused]] const T& x) {

				std::cerr << boost::stacktrace::stacktrace() << '\n'; assert(false);

			}

			std::size_t erase_all_elements(const T& x) {

				return std::multiset<T,Compare,Allocator>::erase(x);

			}

		};

	}

	#define vector dvector

	#define multiset dmultiset

	class SIGFPE_exception : std::exception {};

	class SIGSEGV_exception : std::exception {};

	void catch_SIGFPE([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGFPE_exception(); }

	void catch_SIGSEGV([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGSEGV_exception(); }

	signed convertedmain();

	signed main() { signal(SIGFPE, catch_SIGFPE); signal(SIGSEGV, catch_SIGSEGV); return convertedmain(); }

	#define main() convertedmain()

#else

	#define erase_all_elements erase

#endif

#ifdef LOCAL_DEV

	template <typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) {

		return s << "(" << p.first << ", " << p.second << ")"; }

	template <typename T, std::size_t N> std::ostream& operator<<(std::ostream& s, const std::array<T, N>& a) {

		s << "{ "; for (std::size_t i = 0; i < N; ++i){ s << a[i] << "\t"; } s << "}"; return s; }

	template <typename T, typename Compare> std::ostream& operator<<(std::ostream& s, const std::set<T, Compare>& se) {

		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }

	template <typename T, typename Compare> std::ostream& operator<<(std::ostream& s, const std::multiset<T, Compare>& se) {

		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }

	template <typename T1, typename T2, typename Compare> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2, Compare>& m) {

		s << "{\n"; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << "\n"; } s << "}"; return s; }

	template <typename T> std::ostream& operator<<(std::ostream& s, const std::deque<T>& v) {

		for (std::size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }

	template <typename T> std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {

		for (std::size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }

	template <typename T> std::ostream& operator<<(std::ostream& s, const std::vector<std::vector<T>>& vv) {

		s << "\\\n"; for (std::size_t i = 0; i < vv.size(); ++i){ s << vv[i] << "\n"; } return s; }

	template <typename T, std::size_t N, typename std::enable_if_t<!std::is_same_v<T, char>, std::nullptr_t> = nullptr> std::ostream& operator<<(std::ostream& s, const T (&v)[N]) {

		for (std::size_t i = 0; i < N; ++i){ s << v[i]; if (i < N - 1) s << "\t"; } return s; }

	template <typename T, std::size_t N, std::size_t M, typename std::enable_if_t<!std::is_same_v<T, char>, std::nullptr_t> = nullptr> std::ostream& operator<<(std::ostream& s, const T (&vv)[N][M]) {

		s << "\\\n"; for (std::size_t i = 0; i < N; ++i){ s << vv[i] << "\n"; } return s; }

	#if __has_include(<ext/pb_ds/assoc_container.hpp>)

		template <typename Key, typename Compare> std::ostream& operator<<(std::ostream& s, const __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>& se) {

			s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }

		template <typename Key, typename T, typename Hash> std::ostream& operator<<(std::ostream& s, const __gnu_pbds::gp_hash_table<Key, T, Hash>& m) {

			s << "{\n"; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << "\n"; } s << "}"; return s; }

	#endif

	void debug_impl() { std::cerr << '\n'; }

	template <typename Head, typename... Tail> void debug_impl(Head& head, Tail&... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }

	template <typename Head, typename... Tail> void debug_impl(const Head& head, const Tail&... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }

	#define debug(...) do { std::cerr << ":" << __LINE__ << " (" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__); } while (false)

	constexpr inline long long prodlocal([[maybe_unused]] long long prod, [[maybe_unused]] long long local) { return local; }

#else

	#define debug(...) do {} while (false)

	constexpr inline long long prodlocal([[maybe_unused]] long long prod, [[maybe_unused]] long long local) { return prod; }

#endif

//#define int long long

using ll = long long;

//INT_MAX = (1<<31)-1 = 2147483647, INT64_MAX = (1LL<<63)-1 = 9223372036854775807

constexpr ll INF = std::numeric_limits<ll>::max() == INT_MAX ? (ll)1e9 + 7 : (ll)1e18;

constexpr ll MOD = (ll)1e9 + 7; //primitive root = 5

//constexpr ll MOD = 998244353; //primitive root = 3

constexpr double EPS = 1e-9;

constexpr ll dx[4] = {1, 0, -1, 0};

constexpr ll dy[4] = {0, 1, 0, -1};

constexpr ll dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};

constexpr ll dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};

#define repoverload3(_1, _2, _3, name, ...) name

#define rep3(i, a, b) for(ll i=(a), i##_length=(b); i<i##_length; ++i)

#define rep2(i, n) rep3(i, 0, n)

#define rep1(n) rep3(i, 0, n)

#define rep(...) repoverload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

#define repeq3(i, a, b) rep3(i, (a)+1, (b)+1)

#define repeq2(i, n) rep3(i, 1, (n)+1)

#define repeq1(n) rep3(i, 1, (n)+1)

#define repeq(...) repoverload3(__VA_ARGS__, repeq3, repeq2, repeq1)(__VA_ARGS__)

#define rrep3(i, a, b) for(ll i=(b)-1; i>=(a); --i)

#define rrep2(i, n) rrep3(i, 0, n)

#define rrep1(n) rrep3(i, 0, n)

#define rrep(...) repoverload3(__VA_ARGS__, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define rrepeq3(i, a, b) rrep3(i, (a)+1, (b)+1)

#define rrepeq2(i, n) rrep3(i, 1, (n)+1)

#define rrepeq1(n) rrep3(i, 1, (n)+1)

#define rrepeq(...) repoverload3(__VA_ARGS__, rrepeq3, rrepeq2, rrepeq1)(__VA_ARGS__)

#define all(v) std::begin(v), std::end(v)

#define rall(v) std::rbegin(v), std::rend(v)

void p() { std::cout << '\n'; }

template <typename Head, typename... Tail> void p(Head& head, Tail&... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }

template <typename Head, typename... Tail> void p(const Head& head, const Tail&... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }

template <typename T> inline void pv(const std::vector<T>& v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }

template <typename T> inline bool chmax(T& a, T b) { return a < b && (a = b, true); }

template <typename T> inline bool chmin(T& a, T b) { return a > b && (a = b, true); }

template <typename T> inline void uniq(std::vector<T>& v) { std::sort(v.begin(), v.end()); v.erase(std::unique(v.begin(), v.end()), v.end()); }

template <typename T> inline ll sz(const T& v) { return std::size(v); }

template <typename T, std::size_t N> std::vector<T> make_vector_impl(std::vector<ll>& sizes, typename std::enable_if<(N==1), const T&>::type x) { return std::vector<T>(sizes.front(),x); }

template <typename T, std::size_t N> auto make_vector_impl(std::vector<ll>& sizes, typename std::enable_if<(N>1), const T&>::type x) { ll size=sizes.back(); sizes.pop_back(); return std::vector<decltype(make_vector_impl<T,N-1>(sizes,x))>(size,make_vector_impl<T,N-1>(sizes,x)); }

template <typename T, std::size_t N> auto make_vector(const ll (&sizes)[N], const T& x=T()) { std::vector<ll> s(N); for(std::size_t i=0; i<N; ++i)s[i]=sizes[N-1-i]; return make_vector_impl<T,N>(s,x); }

#if __has_include(<ext/pb_ds/assoc_container.hpp>)

	template <typename Key, typename Mapped, typename Hash = std::hash<Key>, typename std::enable_if_t<std::is_integral_v<Key>, std::nullptr_t> = nullptr> class fmap : public __gnu_pbds::gp_hash_table<Key, Mapped, Hash> {

	public:

		using __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::gp_hash_table;

		template <typename T> fmap(std::initializer_list<std::initializer_list<T>> il) : __gnu_pbds::gp_hash_table<Key, Mapped, Hash>() {

			for (auto&& x : il) __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::insert(std::pair<Key, Mapped>(*x.begin(), *(x.begin() + 1)));

		}

		template <typename T> ll count(const T& x) const {

			return __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::find(x) != __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::end();

		}

	};

#else

	template <typename Key, typename Mapped> using fmap = std::map<Key, Mapped>;

#endif

template <typename T> class each_hepler {

public:

	class iterator {

	public:

		ll _pos;

		typename T::iterator _it;

		iterator(typename T::iterator it): _pos(0), _it(it) {}

		std::pair<ll, typename std::iterator_traits<typename T::iterator>::reference> operator*() const { return {_pos, *_it}; }

		iterator& operator++() { ++_pos; ++_it; return *this; }

		iterator operator++(int) { iterator tmp(*this); ++*this; return tmp; }

		bool operator==(iterator const& it) const { return _it == it._it; }

		bool operator!=(iterator const& it) const { return !(*this == it); }

	};

	T& _container;

	each_hepler(T& t): _container(t) {}

	iterator begin() const { return iterator(_container.begin()); }

	iterator end() const { return iterator(_container.end()); }

};

template <typename T> each_hepler<T> each(T& t) { return each_hepler<T>(t); } // for (auto&& [i, val] : each(v))

template <typename... T> class zip_helper {

public:

	class iterator : std::iterator<std::forward_iterator_tag, std::tuple<decltype(*std::declval<T>().begin())...>> {

	private:

		std::tuple<decltype(std::declval<T>().begin())...> iters_;

		template <std::size_t... I> auto deref(std::index_sequence<I...>) const { return typename iterator::value_type{*std::get<I>(iters_)...}; }

		template <std::size_t... I> void increment(std::index_sequence<I...>) { [[maybe_unused]] auto l = {(++std::get<I>(iters_), 0)...}; }

	public:

		explicit iterator(decltype(iters_) iters) : iters_{std::move(iters)} {}

		iterator& operator++() { increment(std::index_sequence_for<T...>{}); return *this; }

		iterator operator++(int) { auto saved{*this}; increment(std::index_sequence_for<T...>{}); return saved; }

		bool operator!=(const iterator& other) const { return iters_ != other.iters_; }

		auto operator*() const { return deref(std::index_sequence_for<T...>{}); }

	};

	zip_helper(T&... seqs) : begin_{std::make_tuple(seqs.begin()...)}, end_{std::make_tuple(seqs.end()...)} {}

	iterator begin() const { return begin_; }

	iterator end() const { return end_; }

private:

	iterator begin_, end_;

};

template <typename... T> auto zip(T&&... seqs) { return zip_helper<T...>{seqs...}; } // for (auto&& [a, b, c] : zip(A, B, C))



/*-----8<-----template-----8<-----*/



//[lib]ZobristHash.cpp

//ある要素を持っている/持っていないの2^Nの状態を管理するのに使える

//https://cympfh.cc/procon/hash.zobrist.html

using ZobristHashType = unsigned long long;

vector<ZobristHashType> zobristHashVector;

void initZobristHash(ll size) {

	zobristHashVector.resize(size);

	mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

	generate(zobristHashVector.begin(), zobristHashVector.end(), mt);

}



class ZobristHash {

public:

	ZobristHashType hash = 0;

	ZobristHash() {}

	void up(ll index) { hash ^= zobristHashVector[index]; }

	void down(ll index) { hash ^= zobristHashVector[index]; }

	void flip(ll index) { hash ^= zobristHashVector[index]; }

	void add(const ZobristHash& r) { hash ^= r.hash; }

	void erase(const ZobristHash& r) { hash ^= r.hash; }

	bool operator==(const ZobristHash& r) const { return r.hash == hash; }

	bool operator!=(const ZobristHash& r) const { return r.hash != hash; }

	bool operator<(const ZobristHash& r) const { return r.hash < hash; }

};



/*-----8<-----library-----8<-----*/



void solve() {

	ll N, M, K;

	cin >> N >> M >> K;



	//{コスト, 頂点番号}

	vector<vector<pair<ll,ll>>> g(N);

	rep(i,M){

		ll a, b, c;

		cin >> a >> b >> c;

		a--, b--;

		g[a].push_back({c, b});

	}

	for (auto&& v : g) sort(all(v));



	// N要素で初期化

	initZobristHash(N);



	//hashvec[i][j] -> 出次数iの頂点でj番目に小さい辺を選んだときに得られる頂点集合のhash

	vector<vector<ZobristHash>> hashvec(K+1, vector<ZobristHash>(K));

	rep(v,N){

		rep(j,g[v].size()){

			hashvec[g[v].size()][j].up(g[v][j].second);

		}

	}



	//K!通りDFSして全ての頂点集合が得られた組み合わせを数える

	ll ans = 0;

	ZobristHash hashall;

	rep(i, N) hashall.up(i);

	auto dfs = [&](auto&& dfs, ll index, ZobristHash& hash) {

		if (index == K+1) {

			ans += hash == hashall;

			return;

		}

		rep(k, index) {

			hash.add(hashvec[index][k]);

			dfs(dfs, index + 1, hash);

			hash.erase(hashvec[index][k]);

		}

	};

	ZobristHash tmp;

	dfs(dfs, 1, tmp);



	p(ans);

}



//https://codeforces.com/contest/1394/problem/B

signed main() {

#ifndef LOCAL_DEV

	std::cin.tie(nullptr);

	std::ios::sync_with_stdio(false);

#endif

	//ll Q; cin >> Q; while(Q--)solve();

	solve();

	return 0;

}