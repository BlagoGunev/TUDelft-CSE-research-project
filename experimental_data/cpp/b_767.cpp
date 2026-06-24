#include <bits/stdc++.h>

using namespace std;

#include <cstdio>

const int maxN = 100001;
long long v[maxN];

int main() {
	//freopen("test.in", "r", stdin);
	int N;
	long long ts, tf, t;
	scanf("%lld %lld %lld", &ts, &tf, &t);
	scanf("%d", &N);

	for(int i = 1; i <= N; ++ i)
		scanf("%lld", &v[i]);
	
	long long empty = ts, waited = (1LL << 60), ans = 0;

	for(int i = 1; i <= N; ++ i) {
		if(empty == ts and v[i] > ts) {
			ans = ts;
			waited = 0;
		}

		if(v[i] > empty) {
			if(t + empty <= tf) {
				waited = 0;
				ans = empty;
			} else
				waited = t + v[i];
		} else if(v[i] <= empty) {
			if(empty + t <= tf) {
				if(waited > empty - (v[i] - 1)) {
					ans = v[i] - 1;
					waited = empty - (v[i] - 1);
				}
			}
			empty += t;
		}
	}

	if(empty + t <= tf) {
		waited = 0;
		ans = empty;
	}

	printf("%lld\n", ans);
	return 0;
}