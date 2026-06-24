#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int ans,n;
		cin >> n;
		vector<int>a(n + 1);
		vector<int>b(n + 1);
		ans = 0;
		
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			b[a[i]] = i;
		}
		for (int i = 1; i < n; ++i) {
			if (b[i] > b[i + 1]) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}