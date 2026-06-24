#include <iostream>

#include <string>

#include <algorithm>

#include <vector>



using namespace std;



int main() {

	long long n, a, res = 0;

	vector < long long> vec;

	cin >> n;

	for (int j = 0; j < n; j++) {

		cin >> a;

		if (j == 0) vec.push_back(a);

		else {

			for (int i = 0; i < vec.size(); i++) {

				if (a > vec[i]) {

					vec.insert(vec.begin() + i, a);

					break;

				}

				else if (a == vec[i]) {

					a--;

				}

				if (i == vec.size() - 1) {

					vec.push_back(a);

					break;

				}

				if (a == 0) break;

			}

		}

		res += a;

	}

	cout << res << endl;

	return 0;

}