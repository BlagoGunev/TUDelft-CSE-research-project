#include<cstdio>
#include<cmath>

static int d[20010];
static int lens[20010];

int main() {
	int n, T;
	scanf("%d %d", &n, &T);
	int t = n;
	if (T < n) {
		t = T;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &d[i]);
	}

	for (int j = n; j < n * (t + 1); ++j) {
		d[j] = d[j - n];
	}

	for (int i = 0; i < n * (t + 1); ++i) {
		lens[i] = 1;
	}
	int m = 0;
	for (int i = 1; i < n * (t + 1); ++i) {
		int start = i - 2 * n;
		if (start < 0) {
			start = 0;
		}
		for (int j = start; j < i; ++j) {
			if ((d[j] <= d[i]) && (lens[j] + 1 > lens[i])) {
				lens[i] = lens[j] + 1;
			}
		}
	}
	int m1 = 0;
	for (int i = n * (t - 1); i < n * t; ++i) {
		if (lens[i] > m1) {
			m1 = lens[i];
		}
	}
	int m2 = 0;
	for (int i = n * t; i < n * (t + 1); ++i) {
		if (lens[i] > m2) {
			m2 = lens[i];
		}
	}
	int delta = m2 - m1;
	m = m1;
	if (T > t ) {
		m += (T - t) * delta;
	}
	printf("%d", m);
	return 0;
}