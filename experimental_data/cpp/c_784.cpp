#include <cstdio>
#include <algorithm>

using namespace std;

int a[15];

int main()
{
	int n;
	scanf("%d",&n);
	int lar=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		lar=max(lar,a[i]);
	}
	printf("%d\n",lar^a[n]);
	return 0;
}