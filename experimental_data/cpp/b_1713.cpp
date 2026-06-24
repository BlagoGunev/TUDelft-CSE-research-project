#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;

int a[MAX];

int main() {

	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;

	cin >> t;

	while (t--) {

		int n;

		cin >> n;

		for (int i = 1; i <= n; i++) {

			cin >> a[i];

		}

		int cnt1 = 0, cnt2 = 0;

		int st = 1, ed = 1;

		while (st < n && a[st] <= a[st + 1]) {

			st++;

		}

		while (ed < n && a[n - ed] >= a[n - ed + 1]) {

			ed++;

		} 

//		cout << st << " " << ed << endl;

		if (st + ed >= n)  cout << "YES" << endl;

		else cout << "NO" << endl;

	} 

	return 0;

}