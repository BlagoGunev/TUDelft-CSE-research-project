#include<bits/stdc++.h>

#include <math.h>

using namespace std;



#define ll long long

#define slld(t) scanf("%lld",&t)

#define sd(t) scanf("%d",&t)

#define sld(t) scanf("%ld",&t)

#define pd(t) printf("%d\n",t)

#define plld(t) printf("%lld\n",t)

#define pcc pair<char,char>

#define pp pair<int,int>

#define pll pair<ll,ll>

#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)

#define mp(a,b) make_pair(a,b)

#define FF first

#define SS second

#define pb(x) push_back(x)



double dp[101][101][101];



int main()

{

	int r,s,p;

	cin>>r>>s>>p;

	dp[r][s][p] = 1.000000000;

	for( int i=r; i>=0; i--) // denoting rock

	{

		for( int j=s; j>=0; j--) // denoting scissor

		{

			for( int k=p; k>=0; k--) // denoting paper

			{

				double a,b,c,d;

				a = (double(i))*(double(j));

				b = (double(j))*(double(k));

				c = (double(i))*(double(k));

				d = a+b+c;

				if(i==0 && j==0) continue;

				if(j==0 && k==0) continue;

				if(i==0 && k==0) continue;

				double now = dp[i][j][k];

				if(i>0) dp[i-1][j][k] += now*c/d;

				if(j>0) dp[i][j-1][k] += now*(a/d);

				if(k>0) dp[i][j][k-1] += now*(b/d);

			}

		}

	}

	cout.precision(14);

	cout.setf(ios::fixed | ios::showpoint);

	//cout<<dp[r][s][p][1]<<" "<<dp[r][s][p][2]<<" "<<dp[r][s][p][3]<<endl;

	double ans1=0.00,ans2=0.00,ans3=0.00;

	for( int i=1; i<=r; i++) ans1 += dp[i][0][0];

	for( int i=1; i<=s; i++) ans2 += dp[0][i][0];

	for( int i=1; i<=p; i++) ans3 += dp[0][0][i];

	cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;

}