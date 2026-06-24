#include<algorithm>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void solve() {
	string s; cin >> s;
	vector<int> last(26, s.size());
	for (int i = 0; i < s.size(); ++i) {
		last[s[i] - 'a'] = i;
	}
	int ind = *min_element(last.begin(), last.end());
	cout << s.substr(ind) << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int ttt; cin >> ttt;
	while (ttt > 0) {
		solve(); --ttt;
	}
	return 0;
}