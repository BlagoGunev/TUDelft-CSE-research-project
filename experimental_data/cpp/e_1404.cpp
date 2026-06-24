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

#define MAXN 40005

#define MAXM 40005

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

#define MOD 998244353

#define CONST 998244353

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

typedef pair<int,ll> li;

typedef pair<ll,ll> iv;

typedef tuple<int,int,int> iii;

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

#define sortarr(v) sort(begin(v), end(v))



struct hopcroftKarp {

    //***IMPORTANT***

    //BE CAREFUL THIS TEMPLATE USES 1-BASED INDEXING

    int n, m; //take note that this algorithm is 1 index based

    vector<int> pairU, pairV, d;

    vv c; // this is the adjacency list

    

    hopcroftKarp(int n, int m) : n(n), m(m) {

        c.resize(n + 5);

        pairU.resize(n + 5);

        pairV.resize(m + 5);

        d.resize(n + 5);

    }

    

    void addedge(int u, int v) {

        c[u].pb(v);

    }

    

    bool bfs() {

        queue<int> q;

        for (int i = 1; i <= n; i++) {

            if (pairU[i] == 0) {

                d[i] = 0;

                q.push(i);

            } else d[i] = INF;

        }

        d[0] = INF;

        while (!q.empty()) {

            int u = q.front();

            q.pop();

            if (d[u] < d[0]) {

                for (int &i : c[u]) {

                    if (d[pairV[i]] == INF) {

                        d[pairV[i]] = d[u] + 1;

                        q.push(pairV[i]);

                    }

                }

            }

        }

        return d[0] != INF;

    }



    bool dfs(int u) {

        if (u != 0) {

            for (int &i : c[u]) {

                if (d[pairV[i]] == d[u] + 1) {

                    if (dfs(pairV[i])) {

                        pairV[i] = u;

                        pairU[u] = i;

                        return true;

                    }

                }

            }

            d[u] = INF;

            return false;

        }

        return true;

    }

    

    //call this function to return the maximal matching in the graph

    int match() {

        for (int i = 1; i <= n; i++) pairU[i] = 0;

        for (int i = 1; i <= m; i++) pairV[i] = 0;

        int total = 0;

        while (bfs()) {

            for (int i = 1; i <= n; i++) {

                if (pairU[i] == 0 && dfs(i)) total++;

            }

        }

        return total;

    }

};



int r,c;

char a[205][205];

int hsh(int i, int j) {

    return c * i + j + 1;

}



int hsh2(int i, int j) {

    return (c + 1) * i + j + 1;

}



//idea is add edges between vertical and horizontal borders that form L-shapes

//find the maxmimum independent set of this graph which is equal to total borders - min vertex cover, since graph is bipartite, min vertex cover is equal to maximum matching

//total number of black square - max indepdent set is the answer

//similar to removing all conflicts and finding the maximal set with no conflicts which represents all borders that can be added wth no conflicts

//take the total number of black squares - the total number of borders that can be added with no conflcits to get the final answer

int main() {

    ios::sync_with_stdio(false);

    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;

    rep(i,1,r+1) {

        rep(j,1,c+1) {

            cin >> a[i][j];

        }

    }

    hopcroftKarp hkarp(2 * r * c, 2 * r * c);

    int totblack = 0, sub = 0;

    rep(i,1,r+1) {

        rep(j,1,c+1) {

            if (a[i][j] != '#') continue;

            totblack++;

            //has a black square downward

            //valid border here

            if (i + 1 <= r && a[i + 1][j] == '#') sub++;

            //has a black square rightward

            //valid border here

            if (j + 1 <= c && a[i][j + 1] == '#') sub++;

            vector<int> sources;

            

            if (i + 1 <= r && a[i + 1][j] == '#') {

                int src = hsh(i, j - 1); //lower row

                sources.pb(src);

            }

            

            if (i - 1 > 0 && a[i - 1][j] == '#') {

                int src = hsh(i - 1, j - 1); //upper row

                sources.pb(src);

            }

            

            trav(src, sources) {

                if (j - 1 > 0 && a[i][j - 1] == '#') {

                    int dst = hsh2(i - 1, j - 1); //left border

                    hkarp.addedge(src, dst);

                }

                

                if (j + 1 <= c && a[i][j + 1] == '#') {

                    int dst = hsh2(i - 1, j); //right border

                    hkarp.addedge(src, dst);

                }

            }

        }

    }

    //find the maximum matching = min vertex cover by konig

    int ans = hkarp.match();

    cout << totblack - (sub - ans);

}