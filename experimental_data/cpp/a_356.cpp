// .... .... .....!
// P..... C.....!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 3*100000 + 1000;

int n, m;
int nxt[maxn];
int ans[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;

	rep (i, n) nxt[i] = i+1, ans[i] = -1;

	rep (i, m)
	{
		int l, r, x;
		cin >> l >> r >> x;
		x--;
		l--;
		for (int i = l, tmp; i < r; tmp = nxt[i], nxt[i] = (i<x ? x : r), i = tmp)
			if (i != x && ans[i] == -1) ans[i] = x;
	}

	rep (i, n) cout << ans[i] + 1 << ' ';
	cout << endl;

	{ int _; cin >> _; return 0; }
}