#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define F first
#define S second
#define pb push_back
#define fo(i, n) for(int i = 1; i <= n; ++i)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 200200;
const int mod = 1e9 + 7;

int n, cnt[N];


ll dp[2][51][51][51][51];
int d[N];
ll ans;

inline ll C(ll x)
{
	return (x * 1ll * (x - 1) / 2) % mod;
}

inline void add(ll &x, ll y)
{
	x += y;
	if(x >= mod) x -= mod;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	fo(i, n)
		cin >> d[i];	
	int st = 0;
	if(d[1] == 3)
	{
		if(d[2] == 3)
			dp[2 & 1][0][1][0][1] = 1;
		else
			dp[2 & 1][0][1][1][0] = 1;
		st = 3;
	}
	else
	{
		dp[1 & 1][0][0][0][1] = 1;
		st = 2;
	}
	for(int j = st; j <= n; ++j)
	{
		int i = j & 1;
		int was = ((j - 1) & 1);
		int wwas = j - 1;
		memset(dp[i],0,sizeof dp[i]);
		for(int same1 = 0; same1 <= wwas; ++same1)
			for(int same2 = 0; same2 + same1 <= wwas; ++same2)
				for(int other1 = 0; other1 + same2 + same1 <= wwas; ++other1)
					for(int other2 = 0; other2 + same2 + same1 + other1 <= wwas; ++other2)
					{
					   	if(dp[was][other1][other2][same1][same2] == 0) continue;
						if(d[j] == 2)
						{
							// all edges lost
							if(other1 && same1)
								add(dp[i][other1 - 1][other2][same1 - 1][same2], 
									dp[was][other1][other2][same1][same2] * other1 % mod * same1 % mod);
							if(same2 && other1) 
								add(dp[i][other1 - 1][other2][same1 + 1][same2 - 1],
									dp[was][other1][other2][same1][same2] * other1 % mod * same2 % mod);
							if(other2 && same1)
								add(dp[i][other1 + 1][other2 - 1][same1 - 1][same2], 
									dp[was][other1][other2][same1][same2] * other2 % mod * same1 % mod);
							if(same2 && other2) 
								add(dp[i][other1 + 1][other2 - 1][same1 + 1][same2 - 1],
									dp[was][other1][other2][same1][same2] * other2 % mod * same2 % mod);

							//one edge to other		
							if(other1)
								add(dp[i][other1 - 1][other2][same1 + 1][same2], 
									dp[was][other1][other2][same1][same2] * other1 % mod);
							if(other2)
								add(dp[i][other1 + 1][other2 - 1][same1 + 1][same2], 
									dp[was][other1][other2][same1][same2] * other2 % mod);

							//one edge to same

							if(same1 && other1 == 0 && other2 == 0)
								add(dp[i][same1 - 1][same2][1][0],
									dp[was][other1][other2][same1][same2] * same1 % mod);
							if(same2 && other1 == 0 && other2 == 0)
								add(dp[i][same1 + 1][same2 - 1][1][0],
									dp[was][other1][other2][same1][same2] * same2 % mod);
						}
						else
						{
							//1 edge to other, 2 to same
							if(other1 && same1 >= 2)
								add(dp[i][other1 - 1][other2][same1 - 2][same2],
									dp[was][other1][other2][same1][same2] * other1 % mod * C(same1) % mod);
							if(other1 && same1 && same2)
								add(dp[i][other1 - 1][other2][same1][same2 - 1],
									dp[was][other1][other2][same1][same2] * other1 % mod * same1 % mod * same2 % mod);
							if(other1 && same2 >= 2)
								add(dp[i][other1 - 1][other2][same1 + 2][same2 - 2],
									dp[was][other1][other2][same1][same2] * other1 % mod * C(same2) % mod);
							
							if(other2 && same1 >= 2)
								add(dp[i][other1 + 1][other2 - 1][same1 - 2][same2],
									dp[was][other1][other2][same1][same2] * other2 % mod * C(same1) % mod);
							if(other2 && same1 && same2)
								add(dp[i][other1 + 1][other2 - 1][same1][same2 - 1],
									dp[was][other1][other2][same1][same2] * other2 % mod *same1 % mod * same2 % mod);
							if(other2 && same2 >= 2)
								add(dp[i][other1 + 1][other2 - 1][same1 + 2][same2 - 2],
									dp[was][other1][other2][same1][same2] * other2 % mod * C(same2) % mod);

							// 1 edge to other, 1 to same
								
							if(other1 && same1)
								add(dp[i][other1 - 1][other2][same1][same2],
									dp[was][other1][other2][same1][same2] * other1 % mod * same1 % mod);
							if(other1 && same2)
								add(dp[i][other1 - 1][other2][same1 + 2][same2 - 1],
									dp[was][other1][other2][same1][same2] * other1 % mod * same2 % mod);
							
							if(other2 && same1)
								add(dp[i][other1 + 1][other2 - 1][same1][same2],
									dp[was][other1][other2][same1][same2] * other2 % mod * same1 % mod);
							if(other2 && same2)
								add(dp[i][other1 + 1][other2 - 1][same1 + 2][same2 - 1],
									dp[was][other1][other2][same1][same2] * other2 % mod * same2 % mod);

							// 1 edge to other, 0 to same
							if(other1 )
								add(dp[i][other1 - 1][other2][same1][same2 + 1],
									dp[was][other1][other2][same1][same2] * other1 % mod);
							if(other2)
								add(dp[i][other1 + 1][other2 - 1][same1][same2 + 1],
									dp[was][other1][other2][same1][same2] * other2 % mod);
							// 1 edge to same
							if(same1 && other1 == 0 && other2 == 0)
								add(dp[i][same1 - 1][same2][0][1],
									dp[was][other1][other2][same1][same2] * same1 % mod);
							if(same2 && other1 == 0 && other2 == 0)
								add(dp[i][same1 + 1][same2 - 1][0][1],
									dp[was][other1][other2][same1][same2] * same2 % mod);
						}
					}	
	}
	add(ans, dp[n&1][0][0][0][0]);
	cout << ans;
	return 0;
}