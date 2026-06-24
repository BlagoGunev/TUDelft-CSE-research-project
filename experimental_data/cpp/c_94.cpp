#include<iostream>

#include<cstring>

using namespace std;

int n, m;

int main() {

	int a, b;

	while(cin >> n >> m >> a >> b){

		if (m == 1 || a == b) {

			cout << 1 << endl;

			continue;

		}

		int ans = 0;

		int sum = b - a + 1;

		if (sum == n) {

			cout << 1 << endl;

			continue;

		}

		int temp = a % m;

		if (temp == 1 && b == n) {

			cout << 1 << endl;

			continue;

		}

		if (temp != 1) {

			ans++;

			if (temp == 0)

				sum--;

			else

				sum -= (m - temp + 1);

		}

		if (sum > 0) {

			if (sum >= m)

				ans++;

			if (sum % m)

				ans++;

			temp = a % m;

			if (temp == 0)

				temp = 1;

			else

				temp = (m - a % m + 1);

			if (ans == 3 && ((b % m + temp) == m || b == n))

				ans--;

		}

		cout << ans << endl;

	}

	return 0;

}