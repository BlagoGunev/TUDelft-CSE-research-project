#ifndef _GLIBCXX_NO_ASSERT

#include <cassert>

#endif

#include <cctype>

#include <cerrno>

#include <cfloat>

#include <ciso646>

#include <climits>

#include <clocale>

#include <cmath>

#include <csetjmp>

#include <csignal>

#include <cstdarg>

#include <cstddef>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <ctime>

 

#if __cplusplus >= 201103L

#include <ccomplex>

#include <cfenv>

#include <cinttypes>

//#include <cstdalign>

#include <cstdbool>

#include <cstdint>

#include <ctgmath>

#include <cwchar>

#include <cwctype>

#endif

 

// C++

#include <algorithm>

#include <bitset>

#include <complex>

#include <deque>

#include <exception>

#include <fstream>

#include <functional>

#include <iomanip>

#include <ios>

#include <iosfwd>

#include <iostream>

#include <istream>

#include <iterator>

#include <limits>

#include <list>

#include <locale>

#include <map>

#include <memory>

#include <new>

#include <numeric>

#include <ostream>

#include <queue>

#include <set>

#include <sstream>

#include <stack>

#include <stdexcept>

#include <streambuf>

#include <string>

#include <typeinfo>

#include <utility>

#include <valarray>

#include <vector>

 

#if __cplusplus >= 201103L

#include <array>

#include <atomic>

#include <chrono>

#include <condition_variable>

#include <forward_list>

#include <future>

#include <initializer_list>

#include <mutex>

#include <random>

#include <ratio>

#include <regex>

#include <scoped_allocator>

#include <system_error>

#include <thread>

#include <tuple>

#include <typeindex>

#include <type_traits>

#include <unordered_map>

#include <unordered_set>

#endif

using namespace std;

using i64 = long long;

using i128 = __int128;

#define MAXN 200005

#define MAXM 200005

#define M 1000000

#define K 17

#define MAXP 25

#define MAXK 55

#define MAXC 255

#define MAXERR 105

#define MAXLEN 105

#define MDIR 10

#define MAXR 705

#define BASE 102240

#define MAXA 28

#define MAXT 100005

#define LIMIT 86400

#define MAXV 305

#define LEQ 1

#define EQ 0

#define OP 0

#define CLO 1

#define DIG 1

#define C1 0

#define C2 1

#define PLUS 0

#define MINUS 1

#define MUL 2

#define CLO 1

#define VERT 1

//#define B 31

#define B2 1007

#define W 1

#define H 19

#define SPEC 1

#define MUL 2

#define CNT 3

#define ITER 1000

#define INF 1e9

#define EPS 1e9

#define MOD 1000000007

#define CONST 1000000007

#define FACT 100000000000000

#define PI 3.14159265358979

#define SRC 0

#define pb push_back

#define eb emplace_back

typedef long long ll;

typedef __int128_t lint;

typedef long double ld;

typedef pair<int,int> ii;

typedef pair<double,int> ip;

typedef pair<ll,ii> pl;

typedef pair<ll,ll> pll;

typedef pair<ll,int> li;

typedef pair<ll,ll> iv;

typedef tuple<ll,int,int> iii;

typedef vector<vector<int>> vv;

typedef vector<int> vi;

typedef vector<ll> vl;

//typedef pair<ld,int> iv;

typedef vector<ii> vii;

typedef vector<vector<ll>> vll;

typedef complex<ld> cd;

#define sc second

#define fr first

#define rep(i,x,y) for (int i = (x); i < (y); ++i)

#define rev(i,x,y) for (int i = (x); i >= (y); --i)

#define LSOne(S) (S & (-S))

#define trav(i,v) for (auto &i : v)

#define foreach(it,v) for (auto it = begin(v); it != end(v); ++it)

#define bend(v) (v).begin(), (v).end()

#define rbend(v) (v).rbegin(), (v).rend()

#define sortarr(v) sort(bend(v))

#define rsortarr(v) sort(rbend(v))

#define unique(v) v.erase(unique(bend(v)), end(v))

#define combine(A,B) A.insert(end(A), bend(B))

#define fill(V) iota(bend(V), (0))

#define vfill(V, st) iota(bend(V), st)

template<class T> bool ckmin(T &a, T &b) {return a > b ? a = b, 1 : 0; };

template<class T> bool ckmax(T &a, T &b) {return a < b ? a = b, 1 : 0; };

template<class T> int compress(vector<T> &v, T &val) { return (int)(lower_bound(bend(v), val) - begin(v)); };



template <class T = int>

struct dinic {

    struct edge{

        int v;

        T cap, flow;

        edge(int v, T cap, T flow) : v(v), cap(cap), flow(flow) {}

    };

    vector<edge> EL;

    //keep track of previous edge flow before the current

    //iteration

    vector<vector<int>> adj;

    vector<int> d,last;

    //n is the number of nodes

    //s is the source and t is the sink

    int n,s,t;

    T inf;

    

    //constructor

