#include <iostream>
#include <vector>
#include <set>
using ll = long long;
using namespace std;

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false); 
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector <ll> a(n);
		set <ll> s;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			s.insert(a[i]);
		}
		if (s.size() < n) {
			puts("NO");
			continue;
		}
		
		bool flag;
		for (int i = 2; i <= n / 2 + 1; ++i) {
			vector <int> cnt(i, 0);
			for (auto j : a) 
				cnt[j % i]++;
				
			flag = true;
			for (auto j : cnt) {
				if (j < 2) {
					flag = false;
					break;
				}
			}
			if (flag)  break;
		}
		if (flag) {
			puts("NO");
			continue;
		}
		puts("YES");
	}
	return 0;
}