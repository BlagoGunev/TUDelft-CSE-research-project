#include<bits/stdc++.h>

#define pb push_back

#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;

typedef pair<ll, ll> PII;

const int N = 5e5 + 10, P = 1e9 + 7, mod = 998244353;

void solve() {

	int n;

	cin >> n;

	vector<int> a(n), b(n), p(n + 1);

	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0; i < n; i++) {

		if (a[i] <= b[i]) continue;

		p[b[i]]++, p[a[i]]--;

	}

	for (int i = 1; i <= n; i++) p[i] += p[i - 1];

	vector<int> ans;

	for (int i = 1; i <= n; i++) {

		bool ok = 1;

		for (int j = i; j <= n; j += i) {

			if (p[j]) {

				ok = 0;

				break;

			}

		}

		if (ok) ans.pb(i);

	}

	cout << ans.size() << "\n";

	for (int x : ans) cout << x << " ";

	cout << "\n";

}

int main(){

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int tt = 1;

	cin >> tt;

	while(tt--) {

		solve();

	}

	return 0;

}