#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long a, b, c;
		cin >> a >> b >> c;

		long long d = (a + b + c) - 1;
		cout << d << endl;
	}
}