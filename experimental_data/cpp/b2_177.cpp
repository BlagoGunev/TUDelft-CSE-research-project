#include <bits/stdc++.h>

using namespace std;

bool isprime(long long n) {

	for (int i = 2; i * i <= n; i++)

		if (n % i == 0)

			return false;

	return true;

}

int main() {

	long long n;

	cin >> n;

	if (isprime(n)) {

		cout << n + 1;

		return 0;

	}

	long long sum = n;

	while (n > 1) {

		for (long long i = 2; i <= n; i++) {

			if (n % i == 0) {

				n /= i;

				sum += n;

				break;

			}

		}

	}

	cout << sum << endl;

}