//let's do it
 #include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1000000000
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define S second
#define F first
#define boost1 ios::sync_with_stdio(false);
#define boost2 cin.tie(0);
#define mem(a,val) memset(a,val,sizeof a)
#define endl "\n"
#define maxn 100001

string s[55],S;
int dp[55][2505],l,store[55][2505],n;
int helper1(int id,int l,int r)
{
	int cur=l;
	for(int i=0;i<s[id].length();i++)
	{
		if(cur==r+1)
		return 1;
		if(s[id][i]==S[cur])
		{
			cur++;
			if(cur==r+1)
			return 1;
		}
	}
	return 0;
}
void pre_calc()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=l;j++)
		{
			int lo=0;
			int hi=min(j,(int)s[i].length())+1;
			while(hi-lo>1)
			{
				int mid=(lo+hi)/2;
				if(helper1(i,j-mid+1,j))
				lo=mid;
				else
				hi=mid;
			}
			store[i][j]=lo;
		}
	}
}
inline int helper(int str_idx,int idx)
{
	return store[str_idx][idx];
}
int main()
{
	boost1;boost2;
	int i,j,len,ans=inf,k;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>s[i];
	cin>>S;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=S.length();j++)
		dp[i][j]=inf;
	}
	l=S.length();
	S=" "+S;
	pre_calc();
	for(i=0;i<=n;i++)
	dp[i][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=l;j++)
		{
			dp[i][j]=dp[i-1][j];
			len=helper(i,j);
			if(dp[i-1][j-len]!=inf)
			dp[i][j]=min(dp[i][j],dp[i-1][j-len]+1);
			for(k=1;k<=i;k++)
			{
				len=helper(k,j);
				if(dp[i][j-len]!=inf)
				dp[i][j]=min(dp[i][j],dp[i][j-len]+1);
			}
		}
	}
	//cout<<dp[1][2]<<" "<<dp[1][3]<<endl;
	//cout<<dp[2][1]<<" "<<dp[2][2]<<" "<<dp[2][3]<<endl;
	for(i=1;i<=n;i++)
	ans=min(ans,dp[i][l]);
	if(ans==inf)
	ans=-1;
	cout<<ans;
	return 0;
}