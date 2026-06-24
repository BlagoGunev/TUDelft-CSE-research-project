#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	int n; cin >> n;
	vector<pair<int,int>> p(n);
	for (int i = 0; i < n; i++) {
		int a,b,c,d; cin >> a >> b >> c >> d;
		p[i] = {a-b, c-d};
	}
	
	const double PI = acos(-1);
	vector<pair<pair<double,int>,int>> e;
	for (int i = 0; i < n; i++) {
		double a = atan2(p[i].second, p[i].first);
		e.push_back({{a, i}, 1});
		e.push_back({{a+PI, i}, -1});
		e.push_back({{a+2*PI, i}, 1});
		e.push_back({{a+3*PI, i}, -1});
	}
	sort(e.begin(), e.end());
	
	double ans = 0;
	long long xx = 0, yy = 0;
	for (auto [pp, op] : e) {
		auto [a, i] = pp;
		xx += op * p[i].first;
		yy += op * p[i].second;
		ans = max(ans, 1.0 * xx * xx + 1.0 * yy * yy);
	}
	
	cout << fixed << setprecision(15) << ans << '\n';
}