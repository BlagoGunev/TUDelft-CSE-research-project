#include <cinttypes>
#include <inttypes.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <utility>
#include <cmath>
#include <algorithm>
#include <set>
#include <stack>
#include <functional>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;

vector<int> p;

int dsu_get(int v) {
	return (v == p[v])
		? v
		: (p[v] = dsu_get(p[v]));
}

void dsu_join(int a, int b) {
	a = dsu_get(a);
	b = dsu_get(b);
	if (rand() & 1)
		swap(a, b);

	if (a != b)
		p[a] = b;
}


int main() {

#ifdef _DEBUG
	freopen("data.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	if (2 * k > n) {
		k = n - k;
	}

	int x = 1, cycles = 0;
	long long ans = 1ll;
	for (int i = 0; i < n; ++i) {
		if (x + k > n) {
			ans += 2 * cycles + 1;
			x = x + k - n;
			++cycles;
		}
		else {
			ans += 2 * cycles;
			x += k;
		}
		++ans;
		if (x == 1) --ans;
		cout << ans << ' ';
	}

	return 0;
}