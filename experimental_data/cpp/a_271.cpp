#include <iostream>
#include <vector>

#define ll long long

using namespace std;



int main () {

	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);

	ll N;
	cin >> N;


	for (ll k = N + 1; true; k ++) {
		ll used [10] = {0};
		ll ans = 1;

		ll X = k / 1000;
		ans *= ++used[X];

		X = (k/100)%10;
		ans *= ++used[X];

		X = (k%100)/10;
		ans *= ++used[X];

		X = k%10;
		ans *= ++used[X];

		if (ans == 1) {
			cout << k; 
			return 0;
		}
	}

	return 0;
}