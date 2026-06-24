#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <queue>
#include <map>
#include <deque>
using namespace std;
typedef long long li;
const li MAX = 101;
li inf = 1000000000000001, mod = 998244353, z = 0;
li dp[27][MAX], n, k;
string s;
int main(){
	cin >> n >> k;
	dp[0][0] = 1;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		for (int j = n; j >= 1; j--) {
			li cnt = 0;
			for (int z = 0; z < 27; z++) cnt += dp[z][j - 1];
			dp[s[i] - 96][j] = cnt;
		}
	}
	li cnt = 0, ans = 0;
	for (int j = n; j >= 1; j--) {
		for (int i = 1; i < 27; i++) {
			li pl = min(k - cnt, dp[i][j]);
			cnt += pl;
			ans += (n - j) * pl;
			if (ans == -388) {
				cout << "old";
			}
			if (cnt == k) {
				cout << ans;
				return 0;
			}
		}
	}
	if (k - cnt == 1) {
		cout << ans + n << '\n';
	}
	else {
		cout << -1 << '\n';
	}
//	system("pause");
	return 0;

}