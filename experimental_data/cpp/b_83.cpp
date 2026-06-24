#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long i64;
template<class T> int size(const T &a) {
	return int(a.size());
}
template<class T> T sqr(const T &a) {
	return a * a;
}

const int max_n = 100100;
int a[max_n];
int main() {
#ifdef pperm
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	i64 k;
	cin >> k;
	i64 sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	if (sum < k) {
		printf("-1");
		return 0;
	}
	int l = 0, r = int(1e9 + 0.1), x = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		i64 cur = 0;
		for (int i = 0; i < n; i++) {
			cur += min(mid, a[i]);
		}
		if (cur <= k) {
			x = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	for (int i = 0; i < n; i++) {
		k -= min(a[i], x);
	}
	for (int i = 0; i < n; i++) {
		if (k == 0) {
			for (int j = 0; j < n; j++) {
				if (a[(i + j) % n] > x) {
					printf("%d ", (i + j) % n + 1);
				}
			}
			break;
		}
		if (a[i] > x) {
			if (k) {
				k--;
				a[i]--;
			}
		}
	}
	return 0;
}