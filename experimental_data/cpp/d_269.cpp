#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <queue>
using namespace std;

const int kInf = 1000000000;

struct Arc {
	int s, prev, c;
} arr[800005];

int beg[200005];
int kol = 0;

void AddArc(int f, int s, int c) {
//	cerr << "ARC " << f << " " << s << " " << c << endl;
	arr[kol].s = s;
	arr[kol].c = c;
	arr[kol].prev = beg[f];
	beg[f] = kol++;
}

struct Seg {
	int l, r, h, id;
	bool operator<(const Seg &second) const {
		return h < second.h;
	}
} seg[100005];


struct Event {
	int t, h, id;
	bool type;
	bool operator<(const Event &s) const {
		if (t != s.t) {
			return t < s.t;
		} else if (type != s.type) {
			return type < s.type;
		} else {
			return h < s.h;
		}
	}
} ev[200005];

int lastlow[200005];
int lasthigh[200005];

set<Seg> S;

void AddArc(int f, int s) {
	int c = min(seg[f].r, seg[s].r) - max(seg[f].l, seg[s].l);
	AddArc(f, s, c);
}

int mem[200005];

int DFS(int v) {
	if (mem[v] != -1) {
		return mem[v];
	}
	if (beg[v] == -1) {
		return 2 * kInf + 1;
	} else {
		int ret = 0;
		for (int i = beg[v]; i != -1; i = arr[i].prev) {
			ret = max(ret, min(DFS(arr[i].s), arr[i].c));
		}
		return mem[v] = ret;
	}
}

int main() {
	memset(lastlow, 0x80, sizeof lastlow);
	memset(lasthigh, 0x80, sizeof lasthigh);
	memset(beg, -1, sizeof beg);
	memset(mem, -1, sizeof mem);
	int n, t, q = 0;
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &seg[i].h, &seg[i].l, &seg[i].r);
		seg[i].id = i;
		ev[q].h = seg[i].h;
		ev[q].t = seg[i].l;
		ev[q].type = true;
		ev[q].id = i;
		++q;

		ev[q].h = seg[i].h;
		ev[q].t = seg[i].r;
		ev[q].id = i;
		ev[q].type = false;
		++q;
	}
	seg[0].h = t;
	seg[0].id = 0;
	seg[0].l = -kInf;
	seg[0].r = kInf;

	ev[q].h = t;
	ev[q].t = -kInf;
	ev[q].id = 0;
	ev[q].type = true;
	++q;
	ev[q].h = t;
	ev[q].t = kInf;
	ev[q].id = 0;
	ev[q].type = false;
	++q;
	sort(ev, ev + q);

	for (int i = 0; i < q; ++i) {
		if (ev[i].type) {
			Seg cur = seg[ev[i].id];
			S.insert(cur);
		} else {
			Seg cur = seg[ev[i].id];
			set<Seg>::iterator it = S.find(cur);
			if (it != S.begin()) {
				--it;
				if (lastlow[it->id] <= cur.l) {
					AddArc(cur.id, it->id);
				}
				lastlow[it->id] = cur.r;
				++it;
			}
			++it;
			if (it != S.end()) {
				if (lasthigh[it->id] <= cur.l) {
					AddArc(it->id, cur.id);
				}
				lasthigh[it->id] = cur.r;
			}
			--it;
			S.erase(it);
		}
	}
	printf("%d\n", DFS(0));
	return 0;
}