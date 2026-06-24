#include <iostream>

using namespace std;

int t;



int main() {

	cin >> t;

	while (t--) {

		int n;

		cin >> n;

		if (n % 4 == 0)

			cout << n / 4 << " " << n / 4 << " " << n / 4 << " " << n / 4 << endl;

		else {

			if (n % 2 == 0) {

				cout << (n - 2) / 2 - 1 << " " << (n - 2) / 2 + 1 << " " << "1" << " " << "1" << endl;

			} else {

				cout << (n - 2) / 2 << " " << (n - 2) / 2 + 1 << " " << "1" << " " << "1" << endl;

			}



		}

	}

	return 0;

}