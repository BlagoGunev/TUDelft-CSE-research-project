#include <bits/stdc++.h>
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
int rank1[110],rank2[110];
int main()
{
	int n;
	scanf("%d",&n);
	int a,b;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		rank1[i]=a;
		rank2[i]=a+b;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(rank1[i]>=rank1[j]&&rank2[i]<rank2[j])
				ans++;
			else if(rank1[i]>=rank1[j]&&rank2[j]>rank1[i])
				ans+=2;
			else if(rank1[i]>=rank1[j]&&rank2[i]<rank1[j])
				ans+=2;
			else if(rank1[i]<rank1[j]&&rank2[j]<=rank2[i])
				ans++;
			else if(rank1[i]<rank1[j]&&rank2[i]>=rank1[j])
				ans+=2;
			else if(rank1[i]<rank1[j]&&rank2[j]<=rank1[i])
				ans+=2;
		}
	}
	printf("%d\n",ans);
	return 0;
}