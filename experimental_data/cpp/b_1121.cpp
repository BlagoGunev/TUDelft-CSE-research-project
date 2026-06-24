#include<bits/stdc++.h>
using namespace std;
int n,sweet[1003],ans,sum[200005];
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n; i++)
	{
		scanf("%d",&sweet[i]);
	}
	for(int i = 1;i <= n; i++)
	{
		for(int j = i+1;j <= n; j++)
		{
			int s = sweet[i]+sweet[j];
			sum[s]++;
			ans = max(ans,sum[s]);
		}
	}
	printf("%d\n",ans);
}