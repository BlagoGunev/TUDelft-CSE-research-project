#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[11];
vector<int> d;
int n, k;
bool dfs(int x/*搜到了第x位*/, bool larger/*前x位是不是大于n的前x位*/, int cnt/*前x位有多少种不同的数字*/, int num/*答案*/) {
	if (x == d.size()) {
		// 输出
		printf("%d\n", num);
		return true;//可行。
	} else {
		for (int i = larger ? 0 : d[x]/*大于的话就可以从0开始，否则从d[x]开始*/; i <= 9; i++) {
			vis[i] += 1;
			int ncnt = cnt;
			if (vis[i] == 1) ncnt += 1;//若他只出现过一次，那么不同数的个数+1
			if (ncnt <= k/*没有超过k个不同的数*/ && dfs(x + 1/*到了下一位*/, larger | (i > d[x])/*判断*/, ncnt, num * 10 + i/*把i插到答案里面*/)/*可行*/) {
				return true;//也可行。
			}
			vis[i] -= 1;//回溯。
		}
		return false;//不可行。
	}
}
void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= 9; i++) vis[i] = 0;
	d.clear();//清空
	while (n) {
		d.push_back(n % 10);
		n /= 10;
	}
	reverse(d.begin(), d.end());
	dfs(0, 0, 0, 0); // 当前的前缀有没有大于n的前缀
}
int main() {
	int T;
	scanf("%d", &T);
	while (T --) {
		solve();
	}
	return 0;
}