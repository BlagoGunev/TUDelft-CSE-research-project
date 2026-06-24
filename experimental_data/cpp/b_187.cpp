#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>

#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;
const int maxn = 70;
const int cinf = 1000000000;
int tmp[maxn][maxn];
int a[maxn][maxn] = {};
int dp[maxn][maxn][maxn] = {};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int n, m, r; scanf("%d%d%d", &n, &m, &r);
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) a[i][j] = cinf;
	for (int matr = 0; matr < m; ++matr) {
		for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) scanf("%d", &tmp[j][k]);
		for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) tmp[i][j] = min(tmp[i][j], tmp[i][k]+tmp[k][j]);
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) a[i][j] = min(a[i][j], tmp[i][j]);
	}
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) dp[i][j][k] = cinf;
	for (int i = 0; i < n; ++i) dp[i][i][0] = 0;
	for (int cnt = 0; cnt <= n; ++cnt) {
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < n; ++k) {
			dp[i][k][cnt+1] = min(dp[i][k][cnt+1], dp[i][j][cnt]+a[j][k]);
		}
	}
	for (int i = 0; i < r; ++i) {
		int fr, to, cc;
		scanf("%d%d%d", &fr, &to, &cc); fr--; to--; cc++;
		cc = min(cc,n-1);
		printf("%d\n", dp[fr][to][cc]);
	}
	return 0;
}