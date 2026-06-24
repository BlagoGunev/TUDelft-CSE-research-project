#include <bits/stdc++.h>



using namespace std;



int main() {

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	cout.tie(nullptr);

//    freopen("name.in", "r", stdin);

//    freopen("output.txt", "w+", stdout);



	int t; cin >> t;

	while(t--) {

		int n, k, strake = 1, ans = 0; cin >> n >> k;

		vector<int> a(n);

		for (int i = 0; i < n; ++i) cin >> a[i];

		for (int i = 1; i < n; ++i) {

			if(2*a[i] > a[i-1]) strake++;

			else {

				ans += max(0, strake - k);

				strake = 1;

			}

		}

		ans += max(0, strake - k);



		cout << ans << "\n";

	}



	return 0;

}