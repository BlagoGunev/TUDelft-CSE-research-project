#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:66777216")
#include <cstdio>
#else
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <stdio.h>
#endif
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <chrono>
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

int a, b, c, d, n, m, k;
char str[3];
pair<int, pii> chips[16];
int dp[1 << 16][121];
inline void upd(int &a, int b) {
	if (a < b) a = b;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	rept(i, n) {
		scanf("%s%d%d", str, &a, &b);
		if (str[0] == 'R') chips[i].x = 0; else
			chips[i].x = 1;
		chips[i].y = mp(a, b);
	}

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	rept(mask, (1 << n) - 1) {
		int c0 = 0, c1 = 0;
		rept(i, n) {
			if (mask & 1 << i) {
				if (chips[i].x == 0) ++c0; else
					++c1;
			}
		}

		rept(hal, 121) {
			if (dp[mask][hal] < 0) continue;
			int cd = dp[mask][hal];
			rept(i, n) {
				if (~mask & 1 << i) {
					int h0 = min(chips[i].y.x, c0), h1 = min(chips[i].y.y, c1);
					upd(dp[mask | 1 << i][hal + h0], cd + h1);
				}
			}
		}
	}

	int ans = INF;
	int n0 = 0, n1 = 0;
	rept(i, n) {
		n0 += chips[i].y.x;
		n1 += chips[i].y.y;
	}
	rept(hal, 121) {
		int cd = dp[(1 << n) - 1][hal];
		if (cd < 0) continue;
		
		int c0 = n0 - hal;
		int c1 = n1 - cd;
		ans = min(ans, max(c0, c1));
	}

	printf("%d\n", ans + n);
}