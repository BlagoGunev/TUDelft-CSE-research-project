#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(v)              ((v).begin()), ((v).end())



int main() {



	int t;



	cin >> t;

	for (int i = 0; i < t; ++i) {

		int n, p;

		cin >> n >> p;

		int s = 0;

		bool close = false;

		for (int k = 1; k <= n; ++k) {

			for (int k1 = k + 1; k1 <= n; ++k1) {

				cout << k << " " << k1 << endl;

				;

				s++;

				if (s == (2*n + p)) {

					close = true;

					break;

				}

			}

			if (close)

				break;



		}



	}

	return 0;

}