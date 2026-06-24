#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
string s;
int cnt[500005];

int main() {
	
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n >> s;
	int c = 0;
	LL rlt = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			c++;
			cur += c;
			cnt[c] += cnt[c - 1];
			cur += cnt[c - 1];
			cnt[c - 1] = 0;
		}
		else {
			for (int j = 0; j <= c; j++) cnt[j]++;
			c = 0;
		}
		rlt += cur;
	}
	cout << rlt << endl;
	
	return 0;

}