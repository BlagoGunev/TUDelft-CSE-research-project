//author Eterna
#define xiongziliang nb
#define songwenqi AK
#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<cmath>
#include<climits>
#include<deque>
#include<functional>
#include<complex>
#include<numeric>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define Pi acos(-1.0)
#define eps 1e-15
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
#define pb(x) push_back(x)
#define lowbit(x) (x & -x)
#define FRIN freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\in.txt", "r", stdin)
#define FROUT freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\out.txt", "w", stdout)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int maxn = 1000;
const int INF = 0x7fffffff;
const int mod = 1e9 + 7;
inline int read_int() {
	char c;
	int ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
inline ll read_ll() {
	char c;
	ll ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
int n, m, p, s[10], cnt[10];
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
char line[maxn + 5];
pii player[10];
bool mp[maxn + 5][maxn + 5], flag;
queue<pii> q[10];
bool check(int x, int y) { return x > 0 && x <= n&& y > 0 && y <= m; }
void BFS() {
	flag = true;
	while (flag) {
		for (int i = 1; i <= p; ++i) {
			int step = s[i];
			while (step-- && !q[i].empty()) {
				int tot = q[i].size();
				for (int k = 1; k <= tot; ++k) {
					pii now = q[i].front(); q[i].pop();
					for (int j = 0; j < 4; ++j) {
						int x = now.first + dx[j], y = now.second + dy[j];
						if (check(x, y) && !mp[x][y]) {
							q[i].push(pii(x, y));
							mp[x][y] = 1;
							cnt[i]++;
						}
					}
				}
			}
		}
		flag = false;
		for (int i = 1; i <= p; ++i) {
			if (q[i].size()) {
				flag = true;
				break;
			}
		}
	}
}
int main()
{
	cin >> n >> m >> p;
	for (int i = 1; i <= p; ++i)cin >> s[i];
	for (int i = 1; i <= n; ++i) {
		scanf("%s", line + 1);
		for (int j = 1; j <= m; ++j) {
			if (line[j] == '#')mp[i][j] = true;
			else if (line[j] == '.')mp[i][j] = false;
			else {
				int x = line[j] - '1' + 1;
				player[x].first = i, player[x].second = j;
				mp[i][j] = true;
				++cnt[x];
				q[x].push(pii(i, j));
			}
		}
	}
	BFS();
	for (int i = 1; i <= p; ++i)cout << cnt[i] << " ";
	cout << endl;
	return 0;
}