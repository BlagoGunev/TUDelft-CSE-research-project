#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;


const int N = 100010;

int a[N];


int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; ++i)  scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	ll ans = 0;
	if (n == 3 || a[3] < a[4]) ans = 1;
	else {
		int id = 5, cnt = 2;
		while (id <= n && a[id] == a[3]) ++id, ++cnt;
		if (a[2] < a[3]) ans = cnt;
		else {
			if (a[1] < a[2]) ans = (ll)(cnt + 1) * cnt / 2;
			else {
				cnt += 2;
				for (int i = 1; i <= cnt - 2; ++i)
					ans += (ll)(cnt - i - 1) * (cnt - i) / 2;
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}