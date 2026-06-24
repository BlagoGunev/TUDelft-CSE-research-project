#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int N = 1010;
char s[N][N];
int ans[N][N];
int pre[N << 1];
int find(int x) {
	return pre[x] ? pre[x] = find(pre[x]) : x;
}
bool vis[N << 1];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);

    for (int i = 1; i <= n; i++) {
		int l = -1, r = -1;
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == '#') {
				if (l == -1) l = j;
				r = j;
			}
		}
		if (l == -1) continue;
		if (l != r) {
			bool flag = true;
			for (int j = l + 1; j < r; j++)
				if (s[i][j] == '.') flag = false;
		    if (!flag) {
			    printf("-1\n");
			    return 0;
		    }
		}
	}

	for (int i = 1; i <= m; i++) {
		int l = -1, r = -1;
		for (int j = 1; j <= n; j++) {
			if (s[j][i] == '#') {
				if (l == -1) l = j;
				r = j;
			}
		}
		if (l != r) {
			bool flag = true;
			for (int j = l + 1; j < r; j++)
				if (s[j][i] == '.') flag = false;
		    if (!flag) {
			    printf("-1\n");
			    return 0;
		    }
		}
	}

    for (int i = 1; i <= n; i++)
	    for (int j = 1; j <= m; j++)
		    if (s[i][j] == '#') {
			    int x = find(i);
			    int y = find(j + n);
				vis[i] = true;
				vis[j + n] = true;
			    if (x == y) continue;
			    pre[x] = y;
			}

    for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int j = 1; j <= m; j++)
			if (s[i][j] == '#') flag = false;
		if (!flag) continue;
		for (int j = 1; j <= m; j++) {
			if (!vis[j + n]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("-1\n");
			return 0;
		}
	}

	for (int i = 1; i <= m; i++) {
		bool flag = true;
		for (int j = 1; j <= n; j++)
			if (s[j][i] == '#') flag = false;
		if (!flag) continue;
		for (int j = 1; j <= n; j++)
			if (!vis[j]) {
				flag = false;
				break;
			}
		if (flag) {
			printf("-1\n");
			return 0;
		}
	}

	int ans = 0;
    for (int i = 1; i <= n + m; i++)
		if (vis[i] && pre[i] == 0) ans++;
	cout << ans << endl;
 	

	return 0;
}