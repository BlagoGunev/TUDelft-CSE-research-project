#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define pll pair<ll,ll>
#define mp make_pair
#define sz(x) ((ll)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll floor_div(ll x, ll y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x >= 0) return x / y;
    return (x + 1) / y - 1;
}
ll ceil_div(ll x, ll y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x <= 0) return x / y;
    return (x - 1) / y + 1;
}

struct graph{
    int n,lg,timer;
    vector<int> tin,tout,dep;
    vector<vector<int>> up;
    void dfs(int v, int p, vector<vector<int>>& adj){
        tin[v] = timer++;
        up[v][0] = p;
        dep[v] = (p == v) ? 0 : dep[p]+1;
        for(int jump=1; jump<lg; jump++){
            up[v][jump] = up[up[v][jump-1]][jump-1];
        }
        for(int to : adj[v]){
            if(to == p){
                continue;
            }
            dfs(to,v,adj);
        }
        tout[v] = timer++;
    }
    int get_kth(int v, ll k){
        for(int jump=0; jump<lg; jump++){
            if(k&(1LL<<jump)){
                v = up[v][jump];
            }
        }
        return v;
    }
    int get_lca(int u, int v){
        if(dep[u] > dep[v]){
            swap(u,v);
        }
        v = get_kth(v,dep[v]-dep[u]);
        if(v == u){
            return v;
        }
        for(int jump=lg-1; jump>=0; jump--){
            if(up[u][jump] != up[v][jump]){
                u = up[u][jump];
                v = up[v][jump];
            }
        }
        assert(v != u && up[v][0] == up[u][0]);
        return up[v][0];
    }
    int get_dist(int u, int v){
        return dep[u]+dep[v]-2*dep[get_lca(u,v)];
    }
    graph(int n, int lg, vector<vector<int>>& adj){
        this->n = n;
        this->lg = lg;
        tin.assign(n,-1);
        tout.assign(n,-1);
        dep.assign(n,-1);
        up.assign(n,vector<int> (lg,-1));
        this->timer = 0;
        dfs(0,0,adj);
    }
};

const int inf = 1e9;

struct Point_update{
    int n;
    vector<int> t;
    Point_update(int n_){
        this->n = n_;
        t.assign(4*n,-inf);
    }
    int t_comb(int l, int r){
        return max(l,r);
    }
    void build_tree(vector<int>& a, int v, int tl, int tr){
        if(tl == tr){
            t[v] = a[tl];
        }
        else{
            int tm = (tl+tr)>>1;
            build_tree(a,2*v,tl,tm);
            build_tree(a,2*v+1,tm+1,tr);
            t[v] = t_comb(t[2*v],t[2*v+1]);
        }
    }
    void build(vector<int>& a){
        assert(sz(a) == n);
        build_tree(a,1,0,n-1);
    }
    int query_tree(int v, int tl, int tr, int l, int r){
        if(l > r){
            return -inf;
        }
        if(l == tl && r == tr){
            return t[v];
        }
        int tm = (tl+tr)>>1;
        return t_comb(query_tree(2*v,tl,tm,l,min(r,tm)),query_tree(2*v+1,tm+1,tr,max(l,tm+1),r));
    }
    int query(int l, int r){
        return query_tree(1,0,n-1,l,r);
    }
};

