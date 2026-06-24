#include <bits/stdc++.h>

using namespace std;

struct Project {
	int a, b;
};

void maximize(int &a, int b) {
	if (a < b) a = b;
}

int main() {
	int n, r;
	cin >> n >> r;
	
	vector<Project> pos, neg;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		if (b >= 0) {
			pos.push_back({a, b});
		} else {
			neg.push_back({a, -b});
		}
	}

	sort(begin(pos), end(pos), [](const Project &x, const Project &y) { return x.a < y.a; });
	int res = 0;
	for (auto it : pos) {
		if (r >= it.a) {
			r += it.b;
			++res;
		}
	}

	sort(begin(neg), end(neg), [](const Project &x, const Project &y) { return x.a - x.b > y.a - y.b; });
	vector< vector<int> > dp(neg.size() + 1, vector<int>(r + 1, -1));
	dp[0][r] = 0;
	for (int i = 0; i < neg.size(); ++i) {
		for (int j = 0; j <= r; ++j) if (dp[i][j] >= 0) {
			if (j >= max(neg[i].a, neg[i].b)) {
				maximize(dp[i + 1][j - neg[i].b], dp[i][j] + 1);
			}
			maximize(dp[i + 1][j], dp[i][j]);
		}
	}
	cout << res + *max_element(begin(dp[neg.size()]), end(dp[neg.size()])) << endl;
}