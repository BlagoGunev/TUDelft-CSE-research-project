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

const int N = 310000;

struct node {

	int x, y, z;

}T[N];

bool operator < (node A, node B) {

	return A.x < B.x;

}



int tag[N * 4], mx[N * 4], val[N * 4];



PII a[N], b[N], c[N];

int n, m;



void down(int u, int L, int R) {

	int mid = (L + R) >> 1;

	if (tag[u]) {

		tag[u * 2] = tag[u]; mx[u * 2] = L + tag[u], val[u * 2] = tag[u];

		tag[u * 2 + 1] = tag[u]; mx[u * 2 + 1] = mid + 1 + tag[u], val[u * 2 + 1] = tag[u];

		tag[u] = 0;

	}

}



void update(int u) {

	assert(val[u * 2] >= val[u * 2 + 1]);

	mx[u] = min(mx[u * 2], mx[u * 2 + 1]);

	val[u] = min(val[u * 2], val[u * 2 + 1]);

}



void build(int u, int L, int R) {

	if (L == R) {

		mx[u] = L;

		return;

	}

	int mid = (L + R) >> 1;

	build(u * 2, L, mid);

	build(u * 2 + 1, mid + 1, R);

	update(u);

}





void modify(int u, int L, int R, int l, int r, int d) {

	if (l > r) return;

	if (l <= L && r >= R) {

		assert(val[u] < d);

		tag[u] = d;

		mx[u] = L + d;

		val[u] = d;

		return;

	}

	down(u, L, R);

	int mid = (L + R) >> 1;

	if (r <= mid) modify(u * 2, L, mid, l, r, d);

	else if (l > mid) modify(u * 2 + 1, mid + 1, R, l, r, d);

	else {

		modify(u * 2, L, mid, l, mid, d);

		modify(u * 2 + 1, mid + 1, R, mid + 1, r, d);

	}

	update(u);

}



int find(int u, int L, int R, int d) {

	if (val[u] >= d) return n + 1;

	if (L == R) return L;

	down(u, L, R);

	int mid = (L + R) >> 1;

	assert(val[u * 2] >= val[u * 2 + 1]);

	if (val[u * 2] < d) return find(u * 2, L, mid, d);

	else return find(u * 2 + 1, mid + 1, R, d);

}





int pool[N];

int main() {

	cin >> n;

	REP(i,1, n) read(&a[i].FR), a[i].SC = i, pool[++m] = a[i].FR;

	REP(i,1, n) read(&b[i].FR), b[i].SC = i, pool[++m] = b[i].FR;

	REP(i,1, n) read(&c[i].FR), c[i].SC = i, pool[++m] = c[i].FR;

	sort(pool + 1, pool + m + 1);

	sort(a + 1, a + n + 1);

	sort(b + 1, b + n + 1);

	sort(c + 1, c + n + 1);

	m = unique(pool + 1, pool + m + 1) - pool - 1;

	REP(i, 1, m) {

		T[i].x = lower_bound(a + 1, a + n + 1, MP(pool[i], 0)) - a;

		if (a[T[i].x].FR == pool[i]) T[i].x = a[T[i].x].SC;

		else T[i].x = 3 * n + 1;



		T[i].y = lower_bound(b + 1, b + n + 1, MP(pool[i], 0)) - b;

		if (b[T[i].y].FR == pool[i]) T[i].y = b[T[i].y].SC;

		else T[i].y = n + 1;



		T[i].z = lower_bound(c + 1, c + n + 1, MP(pool[i], 0)) - c;

		if (c[T[i].z].FR == pool[i]) T[i].z = c[T[i].z].SC;

		else T[i].z = 3 * n + 1;

	}

	build(1, 0, n);

	sort(T + 1, T + m + 1);

	int ans = T[m].x;

	PER(i, m, 1) {

		int l = find(1, 0, n, T[i].z);

		int r = T[i].y - 1;

		modify(1, 0, n, l, r, T[i].z);

		if (T[i].x != T[i - 1].x && T[i - 1].x <= n) {

			getmin(&ans, T[i - 1].x + mx[1]);

		}

	}

	cout << ans << endl;

	return 0;

}