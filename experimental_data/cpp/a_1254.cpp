#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <random>
#include <cassert>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<char>> f(n, vector<char>(m));
		vector<char> arr(n * m);
		int s = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> f[i][j];
				arr[i * m + j] = f[i][j];
				s += (f[i][j] == 'R');
			}
			if (i & 1) {
				reverse(arr.begin() + i * m, arr.begin() + (i + 1) * m);
			}
		}
		int cur_s = 0;
		char cur = '0';
		vector<char> ans(n * m);
		for (int i = 0; i < n * m; ++i) {
			cur_s += (arr[i] == 'R');
			ans[i] = cur;
			if ((k != 0 && cur_s == s / k) && (i < n * m - 1 && arr[i + 1] == 'R')) {
				s -= cur_s;
				cur_s = 0;
				--k;
				if (cur == '9') {
					cur = 'a';
				}
				else if (cur == 'z') {
					cur = 'A';
				}
				else {
					++cur;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			if (i & 1) {
				reverse(ans.begin() + i * m, ans.begin() + (i + 1) * m);
			}
			for (int j = 0; j < m; ++j) {
				cout << ans[i * m + j];
			}
			cout << '\n';
		}
	}
	//system("pause");
	return 0;
}