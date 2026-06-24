#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#define ff first
#define ss second
typedef long long ll;
using namespace std;
const int ESIM = 24;
const int N = 5e5 + 10;
void solve() {
	int n, m;
	cin >> n >> m;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		mx = max(mx, x);
	}
	while (m--) {
		char e;
		int l, r;
		cin >> e >> l >> r;
		if (l <= mx && r >= mx) {
			if (e == '+') mx++;
			else mx--;
		}
		cout << mx << " ";
	}
	cout << "\n";
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}