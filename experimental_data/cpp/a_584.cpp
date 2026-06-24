#include <bits/stdc++.h>



using namespace std;



int n, m;



int main () {

	cin >> n >> m;

	if (m != 10) {

		for (int i = 1; i <= n; ++i) {

			cout << m;

		} 

	} else {

		if(n == 1) {

			cout << -1;

		} else {

			cout << 1;

			for(int i = 1; i < n; ++i) {

				cout << 0;

			} 

		}

	}

	return 0;

}