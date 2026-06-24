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
const int N = 2e3 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = 1e-9;
//--------head--------
template<typename T>
inline T sqr(T x) {
	return x * x;
}
struct Node {
	double x, y;
	Node() {
	}
	Node(double _x, double _y) {
		x = _x, y = _y;
	}
	Node operator+(const Node &p) const {
		return Node(x + p.x, y + p.y);
	}
	Node operator-(const Node &p) const {
		return Node(x - p.x, y - p.y);
	}
	double operator^(const Node &p) const {
		return x * p.y - y * p.x;
	}
	double operator*(const Node &p) const {
		return x * p.x + y * p.y;
	}
	double dis() {
		return sqrt(sqr(x) + sqr(y));
	}
	double dis2() {
		return sqr(x) + sqr(y);
	}
};
int xp, yp, vp;
int x, y, v, r;
double R;
int sign(double x) {
	if (fabs(x) < EPS)
		return 0;
	return x > 0 ? 1 : -1;
}
double cross(Node a, Node b) {
	return a.x * b.y - a.y * b.x;
}
double cross(Node a, Node b, Node c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
double dot(Node a, Node b, Node c) {
	return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}
int calc(Node a, Node b, double r) {
	double len = (a - b).dis();
	double d = fabs(cross(a, b)) / len;
	if (sign(d - r) >= 0)
		return -1;
	Node vec, o(0, 0);
	vec = (sign(cross(a, b, Node(0, 0))) < 0 ? b - a : a - b);
	vec = Node(-vec.y, vec.x);
	vec.x *= d / len, vec.y *= d / len;
	Node add = b - a;
	double tmp = sqrt(sqr(r) - sqr(d)) / len;
	add.x *= tmp, add.y *= tmp;
	Node tmp1 = vec + add, tmp2 = vec - add;
	int flag1 = sign(dot(tmp1, a, b)) < 0;
	int flag2 = sign(dot(tmp2, a, b)) < 0;
	return flag1 + flag2;	
}
bool check(double T) {
	double t;
	double w = vp / R * T;
	double xb = xp * cos(w) - yp * sin(w), yb = xp * sin(w) + yp * cos(w);
	double ab = sqrt(sqr(x - xb) + sqr(y - yb));
	double d = fabs((Node(0, 0) - Node(x, y)) ^ (Node(xb, yb) - Node(x, y))) / ab; 
//	printf("T = %f, xb = %f, yb = %f, R = %f, ab = %f, v = %d\n", T, xb, yb, R, ab, v);
	if (calc(Node(x, y), Node(xb, yb), r) < 2) {
		t = ab / v;
//		printf("T = %f, ", T);
//		printf("(%f, %f) (%f, %f), r = %f, inter = %d, t = %f, d = %f\n", 1.0 * x, 1.0 * y, xb, yb, 1.0 * r, calc(Node(x, y), Node(xb, yb), r), t, d);
	} else {
		double oa = Node(x, y).dis(), ob = Node(xb, yb).dis();	
		double ac = sqrt(sqr(x) + sqr(y) - sqr(r)), bd = sqrt(sqr(xb) + sqr(yb) - sqr(r));
		double aob = acos((sqr(x) + sqr(y) + sqr(xb) + sqr(yb) - sqr(x - xb) - sqr(y - yb)) / (2.0 * oa * ob));
//		printf("oa = %f, ob = %f, ab = %f, ", oa, ob, ab);
//		printf("(%f, %f) (%f, %f), ang = %f", 1.0 * x, 1.0 * y, xb, yb, aob * 180 / PI);
		double the = aob - acos(r / oa) - acos(r / ob);
		t = (ac + bd + r * the) / v;
//		printf(", the = %f, t = %f, T = %f\n", the * 180 / PI, t, T);
	}
//	printf("t = %f\n", t);
	return t + EPS <= T;
}
double solve() {
	R = sqrt(sqr(xp) + sqr(yp));
	double l = 0, r = 1e9;
//	l = r = 0.447407904;	
	rep(time, 0, 1000) {
		double m = (l + r) / 2.0;
		check(m) ? r = m : l = m;
	}
	return l;
}
int main() {
	scanf("%d%d%d", &xp, &yp, &vp);
	scanf("%d%d%d%d", &x, &y, &v, &r);
	printf("%.10f", solve());
	return 0;
}