#include <cstdio>
#include <utility>
using namespace std;
typedef long long ll;

// returns (x, y) such that ax + by = gcd(a, b)
pair<ll, ll> extended_gcd(long long a, long long b) {
	if (b == 0) return make_pair(1ll, 0ll);
	auto t = extended_gcd(b, a % b);
	return make_pair(t.second, t.first - t.second * (a / b));
}

int main() {
	ll n, a, b;
	scanf("%lld%lld%lld", &n, &a, &b);
	auto t = extended_gcd(a, b);
	ll g = a * t.first + b * t.second;
	if (n%g) {
		puts("NO");
	} else {
		ll x = t.first * (n/g);
		ll y = t.second * (n/g);
		ll dx = b/g, dy = a/g;
		if (x < 0) {
			ll inc = (-x+dx-1)/dx;
			x += inc * dx;
			y -= inc * dy;
		} else if (y < 0) {
			ll inc = (-y+dy-1)/dy;
			x -= inc * dx;
			y += inc * dy;
		}
		if (x<0 || y<0)
			puts("NO");
		else
			printf("YES\n%lld %lld\n", x, y);
	}
	return 0;
}