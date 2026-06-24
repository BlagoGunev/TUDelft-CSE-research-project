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
const ll LINF = 1e18 + 7;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = 1e-8;
//--------head--------
struct Node {
	ll x, y;
	Node() {
	}
	Node(ll _x, ll _y) {
		x = _x, y = _y;
//		_x = __gcd(x, y);
//		if (_x)
//			x /= _x, y /= _x;
//		if (y < 0)
//			x = -x, y = -y;
	}
	bool operator<(const Node &p) const {
		return x * p.y < y * p.x;
	}
};
int n;
vector<Node> po, ne;
int solve() {
	ll ret = 0, k = 0;
	rep(i, 0, sz(ne)) k -= ne[i].y;
	int i = 0, j = 0;
	while (i < sz(po) || j < sz(ne)) {
		Node zero;
		if (i < sz(po) && (j >= sz(ne) || po[i] < ne[j])) {
			zero = po[i];
		} else {
			zero = ne[j];
		}
		ll pk = k;
		while (i < sz(po) && !(zero < po[i]))
			k += po[i++].y;
		while (j < sz(ne) && !(zero < ne[j]))
			k += ne[j++].y;
		ret += k != pk;
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	rep(i, 0, n) {
		int k, b;
		scanf("%d%d", &k, &b);
		if (k == 0)
			continue;
		k > 0 ? po.pb(Node(-b, k)) : ne.pb(Node(b, -k));
	}
	sort(po.begin(), po.end()), sort(ne.begin(), ne.end());
	int ans = solve();
	printf("%d", ans);
	return 0;
}