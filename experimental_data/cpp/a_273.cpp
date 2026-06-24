//#define PROB "test"    //{{{ Preamble
#define IN   PROB ".in"  // "input.txt"
#define OUT  PROB ".out" // "output.txt"
#ifndef LOCAL_PC
#  define NDEBUG
#  define LOG(...) static_cast<void>(0)
#else
#  include <logging.hpp>
#endif
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L || defined(__GXX_EXPERIMENTAL_CXX0X__)
#  include <forward_list>
#  include <future>
#  include <unordered_map>
#  include <unordered_set>
#endif
#ifdef __GLIBCXX__
#  include <ext/numeric>
using __gnu_cxx::power;
#endif
using namespace std; typedef long long ll; typedef unsigned long long ull;
const double pi=3.14159265358979323846; const double E=2.7182818284590452354;
static struct _{ ios::Init i; _(){ srand(time(0)); cin.sync_with_stdio(0);
  cin.tie(0); } }_; template<class T> inline T sq(const T& X){ return X*X; }
template<class I> inline void in(I Y, int X){ do cin >> *Y++; while(--X); }
#if defined(PROB) && !defined(LOCAL_PC)
static struct ${ $(){ cin.rdbuf(a.open(IN, ios::in)); cout.rdbuf(b.open(OUT,
  ios::out)); } ~$(){ cin.rdbuf(0); cout.rdbuf(0); } filebuf a,b; }$;
#endif
#define endl         '\n'
#define pb(...)      push_back(__VA_ARGS__)
#define eb(...)      emplace_back(__VA_ARGS__)
#define sz(v)        static_cast<int>((v).size())
#define X            first
#define Y            second
#define FOREACH(i,c) for(__typeof__((c).begin())i=(c).begin();i!=(c).end();++i)
#define mp(x, y)     make_pair((x), (y))
#define ass(e)       assert(e)
//}}}

int arr[100005];

int main()
{
    int n; cin >> n;

    in(arr+1, n);

    int m; cin >> m;

    ll H = 0;
    for (int i = 0; i < m; i++)
    {
        int w, h; cin >> w >> h;

        H = max(H, (ll)arr[w]);
        cout << H << endl;
        H += h;
    }
}