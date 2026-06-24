#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string decrypt(vector<int> &v) {

	int number = 0;
	string s; 

	unordered_map<char, int> mp;

	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == 0) {
			char c = 'a' + number++;
			s += c;
			mp[c]++;
			
		}
		else {
			for (const auto& p : mp) {
				if (p.second == v[i]) {
					s += p.first;
					mp[p.first]++;
					break;
				}
			}
		}
	}

	return s;

}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		vector<int> v(a);

		for (int j = 0; j < a; ++j) {
			cin >> v[j];
		}

		cout << decrypt(v) << endl;

	}

}