#include<time.h>

#include<stdlib.h>

#include<assert.h>

#include<cmath>

#include<cstring>

#include<cstdio>

#include<set>

#include<map>

#include<queue>

#include<bitset>

#include<vector>

#include<iostream>

#include<algorithm>

#include<iomanip>

#include<string>

#include<sstream>

using namespace std;

typedef long long ll;

typedef unsigned long long ul;

typedef vector<int> vi;

typedef pair<int, int> pii;

#define rep(i,l,r) for(int i=l;i<(r);++i)

#define per(i,l,r) for(int i=r-1;i>=(l);--i)

#define sz(x) ((int)((x).size()))

#define sqr(x) ((ll)(x)*(x))

#define all(x) (x).begin(),(x).end()

#define mp make_pair

#define pb push_back

#define fi first

#define se second

#define de(x) cout << #x << " = " << x << endl;

#define debug(x) freopen(x".in", "r", stdin);

#define setIO(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout);

const ll LINF = 1e18 + 7;

const ul BASE = 1e6 + 7;

const int N = 1e7 + 7;

const int P = 1e3 + 7;

const int INF = 1e9 + 7;

const int MOD = 1000000007;

const double Pi = acos(-1.);

const double EPS = 1e-9;

ll kpow(ll a, ll b, ll mod) {

	ll ret = 1;

	for (; b; b >>= 1, a = a * a % mod)

		if (b & 1)

			ret = ret * a % mod;

	return ret;

}

//--------------head-------------

int n, k;

double ans[20], p[20], f[1 << 20];

void solve() {

	int c = n;

	rep(i, 0, n)

		if (fabs(p[i]) < EPS)

			--c;

	k = min(k, c);

	f[0] = 1;

	rep(mask, 1, 1 << n)

		if (__builtin_popcount(mask) <= k) {

			double S = 0;

			rep(i, 0, n)

				if (mask >> i & 1) {

					S += p[i];

					f[mask] += p[i] * f[mask ^ (1 << i)];

				}

			if (__builtin_popcount(mask) < k && fabs(1 - S) > EPS)

				f[mask] /= 1 - S;

			if (__builtin_popcount(mask) == k)

				rep(i, 0, n)

					if (mask >> i & 1)

						ans[i] += f[mask];

		}

}

int main() {

	scanf("%d%d", &n, &k);

	rep(i, 0, n)

		scanf("%lf", &p[i]);

	solve();

	rep(i, 0, n)

	{

		if (i)

			putchar(' ');

		printf("%.12lf", ans[i]);

	}

	return 0;

}