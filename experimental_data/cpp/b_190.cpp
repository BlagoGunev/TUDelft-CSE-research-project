#include <bits/stdc++.h>

using namespace std;



int main() {



	int x1, y1, r1;

	int x2, y2, r2;

	cin >> x1 >> y1 >> r1;

	cin >> x2 >> y2 >> r2;



	double d = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));

//	cout << d<<endl;

//	cout<<d<<endl;;

	double ans = 0;



	if (d > r1 + r2) {

		ans = (d - r1 - r2) / 2.0;

	} else if (d < r2 - r1) {

		ans = (r2 - d - r1) / 2.0;

	} else if (d < r1 - r2) {

		ans = (r1 - d - r2) / 2.0;

	}



	cout << setprecision(18) << ans;



	return 0;

}