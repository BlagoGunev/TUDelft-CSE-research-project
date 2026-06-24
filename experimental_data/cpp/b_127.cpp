#include <bits/stdc++.h>

using namespace std;



int occ[101];

int main() {

	int n; cin >> n;

	for(int i = 0; i < n; i ++){

		int t; cin >> t;

		occ[t]++;

	}

	int sum = 0;

	for(int i = 1; i <= 100; i ++){

		sum += occ[i] - occ[i] % 2;

	}

	cout << sum / 4 << endl;

	return 0;

}