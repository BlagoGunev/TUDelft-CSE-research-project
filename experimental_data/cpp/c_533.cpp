#ifdef _MSC_VER

#define _CRT_SECURE_NO_WARNINGS

#endif



#include <bits/stdc++.h>



using namespace std;

#define OO ll(1e18)

typedef unsigned long long ull;

typedef long long ll;



int main() {

	int xp, yp, xv, yv;

	cin >> xp >> yp >> xv >> yv;

	int d = 0, f = 0;

	while (xv - 1 >= 0 && yv - 1 >= 0 && !f) {

		xv--;

		yv--;

		d++;

		if (abs(xv - xp) + abs(yv - yp) <= d)f = 1;

	}

	while (xv - 1 >= 0 && !f) {

		xv--;

		d++;

		if (abs(xv - xp) + abs(yv - yp) <= d)f = 1;

	}

	while (yv - 1 >= 0 && !f) {

		yv--;

		d++;

		if (abs(xv - xp) + abs(yv - yp) <= d)f = 1;

	}

	//cout << d << "\n";

	if (f)cout << "Polycarp\n";

	else cout << "Vasiliy\n";

}