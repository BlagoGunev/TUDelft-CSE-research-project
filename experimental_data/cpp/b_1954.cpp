//
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<bitset>
#include<string>

using namespace std;

#define int long long

void solve() {
	int n, m, k, r
		;

	cin >> n
		;


















	vector<int> b;
	int ans1 = 0;
	vector<int> answer(n, 0);

	for (int i = 0; i < 0 + n
		; i++)
	{
		int f = 0;
		cin >> f;
		ans1 += f;

		b.push_back(f);
	}

	int el = b[0];
	answer[0] = 1;

	int minn = 1e9;

	for (int i = 1; i < n; ++i) {
		if (b[i] == el) {
			answer[i] = 1 + answer[i - 1];
		}
		else {
			minn = min(minn, answer[i - 1]);
		}
	}
	minn = min(minn, answer.back());

	if (n <= 2) {
		cout << -1 << '\n';
	}
	else {
		if (minn == n) {
			cout << -1 << '\n';
		}
		else
		cout << minn << '\n';
	}

	//cout << ans1 << '\n';
	//for (auto now : answer) cout << now << ' '; cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t = 1;
	cin >> t;
	while (t--) solve();
}
//*/