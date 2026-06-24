#include <bits/stdc++.h>

using namespace std;



int main() {

	int t;

	cin >> t;

	while(t--){

		int n;

		cin >> n;

		// cout << fixed << setprecision(6);

		double temp = 2.0000000000000*n;

		double pi = 3.14159265358979323;

		double res = 360.0000000001 / temp;

		// double res = 6.92307692308;

		double x = res;

		double z(0.00000000000000);

		// cout << x << endl;

		while(x < 90.000000000000000){

			// cout << fixed << setprecision(6);

			double r = x * pi;

			r /= 180.000000000000000;

			z += 2 * sin(r);

			x += res;

		}

		 //cout << setprecision(3) <<z;

		double ans = 90.000000000000000 * pi;

		ans /= 180.000000000000000;

		z += sin(ans);

		cout << fixed << setprecision(9) <<z << endl;

	}

	return 0;

}