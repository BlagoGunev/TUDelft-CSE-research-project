#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;
typedef long long LL;

const int MAXN = 2e5 + 5;

int a[MAXN], mx, n, m, sum[MAXN][2], b[MAXN];
LL ans;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	int mx = (1 << m) - 1;
	for (int i = 1; i <= n; i ++) sum[i][0] = sum[i - 1][0] ^ a[i];
	for (int i = 1; i <= n; i ++) {
		sum[i][1] = mx - sum[i][0];
		if (sum[i][1] < sum[i][0]) swap(sum[i][0], sum[i][1]);
		b[i] = sum[i][0]; 
	}
	sort(b + 1, b + n + 1);
	int num = 1;
	ans = 1ll * n * (n + 1) / 2;
	for (int i = 2; i <= n; i ++) {
		if (b[i] != b[i - 1]) {
			int p = num / 2;
			if (b[i - 1] == 0) ans -= p;
			ans -= 1ll * p * (p - 1) / 2;
			p = num - p;
			ans -= 1ll * p * (p - 1) / 2;
			num = 1;
		} else num ++;
	}
	int p = num / 2;
	if (b[n] == 0) ans -= p;
	ans -= 1ll * p * (p - 1) / 2;
	p = num - p;
	ans -= 1ll * p * (p - 1) / 2;
	printf("%I64d\n", ans);
}