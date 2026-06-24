#include <bits/stdc++.h>
using namespace std;

#if __cplusplus < 202002L
template <class T> int ssize(const T& a){ return a.size(); }
#endif
template <class T1, class T2> istream& operator>> (istream& in, pair <T1, T2>& a){ in >> a.first >> a.second; return in; }
template <class T> istream& operator>> (istream& in, vector <T>& a){ for (auto &x: a){ in >> x; } return in; }

using ll = long long;
using ld = long double;

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

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

struct string_processor{
	vector<int> pi, pi_rev;
	vector<int> z, z_rev;
	vector<vector<int>> aut;
	// pi[i]: largest proper suffix ending at i that is also a prefix
	// O(n)
	template<class T>
	void build_prefix_function(const vector<T> &s){
		int n = (int)s.size();
		pi.assign(n, 0);
		for(auto i = 1; i < n; ++ i){
			int len = pi[i - 1];
			while(len && s[i] != s[len]) len = pi[len - 1];
			if(s[i] == s[len]) pi[i] = len + 1;
		}
	}
	// pi[i]: largest proper suffix ending at i that is also a prefix
	// O(n)
	void build_prefix_function(const string &s){
		build_prefix_function(vector<int>(s.begin(), s.end()));
	}
	// pi_rev[i]: largest proper prefix starting at i that is also a suffix
	// O(n)
	template<class T>
	void build_suffix_function(const vector<T> &s){
		int n = (int)s.size();
		pi_rev.assign(n, 0);
		for(auto i = 1; i < n; ++ i){
			int len = pi_rev[i - 1];
			while(len && s[n - 1 - i] != s[n - 1 - len]) len = pi_rev[len - 1];
			if(s[n - 1 - i] == s[n - 1 - len]) pi_rev[i] = len + 1;
		}
		reverse(pi_rev.begin(), pi_rev.end());
	}
	// pi_rev[i]: largest proper prefix starting at i that is also a suffix
	// O(n)
	void build_suffix_function(const string &s){
		build_suffix_function(vector<int>(s.begin(), s.end()));
	}
	// z[i]: 0 if i = 0, otherwise largest prefix starting at i that is also a prefix
	// O(n)
	template<class T>
	void build_z_function(const vector<T> &s){
		int n = (int)s.size();
		z.assign(n, 0);
		for(auto i = 1, j = 0; i < n; ++ i){
			if(i < j + z[j]) z[i] = min(j + z[j] - i, z[i - j]);
			while(i + z[i] < n && s[z[i]] == s[i + z[i]]) ++ z[i];
			if(i + z[i] > j + z[j]) j = i;
		}
	}
	// z[i]: 0 if i = 0, otherwise largest prefix starting at i that is also a prefix
	// O(n)
	void build_z_function(const string &s){
		build_z_function(vector<int>(s.begin(), s.end()));
	}
	// z_rev[i]: 0 if i = n-1, otherwise largest suffix ending at i that is also a suffix
	// O(n)
	template<class T>
	void build_z_rev_function(const vector<T> &s){
		int n = (int)s.size();
		z_rev.assign(n, 0);
		for(auto i = 1, j = 0; i < n; ++ i){
			if(i < j + z_rev[j]) z_rev[i] = min(j + z_rev[j] - i, z_rev[i - j]);
			while(i + z_rev[i] < n && s[n - 1 - z_rev[i]] == s[n - 1 - i + z_rev[i]]) ++ z_rev[i];
			if(i + z_rev[i] > j + z_rev[j]) j = i;
		}
		reverse(z_rev.begin(), z_rev.end());
	}
	// z_rev[i]: 0 if i = n-1, otherwise largest suffix ending at i that is also a suffix
	// O(n)
	void build_z_rev_function(const string &s){
		build_z_rev_function(vector<int>(s.begin(), s.end()));
	}
	// all alphabets must lie in range [0, sigma)
	// aut[u][c]: next state when c is added at the end
	// O(sigma * n)
	void build_prefix_automaton(const vector<int> &s, int sigma){
		assert(0 < sigma);
		for(auto c: s) assert(0 <= c && c < sigma);
		build_prefix_function(s);
		int n = (int)s.size();
		aut.assign(n + 1, vector<int>(sigma));
		for(auto i = 0; i <= n; ++ i) for(auto c = 0; c < sigma; ++ sigma){
			if(i > 0 && (i == n || c != s[i])) aut[i][c] = aut[pi[i - 1]][c];
			else aut[i][c] = i + (i < n && c == s[i]);
		}
	}
	vector<int> _s;
	// Assumes s consists only of lowercase alphabets or only of uppercase alphabets
	// Maps 'a'/'A' -> 0, ..., 'z'/'Z' -> 25
	// aut[u][c]: next state when c is added at the end
	// O(sigma * n)
	void build_prefix_automaton(const string &s){
		_s.resize((int)s.size());
		for(auto &c: _s){
			assert(isalpha(c));
			c = tolower(c) - 'a';
		}
		build_prefix_automaton(_s, 26);
	}
};
// O(n + m)
template<class T>
vector<int> find_all_matchings(const vector<T> &text, vector<T> pattern){
	int n = (int)text.size(), m = (int)pattern.size();
	pattern.insert(pattern.end(), text.begin(), text.end());
	string_processor sp;
	sp.build_z_function(pattern);
	vector<int> pos;
	for(auto i = m; i < n + m; ++ i) if(sp.z[i] >= m) pos.push_back(i - m);
	return pos;
}
// O(n + m)
vector<int> find_all_matchings(const string &text, const string &pattern){
	return find_all_matchings(vector<int>(text.begin(), text.end()), vector<int>(pattern.begin(), pattern.end()));
}

