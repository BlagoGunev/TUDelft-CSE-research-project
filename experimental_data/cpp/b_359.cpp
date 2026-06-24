#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
int main()
{
	
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		int now=(n+1-i)*2-1;
		if (k<=now)
		{
			for (int j=1;j<=i-1;j++)
			{
				printf("%d %d ",j,2*n+1-j);
			}
			int spa=0,spb=0;
			if (k!=0)
			{
				if (k<=n-i+1)
				{
					spa=k+n;
					spb=n;
				}
				else
				{
					spa=2*n-i+1;
					spb=spa-k;
				}
				printf("%d %d ",spb,spa);
			}
			int anz=2*n+1-i;
			for (int j=i;j<=n;j++)
				if (j!=spb)
				{
					if (anz==spa)
						--anz;
					printf("%d %d ",anz,j);
					anz--;
				}
			break;
		}
		else
			k-=now;
	}
	printf("\n");
}