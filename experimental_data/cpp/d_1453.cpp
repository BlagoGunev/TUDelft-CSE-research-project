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

#define MAXN 1005

#define MAXM 1005

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

typedef pair<int,ll> li;

typedef pair<ll,ll> iv;

typedef tuple<ll,ll,ll> iii;

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

#define unique(v) v.erase(unique(v.begin(), v.end()), v.end())

template<class T> bool ckmin(T &a, T &b) {return a > b ? a = b, 1 : 0; };

template<class T> bool ckmax(T &a, T &b) {return a < b ? a = b, 1 : 0; };



const int MAX = 2000;

const int CUT = 64;

//expected value e1 - ek+1 = 2^(k + 1) - 2

int main() {

    int t; cin >> t;

    while (t--) {

        ll k; cin >> k;

        bool found = false;

        rep(i,1,MAX+1) {

            if ((k + 2LL * i) % 2 != 0) continue;

            ll tgt = (k + 2LL * i) / 2;

            if (tgt % 2 != 0) continue;

            vector<int> temp;

            int tot = 0, cnt = 0;

            rep(j,0,CUT) {

                if (tgt & (1LL << j)) {

                    tot += j;

                    cnt++;

                    temp.pb(j);

                }

            }

            

            //exactly i checkpoints are used in the solution

            if (cnt <= i) {

                //cout << i << ' ' << tgt << ' ' << tot << '\n';

                //construct the answer and greedily split the binary representation starting from the lowest power of 2

                priority_queue<int, vector<int>, greater<int>> pq;

                trav(j,temp) pq.push(j);

                vector<int> fin;

                while (!pq.empty() && cnt < i) {

                    int u = pq.top();

                    pq.pop();

                    if (u == 1) {

                        fin.pb(u);

                    } else {

                        pq.push(u - 1), pq.push(u - 1);

                    }

                    cnt++;

                }

                while (!pq.empty()) fin.pb(pq.top()), pq.pop();

                

                int ntot = 0;

                trav(j,fin) ntot += j;

                assert((int)(fin.size()) == cnt);

                if (ntot > MAX || (int)(fin.size()) != i) continue;

                

                cout << ntot << '\n';

                vector<bool> used(ntot + 5, false);

                used[0] = true;

                int curr = 0;

                rep(j,1,fin.size()) {

                    rep(l,0,fin[j]) curr++;

                    used[curr] = true;

                }

                rep(j,0,ntot) cout << used[j] << ' ';

                found = true;

                break;

            }

        }

        if (!found) cout << -1;

        cout << '\n';

    }

}