#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
long long a[200005],b[200005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int cnt=0;
		long long j=0,o=0;
		long long minn=-0x3f3f3f3f;
		for(int q=0;q<n;q++)
		{
			scanf("%lld",&a[q]);
			minn=max(minn,a[q]);
			if(a[q]>=0)
			{
			if((q+1)%2==0) o+=a[q];
			else j+=a[q];
			cnt++;
			}
		}
//		for(int q=0;q<n;q++)
//		{
//			if(a[q]>=0)
//			{
//				b[cnt]=a[q];
//				cnt++;
//				if(cnt%2==0) o+=a[q];
//				else j+=a[q];
//			}
//			if(a[q]<0)
//			{
//				if(q==0||q==n-1) continue;
//				if(a[q+1]>=0)
//				{
//					b[cnt-1]+=a[q+1];
//					continue;
//				}
//				
//			}
//		}
		if(cnt>0)
		{
			if(j>=o) printf("%lld\n",j);
			else printf("%lld\n",o);
		}
		else 
		{
			printf("%lld\n",minn);
		}
	}
}