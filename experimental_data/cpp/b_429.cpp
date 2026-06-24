/* Copyright 2016 AcrossTheSky */
#include <iostream>
#include <cstdio>
#include <utility>
#include <cassert>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define RVC(i, c) fot (int i = 0; i < (c).size(); ++i)
#define RED(k, u) for (int k = head[(u)]; k; k = edge[k].next)
#define lowbit(x) ((x) & (-(x)))
#define CL(x, v) memset(x, v, sizeof x)
#define MP std::make_pair
#define PB push_back
#define FR first
#define SC second
#define rank rankk
#define next nextt
#define link linkk
#define index indexx
#define abs(x) ((x) > 0 ? (x) : (-(x)))
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

template<class T> inline
bool getmin(T *a, const T &b) {
    if (b < *a) {
        *a = b;
        return true;
    }
    return false;
}

template<class T> inline
bool getmax(T *a, const T &b) {
    if (b > *a) {
        *a = b;
        return true;
    }
    return false;
}

template<class T> inline
void read(T *a) {
    char c;
    while (isspace(c = getchar())) {}
    bool flag = 0;
    if (c == '-') flag = 1, *a = 0;
    else
        *a = c - 48;
    while (isdigit(c = getchar())) *a = *a * 10 + c - 48;
    if (flag) *a = -*a;
}
const int mo = 1000000007;
template<class T>
T pow(T a, T b, int c = mo) {
    T res = 1;
    for (T i = 1; i <= b; i <<= 1, a = 1LL * a * a % c) if (b & i) res = 1LL * res * a % c;
    return res;
}
/*======================= TEMPLATE =======================*/
const int inf = 100000000;
const int N = 1010;
int f[N][N], g[N][N], l[N][N], r[N][N];
int n, m, a[N][N];
int main() {
	cin >> n >> m;
	REP(i, 1, n) REP(j, 1, m) read(&a[i][j]);
	REP(i, 1, n) 
		REP(j, 1, m) f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
	PER(i, n, 1)
		REP(j, 1, m) g[i][j] = max(g[i + 1][j], g[i][j - 1]) + a[i][j];
	PER(i, n, 1)
		PER(j, m, 1) r[i][j] = max(r[i + 1][j], r[i][j + 1]) + a[i][j];
	REP(i, 1, n) 
		PER(j, m, 1) l[i][j] = max(l[i - 1][j], l[i][j + 1]) + a[i][j];
	int ans = 0;
	REP(i, 2, n - 1) REP(j, 2, m - 1) {
		int v1 = f[i][j - 1] + g[i + 1][j] + r[i][j + 1] + l[i - 1][j];
		int v2 = f[i - 1][j] + g[i][j - 1] + r[i + 1][j] + l[i][j + 1];
		getmax(&ans, max(v1, v2));
	}
	cout << ans << endl;
	return 0;
}