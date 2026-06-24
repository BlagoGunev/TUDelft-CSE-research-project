#include <bits/stdc++.h>
using namespace std;

void i8d() {
	string s; cin >> s;
	int occur[26];
	for(int i = 0; i < 26; i++) occur[i] = 0;
	int n = (int) s.size();
	set<int> present;
	for(int i = 0; i < n; i++) {
		occur[s[i] - 'a']++;
		present.insert(s[i] - 'a');
	}
	for(int i = 0; i < 26; i++) {
		if(occur[i] == 1) {
			char c = 'a' + i; cout << c;
			for(int j = 0; j < 26; j++) {
				if(j != i) {
					for(int k = 0; k < occur[j]; k++) {
						char c = 'a' + j; cout << c;
					}
				}
			}
			cout << '\n';
			return;
		}
	}
	if(present.size() >= 2) {
		auto it = present.begin();
		int fl = *it; it++;
		int sl = *it;
		int rem = n - occur[fl];
		if(rem >= occur[fl] - 2) {
			char c = 'a' + fl; cout << c << c;
			sort(s.begin(), s.end());
			int start = occur[fl];
			occur[fl] -= 2;
			for(int i = start; i < n; i++) {
				cout << s[i];
				if(occur[fl] > 0) {
					char c = 'a' + fl; cout << c;
					occur[fl]--;
				}
			}
			cout << '\n';
		} else {
			char c = 'a' + fl; cout << c;
			c = 'a' + sl; cout << c;
			occur[fl]--;
			occur[sl]--;
			if(occur[fl] > 0 && occur[sl] > 0) {
				if(present.size() >= 3) {
					it++;
					int tl = *it;
					for(int i = 0; i < occur[fl]; i++) {
						char c = 'a' + fl; cout << c;
					}
					char c = 'a' + tl; cout << c;
					occur[tl]--;
					for(int i = sl; i < 26; i++) {
						for(int j = 0; j < occur[i]; j++) {
							char c = 'a' + i; cout << c;
						}
					}
					cout << '\n';
				} else {
					for(int i = 0; i < occur[sl]; i++) {
						char c = 'a' + sl; cout << c;
					}
					for(int i = 0; i < occur[fl]; i++) {
						char c = 'a' + fl; cout << c;
					}
					cout << '\n';
				}
			} else {
				for(int i = 0; i < 26; i++) {
					for(int j = 0; j < occur[i]; j++) {
						char c = 'a' + i; cout << c;
					}
				}
				cout << '\n';
			}
		}
	} else {
		cout << s << '\n';
	}
}

void asdf1234() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		i8d();
	}
}

int main() {
	asdf1234();
}