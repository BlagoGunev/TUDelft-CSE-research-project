#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
long long MOD=1e9+7;
char s[2003];
int a[30];
long long dp[1003];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=0;i<26;i++)scanf("%d",&a[i]);
	int minn=1003;
	minn=min(minn,a[s[1]-'a']);
	for(int i=1;i<=n && i<=minn;i++)
	{
	 minn=min(minn,a[s[i]-'a']);
	 if(i>minn)break;
	 dp[i]=1;
	}
	minn=1003;
	for(int i=2;i<=n;i++)
	{
	 minn=a[s[i]-'a'];
	 for(int j=i-1;j>=1;j--)
	 {
	 	minn=min(minn,a[s[j]-'a']);
	 	
	 	dp[i]=(dp[i]+dp[j])%MOD;
		if(minn<i-j+1)break;
	 }
    }
   printf("%I64d\n",dp[n]);
   
   int ans=1;
   for(int i=2;i<=n;i++)
   {
   	  minn=a[s[i]-'a'];
   	  for(int j=i-1;j>=1 && i-j+1<=minn;j--)
   	  {
   	  	minn=min(minn,a[s[j]-'a']);
   	    if(minn<i-j+1)break;
		ans=max(ans,i-j+1);   	
	  }
   }
   printf("%d\n",ans);
   
   ans=1;
   int l=1,r=1;
   while(r<n)
   {
   	minn=a[s[l]-'a'];
   	while(r<n)
   	{
   		r++;
   		minn=min(minn,a[s[r]-'a']);
   		if(minn<r-l+1)
   		{
   			ans++;
		    l=r;
		    break;
		   }	   
	 }
   }
   printf("%d\n",ans);
   return 0;
   
}