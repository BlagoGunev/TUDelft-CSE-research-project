#include<bits/stdc++.h>



using namespace std;

int p[200010];

int find(int x) {

	if (x != p[x]) p[x] = find(p[x]);

	return p[x];

}

void solve() {

	int n;

	cin >> n;

	for (int i = 1; i <= 2 * n; i++) p[i] = i;

	stack<int>s;

	string str;

	cin >> str;

	for (int i = 0; i < (int)str.length(); i++) {

		if (str[i] == '(') {

			s.push(i + 1);

		}

		else {

			int x = find(s.top()), y = find(i + 1);

			p[y] = x;

			s.pop();

			if (s.size()) {

				p[x] = find(s.top() + 1);

			}

			else p[x] = 1;

		}

	}

	int ans = 0;

	for (int i = 1; i <= 2 * n; i++) {

		if (p[i] == i) ans++;

	}

	cout << ans << '\n';

}

int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

	int t;

	cin >> t;

	while (t--) {

		solve();

	}

	return 0;

}