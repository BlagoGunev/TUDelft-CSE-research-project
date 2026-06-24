#include <bits/stdc++.h>
using namespace std;

vector<long long> a;
int solve(vector<long long>& nums, long long k) {
	if(k < 0) return 0;
	long long largest_bit = 0;
	for(long long l = k; l >= 0; l--) {
		bool works = false;
		for(long long num : nums) {
			if(num & (1 << l)) {
				works = true;
				largest_bit = l;
				break;
			}
		}
		if(works) break;
	}
	vector<long long> has;
	vector<long long> no_has;
	for(long long num : nums) {
		if(num & (1 << largest_bit)) {
			has.push_back(num);
		} else {
			no_has.push_back(num);
		}
	}
	if((int) has.size() <= 1 && (int) no_has.size() <= 1) {
		return 0;
	}
	return min(solve(has, largest_bit - 1) + max((long long) no_has.size() - 1, 0LL), solve(no_has, largest_bit - 1) + max((long long) has.size() - 1, 0LL));
}

int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	a.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << solve(a, 30) << '\n';
}