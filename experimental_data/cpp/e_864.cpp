#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <utility>

#define fi first
#define se second
#define mp make_pair
#define pii pair<int, int>
#define PI 3.14159265
#define INF 1023123123
#define REP(a, b) for (int a = 0; a < b; ++a)
#define FORU(a, b, c) for (int a = b; a <= c; ++a)
#define FORD(a, b, c) for (int a = b; a >= c; --a)

using namespace std;

int n;
pair <pii, pii> items[105];
int dp[105][2055];
const int MAXD = 2000;

int f(int pos, int now) {
	if ((pos == n) || (now > MAXD)) {
		dp[pos][now] = 0;
		
		return dp[pos][now];
	}

	if (dp[pos][now] != -1)
		return dp[pos][now];

	int &ret = dp[pos][now] = f(pos + 1, now);

	if ((now + items[pos].fi.se) < items[pos].fi.fi) {
		ret = max(ret, items[pos].se.fi + f(pos + 1, now + items[pos].fi.se));
	}

	return ret;
}

int main() {
	int t, d, p, savedItems[105], cnt = 0;

	scanf("%d", &n);

	REP(i, n) {
		scanf("%d %d %d", &t, &d, &p);
		items[i] = mp(mp(d, t), mp(p, i));
	}

	memset(dp, -1, sizeof(dp));

	sort(items, items + n);

	printf("%d\n", f(0, 0));

	int pos = 0, now = 0;

	while (pos != n) {
		if ((now + items[pos].fi.se < items[pos].fi.fi) && (dp[pos][now] == dp[pos + 1][now + items[pos].fi.se] + items[pos].se.fi)) {
			savedItems[cnt++] = items[pos].se.se + 1;
			now += items[pos].fi.se;
			++pos;
		}
		else {
			++pos;
		}
	}

	printf("%d\n", cnt);

	// sort(savedItems, savedItems + cnt);

	REP(i, cnt) {
		printf("%d%c", savedItems[i], (i != (cnt - 1)) ? ' ' : '\n');
	}

	return 0;
}