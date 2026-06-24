#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <climits>
#include <cfloat>
#include <ctime>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

typedef long long LL;
template<class T> void minimize(T& a, const T& b) { a=min(a,b); }
template<class T> void maximize(T& a, const T& b) { a=max(a,b); }


double solve(double a, double b, double c) {
	return max(0.0, (-b + sqrt(b * b - 4 * a * c)) / (2 * a));
}

double a, v;

double getTime(double d, double w) {
	double r = d / 2;
	double t = solve(a / 2, w, -r);
	double v1 = w + t * a;
	if (v1 > v) {
		v1 = v;
	}
	t = (v1 - w) / a;
	r = t * w + t * t / 2 * a;
	return 2 * t + (d - 2*r) / v;
}

double getTime(double d, double v0, double v1) {
	if (v0 > v) {
		v0 = v;
	}
	if (v1 > v) {
		v1 = v;
	}
	if (v0 > v1) {
		return getTime(d, v1, v0);
	}
	double t = (v1 - v0) / a;
	double r = t * v0 + t * t / 2 * a;
	if (r > d) {
		r = d;
	}
	t = solve(a / 2, v0, -r);

	return t + getTime(d - r, v1);
}

int main() {
	double len, d, w, ans = 0;
	cin>>a>>v>>len>>d>>w;
	ans = getTime(d, 0, w);
	double v0 = ans * a;
	if (v0 > v) {
		v0 = v;
	}
	if (v0 > w) {
		v0 = w;
	}
	ans += getTime(len - d, v0, v);
	printf("%.8f\n", ans);
}