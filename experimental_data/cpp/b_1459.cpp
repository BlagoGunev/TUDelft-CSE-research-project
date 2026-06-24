#include <iostream>

#include <vector>

#include <algorithm>

#include <string>

#include <map>

#define ll long long

using namespace std;

int main() {

	ios::sync_with_stdio(false);

	cin.tie(0);

	int n;

	cin >> n;

	if (n % 2) {

		cout << 2 * (n / 2 + 1) * (n / 2 + 2) << endl;

	}

	else {

		cout << (n / 2 + 1) * (n / 2 + 1) << endl;

	}

}