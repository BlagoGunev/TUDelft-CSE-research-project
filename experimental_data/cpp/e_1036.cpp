#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

long long x, y;

bool intersect(pair <long long, long long> p1, pair <long long, long long> p2, pair <long long, long long> p3, pair <long long, long long> p4) {
	long long x1 = p1.first;
	long long y1 = p1.second;
	long long x2 = p2.first;
	long long y2 = p2.second;
	long long x3 = p3.first;
	long long y3 = p3.second;
	long long x4 = p4.first;
	long long y4 = p4.second;
	long long a1 = y1 - y2, b1 = x2 - x1;
	long long c1 = -a1 * x1 - b1 * y1;
	long long a2 = y3 - y4, b2 = x4 - x3;
	long long c2 = -a2 * x3 - b2 * y3;
	if (a1 * b2 == a2 * b1 || (c1 * b2 - c2 * b1) % (a1 * b2 - a2 * b1) != 0 || (c1 * a2 - c2 * a1) % (a1 * b2 - a2 * b1) != 0)
		return false;
	x = (c2 * b1 - c1 * b2) / (a1 * b2 - a2 * b1), y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1);
	if (x >= min(x1, x2) && x <= max(x1, x2) && x >= min(x3, x4) && x <= max(x3, x4) && y >= min(y1, y2) && y <= max(y1, y2) && y >= min(y3, y4) && y <= max(y3, y4))
		return true;
	return false;
}

long long gcd(long long a, long long b) {
	if (a > b)
		swap(a, b);
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int main() {
	long long n, ans = 0, _x, _y, g;
	cin >> n;
	set <pair <long long, long long> > b;
	vector <pair <pair <long long, long long>, pair <long long, long long> > > a(n);
	for (long long i = 0; i < n; i++) {
		cin >> a[i].first.first >> a[i].first.second >> a[i].second.first >> a[i].second.second;
		_x = abs(a[i].first.first - a[i].second.first);
		_y = abs(a[i].first.second - a[i].second.second);
		ans += gcd(_x, _y) + 1;
	}
	for (long long i = 0; i < n; i++) {
		for (long long j = i + 1; j < n; j++) {
			if (intersect(a[i].first, a[i].second, a[j].first, a[j].second)) {
				b.insert({ x, y });
			}
		}
		//cout << b.size() << endl;
		ans -= b.size();
		b.clear();
	}
	cout << ans - b.size();
	//system("pause");
}