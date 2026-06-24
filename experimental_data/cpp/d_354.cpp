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
const int N = 100100;
const int M =  800;
int n, k;
int f[2][N], s[N];
vector<int> v[N];
int main() {
	cin >> n >> k;
	int up = sqrt(6.0 * k) + 2;
	getmin(&up, n);
	REP(i, 1, k) {
		int x, y;
		read(&x); read(&y);
		v[y].PB(x);
	}
	int c = 0;
	PER(i, n, 1) {
		c ^= 1;
		REP(j, 1, up + 1) s[j] = 0;
		for (int j = 0; j < v[i].size(); ++j) if (v[i][j] <= n - up) ++s[up + 1];
		else ++s[n - v[i][j] + 1];
		PER(j, up, 1) s[j] += s[j + 1];
		f[c][0] = inf;
		REP(j, 0, up) getmin(&f[c][0], f[c ^ 1][max(j - 1, 0)] + 
				s[j + 1] * 3 + j * (j + 1) / 2 + (j ? 2 : 0));
		REP(j, 1, up) f[c][j] = min(f[c][j - 1], f[c ^ 1][j - 1] + s[j + 1] * 3);
	}
	cout << f[c][0] << endl;
	return 0;
}