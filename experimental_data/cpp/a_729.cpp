#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	int b;
	cin >> b;
	cin >> s;
	char o = 'o', g = 'g';
	int i = 1;
	while (s.find("go", i) != string::npos) {
		i = s.find("go", i);
		if (s[i - 1] == o || s[i - 1] == '!') {
			s.replace(i, 2, "!!");
			
		}
		i++;
	}
	while (s.find("!!!!") != string::npos) {
		int i = s.find("!!!!");
		s.replace(i, 4, "!!");
	}
	for (int i = 1;  i < s.size(); i++) {
		if (s[i] == '!' && s[i - 1] == '!' && s[i - 2] == o) {
			s.replace(i - 2, 3, "***");
		}
	}
	cout << s;
	return 0;
}