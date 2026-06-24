// Problem: E. Battle Lemmings

// Contest: Codeforces - Codeforces Round #672 (Div. 2)

// URL: https://codeforces.com/contest/1420/problem/E

// Memory Limit: 512 MB

// Time Limit: 2000 ms

// 

// Powered by CP Editor (https://cpeditor.org)



#include<bits/stdc++.h>

#define x first

#define y second

#define endl '\n'

using namespace std;

typedef pair<int,int>PII;



const int N=85;



int dp[N][N][N*N],a[N],s[N],n,m=1;



// dp[i][j][k]表示到了第i个1，前面有j个0，走了k步的时候的min(bx*bx) 



void solve(){

	cin>>n;

	for(int i=1;i<=n;i++){

		cin>>a[i];

		if(a[i])m++;

		else s[m]++;

	}

	memset(dp,-1,sizeof dp);

	dp[0][0][0]=0;

	for(int i=1;i<=m;i++)s[i]+=s[i-1];

	for(int i=0;i<m;i++){

		for(int j=0;j<=s[m];j++){

			for(int k=0;k<=(n-1)*n/2;k++){

				if(dp[i][j][k]==-1)continue;

				for(int l=j;l<=s[m];l++){

					int step=k+abs(l-s[i+1]);

					if(step>(n-1)*n/2)continue;

					if(dp[i+1][l][step]==-1)dp[i+1][l][step]=dp[i][j][k]+(l-j)*(l-j);

					else dp[i+1][l][step]=min(dp[i+1][l][step],dp[i][j][k]+(l-j)*(l-j));

				}

			}

		}

	}

	int mi=1e9;

	for(int i=0;i<=n*(n-1)/2;i++){

		if(dp[m][s[m]][i]!=-1)

			mi=min(mi,dp[m][s[m]][i]);

		cout<<(s[m]*s[m]-mi)/2<<" ";

	}

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