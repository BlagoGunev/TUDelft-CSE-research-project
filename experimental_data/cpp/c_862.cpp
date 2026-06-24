#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int fix = (1 << 18);

int main() {

	int n, x;
	cin >> n >> x;

	if (n == 2 && x == 0) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	int XOR = 0;
	for (int i = 0; i < n - 1; i++) {
		XOR ^= i;
	}
	int rem = XOR ^ x;

	if (rem >= n - 1) {
		for (int i = 0; i < n - 1; i++)
			cout << i << " ";
		cout << rem << endl;
	} else {
		bool b = false;
		for (int i = 0; i < n - 1; i++) {
			if (i != rem && !b) {
				b = true;
				cout << i + fix << " ";
			} else {
				cout << i << " ";
			}
		}
		cout << rem + fix << endl;
	}

	return 0;
}