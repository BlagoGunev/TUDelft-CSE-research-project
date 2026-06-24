#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int N = 1e5 + 5;
int n, q, v[N], a[N], f[N];
vector<pair<int, int>> Q;

// void add(int x) {
// 	while (x < N) {
// 		f[x]++;
// 		x += x & -x;
// 	}
// 	return;
// }

// int get(int x) {
// 	int ret = 0;
// 	while (x > 0) {
// 		ret += f[x];
// 		x -= x & -x;
// 	}
// 	return ret;
// }

// int get(int a, int b) {
// 	return get(b) - get(a - 1);
// }

int main() {

	scanf("%d %d", &n, &q);

	int mx_val = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", v + i);
		mx_val = max(mx_val, abs(v[i]));
	}

	while (q--) {
		char c; int x; scanf(" %c %d", &c, &x);
		mx_val = max(mx_val, abs(x));
		if (c == '>') {
			if (x >= -1) Q.eb(0, max(x + 1, 1));
			else {
				Q.eb(2, -x - 1);
				Q.eb(0, -x);
			}
		}
		else {
			assert(c == '<');
			if (x <= 1) Q.eb(1, max(-x + 1, 1));
			else {
				Q.eb(2, x - 1);
				Q.eb(1, x);
			}
		}
	}

	reverse(Q.begin(), Q.end());

	// for (auto x : Q) {
	// 	printf("%d %d\n", x.first, x.second);
	// }

	int assigned = mx_val + 1, cur_tg = 0;
	for (auto x : Q) {
		int tp, i; tie(tp, i) = x;
		if (tp == 2) {
			f[min(i, assigned - 1)]++;
			// f[i]++;
		}
		else {
			while (assigned > i) {
				assigned--;
				cur_tg += f[assigned];
				a[assigned] = tp ^ (cur_tg & 1);
			}
		}
	}

	while (assigned > 1) {
		assigned--;
		cur_tg += f[assigned];
		if (cur_tg & 1) a[assigned] = 2;
		else a[assigned] = 3;
	}

	for (int i = 0; i < n; i++) {
		int ab = abs(v[i]);
		if (a[ab] == 2) v[i] *= -1;
		else if (a[ab] == 1) v[i] = ab;
		else if (a[ab] == 0) v[i] = -ab;
		printf("%d ", v[i]);
	}

}