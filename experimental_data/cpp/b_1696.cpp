#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

#define ll long long

int cnt = 0;

void solve() {

	int n;

	cin >> n;

	vector<int> arr;

	int f = 0;

	for (int i = 0; i < n; ++ i) {

		int x;

		cin >> x;

		f = max(f, (int)(x > 0));

		arr.push_back(x);

	}

	if (f == 0) cout << 0 << endl;

	else {

		int f1 = 0;

		int i = 0, j = n - 1;

		while (arr[i] == 0) ++ i;

		while (arr[j] == 0) -- j;

//		cout << i << " " << j << endl;

		for (int k = i; k <= j; ++ k) {

			f1 = (arr[k] == 0);

			if (f1) break;

		} 

		if (f1) cout << 2 << endl;

		else cout << 1 << endl;

	}



	

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