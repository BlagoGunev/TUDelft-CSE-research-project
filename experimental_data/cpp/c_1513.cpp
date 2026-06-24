#include<iostream>

#define Daybreak7 ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

#define endl "\n"

#define ll long long

#define inf 0x3f3f3f3f

using namespace std;



const int mod = 1e9 + 7;

const int N = 2e5 + 10;

int dp[N];

void init()

{

	for(int i = 0; i < 10; i++) dp[i] = 1;

	for(int i = 10; i < N; i++) dp[i] = (dp[i - 9] + dp[i - 10]) % mod;

}

void solve()

{

	int n, m;

	cin >> n >> m;

	int ans = 0;

	while(n)

	{

		ans = (ans + dp[n % 10 + m]) % mod;

		n /= 10;

	}

	cout << ans << endl;

}

int main()

{

	init();

	Daybreak7;

	int T = 1;

	cin >> T;

	while(T--)

	{

		solve();

	}

}