#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#pragma comment(linker, "/STACK:66777216")
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

int a,b,c,d,i,j,n,m,k;
pair<pii, int> mas[100002], quer[100002], beg[100002];
int no[100002], nv[100002], so, sv;
int fen[100002], cnt[100002], ans[100002];
int tr[(1 << 18) + 2];
inline void upd(int x, int val) {
	for (; x < n; x |= x + 1) fen[x] += val;
}
inline int sum(int x) {
	int ans = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1) ans += fen[x];
	return ans;
}
inline int sum(int l, int r) {
	if (l > r) return 0;
	return sum(r) - sum(l - 1);
}
inline bool cmp(const pair<pii, int> &a, const pair<pii, int> &b) {
	return max(beg[a.x.x].x.x, beg[a.x.y].x.x) < max(beg[b.x.x].x.x, beg[b.x.y].x.x);
}

inline void upd2(int x, int val) {
	x += sv;
	tr[x] = max(tr[x], val);
	for (; x /= 2;) tr[x] = max(tr[x], max(tr[x * 2], tr[x * 2 + 1]));
}
inline int sum2(int l, int r) {
	int ans = 0;
	for (l += sv, r += sv; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) ans = max(ans, max(tr[l], tr[r]));
	return ans;
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d", &n, &k);
	rept(i, n) scanf("%d", &mas[i].x.x);
	rept(i, n) scanf("%d", &mas[i].x.y);
	rept(i, n) {
		no[so++] = mas[i].x.x;
		nv[sv++] = mas[i].x.y;
		mas[i].y = i;
		beg[i] = mas[i];
	}
	sort(no, no + so);
	so = unique(no, no + so) - no;
	sort(nv, nv + sv);
	sv = unique(nv, nv + sv) - nv;

	sort(mas, mas + n);
	rept(i, n) {
		if (i && mas[i - 1].x.x == mas[i].x.x) continue;
		a = i;
		while (a < n && mas[a].x.x == mas[i].x.x) {
			upd(lower_bound(nv, nv + sv, mas[a].x.y) - nv, 1);
			++a;
		}
		FOR(j, i, a - 1) {
			int l = lower_bound(nv, nv + sv, mas[j].x.y - k) - nv;
			int r = upper_bound(nv, nv + sv, mas[j].x.y + k) - nv - 1;
			cnt[mas[j].y] = sum(l, r);
		}
	}

	scanf("%d", &m);
	rept(i, m) {
		scanf("%d%d", &quer[i].x.x, &quer[i].x.y); --quer[i].x.x; --quer[i].x.y;
		quer[i].y = i;
	}
	sort(quer, quer + m, cmp);
	a = n - 1;
	memset(ans, -1, sizeof(ans));
	FORD(i, m - 1, 0) {
		int n1 = quer[i].x.x, n2 = quer[i].x.y;
		int cm = max(beg[n1].x.x, beg[n2].x.x);
		while (a >= 0 && mas[a].x.x >= cm) {
			upd2(lower_bound(nv, nv + sv, mas[a].x.y) - nv, cnt[mas[a].y]);
			--a;
		}
		
		int l = max(beg[n1].x.y - k, beg[n2].x.y - k);
		int r = min(beg[n1].x.y + k, beg[n2].x.y + k);
		if (l > r) continue;
		l = lower_bound(nv, nv + sv, l) - nv;
		r = upper_bound(nv, nv + sv, r) - nv - 1;
		if (l > r) continue;
		ans[quer[i].y] = sum2(l, r);
	}
	rept(i, m) {
		if (ans[i] == 0) ans[i] = -1;
		printf("%d\n", ans[i]);
	}
}