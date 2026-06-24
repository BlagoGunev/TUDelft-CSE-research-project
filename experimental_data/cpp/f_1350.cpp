// Problem: F. Slime and Sequences (Easy Version)

// Contest: Codeforces - Codeforces Round #641 (Div. 2)

// URL: https://codeforces.com/contest/1350/problem/F

// Memory Limit: 256 MB

// Time Limit: 2000 ms

// 

// Powered by CP Editor (https://cpeditor.org)



#include<bits/stdc++.h>

#define x first

#define y second

#define int long long 

using namespace std;

typedef pair<int,int>PII;

const int mod=998244353;

int qmi(int x,int n) {

	int ans = 1;

	while (n) {

		if (n&1) ans = ans * x %mod;

		x=x*x%mod;

		n>>=1;

	}

	return ans;

}

int inv(int x) {

	return qmi(x,mod-2);

}



const int N=5050;



int dp[N][N],fa[N],ans[N],n;



void solve(){

	cin>>n;

	dp[1][1]=1;

	for(int i=2;i<=n;i++)

		for(int j=1;j<=i;j++)

			dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1]*(i-j+1))%mod;

	fa[n]=1;

	for(int i=n;i>1;i--)fa[i-1]=fa[i]*i%mod;

	for(int i=1;i<=n;i++)

		for(int j=1;j<=i;j++)

			ans[j]=(ans[j]+fa[i]*dp[i][j]%mod)%mod;

	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';

}





signed main()

{

	ios::sync_with_stdio(false);

    cin.tie(nullptr);

	int T=1;

//	cin>>T;

	while(T--)

		solve();

	return 0;

}