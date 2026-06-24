#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN=100100;
int npri[MAXN],sum[MAXN],a[MAXN];
vector<int> fac[MAXN];

int main()
{
	int i,j,k,T,n,limit,tmp,num1,cnt,x;
	ll ans;
	for(i=2;i<MAXN;i++)
	{
		if(npri[i])
			continue;
		fac[i].push_back(i);
		for(j=i+i;j<MAXN;j+=i)
		{
			npri[j]=1;
			fac[j].push_back(i);
		}
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cnt=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x%2)
				a[++cnt]=x;
		}
		ans=1ll*(n-1+cnt)*(n-cnt)/2;
		sort(a+1,a+cnt+1);
		memset(sum,0,sizeof(sum));
		for(i=1;i<=cnt;i++)
		{
			limit=1<<(fac[a[i]].size());
			for(j=1;j<limit;j++)
			{
				tmp=1;
				num1=0;
				for(k=0;k<fac[a[i]].size();k++)
				{
					if((j>>k)&1)
					{
						num1++;
						tmp*=fac[a[i]][k];
					}
				}
				if(num1&1)
					ans+=sum[tmp];
				else
					ans-=sum[tmp];
				sum[tmp]++;
			}
		}
		printf("%lld\n",ans);
	}
}