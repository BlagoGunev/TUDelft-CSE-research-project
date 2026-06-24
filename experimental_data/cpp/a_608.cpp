#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int n, s;
int fl[N] = {0};
int ans = 0;

void solve() {
	for(int i = s; i > 0; --i) {
		ans = max(ans, fl[i]);
		ans++;
	}
	printf("%d", ans);
}

int main (int argc, char *argv[])
{
	scanf("%d%d", &n, &s);
	for(int i = 0; i < n; ++i) {
		int f, t;
		scanf("%d%d", &f, &t);
		f;
		fl[f] = max(fl[f], t);
	}
	solve();
	return 0;
}