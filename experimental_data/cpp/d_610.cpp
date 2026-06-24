#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

#define y1 asdfsadaads
#define union fuck_this


const int N = 200100;

struct segment {
	int l, r;
	segment() {}
	segment(int a, int b): 
		l(min(a, b)), r(max(a, b)) {}
};

long long ans;
int cover, range, n, i, j, l, r, rr, q, L, R;
int x1[100100];
int y1[100100];
int x2[100100];
int y2[100100];
int cx1[100100];
int cx2[100100];
int cy1[100100];
int cy2[100100];
int fwt[N];
vector < pair <int, int> > events[N];
vector <int> xvals, yvals;
segment A;

int compressx(int x) {
	int l = 0, r = (int)xvals.size() - 1, mid;
	for (int it = 0; it < 20; it++) {
		mid = (l + r) >> 1;
		if (xvals[mid] < x) {
			l = mid + 1;
		} else {
			if (xvals[mid] > x) {
				r = mid;
			} else {
				return mid + 1;
			}
		}
	}
	assert(0);
}


int compressy(int x) {
	int l = 0, r = (int)yvals.size() - 1, mid;
	for (int it = 0; it < 20; it++) {
		mid = (l + r) >> 1;
		if (yvals[mid] < x) {
			l = mid + 1;
		} else {
			if (yvals[mid] > x) {
				r = mid;
			} else {
				return mid + 1;
			}
		}
	}
	assert(0);
}

bool inter(segment a, segment b) {
	int l1 = a.l, r1 = a.r, l2 = b.l, r2 = b.r;
	return max(0, min(r1, r2) - max(l1, l2) + 1) > 0;
}

segment union(segment a, segment b) {
	int l = min(a.l, b.l);
	int r = max(a.r, b.r);
	segment s = segment(l, r);
	return s;
}

vector <segment> ver[N];
vector <segment> hor[N];
vector <segment> nhor, nver;

inline bool operator< (const segment & a, const segment & b) {
	if (a.l != b.l) {
		return (a.l < b.l);
	}
	return (a.r > b.r);
}

inline void modify(int l, int v) {
	l += 4;
	for (int i = l; i <= range; i = (i | (i - 1)) + 1) {
		fwt[i] += v;
	}
}

long long getsum(int r) {
	r += 4;
	long long s = 0;
	for (int i = r; i; i &= (i - 1)) {
		s += fwt[i];
	}
	return s;
}

