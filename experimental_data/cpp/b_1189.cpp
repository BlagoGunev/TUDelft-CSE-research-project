#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;

int main()
{
	//freopen("test.in","r",stdin);
	int n,a[N],v=-1;
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	if (a[n]>=a[1]+a[n-1])
	{
		for (v=n-2;v>=1;--v) if (a[v]+a[v+1]>a[n]) break;
		if (a[v]+a[v+1]<=a[n])
		{
			printf("NO");
			return 0;
		}
		printf("YES\n");
		for (int i=1;i<=v;++i) printf("%d ",a[i]);
		printf("%d ",a[n]);--n;
		for (int i=v+1;i<=n;++i) printf("%d ",a[i]);
	}
	else 
	{
		printf("YES\n");
		for (int i=1;i<=n;++i) printf("%d ",a[i]);
	}
}