void solve(int tc = 0){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // remember dep is for edges
    vector<int> par(n,-1), dep(n), win_a(n,inf), win_b(n,inf), lev(n); 
    graph G(n,24,adj);
    auto dfs = [&](auto dfs, int v) -> void{
        dep[v] = 0;
        for(int to : adj[v]){
            if(to == par[v])
                continue;
            par[to] = v;
            lev[to] = lev[v] + 1;
            dfs(dfs,to);
            dep[v] = max(dep[v],1 + dep[to]);
        }
    };
    dfs(dfs,0);
    auto solve_path = [&](vector<int> path){
        // remember the path is like 0,1,2....m-1
        // and at the zero place we have 0
        int m = path.size();
        assert(m >= 2);
        // need the sideways subtree vals
        vector<vector<int>> add(m), del(m);
        // bob case
        Point_update segtree(m);
        vector<int> aux(m), vals(m);
        for(int i=0; i<m; i++){
            int val = 0;
            for(int u : adj[path[i]]){
                if(u == par[path[i]] || (i+1 < m && u == path[i+1]))
                    continue;
                val = max(val,1 + dep[u]);
            }
            vals[i] = val;
            aux[i] = i + val;
        }
        // bob win right ? 
        segtree.build(aux);
        for(int i=2; i<m; i++){
            int l = 1;
            int r = i-1;
            while(r-l){
                int mid = (r+l)/2;
                int get = segtree.query(mid,i-1);
                assert(get != -inf);
                get -= mid;
                if(vals[i] > get){
                    r = mid;
                }
                else{
                    l = mid+1;
                }
            }
            int get = segtree.query(l,i-1);
            assert(get != -inf);
            get -= l;
            if(vals[i] > get){
				int tl = max(l-1,1);
				int tr = i-2;
				if(tl <= tr){
					if(i+tl < m){
                    	add[i+tl].pb(i);
                	}		
					if(i+tr+1 < m){
                    	del[i+tr+1].pb(i);
                	}
				}
            }
        }
        assert(add[0].empty());
        set<int> good; 
        for(int i=1; i<m; i++){
            for(int &each : add[i]){
                good.insert(each);
            }
            for(int &each : del[i]){
                good.erase(each);
            }
            // also have to check the zero case
            if(!good.empty()){
                int at = *prev(good.end());
                at = i-at+1;
                win_b[path[i]] = min(win_b[path[i]],2*at+1);
            }
            if(i >= 2){
				int get = segtree.query(1,i-1)-1;
            	if(get < dep[path[i]]){
                	win_b[path[i]] = min(win_b[path[i]],2*1 + 1);
            	}	
			}
        }
        // alice case
        for(int i=0; i<m; i++){
            vector<int>().swap(add[i]);
            vector<int>().swap(del[i]);
        }
        // remember to check the 0 case 
        set<int> ().swap(good);
        for(int i=0; i<m; i++){
            aux[i] = vals[i] + m-1-i;
        }
        segtree.build(aux);
        for(int i=1; i+1<m; i++){
            int l = i+1;
            int r = m-1;
            while(r - l){
                int mid = (r+l)/2;
                int get = segtree.query(i+1,mid+1);
                assert(get != -inf);
                get -= (m-1-(mid+1));
                if(get < vals[i]){
                    l = mid+1;
                }
                else{
                    r = mid;
                }
            }
            int get = segtree.query(i+1,l);
            assert(get != -inf);
            get -= (m-1-l);
            if(get < vals[i]){
                // the range of goodness is i+1 ... l
                int min_l = 2*i + 1;
                if(min_l < m){
                    add[min_l].pb(i);
                }
                if(min_l+l-i < m){
                    del[min_l+l-i].pb(i);
                }
            }
        }
        assert(add[0].empty());
        for(int i=1; i<m; i++){
            for(int &each : add[i]){
                good.insert(each);
            }
            for(int &each : del[i]){
                good.erase(each);
            }
            if(!good.empty()){
                int at = *good.begin() + 1;
                win_a[path[i]] = min(win_a[path[i]],2*at);
            }
            int get = segtree.query(1,i);
            get -= (m-1-i);
            get = max(get,dep[path[i]]);
            if(vals[0] > get){
                win_a[path[i]] = min(win_a[path[i]],2);
            }
        }
    };
    int u,v;
    cin >> u >> v;
    u--;v--;
    auto get_path = [&](int from, int to){
        int cur = from;
        vector<int> path;
        while(cur != to){
            path.pb(cur);
            cur = par[cur];
        }
        path.pb(to);
        return path;
    };
    auto get_complete_path = [&](int u, int v){
        int l = G.get_lca(u,v);
        vector<int> path1, path2;
        path1 = get_path(u,l);
        path2 = get_path(v,l);
        for(int i=int(path2.size())-2; i>=0; i--){
            path1.pb(path2[i]);
        }
        return path1; 
    };
    vector<int> path;
    path = get_path(u,0);
    reverse(path.begin(), path.end());
    solve_path(path);
    path = get_path(v,0);
    reverse(path.begin(), path.end());
    solve_path(path);
    path = get_complete_path(u,v);
    for(int v : path){
		if(win_a[v] != win_b[v]){
            cout << (win_a[v] < win_b[v] ? "Alice" : "Bob") << "\n";
        }
        else{
            assert(win_a[v] == inf);
            int mod2 = (lev[v]+1)%2;
            cout << (mod2 ? "Alice" : "Bob") << "\n";
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    int t;
    cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
}