    dinic(int num) {

        n = num; s = n - 2, t = n - 1;

        adj.resize(n);

        inf = numeric_limits<T>::max();

    }



    bool bfs() {

        d.assign(n,-1); d[s] = 0;

        queue<int> q; q.push(s);

        while (!q.empty()) {

            int u = q.front(); q.pop();

            if (u == t) return true;

            for (auto idx: adj[u]) {

                edge &e = EL[idx];

                if (d[e.v] == -1 && e.cap - e.flow > 0) {

                    d[e.v] = d[u] + 1;

                    q.push(e.v);

                }

            }

        }

        return false;

    }

     

    T dfs(int u, T flow) {

        if (u == t) return flow;

        for (int &i = last[u]; i < adj[u].size(); i++) {

            edge &e = EL[adj[u][i]], &res = EL[adj[u][i]^1];

            T remcap = e.cap - e.flow;

            if (remcap && d[e.v] == d[u] + 1) {

                T fl = dfs(e.v, min(flow, remcap));

                if (fl) {

                    e.flow += fl; res.flow -= fl;

                    return fl;

                }

            }

        }

        return 0;

    }

     

    void addedge(int u, int v,T cap) {

        adj[u].push_back((int)(EL.size()));

        EL.push_back(edge(v,cap,0));

        adj[v].push_back((int)(EL.size()));

        EL.push_back(edge(u,0,0));

    }



    bool got_flow(int u, int v) {

        for (int &idx : adj[u]) {

            edge &e = EL[idx];

            if (e.v == v) return e.flow > 0;

        }

        return false;

    }



    T amt_flow(int u, int v) {

        for (int &idx : adj[u]) {

            edge &e = EL[idx];

            if (e.v == v) return e.flow;

        }

        return 0;

    }



    bool is_full(int u, int v) {

         for (int &idx : adj[u]) {

               edge &e = EL[idx];

             if (e.v == v) return e.flow == e.cap;

         }

        return false;

    }



    T run() {

        T res = 0;

        while (bfs()) {

            last.assign(n, 0);

            while (T flow = dfs(s, inf)) res += flow;

        }

        return res;

    }



    vector<bool> getmincut() {

        queue<int> q;

        q.push(s);

        vector<bool> vis(n, false);

        vis[s] = true;

        while (!q.empty()) {

            int u = q.front();

            q.pop();

            for (auto idx: adj[u]) {

                edge &e = EL[idx];

                if (!vis[e.v] && e.cap - e.flow > 0) {

                    vis[e.v] = true;

                    q.push(e.v);

                }

            }

        }

        return vis;

    }

};



int n;

vector<int> val,a,ans;

//divide and conquer here

//apply dilworth: max antichain is equal to minimal chain decomposition

//find minimal chain decomposition using max flow then find all edges in antichain

//antichain edges agree with the invariant that first vertex value is smaller than or equal to second vertex value (edge from first vertex -> second vertex)

void solve(int l, int r, vector<ii> E, vector<int> V) {

    if (l > r || V.empty()) return;

    if (l == r) {

        trav(i, V) ans[i] = val[l];

        return;

    }

    dinic<int> mf((int)(V.size()) + 2);

    int s = (int)(V.size()), t = (int)(V.size()) + 1;

    int mid = (l + r) >> 1;

    rep(i,0,V.size()) {

        int coef = (a[V[i]] <= mid) ? 1 : -1;

        //attach vertices smaller than or equal to mid to the sink and vertices larger to the source

        if (coef < 0) mf.addedge(s, i, -coef);

        else mf.addedge(i, t, coef);

    }

    trav(i,E) {

        int u = compress(V, i.fr);

        int v = compress(V, i.sc);

        mf.addedge(u, v, INF);

    }

    mf.run();

    vector<bool> vis = mf.getmincut();

    vector<int> VL, VR;

    vector<ii> EL, ER;

    rep(i,0,V.size()) {

        if (vis[i]) VR.eb(V[i]);

        else VL.eb(V[i]);

    }

    

    trav(i,E) {

        int u = compress(V, i.fr);

        int v = compress(V, i.sc);

        if (vis[u] && vis[v]) ER.eb(i);

        else if (!vis[u] && !vis[v]) EL.eb(i);

    }

    solve(l, mid, EL, VL), solve(mid + 1, r, ER, VR);

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(NULL); cout.tie(NULL);

    int m; cin >> n >> m;

    a.resize(n);

    ans.resize(n);

    vector<ii> E;

    rep(i,0,n) {

        cin >> a[i];

        val.pb(a[i]);

    }

    rep(i,0,m) {

        int u,v; cin >> u >> v;

        u--, v--;

        E.eb(u,v);

    }

    sortarr(val);

    unique(val);

    rep(i,0,n) {

        //cooredinate compress all values

        a[i] = compress(val, a[i]);

    }

    vector<int> V(n);

    fill(V);

    solve(0, (int)(val.size()) - 1, E, V);

    rep(i,0,n) cout << ans[i] << ' ';

}