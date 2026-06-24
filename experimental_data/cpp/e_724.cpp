#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <cmath>

#include <string>

#include <map>

#include <vector>

#include <set>

#include <queue>

#include <algorithm>



using namespace std;



typedef long long 	LL;

typedef pair <int, int> 	PII;

typedef vector <int> 	VI;



#define FOR(i, x, y) 	for(int i = x; i < y; ++ i)

#define IFOR(i, x, y) 	for(int i = x; i > y; -- i)

#define pb	push_back

#define mp 	make_pair

#define fi 	first

#define se 	second

#define lrt rt<<1

#define rrt rt<<1|1

#define lson rt<<1, l, mid

#define rson rt<<1|1, mid+1, r



const int maxn = 10010;

const LL inf = 1LL << 60;



int n, p[maxn], s[maxn], c;



LL dp[maxn];



int main() {

	while(~scanf("%d%d", &n, &c)) {

		FOR(i, 1, n+1) 	scanf("%d", p+i);

		FOR(i, 1, n+1) 	scanf("%d", s+i);

		FOR(i, 0, n+1)  dp[i] = inf;

		dp[0] = 0;

		FOR(i, 1, n+1) {

			IFOR(j, i+1, 0) {

				dp[j] = min(dp[j-1]+s[i], dp[j]+(LL)j*c+p[i]);

			} 

			dp[0] = dp[0]+p[i];

		}

		LL ans = dp[0];

		FOR(i, 1, n+1) 	ans = min(ans, dp[i]);

		printf("%I64d\n", ans);

	}

	return 0;

}