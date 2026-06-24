#include<cstdio>
#include<algorithm>
using namespace std;
char str[1000010];
int g[26];
bool visit[26];
int n, m;
int main() {
	scanf("%d %d %s", &n, &m, str);
	int cnt = 0;
	bool flag = false;
	for (int i = n - 1; i >= 0; i--) 
		if (!g[str[i] - 'A']) g[str[i] - 'A'] = i;

	for (int i = 0; i < n; i++) {
		if (cnt > m) {
			flag = true;
			break;
		}
		if (!visit[str[i] - 'A']) {
			visit[str[i] - 'A'] = true;
			cnt++;
			if (cnt > m) {
				flag = true;
				break;
			}
			if (g[str[i] - 'A'] == i) cnt--;
		}
		else if (visit[str[i] - 'A'] && g[str[i] - 'A'] > i) continue;
		else if (visit[str[i] - 'A'] && g[str[i] - 'A'] == i) cnt--;
	}
	if (flag) puts("YES");
	else puts("NO");
}