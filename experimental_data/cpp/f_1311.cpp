#include <cstdio>
#include <algorithm>
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef long long ll;
const int maxDot = 2e5 + 5;
int nbDot, tot, diff[maxDot];
struct Node {
	int pos, speed;
} dot[maxDot];
bool cmp(Node fir, Node sec) { return fir.pos < sec.pos; }
int find(int num) { return lower_bound(diff + 1, diff + tot + 1, num) - diff; }
struct BIT {
	ll sum[maxDot];
	void Add(int pos, int val) {
		for (int i = pos; i <= tot; i += lowbit(i)) sum[i] += val;
	}
	ll GetSum(int pos) {
		ll ret = 0ll;
		for (int i = pos; i; i -= lowbit(i)) ret += sum[i];
		return ret;
	}
};
BIT sum, cnt;
int main() {
	scanf("%d", &nbDot);
	for (int i = 1; i <= nbDot; ++i) scanf("%d", &dot[i].pos);
	for (int i = 1; i <= nbDot; ++i) scanf("%d", &dot[i].speed), diff[++tot] = dot[i].speed;
	sort(diff + 1, diff + maxDot + 1);
	tot = unique(diff + 1, diff + maxDot + 1) - (diff + 1);
	sort(dot + 1, dot + nbDot + 1, cmp);
	for (int i = 1; i <= nbDot; ++i) dot[i].speed = find(dot[i].speed);
	ll ans = 0ll;
	for (int i = 1; i <= nbDot; ++i) {
		ll nowSum = sum.GetSum(dot[i].speed);
		int nowCnt = cnt.GetSum(dot[i].speed);
		ans += 1ll * nowCnt * dot[i].pos - nowSum;
		sum.Add(dot[i].speed, dot[i].pos);
		cnt.Add(dot[i].speed, 1);
	}
	printf("%lld\n", ans);
	return 0;
}