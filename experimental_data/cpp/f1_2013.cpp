#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<pdd> vpdd;
typedef vector<vd> vvd;
#define yn(ans) printf("%s\n", (ans)?"Yes":"No");
#define YN(ans) printf("%s\n", (ans)?"YES":"NO");
    template<class T> bool chmax(T &a, T b) {
	if (a >= b) return false;
	a = b; return true;
}
template<class T> bool chmin(T &a, T b) {
	if (a <= b) return false;
	a = b; return true;
}
#define FOR(i, s, e, t) for ((i) = (s); (i) < (e); (i) += (t)) 
#define REP(i, e) for (int i = 0; i < (e); ++i) 
#define REP1(i, s, e) for (int i = (s); i < (e); ++i)
#define RREP(i, e) for (int i = (e); i >= 0; --i)
#define RREP1(i, e, s) for (int i = (e); i >= (s); --i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define qb pop_back
#define pf push_front
#define qf pop_front
#define maxe max_element
#define mine min_element
ll inf = 1e18;
#define DEBUG printf("%d\n", __LINE__); fflush(stdout);
template<class T> void print(vector<T> &v, bool withSize = false) {
	if (withSize) cout << v.size() << endl;
	REP(i, v.size()) cout << v[i] << " "; 
	cout << endl;
}
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int __FAST_IO__ = []() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	return 0;
}();

class LCA {
public:
    LCA(vector<vector<int>> &_g): N(_g.size()), depth(N, 0), sz(N, 1), g(_g), dp(N, vi(20, -1)) {
        dfs(0, -1);
    }
    
    void dfs(int cur, int par) {
        if (par != -1) {
    	    depth[cur] = depth[par] + 1;
    	    dp[cur][0] = par;
    	    int x = par;
    	    REP1(i, 1, 20) {
    	        dp[cur][i] = dp[x][i - 1];
    	        x = dp[x][i - 1];
    	        if (x == -1) break;
    	    }
    	}
    	for (auto son: g[cur]) {
    	    if (son == par) continue;
    	    dfs(son, cur);
	    sz[cur] += sz[son];
    	}
    }
    
    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
    	int diff = depth[u] - depth[v];
        REP(i, 20) {
            if (diff >> i & 1) u = dp[u][i];
        }
        RREP(i, 19) {
            if (dp[u][i] != dp[v][i]) {
                u = dp[u][i];
                v = dp[v][i];
            }
        }
	if (u != v) u = dp[u][0];
        return u;
    }
    
    int dis(int u, int v) {
    	int par = lca(u, v);
    	return depth[u] + depth[v] - 2 * depth[par];
    }

    int dep(int u) {return depth[u];}
    int size(int u) {return sz[u];}

    int parent(int u, int d) {
        REP(i, 20) {
            if (d >> i & 1) u = dp[u][i];
        }
        return u;
    }

    bool isParent(int u, int v) {
        if (dep(u) > dep(v)) return false;
        int d = dis(u, v);
        return dep(v) >= d && parent(v, d) == u;
    }

    bool inPath(int s, int t, int k) {
    	int p = lca(s, t);
    	return (isParent(p, k) && (isParent(k, s) || isParent(k, t)));
    }


    int N;
    vi depth, sz;
    vvi &g, dp; 
};

template<typename T, T (*S)(T, T)> struct SparseTable {
	SparseTable(vector<T> &v) {
		N = v.size();
		lg.resize(N + 1, 0);
		REP1(i, 2, N + 1) lg[i] = lg[i >> 1] + 1;
		f.resize(N, vector<T>(lg[N] + 1));
		REP(i, N) f[i][0] = v[i];
		for (int i = 1; i <= lg[N]; ++i) {
			for (int j = 0; j + (1 << i) <= N; ++j) {
				f[j][i] = S(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
			}
		}
	}
	
	T query(int L, int R) {
		int len = R - L + 1, s = lg[len];
		return S(f[L][s], f[R - (1 << s) + 1][s]);
	}
	vector<vector<T>> f;
	vi lg;
	int N;
};

int op(int a, int b) {
    return max(a, b);
}

#define TESTS int t; cin >> t; while (t--)
#define TEST 
int main() {
    TESTS {
    	int N;
    	cin >> N;
    	vvi g(N);
    	REP(i, N - 1) {
    	    int u, v;
    	    cin >> u >> v;
    	    --u, --v;
    	    g[u].pb(v);
    	    g[v].pb(u);
    	}
    	
    	LCA lca(g);
    	
    	int U, V;
    	cin >> U >> V;
    	--U, --V;
    	
    	vi mxdep(N, 0);
    	function<void(int, int)> dfs = [&](int u, int p) {
    	    for (auto v: g[u]) {
    	        if (v == p) continue;
    	        dfs(v, u);
    	        chmax(mxdep[u], mxdep[v] + 1);
    	    }  
    	};
    	dfs(0, -1);
    	
    	int d = lca.dep(U);
    	
    	vi mx0(d, 0), mx1(d + 1, 0);
    	
    	REP(i, d) {
    	    int p0 = lca.parent(U, d - i);
    	    mx0[i] = i;
    	    for (auto v: g[p0]) {
    	        if (!lca.isParent(v, U)) {
    	            chmax(mx0[i], mxdep[v] + i + 1);
    	        }
    	    }
    	}
    	
    	RREP1(i, d, 1) {
    	    int p1 = lca.parent(U, d - i);
    	    mx1[i] = d - i;
    	    for (auto v: g[p1]) {
    	        if (!lca.isParent(v, U)) chmax(mx1[i], mxdep[v] + d - i + 1);
    	    }
    	}
    	
    	SparseTable<int, op> st0(mx0), st1(mx1);
    	
    //	print(mxdep), print(mx0), print(mx1);
    	bool ans = false;
    	int l = 0, r = d;
    	while (1) {
    	    if (mx0[l] > st1.query(l + 1, r)) {
    	        ans = true;
    	        break;
    	    } else if (l + 1 == r) break;
    	    else ++l;
    	    
    	    if (mx1[r] >= st0.query(l, r - 1)) {
    	        break;
    	    } else if (l + 1 == r) {
    	        ans = true;
    	        break;
    	    } else --r;
    	}
    	
    	printf("%s\n", ans ? "Alice" : "Bob");
    }
    
    return 0;
}