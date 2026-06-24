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

#define MAXN 5005

#define MAXM 5005

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

#define FACT 100000000000000

#define PI 3.14159265358979

#define SRC 0

typedef long long ll;

typedef ll hash_t;

typedef __int128_t lint;

typedef long double ld;

typedef pair<int,int> ii;

typedef pair<double,int> ip;

typedef pair<ll,ii> pl;

typedef pair<int,ll> pll;

typedef pair<ll,int> li;

typedef pair<ll,ll> iv;

typedef tuple<int,int,int> iii;

typedef tuple<ll,ll,int> tll;

typedef vector<vector<int>> vv;

typedef vector<int> vi;

typedef vector<ll> vl;

typedef vector<ii> vii;

typedef vector<vector<ll>> vll;

typedef complex<ld> cd;

#define pb push_back

#define eb emplace_back

#define ins insert

#define er erase

#define sc second

#define fr first

#define repl(i,x,y) for (int i = (x); i <= (y); ++i)

#define rep(i,x,y) for (int i = (x); i < (y); ++i)

#define rev(i,x,y) for (int i = (x); i >= (y); --i)

#define LSOne(S) (S & (-S))

#define trav(i,v) for (auto &i : v)

#define foreach(it,v) for (auto it = begin(v); it != end(v); ++it)

#define bend(v) (v).begin(), (v).end()

#define rbend(v) (v).rbegin(), (v).rend()

#define sortarr(v) sort(bend(v))

#define rsortarr(v) sort(rbend(v))

#define sz(v) (int)((v).size())

#define unique(v) v.erase(unique(v.begin(), v.end()), v.end())

#define combine(A,B) A.insert(end(A), bend(B))

template<class T> bool ckmin(T &a, T &b) { return a > b ? a = b, 1 : 0; };

template<class T> bool ckmax(T &a, T &b) { return a < b ? a = b, 1 : 0; };

template<class T> void amax(T &a, T b, T c) { a = max(b, c); };

template<class T> void amin(T &a, T b, T c) { a = min(b, c); };

template<class T> T getmax(vector<T> &v) { return *max_element(bend(v)); };

template<class T> T getmin(vector<T> &v) { return *min_element(bend(v)); };

template<class T> int compress(vector<T> &v, T &val) { return (int)(lower_bound(bend(v), val) - begin(v)); };

template<class T> auto vfind(vector<T> &v, T val) {

    return find(bend(v), val);

}

template<class T> auto verase(vector<T> &v, T val) {

    return v.er(vfind(v, val));

}



int n,m;

//candidate stores all possible cows with favourite jelly i

vv cand, occ;

int pos[MAXN];

//idea is to find an invariant(in this case rightmost point of the left queue and fix it)

//now we want to count the number of cows in the left and right queue respectively

//for all cows that likes the same jelly, 2 cows of the same type cannot both appear on the left of right queue but separately

//calculate the number of ways to add the pair of cows to the left and right queue independently

//only need to choose a subset so ordering of the cows do not matter

int main() {

    cin >> n >> m;

    vector<int> a(n);

    cand.resize(n), occ.resize(n);

    rep(i,0,n) {

        int x; cin >> x;

        x--;

        a[i] = x;

        occ[x].pb(i);

    }

    rep(i,0,m) {

        int  f,h; cin >> f >> h;

        f--;

        if (h <= sz(occ[f])) cand[f].pb(h), pos[occ[f][h - 1]] = true;

    }

    pll ans = {0, 1};

    //consider the case where we leave the right queue empty

    rep(i,0,n) {

        if (sz(cand[i]) > 0) ans.fr++, ans.sc = (1LL * ans.sc * sz(cand[i])) % MOD;

    }

    

    //fix the valid starting positions

    rep(i,0,n) {

        if (pos[i]) {

            pll tmp = {1, 1};

            //calculate all possible ending points for cows that like the same candy

            int canrgt = 0;

            trav(j, cand[a[i]]) {

                if (occ[a[i]][sz(occ[a[i]]) - j] > i) {

                    if (occ[a[i]][j - 1] != i) canrgt++;

                }

            }

            

            if (canrgt) tmp.fr++, tmp.sc = (tmp.sc * canrgt) % MOD;

            

            rep(j,0,n) {

                if (a[i] == j) continue;

                int cntlft = 0, cntrgt = 0, cntdup = 0;

                trav(k, cand[j]) {

                    if (occ[j][k - 1] < i) cntlft++;

                    if (occ[j][sz(occ[j]) - k] > i) cntrgt++;

                    if (occ[j][k - 1] < i && occ[j][sz(occ[j]) - k] > i) cntdup++;

                }

                int c2 = cntlft * cntrgt - cntdup;

                int c1 = cntlft + cntrgt;

                if (c2) {

                    //add this pair of cows to the left and right queues respectively

                    tmp.fr += 2;

                    tmp.sc = (tmp.sc * c2) % MOD;

                } else if (c1) {

                    tmp.fr++;

                    tmp.sc = (tmp.sc * c1) % MOD;

                }

            }

            if (tmp.fr > ans.fr) {

                ans = tmp;

            } else if (tmp.fr == ans.fr) ans.sc = (ans.sc + tmp.sc) % MOD;

        }

    }

    cout << ans.fr << ' ' << ans.sc;

}