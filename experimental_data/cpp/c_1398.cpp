#include<bits/stdc++.h>
using namespace std;
char s[100011];
int t,n,sum,cnt[2000011];
long long res;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		res=0;
		cnt[(sum-0)+1000000]++;
		for(int i=1;i<=n;i++)
		{
			sum+=s[i]-'0';
			res+=cnt[(sum-i)+1000000]++;
		}
		
		for(int i=n;i;i--)
		{
			cnt[(sum-i)+1000000]--;
			sum-=s[i]-'0';
		}
		cnt[(sum-0)+1000000]--;
		
		printf("%lld\n",res);
	}
	return 0;
}