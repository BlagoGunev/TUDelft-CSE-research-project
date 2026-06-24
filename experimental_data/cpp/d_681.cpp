#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int read() {
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	int ans = 0;
	while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
	return ans;
}

const int N = 100010;
struct edge {int x, y, next;} e[N];
int h[N], ett = 0;
void match(int x, int y) {
	e[ett].x = x;
	e[ett].y = y;
	e[ett].next = h[x];
	h[x] = ett++;
}

int q[N], tar[N], que[N], rd[N], ap[N];
int main() {
//	freopen("gift.in", "r", stdin);
//	freopen("gift.out", "w", stdout);
	int n = read(), m = read();
	memset(h, -1, sizeof(h));
	memset(rd, 0, sizeof(rd));
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		match(x, y);
		rd[y]++;
	}
	
	for (int i = 1; i <= n; i++) tar[i] = read();
	
	int tot = 0;
	memset(ap, 0, sizeof(ap));
	for (int i = 1; i <= n; i++) if (!rd[i]) {
		int l = 1, r = 1; q[1] = i;
		for (; l <= r; l++)
			for (int x = q[l], p = h[x]; p != -1; p = e[p].next)
				q[++r] = e[p].y;
		
		for (int i = r; i; i--) {
			int x = q[i], sam = tar[x], flag = 1;
			for (int p = h[x]; p != -1; p = e[p].next)
				if (tar[e[p].y] && tar[e[p].y] != sam) {
					flag = 0; 
					break;
				}
			if (!flag) {
				printf("-1\n"); 
				return 0;
			}
			if (tar[x] == x) tar[x] = 0, que[++tot] = x;
		}
	}
	
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++) printf("%d\n", que[i]);
	return 0;
}