#include <bits/stdc++.h>



using namespace std;



int main() {

#ifndef ONLINE_JUDGE

	freopen("C:\\Users\\Omar Mohamed\\ClionProjects\\Go\\input.in", "r", stdin);

#endif

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

	int n, k;

	cin >> n >> k;

	int baseN = n;

	string baseA[3];

	string a[243];

	for (int i = 0; i < n; ++i) {

		cin >> a[i];

		baseA[i] = a[i];

	}

	--k;

	string result[243];

	for (int w = 0; w < k; ++w) {

		for (int i = 0; i < n; ++i) {

			for (int j = 0; j < n; ++j) {

				if (a[i][j] == '.') {

					for (int u = 0; u < baseN; ++u) {

						result[i * baseN + u] += baseA[u];

					}

				} else {

					for (int u = 0; u < baseN; ++u) {

						for (int v = 0; v < baseN; ++v)

							result[i * baseN + u] += "*";

					}

				}

			}

		}

		for (int i = 0; i < 243; i++) {

			a[i] = result[i];

			result[i] = "";

		}

		n *= baseN;

	}



	for (int i = 0; i < n; ++i)

		cout << a[i] << endl;



	return 0;

}