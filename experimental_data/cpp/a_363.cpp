#include <iostream>

#include <cmath>

#include <string>



using namespace std;



int main()

{

	int n;

	cin >> n;

	if (n == 0) {

		cout << "O-|-OOOO\n";

	}

	while (n) {

		if (n % 10 == 0) {

			cout << "O-|-OOOO\n";

		}

		else if (n % 10 == 1) {

			cout << "O-|O-OOO\n";

		}

		else if (n % 10 == 2) {

			cout << "O-|OO-OO\n";

		}

		else if (n % 10 == 3) {

			cout << "O-|OOO-O\n";

		}

		else if (n % 10 == 4) {

			cout << "O-|OOOO-\n";

		}

		else if (n % 10 == 5) {

			cout << "-O|-OOOO\n";

		}

		else if (n % 10 == 6) {

			cout << "-O|O-OOO\n";

		}

		else if (n % 10 == 7) {

			cout << "-O|OO-OO\n";

		}

		else if (n % 10 == 8) {

			cout << "-O|OOO-O\n";

		}

		else if (n % 10 == 9) {

			cout << "-O|OOOO-\n";

		}

		n /= 10;

	}

	return 0;

}