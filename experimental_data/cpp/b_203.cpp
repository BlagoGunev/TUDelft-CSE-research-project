//#define PROB "test"         /* Comment to use standard I/O everywhere    */
#define STDIO                 /* Uncomment to use standard I/O on local PC */

//{{{ Preamble
#if !defined(LOCAL_PC) && !defined(NDEBUG)
#  define NDEBUG
#endif
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#ifdef LOCAL_PC
#  include <debug_output.hpp>
#else
#  define LOG(x)      static_cast<void>(0)
#  define LOG2(x,y)   static_cast<void>(0)
#  define LOG3(x,y,z) static_cast<void>(0)
#endif
using namespace std; typedef long long ll; typedef unsigned long long ull;
const double pi=3.14159265358979323846; const double E=2.7182818284590452354;
static struct _{ ios_base::Init i; _(){cin.sync_with_stdio(0);cin.tie(0);} } _;
inline ostream& endl(ostream& os) { return os << '\n'; }
#if defined(PROB) && (!defined(LOCAL_PC) || !defined(STDIO))
static struct __{ __(){cin.rdbuf(a.open(PROB".in",ios::in));cout.rdbuf(b.open(
PROB".out",ios::out));} ~__(){cin.rdbuf(0);cout.rdbuf(0);} } __;
#endif
#define FOREACH(i,c) for(__typeof__((c).begin())i=(c).begin();i!=(c).end();++i)
#define pb           push_back
#define mp           make_pair
#define sz(v)        static_cast<int>((v).size())
#define X            first
#define Y            second
//}}}

static bool arr[1004][1004];

static inline bool test(int x, int y)
{
	return arr[x-1][y-1] && arr[x][y-1] && arr[x+1][y-1]
		&& arr[x-1][y] && arr[x][y] && arr[x+1][y]
		&& arr[x-1][y+1] && arr[x][y+1] && arr[x+1][y+1];
}

int main()
{
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		x++; y++;
		arr[x][y] = true;

		if (test(x-1, y-1) || test(x, y-1) || test(x+1, y-1)
		||	test(x-1, y) || test(x, y) || test(x+1, y)
		||  test(x-1, y+1) || test(x, y+1) || test(x+1, y+1))
		{
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}