//CHALLENGE: ACCEPTED
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define ll long long
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	int ans[t];
	for (int i = 0; i < t; i++) {
		string s, t;
		cin >> s >> t;
		int ind = 0, cnt = 1;
		vector<int> search[26];
		for (int j = 0;j < s.length(); j++) {
			search[s[j] - 'a'].push_back(j);
		}
		for(char c:t) {
			int x = lower_bound(search[c - 'a'].begin(), search[c - 'a'].end(), ind) - search[c - 'a'].begin();
			if (x == search[c - 'a'].size()) {
				cnt++;
				if (search[c - 'a'].empty()) {
					cnt = -1;
					break;
				}
				ind = search[c - 'a'][0] + 1;
			} else {
				ind = search[c - 'a'][x] + 1;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}