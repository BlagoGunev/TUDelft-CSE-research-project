// Shalin

#include <bits/stdc++.h>

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <math.h>

#include <limits.h>

using namespace std;

#define si(x) scanf("%d",&x)

#define slli(x) scanf("%lld",&x);

#define sc(x) scanf("%c",&x);

#define ss(x) scanf("%s",x);

#define sd(x) scanf("%lf",&x);

#define bitcount __builtin_popcount

#define gcd __gcd

#define llu long long unsigned int

#define lli long long int

#define fi first

#define se second

#define pb push_back

#define mod 1000000007

#define mp make_pair

#define vi vector<int>

#define vlli vector<long long int>

#define pii pair<int,int>

double dp[1010][1010];

double func(int w,int b)

{

	if(dp[w][b]!=-1)

		return dp[w][b];

	if(w==0 and b==0)

	{

		dp[w][b]=0;

		return dp[w][b];

	}

	if(w==0)

		return 0;

	if(b==0)

		return 1;

	double ret,ww=w,bb=b;

	if(b==1)

	{

		ret=ww/(ww+bb);

	}

	else if(bb==2)

	{

		if(ww==1)

		{

			ret=ww/(ww+bb);

		}

		else

		{

			ret=(ww/(ww+bb))+(bb/(ww+bb))*((bb-1)/(ww+bb-1));

		}

	}

	else

	{

		ret=ww/(ww+bb);

		ret=ret+(bb/(ww+bb))*((bb-1)/(ww+bb-1))*((ww/(ww+bb-2))*(func(ww-1,bb-2)) + ((bb-2)/(ww+bb-2))*func(ww,bb-3));

	}

	dp[w][b]=ret;

	//cout<<"w: "<<w<<" b: "<<b<<" ret: "<<ret<<endl;

	return ret;

}

int main()

{

	//freopen("input.txt","r",stdin);

    //freopen("output.txt","w",stdout);

	int w,b,i,j;

	cin>>w>>b;

	for(i=0;i<=1000;i++)

	{

		for(j=0;j<=1000;j++)

			dp[i][j]=-1;

	}

	double ans=func(w,b);

	printf("%.12lf\n",ans);

	return 0;

}