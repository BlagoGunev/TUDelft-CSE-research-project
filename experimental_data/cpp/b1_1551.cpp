#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t) {
		string s;
		cin >> s;
		int a[26] = { 0 };
		for (int i = 0;; i++) {
			if (s[i] == '\0') break;
			a[s[i] - 97]++;
		}
		int zhong = 0, final = 0;
		for (int i = 0; i < 26; i++) {
			if (a[i] == 1) zhong++;
			else if (a[i] > 1) final++;
		}
		final = final + zhong / 2;
		cout << final << endl;

		t--;
	}
	return 0;
}