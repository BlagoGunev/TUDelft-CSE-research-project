// #pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
// #include <x86intrin.h>
using namespace std;
#if __cplusplus >= 202002L
using namespace numbers;
#endif

template<class T>
struct graph{
	using Weight_t = T;
	struct Edge_t{
		int from, to;
		T cost;
	};
	int n;
	vector<Edge_t> edge;
	vector<vector<int>> adj;
	function<bool(int)> ignore;
	graph(int n = 1): n(n), adj(n){
		assert(n >= 1);
	}
	graph(const vector<vector<int>> &adj, bool undirected = true): n((int)adj.size()), adj(n){
		assert(n >= 1);
		if(undirected){
			for(auto u = 0; u < n; ++ u) for(auto v: adj[u]) if(u < v) link(u, v);
		}
		else for(auto u = 0; u < n; ++ u) for(auto v: adj[u]) orient(u, v);
	}
	graph(const vector<vector<pair<int, T>>> &adj, bool undirected = true): n((int)adj.size()), adj(n){
		assert(n >= 1);
		if(undirected){
			for(auto u = 0; u < n; ++ u) for(auto [v, w]: adj[u]) if(u < v) link(u, v, w);
		}
		else for(auto u = 0; u < n; ++ u) for(auto [v, w]: adj[u]) orient(u, v, w);
	}
	graph(int n, vector<array<int, 2>> &edge, bool undirected = true): n(n), adj(n){
		assert(n >= 1);
		for(auto [u, v]: edge) undirected ? link(u, v) : orient(u, v);
	}
	graph(int n, vector<tuple<int, int, T>> &edge, bool undirected = true): n(n), adj(n){
		assert(n >= 1);
		for(auto [u, v, w]: edge) undirected ? link(u, v, w) : orient(u, v, w);
	}
	int add_vertex(){
		adj.emplace_back();
		return n ++;
	}
	int operator()(int u, int id) const{
		#ifdef LOCAL
		assert(0 <= id && id < (int)edge.size());
		assert(edge[id].from == u || edge[id].to == u);
		#endif
		return u ^ edge[id].from ^ edge[id].to;
	}
	int link(int u, int v, T w = {}){ // insert an undirected edge
		int id = (int)edge.size();
		adj[u].push_back(id), adj[v].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = {}){ // insert a directed edge
		int id = (int)edge.size();
		adj[u].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	vector<int> neighbor(int u, int exclude = -1) const{
		vector<int> res;
		for(auto id: adj[u]){
			if(id == exclude || ignore && ignore(id)) continue;
			res.push_back(operator()(u, id));
		}
		return res;
	}
	void clear(){
		for(auto [u, v, w]: edge){
			adj[u].clear();
			adj[v].clear();
		}
		edge.clear();
		ignore = {};
	}
	graph transpose() const{ // the transpose of the directed graph
		graph res(n);
		for(auto id = 0; id < (int)edge.size(); ++ id){
			if(ignore && ignore(id)) continue;
			res.orient(edge[id].to, edge[id].from, edge[id].cost);
		}
		return res;
	}
	int degree(int u) const{ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
	// The adjacency list is sorted for each vertex.
	vector<vector<int>> get_adjacency_list() const{
		vector<vector<int>> res(n);
		for(auto u = 0; u < n; ++ u) for(auto id: adj[u]){
			if(ignore && ignore(id)) continue;
			res[(*this)(u, id)].push_back(u);
		}
		return res;
	}
	void set_ignoration_rule(const function<bool(int)> &f){
		ignore = f;
	}
	void reset_ignoration_rule(){
		ignore = nullptr;
	}
	friend ostream &operator<<(ostream &out, const graph &g){
		for(auto id = 0; id < (int)g.edge.size(); ++ id){
			if(g.ignore && g.ignore(id)) continue;
			auto &e = g.edge[id];
			out << "{" << e.from << ", " << e.to << ", " << e.cost << "}\n";
		}
		return out;
	}
};

// returns an euler walk starting at s given that there are edge_cnt edges reachable from s
// Returns the edge list
// O(|V|+|E|)
template<class T>
optional<vector<int>> euler_walk(const graph<T> &g, int s, int edge_cnt){
	if(!edge_cnt) return {vector<int>{}};
	int n = g.n, m = (int)g.edge.size();
	vector<int> deg(n), its(n), used(m), res_e;
	vector<array<int, 2>> st = {{s, -1}};
	++ deg[s]; // to allow Euler paths, not just cycles
	while(!st.empty()){
		auto [u, id] = st.back();
		int &it = its[u], end = (int)g.adj[u].size();
		if(g.ignore) while(it < end && g.ignore(g.adj[u][it])) ++ it;
		if(it == end){
			res_e.push_back(id), st.pop_back();
			continue;
		}
		int id_next = g.adj[u][it ++];
		if(!used[id_next]){
			int v = g(u, id_next);
			-- deg[u], ++ deg[v];
			used[id_next] = 1, st.push_back({v, id_next});
		}
	}
	for(auto d: deg) if(d < 0 || (int)res_e.size() != edge_cnt + 1) return {};
	return {{res_e.rbegin() + 1, res_e.rend()}};
}

struct number_theory{
	int SZ;
	vector<int> lpf, prime;
	number_theory(int SZ): SZ(SZ), lpf(SZ + 1){ // O(SZ)
		lpf[0] = lpf[1] = numeric_limits<int>::max() / 2;
		for(auto i = 2; i <= SZ; ++ i){
			if(!lpf[i]) lpf[i] = i, prime.push_back(i);
			for(auto j = 0; j < (int)prime.size() && prime[j] <= lpf[i] && prime[j] * i <= SZ; ++ j) lpf[prime[j] * i] = prime[j];
		}
	}
	vector<int> precalc_mobius() const{
		vector<int> mobius(SZ + 1, 1);
		for(auto i = 2; i <= SZ; ++ i){
			if(i / lpf[i] % lpf[i]) mobius[i] = -mobius[i / lpf[i]];
			else mobius[i] = 0;
		}
		return mobius;
	}
	vector<int> precalc_phi() const{
		vector<int> phi(SZ + 1, 1);
		for(auto i = 2; i <= SZ; ++ i){
			if(i / lpf[i] % lpf[i]) phi[i] = phi[i / lpf[i]] * (lpf[i] - 1);
			else phi[i] = phi[i / lpf[i]] * lpf[i];
		}
		return phi;
	}
	// Returns {gcd(0, n), ..., gcd(SZ, n)}
	vector<int> precalc_gcd(int n) const{
		vector<int> res(SZ + 1, 1);
		res[0] = n;
		for(auto x = 2; x <= SZ; ++ x) res[x] = n % (lpf[x] * res[x / lpf[x]]) ? res[x / lpf[x]] : lpf[x] * res[x / lpf[x]];
		return res;
	}
	bool is_prime(int x) const{
		assert(0 <= x && x <= SZ);
		return lpf[x] == x;
	}
	int mu_large(long long x) const{ // O(sqrt(x))
		int res = 1;
		for(auto i = 2LL; i * i <= x; ++ i) if(x % i == 0){
			if(x / i % i) return 0;
			x /= i, res = -res;
		}
		if(x > 1) res = -res;
		return res;
	}
	long long phi_large(long long x) const{ // O(sqrt(x))
		long long res = x;
		for(auto i = 2LL; i * i <= x; ++ i) if(x % i == 0){
			while(x % i == 0) x /= i;
			res -= res / i;
		}
		if(x > 1) res -= res / x;
		return res;
	}
	// returns an array is_prime of length high-low where is_prime[i] = [low+i is a prime]
	vector<int> sieve(long long low, long long high) const{
		assert(high - 1 <= 1LL * SZ * SZ);
		vector<int> is_prime(high - low, true);
		for(auto p: prime) for(auto x = max(1LL * p, (low + p - 1) / p) * p; x < high; x += p) is_prime[x - low] = false;
		for(auto x = 1; x >= low; -- x) is_prime[x - low] = false;
		return is_prime;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	number_theory nt{100'000};
	auto __solve_tc = [&](auto __tc_num)->int{
		int m;
		cin >> m, -- m;
		int n = 3;
		for(; ; ++ n){
			int cnt = n * (n + 1) / 2;
			if(~n & 1){
				cnt -= n / 2 - 1;
			}
			if(cnt >= m){
				break;
			}
		}
		graph<int> g(n);
		for(auto i = 0; i < n; ++ i){
			for(auto j = i; j < n; ++ j){
				if(~n & 1 && i >= 2 && ~i & 1 && j == i + 1){
					continue;
				}
				g.link(i, j);
			}
		}
		auto walk = *euler_walk(g, 0, n * (n + 1) / 2 - (~n & 1 ? n / 2 - 1 : 0));
		walk.resize(m);
		cout << "2 ";
		for(auto u = 0; auto id: walk){
			u = g(u, id);
			cout << nt.prime[u] << " ";
		}
		cout << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
	}
	return 0;
}

/*

*/