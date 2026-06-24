#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
int r[N], c[N], n, m;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m; r[0] = r[n-1] = c[0] = c[n-1] = 1;
	for(int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y; --x; --y;
		r[x] = 1; c[y] = 1;
	}
	int res = 2 * n;
	for(int i = 0; i < n; ++i) res -= r[i] + c[i];
	if(n % 2 == 1 && r[n/2] == 0 && c[n/2] == 0) --res;
	cout << res << endl;
	return 0;
}