#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 200005;
ll lastused[MAXN];
int X[MAXN];
struct cmp {
	bool operator()(int a, int b) {
		if (X[a] != X[b]) return X[a] < X[b];
		if (lastused[a] != lastused[b]) return lastused[a] < lastused[b];
		return a < b;
	}
};
int main() {
	int N, K, M;
	scanf("%d%d%d", &N, &K, &M);
	set<int, cmp> cars;
	set<pair<ll, int>> events;
	for (int i = 1; i <= K; ++i) {
		scanf("%d", &X[i]);
		cars.insert(i);
	}
	ll t = 0;
	for (int i = 0; i < M; ++i) {
		ll ot;
		int a, b;
		scanf("%lld%d%d", &ot, &a, &b);
		t = max(t, ot);
		// Process event queue up to this time
		while (!events.empty()) {
			ll timefree;
			int car;
			tie(timefree, car) = *events.begin();
			if (timefree > t) break;
			cars.insert(car);
			events.erase(events.begin());
		}
		if (cars.empty()) {
			t = events.begin()->first;
			while (!events.empty()) {
				ll timefree;
				int car;
				tie(timefree, car) = *events.begin();
				if (timefree > t) break;
				cars.insert(car);
				events.erase(events.begin());
			}
		}
		X[0] = a;
		lastused[0] = -1;
		auto it = cars.lower_bound(0);
		int dist = INT_MAX;
		if (it != cars.end()) dist = min(dist, X[*it] - a);
		if (it != cars.begin()) dist = min(dist, a - X[*prev(it)]);
		int take = -1;
		if (it != cars.end() && X[*it] - a == dist) take = *it;
		if (it != cars.begin() && a - X[*prev(it)] == dist) {
			X[0] = a - dist;
			it = cars.lower_bound(0);
			if (take == -1 || lastused[*it] < lastused[take] || (lastused[*it] == lastused[take] && *it < take))
				take = *it;
		}
		cars.erase(take);
		ll wait = t - ot + abs(a - X[take]);
		printf("%d %lld\n", take, wait);
		ll timefree = t + abs(b - a) + abs(a - X[take]);
		X[take] = b;
		lastused[take] = timefree;
		events.insert({timefree, take});
	}
}