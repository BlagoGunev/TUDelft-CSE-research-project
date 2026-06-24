#include <iostream>

#include <vector>



#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)



using namespace std;



const long long INF = 1e18;



vector<int> a, b;



signed main() {

	fastio;

	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {

		int x;

		cin >> x;

		a.push_back(x);

	}

	for (int i = 0; i < n; ++i) {

		int x;

		cin >> x;

		b.push_back(x);

	}

	int sa = 0, sb = 0;

	for (int i = 0; i < n; ++i)

		if (a[i] == 1 && b[i] == 0)

			++sa;

	for (int i = 0; i < n; ++i)

		if (a[i] == 0 && b[i] == 1)

			++sb;

	if (sa == 0)

		cout << -1;

	else

		cout << sb / sa + 1;

}