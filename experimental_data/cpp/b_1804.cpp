#include<iostream>
	#include<cmath>
	#include<string>
	#include<map>
	#include<algorithm>
	#include<vector>
	using namespace std;
	void solve() {
		int n = 0, k = 0, d = 0, w = 0, ans = 1,s_num=1,s_time=0,ct=1;
		cin >> n >> k >> d >> w;
		vector<int> t(n+1);
		t[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> t[i];
		}
		
		for (int i = 2; i <= n; i++) {
			if (s_time + t[i] - t[i - 1]  > w + d) {
				ans++;
				s_time =0;
				s_num = 1;
				continue;
			}
			if (s_num ==k) {
				ans++;
				s_num = 1;
				s_time = 0;
				continue;
			}
			s_time += t[i] - t[i - 1];
			s_num++;
		}
       
		cout << ans << '\n';
	}
	int main() {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		int n = 0;
		cin >> n;
		while (n--) {
			solve();
		}
		return 0;
	}