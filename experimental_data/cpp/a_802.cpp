#include <bits/stdc++.h>
using namespace std;
#define maxn 100
int flag2[maxn][maxn];
int tmp[maxn];
int res[maxn];
int a[maxn];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=n-1;i>=0;i--)
	{
		if(i!=n-1)
			memcpy(flag2[i],flag2[i+1],maxn*sizeof(int));
		flag2[i][a[i]]=1;
	}
/*
4 80
1 2 2 1
4 1
1 2 2 1
4 1
1 2 3 1
4 2
1 2 3 1
4 2
4 2 3 4
7 2
1 2 3 4 3 2 1
7 3
1 2 3 4 3 2 1
7 2
1 2 3 4 2 2 1


8 2
3 2 1 4 3 2 1 4


*/
	int diff=0,v=0,buy;
	for(i=0;i<n;i++)
	{
		buy=-1;
		if(!res[a[i]])
		{
			diff++;
			res[a[i]]=1;
			v++;
			buy=a[i];
		}
		if(diff>k)
		{
			diff--;
			if(i==n-1)
				break;
			int jcnt=0;
			for(j=1;j<=n;j++) if(res[j])
			{
				if(j==buy) continue;
				tmp[jcnt++]=j;
				if(!flag2[i+1][j])
					break;
			}
			if(j<=n)
				res[j]=0;
			else{
				int maxp=-1,maxv;
				for(j=0;j<jcnt;j++)
				{
					int p;
					int mini=0x3f3f3f3f;
					for(p=i+1;p<n;p++)
						if(a[p]==tmp[j]&&(mini==0x3f3f3f3f||mini>p))
							mini=p;
					if(maxp<mini)
						maxp=mini,maxv=tmp[j];
				}
				res[maxv]=0;				
			}
		}
	}
	printf("%d\n",v);
	return 0;
}