#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[2005][2005];

struct BIT
{
	int tre[2005];
	void push(int id)
	{
		while(id <= n) {
			tre[id] ++;
			id += id & -id;
		}
	}
	void pop(int id)
	{
		while(id <= n) {
			tre[id] --;
			id += id & -id;
		}
	}
	int query_s(int l, int r)
	{
		if(l > r) return 0;
		if(l == 0) {
			int ret = 0;
			while(r > 0) {
				ret += tre[r];
				r -= r & -r;
			}
			return ret;
		} else return query_s(0, r) - query_s(0, l - 1);
	}
}cur, cur2;
bool apr0[2005], apr1[2005];

int dp[2005][2005];
void gen_dp()
{
	dp[0][0] = 1;
	rep1(i, n) {
		dp[i][0] = 1LL * dp[i - 1][0] * i % MOD;
		for(int j = 0; j <= i; j ++) {
			dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j - 1] * (i - j)) % MOD;
			if(j > 1) dp[i][j] = (dp[i][j] + 1LL * dp[i - 1][j - 2] * (j - 1)) % MOD;
		}
	}
}

int main()
{
	scanf("%d", &n);
	rep(i, n) rep(j, n) scanf("%d", &a[i][j]);
	
	gen_dp();
	
	int ans = 0;
	rep(i, n) {
		int ca = 0;
		
		if(i == 0) {
			rep1(j, n) cur.push(j);
			rep(j, n) {
				cur.pop(a[i][j]);
				ca = (ca + 1LL * cur.query_s(0, a[i][j]) * dp[n - j - 1][0]) % MOD;
			}
		} else {
			memset(apr0, 0, sizeof(apr0));
			memset(apr1, 0, sizeof(apr1));
			int tot = 0;
			rep1(j, n) cur2.push(j);
			rep(j, n) {
				if(!apr1[a[i - 1][j]]) {
					cur.push(a[i - 1][j]);
					apr0[a[i - 1][j]] = true;
				} else tot ++;
				
				int num1 = cur.query_s(0, a[i][j] - 1);
				int num0 = cur2.query_s(0, a[i][j]) - 1 - num1;
				if(a[i - 1][j] < a[i][j] && cur.query_s(a[i - 1][j], a[i - 1][j])) num1 --;
				
				if(num0 > 0) ca = (ca + 1LL * num0 * dp[n - j - 1][n - 2 * j - 2 + tot]) % MOD;
				if(num1 > 0) ca = (ca + 1LL * num1 * dp[n - j - 1][n - 2 * j - 1 + tot]) % MOD;
				
				cur2.pop(a[i][j]);
				if(apr0[a[i][j]]) {
					cur.pop(a[i][j]);
					tot ++;
				} else apr1[a[i][j]] = true;
			}
		}
		
		rep(j, n - i - 1) ca = 1LL * ca * dp[n][n] % MOD; 
		ans = (ans + ca) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}