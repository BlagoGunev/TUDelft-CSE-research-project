#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

int read() {
	int tem;
	scanf("%d",&tem);
	return tem;
}

int a[maxn], b[maxn];

int main() {
	#ifdef LOCAL
		freopen("in.txt", "rb", stdin);
	#endif
	int t = read();
	while(t--) {
		int n = read(), l = read(), r = read();
		for(int i = 1; i <= n; i++)
			a[i] = b[i] = read();
		int k = r - l + 1;
		sort(a + 1, a + r + 1);
		ll ans1 = 0, ans2 = 0;
		for(int i = 1; i <= k; i++)
			ans1 += a[i];
		sort(b + l, b + n + 1);
		for(int i = 1; i <= k; i++)
			ans2 += b[l - 1 + i];
		printf("%lld\n", min(ans1, ans2));
	}
	return 0;
}