#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll M = 998244353;
ll a[202020], b[202020];
vector<ll>av, bv;
ll pow(ll a, ll b) {
	if (!b)return 1;
	ll r = pow(a, b / 2);
	r = (r * r) % M;
	if (b % 2)r = (r * a) % M;
	return r;
}
int main() {
	ll T, n, q, i, t, r;
	scanf("%lld", &T);
	while (T--) {
		scanf("%lld%lld", &n, &q);
		av.clear();
		bv.clear();
		for (i = 0;i < n;i++) {
			scanf("%lld", &a[i]);
			av.push_back(a[i]);
		}
		sort(av.begin(), av.end());
		for (i = 0;i < n;i++) {
			scanf("%lld", &b[i]);
			bv.push_back(b[i]);
		}
		sort(bv.begin(), bv.end());
		r = 1;
		for (i = 0;i < n;i++) {
			r = (r * min(av[i], bv[i])) % M;
		}
		while (q--) {
			printf("%lld ", r);
			scanf("%lld%lld", &t, &i);
			i--;
			if (t == 1) {
				a[i]++;
				i = lower_bound(av.begin(), av.end(), a[i]) - av.begin();
				av[--i]++;
				if (av[i] <= bv[i]) {
					r = (r * pow(av[i] - 1, M - 2)) % M;
					r = (r * av[i]) % M;
				}
			}
			else {
				b[i]++;
				i = lower_bound(bv.begin(), bv.end(), b[i]) - bv.begin();
				bv[--i]++;
				if (bv[i] <= av[i]) {
					r = (r * pow(bv[i] - 1, M - 2)) % M;
					r = (r * bv[i]) % M;
				}
			}
		}
		printf("%lld\n", r);
	}
	return 0;
}