#include <algorithm>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m; long long a_; cin >> n >> m >> a_;
	long long d = 0;
	while (--n) {
		long long a; cin >> a;
		d = gcd(d, abs(a - a_));
	}
	while (m--) {
		long long b; cin >> b;
		cout << gcd(a_ + b, d) << ' ';
	}
	cout << '\n';
	return 0;
}