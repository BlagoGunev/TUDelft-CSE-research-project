#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz(x) ((int)(x).size())
#define rep(i,l,r) for(int i=(l);i<(r);++i)
//-------head-------
const int N = 207;
int n, k, r[N];
void solve() {
	for (int i = 1; i <= (n << 1) && k > 0; i += 2)
		if (r[i - 1] < r[i] - 1 && r[i] - 1 > r[i + 1]) {
			--k, --r[i];
		}
}
int main() {
	scanf("%d%d", &n, &k);
	rep(i, 0, 2 * n + 1)
		scanf("%d", r + i);
	solve();
	rep(i, 0, 2 * n + 1) {
		if (i)
			putchar(' ');
		printf("%d", r[i]);
	}
	return 0;
}