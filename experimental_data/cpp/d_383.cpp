/***********************************************

 |Author: Fry

 |Created Time: 2016/7/13 9:23:39

 |File Name: E.cpp

 |Copyright: 

 |  For personal use, feel free to use

 |  Otherwise call me at http://blog.csdn.net/fry_guest 

***********************************************/

#include <bits/stdc++.h>

using namespace std;

const int mod=1e9+7;

int a[1005];

int dp[2][22000];

int main()

{

	int n,ans;

	while (~scanf("%d",&n)){

		memset(dp,0,sizeof(dp));

		ans=0;

		for (int i=1;i<=n;i++) scanf("%d",&a[i]);

		for (int i=1;i<=n;i++){

			for (int j=1000;j<=21000;j++){

				dp[i%2][j]=(dp[(i+1)%2][j-a[i]]+dp[(i+1)%2][j+a[i]])%mod;

			}

			dp[i%2][11000+a[i]]=(dp[i%2][11000+a[i]]+1)%mod;

			dp[i%2][11000-a[i]]=(dp[i%2][11000-a[i]]+1)%mod;

			ans=(ans+dp[i%2][11000])%mod;

		}

		printf("%d\n",ans);

	}

	return 0;

}