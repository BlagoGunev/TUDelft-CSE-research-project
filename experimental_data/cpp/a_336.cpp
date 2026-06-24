#include <iostream>

#include <cmath>

using namespace std;



#define ll long long



int main() {

	

	ll x, y, sum;

	

	cin >> x >> y;

	

	sum = abs(x) + abs(y);

	

	if (x > 0 && y > 0) {

		cout << 0 << " " << sum << " " << sum << " " << 0 << endl;

	} else if (x < 0 && y > 0) {

		cout << -1*sum << " " << 0 << " " << 0 << " " << sum << endl;

	} else if (x < 0 && y < 0) {

		cout << -1*sum << " " << 0 << " " << 0 << " " << -1*sum << endl;

	} else {

		cout << 0 << " " << -1*sum << " " << sum << " " << 0 << endl;

	}

	

	return 0;

}