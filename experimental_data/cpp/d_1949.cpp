#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
	fast_io;

	int n; cin >> n;
	vector<string> grid(n);
	for (auto &s : grid) cin >> s;

	if (n < 8) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (grid[i][j] == '?')
					grid[i][j] = grid[j][i] = 'F';
			}
		}
	}

	vector<tuple<int, int, int>> edges;

	string ch = "FS";
	array<int, 2> cnt = {0, 0};
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (grid[i][j] != '?') {
				int x = grid[i][j] == ch[1];
				cnt[x]++;
				edges.emplace_back(i, j, x);
			}
		}
	}
	int who = cnt[1] > cnt[0];

	int qt = (n - 1) - (3*n + 3) / 4;

	pair<int, int> best = {-1, 0};
	for (int mask = 0; mask < (1 << n); mask++) {
		if (__builtin_popcount(mask) != qt) continue;
		int cur = 0;
		bool ok = true;
		for (auto [i, j, x] : edges) {
			if (x == who) cur += (mask >> i & 1) && (mask >> j & 1);
			else {
				if (mask >> i & 1) ok = false;
				if (mask >> j & 1) ok = false;
			}
		}
		if (!ok) continue;
		best = max(best, {cur, mask});
	}

	auto [_, mask] = best;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (grid[i][j] == '?') {
				if (mask >> i & 1) grid[i][j] = grid[j][i] = ch[who];
				else if (mask >> j & 1) grid[i][j] = grid[j][i] = ch[who];
				else grid[i][j] = grid[j][i] = ch[!who];
			}
		}
	}

	for (auto x : grid) cout << x << endl;

	return 0;
}