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
const int N = 1e5 + 10;
int c[N];
int gcd(int x, int y) {
	while (x > 0 && y > 0) {
		if (x > y) x %= y;
		else y %= x;
	}
	return x + y;
}
void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	int g = gcd(a, b);
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		c[i] %= g;
	}
	sort(c + 1, c + n + 1);
	int u = 0;
	for (int i = 1; i < n; i++) {
		u = max(u, c[i + 1] - c[i]);
	}
	u = max(u, g - c[n] + c[1]);
	cout << g - u << "\n";
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}