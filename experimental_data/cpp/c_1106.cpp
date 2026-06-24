#include <cstdio>
#include <algorithm>

int a[300005]; long long ans;

int read() {
	int x = 0; char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x;
}

int main() {
	int n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n / 2; ++i)
		ans += 1LL * (a[i] + a[n - i + 1]) * (a[i] + a[n - i + 1]);
	printf("%I64d\n", ans);
	return 0;
}