#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char a[N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", a + 1);
		int n = strlen(a + 1);
		int ans = 0x3f3f3f3f, cnt = 0;
		bool flag = false;
		if (a[1] == 'B' || a[n] == 'B') flag = true;
		else for (int i = 1; i <= n; i++)if (a[i] == 'B' && a[i - 1] == 'B') {
					flag = true;
					break;
				}
		if (flag) {
			for (int i = 1; i <= n; i++) if (a[i] == 'A') cnt++;
			printf("%d\n", cnt);
			continue;
		}
		for (int i = 1; i <= n + 1; i++) {
			if (a[i] == 'A') cnt++;
			else if (cnt) ans = min(ans, cnt), cnt = 0;
		}
		cnt = 0;
		for (int i = 1; i <= n; i++) if (a[i] == 'A') cnt++;
		if (cnt == n || cnt == 0) puts("0");
		else printf("%d\n", cnt - ans);
	}
	return 0;
}