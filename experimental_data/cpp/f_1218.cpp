#include <cstdio>
#include <queue>
using namespace std;
int w[100010], c[100010];
int main() {
	int n, k, a;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	scanf("%d", &a);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	priority_queue<int> q;
	long long ans = 0;
	int t = 0;
	for (int i = 0; i < n; i++) {
		w[i] = (w[i] - k + a - 1) / a;
		if (w[i] < 0) w[i] = 0;
		q.push(-c[i]);
		while (q.size() && t < w[i]) {
			ans -= q.top();
			q.pop();
			t++;
		}
		if (t < w[i]) {
			puts("-1");
			return 0;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}