struct Graph{
	int n, k;
	vector <int> is_out;
	graph <int> g;

	Graph(int _n, int _k): n(_n), k(_k){
		is_out.resize(n);
		g = graph <int>(n);

		cin >> is_out;
		int m;
		cin >> m;
		for (auto i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			g.orient(u, v);
		}
	}

	vector <int> type;
	vector <int> cnt_out, cnt_in;

	void process(){
		type.assign(n, -1);
		type[0] = 0;
		y_combinator([&](auto self, int u, int _pe)->void{
			for(auto id: g.adj[u] | ranges::views::filter([&](int id){ return !g.ignore or !g.ignore(id);})){
				if(id == _pe) continue;
				int v = g(u, id);
				if (type[v] != -1){
					continue;
				}
				type[v] = type[u] + 1;
				if (type[v] == k){
					type[v] = 0;
				}
				self(v, id);
			}
		})(0, -1);

		cnt_out.assign(k, 0);
		cnt_in.assign(k, 0);
		for (auto u = 0; u < n; u++){
			if (is_out[u]){
				cnt_out[type[u]]++;
			}
			else{
				cnt_in[type[u]]++;
			}
		}
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifdef LOCAL
	if (fopen("input.txt", "r")){
		freopen("input.txt", "r", stdin);
		freopen("output1.txt", "w", stdout);
	}
#endif
int tests; cin >> tests; while (tests--){
	int n, k;
	cin >> n >> k;

	Graph G1(n, k);
	Graph G2(n, k);

	if (accumulate(begin(G1.is_out), end(G1.is_out), 0) != n - accumulate(begin(G2.is_out), end(G2.is_out), 0)){
		cout << "NO" << "\n";
		continue;
	}
	if (accumulate(begin(G1.is_out), end(G1.is_out), 0) == n or accumulate(begin(G1.is_out), end(G1.is_out), 0) == 0){
		cout << "YES" << "\n";
		continue;
	}

	G1.process();
	G2.process();

	vector <int> arr1 = G1.cnt_out;
	arr1.emplace_back(-1);
	arr1.insert(arr1.end(), begin(G2.cnt_in), end(G2.cnt_in));
	arr1.insert(arr1.end(), begin(G2.cnt_in), end(G2.cnt_in));
	string_processor sp1;
	sp1.build_z_function(arr1);

	vector <int> arr2 = G2.cnt_out;
	arr2.emplace_back(-1);
	arr2.insert(arr2.end(), begin(G1.cnt_in), end(G1.cnt_in));
	arr2.insert(arr2.end(), begin(G1.cnt_in), end(G1.cnt_in));
	string_processor sp2;
	sp2.build_z_function(arr2);

	bool ans = false;
	for (auto i = 0; i < k; i++){
		ans |= (sp1.z[k + 1 + i] >= k and sp2.z[k + 1 + (2 - i + k) % k] >= k);
	}

	if (ans){
		cout << "YES" << "\n";
	}
	else{
		cout << "NO" << "\n";
	}
}
}