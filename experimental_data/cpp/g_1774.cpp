#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL

string to_string(string s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string(string(s)); }

string to_string(bool b) { return to_string(int(b)); }

string to_string(vector<bool>::reference b) { return to_string(int(b)); }

string to_string(char b) { return "'" + string(1, b) + "'"; }

template <typename A, typename B>

string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template <typename A, typename B, typename C>

string to_string(tuple<A, B, C> p) {

	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";

}

template <typename A, typename T = typename A::value_type>

string to_string(A v) {

	string res = "{";

	for (const auto& x : v) res += (res == "{" ? "" : ", ") + to_string(x);

	return res + "}";

}

void debug() { cerr << endl; }

template <typename Head, typename... Tail>

void debug(Head H, Tail... T) {

	cerr << " " << to_string(H);

	debug(T...);

}

#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)

#else

#define db(...) 42

#endif

using ll = long long;

using ld = long double;

namespace tree {

struct Edge {

//	int cost;

//	int id;

};

int n;

vector<Edge> edges;

vector<vector<pair<int, int>>> adj; // (vertexId, edgeId)

void makeTree(int _n) {

	n = _n;

	adj = vector<vector<pair<int, int>>>(n);

	edges.clear();

}

template <typename... T>

int addEdge(int from, int to, const T&... e) {

	int id = edges.size();

	adj[from].emplace_back(to, id);

	adj[to].emplace_back(from, id);

	edges.push_back({e...});

	return id;

}

vector<int> depth, pv, pe, pre, endpre, preseq, siz;

int logn;

vector<vector<int>> anc;

struct Jump {

	int sum = 0; // Initialize to 0-edge jumps.

	void init(int v) {

		// Initialize to 1-edge jumps.

		Edge& e = edges[pe[v]];

		sum = 1;

	}

	friend Jump combine(const Jump& x, const Jump& a) { // a is ancestor of x

		Jump ret;

		ret.sum = x.sum + a.sum;

		return ret;

	}

};

vector<vector<Jump>> jump;

void dfs(int x, int p = -1) {

	siz[x] = 1;

	pre[x] = preseq.size();

	preseq.push_back(x);

	// Warning: adj order is not the initial order for HLD.

	for (auto& e : adj[x]) {

		int y = e.first, eid = e.second;

		if (y == p) continue;

		depth[y] = depth[x] + 1;

		pv[y] = x;

		pe[y] = eid;

		dfs(y, x);

		siz[x] += siz[y];

	}

	endpre[x] = preseq.size() - 1; // This is the last vertex in the subtree of x

}

void init(int root = 0) {

	siz = vector<int>(n);

	depth = vector<int>(n);

	pv = vector<int>(n, -1);

	pe = vector<int>(n, -1);

	pre = vector<int>(n, -1);

	endpre = vector<int>(n, -1);

	preseq.clear();

	preseq.reserve(n);

	dfs(root);

	logn = 31 - __builtin_clz(n);

	anc = vector<vector<int>>(n, vector<int>(logn + 1));

	for (int i = 0; i < n; ++i) anc[i][0] = pv[i];

	for (int p = 1; p <= logn; ++p)

		for (int i = 0; i < n; ++i)

			anc[i][p] = anc[i][p - 1] == -1 ? -1 : anc[anc[i][p - 1]][p - 1];

//	jump = vector<vector<Jump>>(n, vector<Jump>(logn + 1));

//	for (int i = 0; i < n; ++i)

//		if (anc[i][0] != -1) jump[i][0].init(i);

//	for (int p = 1; p <= logn; ++p)

//		for (int i = 0; i < n; ++i)

//			if (anc[i][p] != -1)

//				jump[i][p].combine(jump[i][p - 1], jump[anc[i][p - 1]][p - 1]);

}

inline bool isAnc(int a, int b) {

	return pre[a] <= pre[b] && endpre[a] >= endpre[b];

}

/* Gets ancestor of a [up] edges upwards. */

inline int getAnc(int a, int up) {

	assert(0 <= up && up <= depth[a]);

	for (int p = logn; p >= 0; --p)

		if (up & (1 << p)) a = anc[a][p];

	return a;

}

inline int getChildTowards(int a, int sub) {

	int dh = depth[sub] - depth[a] - 1;

	return getAnc(sub, dh);

}

/* a == b ok. For O(1) min-style computation, see bottom. */

int getLca(int a, int b) {

	if (isAnc(a, b)) return a;

	if (isAnc(b, a)) return b;

	for (int p = logn; p >= 0; --p)

		if (anc[a][p] != -1 && !isAnc(anc[a][p], b))

			a = anc[a][p];

	a = anc[a][0];

	return a;

}

int getDist(int a, int b) {

	int c = getLca(a, b);

	return depth[a] + depth[b] - 2 * depth[c];

}

/* Jump up from a to ancestor, running f on each 2^k-block in order. */

void jumpUp(int a, int ancestor, function<void(const Jump&)> f) {

	assert(isAnc(ancestor, a));

	int up = depth[a] - depth[ancestor];

	for (int p = logn; p >= 0; --p)

		if (up & (1 << p)) {

			f(jump[a][p]);

			a = anc[a][p];

		}

}

/* Makes max subtree the first child (except leafs). */

void reorderHld(int x, int p = -1) {

	siz[x] = 1;

	for (auto& e : adj[x]) {

		int y = e.first;

		if (y == p) continue;

		reorderHld(y, x);

		siz[x] += siz[y];

		if (adj[x][0].first == p || siz[y] > siz[adj[x][0].first]) swap(e, adj[x][0]);

	}

}

// chainRoots are either the tree root, or have a light parent edge (siz[x]*2 < siz[pv[x]]).

// So number of chainRoots on any path v..root is O(log n).

// And over whole tree, sum_{x is chainRoot} siz[x] = O(n log n).

vector<int> chainRoot;

void setHldChains(int x, int hldRoot, int p = -1) {

	chainRoot[x] = hldRoot;

	for (auto& e : adj[x]) {

		int y = e.first;

		if (y == p) continue;

		setHldChains(y, y == adj[x][0].first ? hldRoot : y, x);

	}

}

/* Move upwards from x to y (ancestor)

A segment consists of *vertices* on a heavy path. For edges we may want to exclude y.

pre[vertex_top] <= pre[vertex_bot].

Apply f(vertex_top, vertex_bot) on some prefix of the chain. */

void moveUp(int x, int y, function<void(int, int)> f) {

	for (;;) {

		int z = chainRoot[x];

		bool isLastChain = z == chainRoot[y];

		f(isLastChain ? y : z, x);

		if (isLastChain) break;

		x = pv[z];

	}

}

/* Returns O(log n) {vertex_top, vertex_bot} pairs. */

vector<array<int, 2>> getHldChains(int x, int y) {

	vector<array<int, 2>> ret;

	moveUp(x, y, [&](int top, int bot) { ret.push_back({top, bot}); });

	return ret;

}

void initHld(int root = 0) {

	siz = vector<int>(n);

	chainRoot = vector<int>(n);

	reorderHld(root); // If x != leaf, make adj[x][0] the largest subtree

	setHldChains(root, root);

	init(root); // Now pre and endpre is on the hld sequence

}

/* Returns all HLD chains in tree, {vertex_top, vertex_bot} pairs. */

vector<array<int, 2>> getAllHldChains() {

	vector<int> chainBottom(n, -1);

	for (int i = 0; i < n; ++i)

		if (chainBottom[chainRoot[i]] == -1 || depth[chainBottom[chainRoot[i]]] < depth[i])

			chainBottom[chainRoot[i]] = i;

	vector<array<int, 2>> chains;

	for (int i = 0; i < n; ++i) {

		if (chainRoot[i] != i) continue;

		chains.push_back({i, chainBottom[i]});

	}

	return chains;

}

}; // namespace tree

