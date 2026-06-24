#include <iostream>

using namespace std;



const int N = 4000 + 100;



bool used[N];



int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int x, k;

	cin >> x >> k;

	int tot = 0;

	for (int i = 0; i < k; ++i) {

		int t, n1, n2 = 0;

		cin >> t;

		if (t == 2) {

			cin >> n1;

			used[n1] = true;

			++tot;

		} else {

			cin >> n1 >> n2;

			used[n1] = used[n2] = true;

			tot += 2;

		}

	}

	int mn = 0;

	used[0] = true;

	for (int lst = x, i = x-1; i >= 0; --i) {

		if (!used[i]) continue;

		mn += (lst - i) / 2;

		lst = i;

	}

	int mx = x-1 - tot;

	cout << mn << ' ' << mx << '\n';

}