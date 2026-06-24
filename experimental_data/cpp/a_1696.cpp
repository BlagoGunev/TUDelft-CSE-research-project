#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define ll long long

int cnt = 0;

void solve() {

	int n, z;

	cin >> n >> z;

	int ret = 0;

	for (int i = 0; i < n; ++ i) {

		int x;

		cin >> x;

		ret = max(ret, x | z);

	}

	cout << ret << endl;

}

int main() {

	ios_base::sync_with_stdio(0); 

    cin.tie(0); cout.tie(0);

	int t;

	cin >> t;

	while (t --) {

		solve();

	}

	return 0;

}