using namespace tree;

const int MOD = 998244353;

int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(nullptr);

	int m, q;

	cin >> m >> q;

	vector<array<int, 2>> ranges(m);

	for (int i = 0; i < m; ++i) {

		int x, y;

		cin >> x >> y;

		ranges[i] = {y, -x};

	}

	vector<array<int, 2>> R;

	sort(ranges.begin(), ranges.end());

	for (auto& r : ranges) {

		if (!R.empty() && -r[1] <= R.back()[0]) {

			continue;

		}

		R.push_back({-r[1], r[0]});

	}

	db(R);

	int n = R.size();

	makeTree(n + 1);

	for (int i = 0; i < n; ++i) {

		int p = upper_bound(R.begin(), R.end(), array<int, 2>{R[i][1] + 1, -1}) - R.begin();

		addEdge(i, p);

	}

	init(n);

	R.push_back({(int)1e9 + 1, (int)1e9 + 1});

	while (q--) {

		int l, r;

		cin >> l >> r;

		auto solve = [&]() {

			int a = lower_bound(R.begin(), R.end(), array<int, 2>{l, -1}) - R.begin();

			if (R[a][0] != l) return 0;

			if (R[a][1] > r) return 0;

			if (R[a][1] == r) return MOD - 1;

			if (a == n - 1) return 0;

			// Find last ancestor that has R[i][1] <= r.

			int cnt = 2, lastA = a;

			for (int p = logn; p >= 0; --p)

				if (anc[lastA][p] != -1 && R[anc[lastA][p]][1] <= r) {

					cnt += 1 << p;

					lastA = anc[lastA][p];

				}

			int b = a + 1;

			if (R[b][1] > r) return 0;

			int lastB = b;

			for (int p = logn; p >= 0; --p)

				if (anc[lastB][p] != -1 && R[anc[lastB][p]][1] <= r) {

					cnt += 1 << p;

					lastB = anc[lastB][p];

				}

			if (R[lastB][1] != r && R[lastA][1] != r) return 0;

			int c = getLca(a, b);

			if (isAnc(lastA, c) || isAnc(lastB, c)) return 0;

			return (cnt & 1) ? MOD - 1 : 1;

		};

		cout << solve() << '\n';

	}

}