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
	int x, y;
	Node() {
	}
	Node(int _x, int _y) {
		x = _x, y = _y;
		int g = abs(__gcd(x, y));
		if (g)
			x /= g, y /= g;
		if (y < 0)
			x = -x, y = -y;
	}
	void out() {
		if (!y) {
			puts(x > 0 ? "Infinity" : "-Infinity");
			return ;
		}
		printf("%d/%d\n", x, y);
	}
};
int n, m, a0, b0;
Node solve() {
	if (n == m)
		return Node(a0, b0);
	if (n < m)
		return Node(0, 1);
	return Node(a0 * b0, 0);
}
void read(int t, int &a) {
	scanf("%d", &a);
	rep(i, 0, t) {
		int x;
		scanf("%d", &x);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	read(n, a0);
	read(m, b0);
	Node ans = solve();
	//	printf("%d / %d\n", ans.x, ans.y);
	ans.out();
	return 0;
}