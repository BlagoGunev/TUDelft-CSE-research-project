#include <bits/stdc++.h>
using namespace std;

string s = "aeiou";

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < n / 5; ++j) cout << s[i];
			if (i < (n % 5)) cout << s[i];
		}
		cout << "\n";
	}

	return 0;
}