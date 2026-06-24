#include <bits/stdc++.h>

using namespace std;

#define lli long long int

#define pb push_back

int main()

{

ios::sync_with_stdio(0);cin.tie(0);

	lli n,i,inf=100000;

	cin>>n;

	lli dp[n][3],a[n+5];

	for(i=0;i<n;i++)

		cin>>a[i];

	dp[0][0]=1;

	if(a[0]==1 || a[0]==3)

		dp[0][1]=0;

	else

		dp[0][1]=inf;

	if(a[0]==2 || a[0]==3)

		dp[0][2]=0;

	else

		dp[0][2]=inf;

	for(i=1;i<n;i++){

		dp[i][0]=1+min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]));

		if(a[i]==1 || a[i]==3)

			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);

		else

			dp[i][1]=inf;

		if(a[i]==2 || a[i]==3)

			dp[i][2]=min(dp[i-1][0],dp[i-1][1]);

		else

			dp[i][2]=inf;

	}

	cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));

}