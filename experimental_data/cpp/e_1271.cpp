#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll N, K;

ll even() {
	ll s = 1;
	ll e = N / 2;
	ll m;
	while (s < e) {
		m = (s + e) / 2 + (s + e) % 2;
		ll tmps = m * 2;
		ll tmpe = tmps + 1;
		ll sum = 0;
		while (1) {
			if (tmps > N) break;
			if (tmpe % 2 == 0) tmpe++;
			if (tmpe > N) tmpe = N;
			sum += tmpe - tmps + 1;
			if (tmpe == N) break;
			tmps *= 2;
			tmpe *= 2;
		}
		if (sum < K) e = m - 1;
		else s = m;
	}
	return 2 * e;
}
ll odd() {
	ll s = 0;
	ll e = N / 2;
	if (N % 2 == 0) e--;
	ll m;
	while (s < e) {
		m = (s + e) / 2 + (s + e) % 2;
		ll tmps = m * 2 + 1;
		ll tmpe = tmps;
		ll sum = 0;
		while (1) {
			if (tmps > N) break;
			if (tmpe % 2 == 0) tmpe++;
			if (tmpe > N) tmpe = N;
			sum += tmpe - tmps + 1;
			if (tmpe == N) break;
			tmps *= 2;
			tmpe *= 2;
		}
		if (sum < K) e = m - 1;
		else s = m;
	}
	return 2 * e + 1;
}
int main() {
	cin >> N >> K;
	if (N == K) cout << 1;
	else cout << max(even(), odd());
}