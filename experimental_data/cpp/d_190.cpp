#include<cmath>

#include<cstdio>

#include<cstring>

#include<map>

#include<set>

#include<queue>

#include<vector>

#include<sstream>

#include<iomanip>

#include<iostream>

#include<algorithm>

#include<time.h>

#include<stdlib.h>

#include<assert.h>

using namespace std;

#define fi first

#define se second

#define mp make_pair

#define pb push_back

#define sz(x) ((int)(x).size())

#define rep(i,l,r) for(int i=(l);i<(r);++i)

typedef long long ll;

typedef pair<int, int> pii;

const int N = 4e5 + 7;

const int INF = 1e9 + 7;

const int MOD = 1e6 + 3;

const double Pi = acos(-1.0);

const double EPS = 1e-8;

//--------head---------

int n, k, a[N], c[N];

vector<int> V;

int main() {

	scanf("%d%d", &n, &k);

	rep(i, 0, n)

		scanf("%d", a + i), V.pb(a[i]);

	sort(V.begin(), V.end());

	V.erase(unique(V.begin(), V.end()), V.end());

	rep(i, 0, n)

		a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin();

	ll ans = 0;

	int r = 0, flag = -1;

	rep(l, 0, n)

	{

		if (l > 0) {

			--c[a[l - 1]];

			if (flag == a[l - 1])

				flag = -1;

		}

		while (r < n && flag == -1) {

			int v = a[r++];

			if (++c[v] == k) {

				flag = v;

				break;

			}

		}

		if (flag == -1)

			break;

//		printf("l = %d, r = %d\n", l, r);

		ans += n - r + 1;

	}

	printf("%I64d", ans);

	return 0;

}