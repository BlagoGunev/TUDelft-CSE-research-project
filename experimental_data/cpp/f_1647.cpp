#include <iostream>

#include <sstream>

#include <iomanip>

#include <numeric>

#include <algorithm>

#include <set>

#include <map>

#include <unordered_map>

#include <queue>

#include <stack>

#include <vector>

#include <bitset>

#include <string>

#include <cstring>

#include <cassert>

#include <cstdio>

#include <cmath>

#include <random>

#include <chrono>

#define all(v) (v).begin(), (v).end()

#define sz(v) ((int)(v).size())

#define pii pair <int, int>

#define pli pair <ll, int>

#define pil pair <int, ll>

#define pll pair <ll, ll>

#define mp make_pair

#define pb push_back

#define fi first

#define se second

#define MULTI int _T; cin >> _T; while(_T--)

#define sqr(x) ((x) * (x))

#define yesno(x) cout << ((x) ? "YES" : "NO") << endl

#define test cerr << '!' << endl;

using namespace std;



typedef long long ll;

typedef unsigned int uint;

typedef unsigned long long ull;



void main0 ();

int main () {

	clock_t start, end;

	#ifndef ONLINE_JUDGE

		freopen("file.in", "r", stdin);

		start = clock();

	#endif

	ios::sync_with_stdio(false); cin.tie(0);

	main0();

	#ifndef ONLINE_JUDGE

		end = clock();

		cout << "( " << (end - start) << " ms )" << endl;

		fclose(stdin);

	#endif

	return 0;

}



const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};

const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};

const int N = 1e6 + 5;

const int M = 1e5;

const int INF = 0x3f3f3f3f;

const ll INFF = 0x3f3f3f3f3f3f3f3f;

const int mod = 998244353;

const double eps = 1e-6;

mt19937 rnd((uint) chrono::steady_clock::now().time_since_epoch().count());

template <typename T> bool chkmin (T &x, T y) {return y < x ? x = y, 1 : 0;}

template <typename T> bool chkmax (T &x, T y) {return y > x ? x = y, 1 : 0;}



int n;

int a[N];



int ans = 0;

int fl[N], fr[N];

int g[N][2];

void solve () {

	memset(fl, 0x3f, sizeof fl);

	fl[1] = 0;

	for (int i = 2;i <= n;++i) {

		int u = a[i - 1], v = fl[i - 1];

		if (a[i] >= u) chkmin(fl[i], v);

		if (a[i] >= v) chkmin(fl[i], u);

	}

	

	memset(fr, 0x3f, sizeof fr);

	fr[n] = 0;

	for (int i = n - 1;i >= 1;--i) {

		int u = a[i + 1], v = fr[i + 1];

		if (a[i] >= u) chkmin(fr[i], v);

		if (a[i] >= v) chkmin(fr[i], u);

	}

	

	int x = max_element(a + 1, a + n + 1) - a;

	g[x][0] = a[x];

	g[x][1] = fl[x];

	for (int i = x + 1;i <= n;++i) {

		g[i][0] = -INF;

		g[i][1] = INF;

		if (a[i - 1] < a[i]) chkmax(g[i][0], g[i - 1][0]);

		if (g[i - 1][1] < a[i]) chkmax(g[i][0], a[i - 1]);

		if (a[i - 1] > a[i]) chkmin(g[i][1], g[i - 1][1]);

		if (g[i - 1][0] > a[i]) chkmin(g[i][1], a[i - 1]);

		ans += (g[i][0] > fr[i]);

	}

}



void main0 () {

	cin >> n;

	for (int i = 1;i <= n;++i) {

		cin >> a[i];

	}

	solve();

	reverse(a + 1, a + n + 1);

	solve();

	cout << ans << endl;

}