inline int nextint() {
	int x = 0, p = 1;
	char c;
	do { 
		c = getchar();
	}	while (c <= 32);
	if (c == '-') {
		p = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * p;
}

int main() {
	//freopen("input.txt", "r", stdin);
	n = nextint();
	for (int i = 1; i <= n; i++) {
		x1[i] = nextint();
		y1[i] = nextint();
		x2[i] = nextint();
		y2[i] = nextint();
		xvals.push_back(x1[i]);
		xvals.push_back(x2[i]);
		yvals.push_back(y1[i]);
		yvals.push_back(y2[i]);
	}	
	sort(xvals.begin(), xvals.end());
	xvals.resize(unique(xvals.begin(), xvals.end()) - xvals.begin());
	sort(yvals.begin(), yvals.end());
	yvals.resize(unique(yvals.begin(), yvals.end()) - yvals.begin());
	for (int i = 1; i <= n; i++) {
		cx1[i] = compressx(x1[i]);
		cx2[i] = compressx(x2[i]);
		cy1[i] = compressy(y1[i]);
		cy2[i] = compressy(y2[i]);
		if (cx1[i] == cx2[i]) {
			ver[cx1[i]].push_back(segment(cy1[i], cy2[i]));
		} else {
			hor[cy1[i]].push_back(segment(cx1[i], cx2[i]));
		}
	}
	range = 2 * n + 10;
	for (int i = 1; i <= range; i++) {
		if (hor[i].empty()) {
			continue;
		}
		nhor.clear();
		for (int j = 0; j < (int)hor[i].size(); j++) {
			A = hor[i][j];
			while (!nhor.empty() && inter(A, nhor.back())) {
				A = union(A, nhor.back());
				nhor.pop_back();
			}
			nhor.push_back(A);
		}
		hor[i] = nhor;
	}
	for (int i = 1; i <= range; i++) {
		if (ver[i].empty()) {
			continue;
		}
		nver.clear();
		for (int j = 0; j < (int)ver[i].size(); j++) {
			A = ver[i][j];
			while (!nver.empty() && inter(A, nver.back())) {
				A = union(A, nver.back());
				nver.pop_back();
			}
			nver.push_back(A);
		}
		ver[i] = nver;
	}
	
	for (int i = 1; i <= range; i++) {
		if (hor[i].empty()) {
			continue;
		}
		nhor.clear();
		sort(hor[i].begin(), hor[i].end());
		j = 0;
		while (j < (int)hor[i].size()) {
			rr = j;
			while (rr + 1 < (int)hor[i].size() && hor[i][j].l == hor[i][rr + 1].l) {
				rr++;
			}
			cover = -(int)2e9;
			for (int q = j; q <= rr; q++) {
				cover = max(cover, hor[i][q].r);
			}
			rr = j;
			while (rr + 1 < (int)hor[i].size() && cover >= hor[i][rr + 1].l) {
				rr++;
			}
			L = (int)2e9;
			R = -(int)2e9;
			for (int q = j; q <= rr; q++) {
				L = min(L, hor[i][q].l);
				R = max(R, hor[i][q].r);
			}
			nhor.push_back(segment(L, R));
			j = rr + 1;
		}
		hor[i] = nhor;
	}
	for (int i = 1; i <= range; i++) {
		if (ver[i].empty()) {
			continue;
		}
		nver.clear();
		sort(ver[i].begin(), ver[i].end());
		j = 0;
		while (j < (int)ver[i].size()) {
			rr = j;
			while (rr + 1 < (int)ver[i].size() && ver[i][j].l == ver[i][rr + 1].l) {
				rr++;
			}
			cover = -(int)2e9;
			for (int q = j; q <= rr; q++) {
				cover = max(cover, ver[i][q].r);
			}
			rr = j;
			while (rr + 1 < (int)ver[i].size() && cover >= ver[i][rr + 1].l) {
				rr++;
			}
			L = (int)2e9;
			R = -(int)2e9;
			for (int q = j; q <= rr; q++) {
				L = min(L, ver[i][q].l);
				R = max(R, ver[i][q].r);
			}
			nver.push_back(segment(L, R));
			j = rr + 1;
		}
		ver[i] = nver;
	}
	
	for (int i = 1; i <= range; i++) {
		for (int j = 0; j < (int)hor[i].size(); j++) {
			ans += xvals[hor[i][j].r - 1] - xvals[hor[i][j].l - 1] + 1;
		}
		for (int j = 0; j < (int)ver[i].size(); j++) {
			ans += yvals[ver[i][j].r - 1] - yvals[ver[i][j].l - 1] + 1;
		}
	}
	for (int i = 1; i <= range; i++) {
		for (int j = 0; j < (int)hor[i].size(); j++) {
			l = hor[i][j].l, r = hor[i][j].r;
			events[l].push_back(make_pair(i, 0));
			events[r + 1].push_back(make_pair(i, 1));
		}
	}
	for (int i = 1; i <= range + 10; i++) {
		for (int j = 0; j < (int)events[i].size(); j++) {
			if (events[i][j].second == 0) {
				modify(events[i][j].first, 1);
			} else {
				modify(events[i][j].first, -1);
			}	
		}	
		for (int j = 0; j < (int)ver[i].size(); j++) {
			l = ver[i][j].l, r = ver[i][j].r;
			ans -= (getsum(r) - getsum(l - 1));
		}
	}
	cout << ans << endl;
	return 0;
}