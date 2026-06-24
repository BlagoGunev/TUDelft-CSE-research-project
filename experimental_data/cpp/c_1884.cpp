#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
	int n, m, ans = 0; cin >> n >> m;
	vector<int> lisan;
	vector<PII> seg(n + 1);
	for (int i = 1; i <= n; i ++ ) {
		cin >> seg[i].first >> seg[i].second;
		lisan.push_back(seg[i].first);
		lisan.push_back(seg[i].second);
	}
	sort(lisan.begin(), lisan.end());
	lisan.erase(unique(lisan.begin(), lisan.end()), lisan.end());
	unordered_map<int, int> mp;
	for (int i = 0; i < lisan.size(); i ++ ) mp[lisan[i]] = i + 1;
	vector<int> c(lisan.size() + 2);
	for (int i = 1; i <= n; i ++ ) {
		if (seg[i].first == 1) continue;
		c[mp[seg[i].first]] ++;
		c[mp[seg[i].second] + 1] --;
	}
	for (int i = 1; i <= lisan.size(); i ++ ) {
		c[i] += c[i - 1];
		ans = max(ans, c[i]);
	}
	c.assign(lisan.size() + 2, 0);
	for (int i = 1; i <= n; i ++ ) {
		if (seg[i].second == m) continue;
		c[mp[seg[i].first]] ++;
		c[mp[seg[i].second] + 1] --;
	}
	for (int i = 1; i <= lisan.size(); i ++ ) {
		c[i] += c[i - 1];
		ans = max(ans, c[i]);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T -- ) solve();
	return 0;
}