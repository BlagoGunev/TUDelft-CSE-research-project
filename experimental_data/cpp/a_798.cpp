#include <iostream>
#include <string>

using namespace std;

int main() {

	string in;
	cin >> in;
	int l = in.length();
	if (l == 1) {
		cout << "YES";
	} else {
		int c = 0;
		if (l%2 == 0) {
			for (int i = 0; i < l/2; i++) {
				if (in.at(i) != in.at(l-i-1)) {
					c++;
				}
			}
			if (c == 1) {
				cout << "YES";
			} else {
				cout << "NO";
			}
		} else {
			for (int i = 0; i < l/2; i++) {
				if (in.at(i) != in.at(l-i-1)) {
					c++;
				}
			}
			if (c == 0||c == 1) {
				cout << "YES";
			} else {
				cout << "NO";
			}
		}

	}
	
	return 0;
}