#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define reset(a, v) memset((a), v, sizeof(a))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N = 100005;

int n, k;
int occ[N];
bitset<N> isPrime;
vi primes;
ll ans;

void sieve() {
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for (ll i = 2; i < N; i++) {
		if (!isPrime[i]) continue;
		primes.push_back(i);
		for (ll j = i * i; j < N; j += i) {
			isPrime[j] = 0;
		}
	}
}

vii tmp;

void getPrimeFactors(int x) {
	int idx = 0;
	int p = primes[idx];
	while (1ll * p * p <= x) {
		if (x % p == 0) {
			int cnt = 0;
			while (x % p == 0) {
				x /= p;
				cnt++;
			}
			tmp.push_back(make_pair(p, cnt));
		}
		idx++;
		p = primes[idx];
	}

	if (x != 1) tmp.push_back(make_pair(x, 1));
}

int exp(int base, int p) {
	ll ret = 1;
	for (int i = 1; i <= p; i++) {
		ret *= base;
		if (ret >= N) return -1;
	}
	return ret;
}

void process(int x) {
	getPrimeFactors(x);
	int goal = 1, adds = 1;
	for (ii p : tmp) {
		int mods = p.se % k;
		if (mods == 0) continue;
		adds *= exp(p.fi, mods);
		if (goal == -1) continue;
		int resGoal = exp(p.fi, k - mods);
		if (resGoal != -1) goal *= resGoal;
		else goal = -1;
	}
	if (goal != -1) ans += occ[goal];
	occ[adds]++;
	tmp.clear();
}

int main() {
	sieve();
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		process(x);
		// printf("ans = %I64d\n", ans);
	}
	printf("%I64d\n", ans);
	return 0;
}